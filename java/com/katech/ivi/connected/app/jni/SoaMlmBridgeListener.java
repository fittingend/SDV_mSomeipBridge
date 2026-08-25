package com.katech.ivi.connected.app.jni;

public interface SoaMlmBridgeListener {
    void onMlmStatusChanged(SoaMlmJNI.SoaMlmStatus status);
    void onMlmSwVersionChanged(byte swVersion);
}
