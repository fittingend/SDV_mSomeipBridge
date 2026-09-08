# MSomeIP Bridge 외부 앱 연동 가이드

## 전제 조건

차량 IVI 이미지에 `MSomeIPBridgeService`가 시스템 앱으로 설치되어 있어야 한다.
외부 앱은 브리지와 Binder/AIDL로 통신하며 SOME/IP 또는 JNI 라이브러리를 직접
포함하지 않는다.

브리지 식별자는 다음과 같다.

| 항목 | 값 |
|---|---|
| 패키지 | `com.katech.ivi.msomeip.bridge` |
| 서비스 | `com.katech.ivi.connected.app.jni.MSomeIpBridgeService` |
| Bind action | `com.katech.ivi.msomeip.bridge.action.BIND` |
| 권한 | `com.katech.ivi.msomeip.bridge.permission.ACCESS_BRIDGE` |

## 1. 계약 파일 포함

브리지 저장소에서 다음 디렉터리를 외부 앱의 `app/src/main` 아래 동일한 패키지
경로로 복사한다.

```text
aidl/com/katech/ivi/msomeip/bridge/  -> app/src/main/aidl/com/katech/ivi/msomeip/bridge/
java/com/katech/ivi/msomeip/bridge/  -> app/src/main/java/com/katech/ivi/msomeip/bridge/
```

첫 번째 디렉터리에는 Binder 인터페이스와 Listener가 있고, 두 번째 디렉터리에는
Binder로 전달되는 Parcelable 구현이 있다. 일부 파일만 선택해서 복사하지 말고
두 디렉터리 전체를 같은 Git 커밋 기준으로 사용한다.

Gradle Android 모듈에서 AIDL 빌드가 꺼져 있다면 활성화한다.

```kotlin
android {
    buildFeatures {
        aidl = true
    }
}
```

## 2. AndroidManifest 설정

```xml
<manifest ...>
    <uses-permission
        android:name="com.katech.ivi.msomeip.bridge.permission.ACCESS_BRIDGE" />

    <queries>
        <package android:name="com.katech.ivi.msomeip.bridge" />
    </queries>

    <application ...>
        ...
    </application>
</manifest>
```

## 3. 브리지 연결

Kotlin 예제:

```kotlin
private const val BRIDGE_PACKAGE = "com.katech.ivi.msomeip.bridge"
private const val BRIDGE_SERVICE =
    "com.katech.ivi.connected.app.jni.MSomeIpBridgeService"
private const val BRIDGE_ACTION = "com.katech.ivi.msomeip.bridge.action.BIND"

private var bridge: IMSomeIpBridge? = null

private val connection = object : ServiceConnection {
    override fun onServiceConnected(name: ComponentName, binder: IBinder) {
        bridge = IMSomeIpBridge.Stub.asInterface(binder)
    }

    override fun onServiceDisconnected(name: ComponentName) {
        bridge = null
    }
}

fun bindBridge(context: Context): Boolean {
    val intent = Intent(BRIDGE_ACTION).apply {
        component = ComponentName(BRIDGE_PACKAGE, BRIDGE_SERVICE)
        `package` = BRIDGE_PACKAGE
    }
    return context.bindService(intent, connection, Context.BIND_AUTO_CREATE)
}
```

앱 종료 시 등록한 Listener를 해제한 다음 `unbindService()`를 호출한다.

## 4. VehicleInfo 수신

```kotlin
private val vehicleListener = object : IMSomeIpVehicleInfoListener.Stub() {
    override fun onVehicleInfoChanged(info: MSomeIpVehicleInfo) {
        val speed = info.speed
        val gear = info.gearState.toInt() and 0xff
        val acc = info.accIn.toInt() and 0xff
        val ign1 = info.ign1In.toInt() and 0xff
        val ign2 = info.ign2In.toInt() and 0xff
    }
}

bridge?.registerVehicleInfoListener(vehicleListener)
val current = bridge?.vehicleInfo
```

콜백은 Binder thread에서 실행되므로 UI 변경은 main thread로 전달한다.

## 5. 무드램프 상태 및 제어

```kotlin
private val mlmListener = object : IMSomeIpMlmListener.Stub() {
    override fun onMlmStatusChanged(status: MSomeIpMlmStatus) {
        val colorIndex = status.colorTableIndex.toInt() and 0xff
        val brightness = status.brightness
        val isNormal = status.isNormal.toInt() and 0xff
    }

    override fun onMlmSwVersionChanged(swVersion: Byte) = Unit
}

bridge?.registerMlmListener(mlmListener)

// 일반 제어 요청
bridge?.requestMlmSetRgbColor(colorTableIndex.toByte())
bridge?.requestMlmSetBrightness(brightness)
bridge?.requestMlmSetMode(mode.toByte())
```

AIDL의 `byte`는 signed이므로 0~255 값을 읽을 때는 `toInt() and 0xff`, 전달할 때는
`toByte()`를 사용한다. 색상 번호와 밝기의 유효 범위는 차량의 SoaMlm 인터페이스
정의 및 실제 제어기 사양을 따른다.

`...Ext` 메서드와 `startExtJobMlm()`/`stopExtJobMlm()`은 외부 제어권 방식이 필요한
경우에만 사용한다. 일반 앱의 기본 연동은 `requestMlmSet...()` 메서드로 시작한다.

## 6. HVAC

HVAC 상태는 `registerHvacListener()`로 수신하고 `setHvac...()` 메서드로 제어한다.
현재 차량에서 HVAC 제어기 연동 검증이 완료되지 않았으므로 실제 적용 전 별도
통합시험이 필요하다.

## 7. 확인 명령

```bash
adb shell pm list packages | grep msomeip
adb shell dumpsys package com.katech.ivi.msomeip.bridge
adb logcat | grep -E "MSomeIpBridgeService|SoaVehicleInfo|SoaMlm|SoaHvac"
```

무드램프 요청 시 브리지 로그에서 다음 메시지를 확인할 수 있다.

```text
AIDL MLM command received: colorTableIndex=...
requestMlmSetRgbColor dispatched: colorTableIndex=...
```

첫 번째 로그는 외부 앱에서 Binder 요청이 도착했다는 뜻이고, 두 번째 로그는
브리지가 SOME/IP 요청을 송신했다는 뜻이다.

## 호환성 원칙

- 외부 앱과 차량의 브리지 시스템 앱은 동일한 AIDL/Parcelable 계약을 사용해야 한다.
- 계약 파일의 package, 필드 순서, 타입 또는 메서드 순서를 임의로 변경하지 않는다.
- 브리지 기능을 추가할 때는 계약 변경과 시스템 앱 배포 버전을 함께 공지한다.
- 여러 업체가 이용하더라도 각 앱은 개별 Listener를 등록할 수 있다.
