package com.katech.ivi.connected.app.jni;

/** Command-only normal SOA client. No subscriptions or Ext entry points. */
public final class SoaDriverSeatJNI {
    static { System.loadLibrary("MSomeIPBridgeSoaDriverSeat-Client"); }
    public long proxyptr;

    public SoaDriverSeatJNI() { proxyptr = start(); }
    private native long start();
    private native void destroy(long proxy);
    public void close() {
        if (proxyptr != 0) { destroy(proxyptr); proxyptr = 0; }
    }
    public void RequestMoveDrvSeatSlide(byte dir) { RequestMoveDrvSeatSlide(proxyptr, dir); }
    private native void RequestMoveDrvSeatSlide(long proxy, byte dir);
    public void RequestMoveDrvSeatRecline(byte dir) { RequestMoveDrvSeatRecline(proxyptr, dir); }
    private native void RequestMoveDrvSeatRecline(long proxy, byte dir);
    public void RequestMoveDrvSeatHeight(byte dir) { RequestMoveDrvSeatHeight(proxyptr, dir); }
    private native void RequestMoveDrvSeatHeight(long proxy, byte dir);
}
