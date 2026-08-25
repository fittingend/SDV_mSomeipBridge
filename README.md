# MSomeIPBridgeService

System App that exposes `SoaVehicleInfo`, `SoaHvac`, and `SoaMlm` through AIDL/Binder so market-installed APKs do not link against `libmsomeip_cpp.so`.

Installed location in this tree:

- `lagvm/LINUX/android/vendor/mobis/packages/apps/ivi/MSomeIPBridgeService`

This vendor path is intentional because the app depends on `libmsomeip_cpp` and the existing Mobis vendor JNI/SOME-IP integration pattern.

## Reused from existing code

- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/src/SoaVehicleInfoClient.cpp`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/src/SoaHvacClient.cpp`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/src/SoaMlmClient.cpp`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/src/SoaVehicleInfoJNI.java`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/src/SoaHvacJNI.java`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/src/SoaMlmJNI.java`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/generated/eevp/control/SoaVehicleInfo*.h`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/generated/eevp/control/SoaHvac*.h`
- `/home/sujin/Documents/01_GIT/03_SDV_example/src/eevp_main_machine/ivi_app/jni_interface/generated/eevp/control/SoaMlm*.h`

## TODO before image integration

- Set real SOME/IP `instance` and `connection` values via `persist.vendor.msomeip.*` properties.
- Confirm SELinux policy for exported system service access from third-party apps.
- If the product forbids `android:persistent="true"`, remove it and rely on bind-on-demand.
- Build once in-tree to validate `libmsomeip_cpp` header/export visibility on this branch.

## Client integration

- Copy `aidl/com/katech/ivi/msomeip/bridge/*` into the subscribing APK source tree.
- Declare `com.katech.ivi.msomeip.bridge.permission.ACCESS_BRIDGE`.
- Bind using action `com.katech.ivi.msomeip.bridge.action.BIND`.
