package com.katech.ivi.connected.app.jni;

public interface SoaHvacBridgeListener {
    void onHvacSwVersionChanged(byte swVersion);
    void onHvacDeviceNormalChanged(byte deviceNormal);
    void onHvacSettingChanged(SoaHvacJNI.SoaHvacStatus setting);
    void onHvacStatusChanged(SoaHvacJNI.SoaHvacStatus status);
    void onHvacTempsChanged(SoaHvacJNI.SoaHvacTemps temps);
}
