package com.katech.ivi.connected.app.jni;

/** Command-only normal SOA client. No subscriptions or Ext entry points. */
public final class SoaWiperJNI {
    static { System.loadLibrary("MSomeIPBridgeSoaWiper-Client"); }
    public long proxyptr;

    public SoaWiperJNI() { proxyptr = start(); }
    private native long start();
    private native void destroy(long proxy);
    public void close() {
        if (proxyptr != 0) { destroy(proxyptr); proxyptr = 0; }
    }
    public void RequestWiperOperation(byte mode) { RequestWiperOperation(proxyptr, mode); }
    private native void RequestWiperOperation(long proxy, byte mode);
}
