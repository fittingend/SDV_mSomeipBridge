package com.katech.ivi.connected.app.jni;

public class SoaMlmJNI {

	static {
		System.loadLibrary("MSomeIPBridgeSoaMlm-Client");
	}

	public long proxyptr;
	public native long start(String instance, String connection);
	private final SoaMlmBridgeListener listener;
    private final int timeout;
    private final int sender;

    public static class SoaMlmStatus {
		byte colorTableIndex;
		int brightness;
		byte isNormal;

		public SoaMlmStatus(){}

		public SoaMlmStatus(byte colorTableIndex, int brightness, byte isNormal){
			this.colorTableIndex = colorTableIndex;
			this.brightness = brightness;
			this.isNormal = isNormal;
		}
	}
    public SoaMlmStatus SoaMlmStatusToCPP() {
        return new SoaMlmStatus();
    }
    int AttributeSoaMlmStatusSubscription = -1;
    public void subscribeAttributeSoaMlmStatus(){
        subAttributeSoaMlmStatus(this.proxyptr);
        ++AttributeSoaMlmStatusSubscription;
    }

    public SoaMlmStatus getAttributeSoaMlmStatusValue(){
        return getAttributeSoaMlmStatusValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaMlmStatus(long proxyptr);
    public void subAttributeSoaMlmStatusHandler(SoaMlmStatus soaMlmStatus){
        listener.onMlmStatusChanged(soaMlmStatus);
    }
    public native SoaMlmStatus getAttributeSoaMlmStatusValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaMlmStatus(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaMlmStatus(){
        if(this.AttributeSoaMlmStatusSubscription >= 0){
            unsubAttributeSoaMlmStatus(this.proxyptr, this.AttributeSoaMlmStatusSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int AttributeSoaMlmSwVersionSubscription = -1;
    public void subscribeAttributeSoaMlmSwVersion(){
        subAttributeSoaMlmSwVersion(this.proxyptr);
        ++AttributeSoaMlmSwVersionSubscription;
    }

    public byte getAttributeSoaMlmSwVersionValue(){
        return getAttributeSoaMlmSwVersionValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaMlmSwVersion(long proxyptr);
    public void subAttributeSoaMlmSwVersionHandler(byte soaMlmSwVersion){
        listener.onMlmSwVersionChanged(soaMlmSwVersion);
    }
    public native byte getAttributeSoaMlmSwVersionValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaMlmSwVersion(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaMlmSwVersion(){
        if(this.AttributeSoaMlmSwVersionSubscription >= 0){
            unsubAttributeSoaMlmSwVersion(this.proxyptr, this.AttributeSoaMlmSwVersionSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void RequestMlmSetBrightness(int brightness){
        RequestMlmSetBrightness(this.proxyptr, brightness);
    }
    public native void RequestMlmSetBrightness(long proxyptr, int brightness);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void RequestMlmSetBrightnessExt(int brightness){
        RequestMlmSetBrightnessExt(this.proxyptr, brightness);
    }
    public native void RequestMlmSetBrightnessExt(long proxyptr, int brightness);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void RequestMlmSetMode(byte mood){
        RequestMlmSetMode(this.proxyptr, mood);
    }
    public native void RequestMlmSetMode(long proxyptr, byte mood);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void RequestMlmSetModeExt(byte mood){
        RequestMlmSetModeExt(this.proxyptr, mood);
    }
    public native void RequestMlmSetModeExt(long proxyptr, byte mood);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void RequestMlmSetRgbColor(byte colorTableIndex){
        RequestMlmSetRgbColor(this.proxyptr, colorTableIndex);
    }
    public native void RequestMlmSetRgbColor(long proxyptr, byte colorTableIndex);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void RequestMlmSetRgbColorExt(byte colorTableIndex){
        RequestMlmSetRgbColorExt(this.proxyptr, colorTableIndex);
    }
    public native void RequestMlmSetRgbColorExt(long proxyptr, byte colorTableIndex);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void StartExtJob_Mlm(){
        StartExtJob_Mlm(this.proxyptr);
    }
    public native void StartExtJob_Mlm(long proxyptr);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void StopExtJob_Mlm(){
        StopExtJob_Mlm(this.proxyptr);
    }
    public native void StopExtJob_Mlm(long proxyptr);

    /////////////////////////////////////////////////////////////////////////////////////////
	public SoaMlmJNI(SoaMlmBridgeListener listener, String instance, String connection,
            int timeout, int sender){
		this.proxyptr = start(instance, connection);
		this.listener = listener;
        this.timeout = timeout;
        this.sender = sender;
	}

}
