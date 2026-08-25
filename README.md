# MSomeIPBridgeService

`MSomeIPBridgeService`는 IVI Android 플랫폼 내부에서 SOME/IP 기반 차량 신호를 Binder/AIDL 서비스로 노출하는 시스템 앱이다. 마켓 또는 별도 설치 APK가 `libmsomeip_cpp.so`에 직접 링크하지 않고도 `SoaVehicleInfo`, `SoaHvac`, `SoaMlm` 데이터를 사용할 수 있도록 중간 브리지 역할을 한다.

## 구성

- 앱 모듈명: `MSomeIPBridgeService`
- 패키지명: `com.katech.ivi.msomeip.bridge`
- 서비스 클래스: `com.katech.ivi.connected.app.jni.MSomeIpBridgeService`
- 바인드 액션: `com.katech.ivi.msomeip.bridge.action.BIND`
- 접근 권한: `com.katech.ivi.msomeip.bridge.permission.ACCESS_BRIDGE`
- JNI 라이브러리:
  - `libSoaVehicleInfo-Client`
  - `libSoaHvac-Client`
  - `libSoaMlm-Client`

## 디렉터리 개요

- `aidl/`
  - 외부 클라이언트가 사용하는 AIDL 인터페이스 정의
- `java/`
  - Android 서비스, Binder Stub, 콜백 브리지 구현
- `jni/`
  - SOME/IP 클라이언트 및 JNI 연동 코드
- `client-sample/`
  - 브리지 서비스 연동 예제 앱

## IVI 플랫폼 소스 트리 반영 위치

이 프로젝트는 원래 아래 vendor 경로에 들어가도록 작성되었다.

```text
lagvm/LINUX/android/vendor/mobis/packages/apps/ivi/MSomeIPBridgeService
```

IVI 플랫폼 이미지를 빌드하려면 이 저장소를 위 경로에 복사하거나, 기존 소스 트리의 해당 경로와 동기화한 뒤 빌드해야 한다.

## IVI 플랫폼 이미지 빌드 방법

### 1. 소스 반영

IVI Android 소스 트리 기준으로 `MSomeIPBridgeService` 디렉터리를 아래 위치에 반영한다.

```bash
cp -a /home/sujin/Documents/01_GIT/08_mSomeipBridgeService/MSomeIPBridgeService \
  /path/to/ivi/lagvm/LINUX/android/vendor/mobis/packages/apps/ivi/
```
### 2-i) 전체 이미지 빌드

정식 반영은 전체 IVI 이미지 빌드로 확인하는 것이 안전하다.

```bash
cd release
source build_mis.sh 2
build_la -j2
```

### 2-ii) 모듈 단독 빌드

```bash
cd /path/to/ivi/lagvm/LINUX/android
source build/envsetup.sh
lunch mis-userdebug
m -j2 MSomeIPBridgeService
```

## 빌드 산출물

빌드가 끝나면 일반적으로 아래 산출물을 확인하면 된다.

- APK:
  - `out/target/product/mis/system/priv-app/MSomeIPBridgeService/MSomeIPBridgeService.apk`
- JNI `.so`:
  - `out/target/product/mis/system/lib64/libSoaVehicleInfo-Client.so`
  - `out/target/product/mis/system/lib64/libSoaHvac-Client.so`
  - `out/target/product/mis/system/lib64/libSoaMlm-Client.so`
  - `out/target/product/mis/system/lib/libSoaVehicleInfo-Client.so`
  - `out/target/product/mis/system/lib/libSoaHvac-Client.so`
  - `out/target/product/mis/system/lib/libSoaMlm-Client.so`

이 앱은 `privileged: true`, `certificate: "platform"` 설정을 사용하므로 플랫폼 이미지 내부 탑재를 전제로 한다.

## 디바이스에 로드하는 방법

반영 방식은 두 가지로 보면 된다.

### 1. 플랫폼 이미지에 포함해서 플래시

가장 정상적인 방법이다.

1. IVI 전체 이미지를 빌드한다.
2. 이미지 산출물을 준비한다.

```bash
cd release
source build_mis.sh
cpimg
```

`cpimg`가 끝나면 이미지들이 `out` 디렉터리로 복사된다.

3. UART serial을 PC와 연결하고, serial 로그를 볼 수 있는 터미널(putty, `cmd` 등)을 연다.
4. 보드 전원을 넣을 때 serial 콘솔에서 아래 화살표를 누른 상태로 유지해 부트로더 진입을 준비한다.
5. 부트로더/fastboot/제조사 전용 다운로드 도구를 사용해 디바이스에 플래시한다.

```bash
cd out/LA
fastboot_LA.sh
```
6. 부팅 후 서비스 탑재 여부를 확인한다.

확인 예시:

```bash
adb shell pm list packages | grep msomeip
adb shell dumpsys package com.katech.ivi.msomeip.bridge
adb shell dumpsys activity services com.katech.ivi.msomeip.bridge
```

### 2. 개발용으로 APK만 수동 반영

디바이스가 `adb root`와 `adb remount`를 허용하는 개발 빌드일 때만 사용한다.

```bash
adb root
adb remount
adb push out/target/product/mis/system/priv-app/MSomeIPBridgeService/MSomeIPBridgeService.apk /system/priv-app/MSomeIPBridgeService/MSomeIPBridgeService.apk
adb push out/target/product/mis/system/lib64/libSoaMlm-Client.so /system/lib64/libSoaMlm-Client.so
adb push out/target/product/mis/system/lib64/libSoaHvac-Client.so /system/lib64/libSoaHvac-Client.so
adb push out/target/product/mis/system/lib64/libSoaVehicleInfo-Client.so /system/lib64/libSoaVehicleInfo-Client.so
adb push out/target/product/mis/system/lib/libSoaMlm-Client.so /system/lib/libSoaMlm-Client.so
adb push out/target/product/mis/system/lib/libSoaHvac-Client.so /system/lib/libSoaHvac-Client.so
adb push out/target/product/mis/system/lib/libSoaVehicleInfo-Client.so /system/lib/libSoaVehicleInfo-Client.so
adb reboot
```

## 서비스 동작 확인

부팅 후 아래 항목을 확인한다.

```bash
adb logcat | grep -i MSomeIpBridgeService
adb logcat | grep -i SoaVehicleInfo
adb logcat | grep -i SoaHvac
adb logcat | grep -i SoaMlm
```

필요 시 Binder 바인드 가능 여부도 확인한다.

```bash
adb shell dumpsys activity services | grep -i MSomeIpBridgeService
```

## 주의 사항

- 현재 `SoaVehicleInfo` 알림 수신부는 AA에서 송신하는 실제 payload 형태가 FIDL/FDEPL 정의와 일치하지 않아, generated proxy의 일반 `Deserialize` 경로 대신 수동 parsing으로 우회하고 있다.
- `SoaVehicleInfo`를 제외한 다른 부품(`SoaHvac`, `SoaMlm`)의 경우에도 현재 AA 송신 payload가 FIDL/FDEPL 정의와 완전히 일치하는지, 그리고 generated proxy의 `Deserialize`가 실차/실서비스 환경에서 정상 동작하는지는 아직 확인되지 않았다.
- 따라서 실제 연동 중 deserialize 실패, 필드 누락, 값 깨짐이 보이면 각 도메인 payload 구조에 맞춰 수동 parsing 또는 generated proxy 보정 작업이 추가로 필요할 수 있다.
