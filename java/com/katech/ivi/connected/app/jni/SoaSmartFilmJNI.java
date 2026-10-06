package com.katech.ivi.connected.app.jni;

/** Command-only normal SOA client. No subscriptions or Ext entry points. */
public final class SoaSmartFilmJNI {
    static { System.loadLibrary("MSomeIPBridgeSoaSmartFilm-Client"); }
    public long proxyptr;

    public SoaSmartFilmJNI() { proxyptr = start(); }
    private native long start();
    private native void destroy(long proxy);
    public void close() {
        if (proxyptr != 0) { destroy(proxyptr); proxyptr = 0; }
    }
    public void SetAllOpacities(byte opacity) { SetAllOpacities(proxyptr, opacity); }
    private native void SetAllOpacities(long proxy, byte opacity);
}
