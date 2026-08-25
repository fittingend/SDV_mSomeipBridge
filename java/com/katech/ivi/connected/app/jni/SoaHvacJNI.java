package com.katech.ivi.connected.app.jni;

public class SoaHvacJNI {

	static {
		System.loadLibrary("SoaHvac-Client");
	}

	public long proxyptr;
	public native long start(String instance, String connection);
	private final SoaHvacBridgeListener listener;
    private final int timeout;
    private final int sender;

    public static class SoaHvacStatus {
		boolean powerOn;
		boolean acOnOff;
		boolean autoMode;
		boolean syncMode;
		byte driverTemp;
		byte passengerTemp;
		byte blowingForce;
		byte blowingDir;
		byte airSrc;
		boolean forwardFrostOn;
		boolean backwardFrostOn;
		byte driverMode;
		byte passengerMode;

		public SoaHvacStatus(){}

		public SoaHvacStatus(boolean powerOn, boolean acOnOff, boolean autoMode, boolean syncMode, byte driverTemp, byte passengerTemp, byte blowingForce, byte blowingDir, byte airSrc, boolean forwardFrostOn, boolean backwardFrostOn, byte driverMode, byte passengerMode){
			this.powerOn = powerOn;
			this.acOnOff = acOnOff;
			this.autoMode = autoMode;
			this.syncMode = syncMode;
			this.driverTemp = driverTemp;
			this.passengerTemp = passengerTemp;
			this.blowingForce = blowingForce;
			this.blowingDir = blowingDir;
			this.airSrc = airSrc;
			this.forwardFrostOn = forwardFrostOn;
			this.backwardFrostOn = backwardFrostOn;
			this.driverMode = driverMode;
			this.passengerMode = passengerMode;
		}
	}
    public SoaHvacStatus SoaHvacStatusToCPP() {
        return new SoaHvacStatus();
    }
    public static class SoaHvacTemps {
		byte inside;
		byte outside;
		byte duct;
		byte evaporator;
		byte driverVentDuct;
		byte driverFloorDuct;
		byte passengerVentDuct;
		byte passengerFloorDuct;

		public SoaHvacTemps(){}

		public SoaHvacTemps(byte inside, byte outside, byte duct, byte evaporator, byte driverVentDuct, byte driverFloorDuct, byte passengerVentDuct, byte passengerFloorDuct){
			this.inside = inside;
			this.outside = outside;
			this.duct = duct;
			this.evaporator = evaporator;
			this.driverVentDuct = driverVentDuct;
			this.driverFloorDuct = driverFloorDuct;
			this.passengerVentDuct = passengerVentDuct;
			this.passengerFloorDuct = passengerFloorDuct;
		}
	}
    public SoaHvacTemps SoaHvacTempsToCPP() {
        return new SoaHvacTemps();
    }
    int AttributeSoaHvacSwVersionSubscription = -1;
    public void subscribeAttributeSoaHvacSwVersion(){
        subAttributeSoaHvacSwVersion(this.proxyptr);
        ++AttributeSoaHvacSwVersionSubscription;
    }

    public byte getAttributeSoaHvacSwVersionValue(){
        return getAttributeSoaHvacSwVersionValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaHvacSwVersion(long proxyptr);
    public void subAttributeSoaHvacSwVersionHandler(byte soaHvacSwVersion){
        listener.onHvacSwVersionChanged(soaHvacSwVersion);
    }
    public native byte getAttributeSoaHvacSwVersionValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaHvacSwVersion(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaHvacSwVersion(){
        if(this.AttributeSoaHvacSwVersionSubscription >= 0){
            unsubAttributeSoaHvacSwVersion(this.proxyptr, this.AttributeSoaHvacSwVersionSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int AttributeSoaHvacDeviceNormalSubscription = -1;
    public void subscribeAttributeSoaHvacDeviceNormal(){
        subAttributeSoaHvacDeviceNormal(this.proxyptr);
        ++AttributeSoaHvacDeviceNormalSubscription;
    }

    public byte getAttributeSoaHvacDeviceNormalValue(){
        return getAttributeSoaHvacDeviceNormalValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaHvacDeviceNormal(long proxyptr);
    public void subAttributeSoaHvacDeviceNormalHandler(byte soaHvacDeviceNormal){
        listener.onHvacDeviceNormalChanged(soaHvacDeviceNormal);
    }
    public native byte getAttributeSoaHvacDeviceNormalValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaHvacDeviceNormal(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaHvacDeviceNormal(){
        if(this.AttributeSoaHvacDeviceNormalSubscription >= 0){
            unsubAttributeSoaHvacDeviceNormal(this.proxyptr, this.AttributeSoaHvacDeviceNormalSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int AttributeSoaHvacSettingSubscription = -1;
    public void subscribeAttributeSoaHvacSetting(){
        subAttributeSoaHvacSetting(this.proxyptr);
        ++AttributeSoaHvacSettingSubscription;
    }

    public SoaHvacStatus getAttributeSoaHvacSettingValue(){
        return getAttributeSoaHvacSettingValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaHvacSetting(long proxyptr);
    public void subAttributeSoaHvacSettingHandler(SoaHvacStatus soaHvacSetting){
        listener.onHvacSettingChanged(soaHvacSetting);
    }
    public native SoaHvacStatus getAttributeSoaHvacSettingValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaHvacSetting(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaHvacSetting(){
        if(this.AttributeSoaHvacSettingSubscription >= 0){
            unsubAttributeSoaHvacSetting(this.proxyptr, this.AttributeSoaHvacSettingSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int AttributeSoaHvacStatusSubscription = -1;
    public void subscribeAttributeSoaHvacStatus(){
        subAttributeSoaHvacStatus(this.proxyptr);
        ++AttributeSoaHvacStatusSubscription;
    }

    public SoaHvacStatus getAttributeSoaHvacStatusValue(){
        return getAttributeSoaHvacStatusValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaHvacStatus(long proxyptr);
    public void subAttributeSoaHvacStatusHandler(SoaHvacStatus soaHvacStatus){
        listener.onHvacStatusChanged(soaHvacStatus);
    }
    public native SoaHvacStatus getAttributeSoaHvacStatusValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaHvacStatus(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaHvacStatus(){
        if(this.AttributeSoaHvacStatusSubscription >= 0){
            unsubAttributeSoaHvacStatus(this.proxyptr, this.AttributeSoaHvacStatusSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int AttributeSoaHvacTempsSubscription = -1;
    public void subscribeAttributeSoaHvacTemps(){
        subAttributeSoaHvacTemps(this.proxyptr);
        ++AttributeSoaHvacTempsSubscription;
    }

    public SoaHvacTemps getAttributeSoaHvacTempsValue(){
        return getAttributeSoaHvacTempsValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaHvacTemps(long proxyptr);
    public void subAttributeSoaHvacTempsHandler(SoaHvacTemps soaHvacTemps){
        listener.onHvacTempsChanged(soaHvacTemps);
    }
    public native SoaHvacTemps getAttributeSoaHvacTempsValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaHvacTemps(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaHvacTemps(){
        if(this.AttributeSoaHvacTempsSubscription >= 0){
            unsubAttributeSoaHvacTemps(this.proxyptr, this.AttributeSoaHvacTempsSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetAcOnOff(boolean on){
        SetAcOnOff(this.proxyptr, on);
    }
    public native void SetAcOnOff(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetAcOnOffExt(boolean on){
        SetAcOnOffExt(this.proxyptr, on);
    }
    public native void SetAcOnOffExt(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetAirSource(byte src){
        SetAirSource(this.proxyptr, src);
    }
    public native void SetAirSource(long proxyptr, byte src);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetAirSourceExt(byte src){
        SetAirSourceExt(this.proxyptr, src);
    }
    public native void SetAirSourceExt(long proxyptr, byte src);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetAutoTemp(boolean on){
        SetAutoTemp(this.proxyptr, on);
    }
    public native void SetAutoTemp(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetAutoTempExt(boolean on){
        SetAutoTempExt(this.proxyptr, on);
    }
    public native void SetAutoTempExt(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetBackwardDefrostOn(boolean on){
        SetBackwardDefrostOn(this.proxyptr, on);
    }
    public native void SetBackwardDefrostOn(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetBackwardDefrostOnExt(boolean on){
        SetBackwardDefrostOnExt(this.proxyptr, on);
    }
    public native void SetBackwardDefrostOnExt(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetBlowingDirection(byte dir){
        SetBlowingDirection(this.proxyptr, dir);
    }
    public native void SetBlowingDirection(long proxyptr, byte dir);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetBlowingDirectionExt(byte dir){
        SetBlowingDirectionExt(this.proxyptr, dir);
    }
    public native void SetBlowingDirectionExt(long proxyptr, byte dir);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetBlowingForce(byte force){
        SetBlowingForce(this.proxyptr, force);
    }
    public native void SetBlowingForce(long proxyptr, byte force);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetBlowingForceExt(byte force){
        SetBlowingForceExt(this.proxyptr, force);
    }
    public native void SetBlowingForceExt(long proxyptr, byte force);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetDriverMode(byte dir){
        SetDriverMode(this.proxyptr, dir);
    }
    public native void SetDriverMode(long proxyptr, byte dir);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetDriverModeExt(byte dir){
        SetDriverModeExt(this.proxyptr, dir);
    }
    public native void SetDriverModeExt(long proxyptr, byte dir);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetDriverTemp(byte temperature){
        SetDriverTemp(this.proxyptr, temperature);
    }
    public native void SetDriverTemp(long proxyptr, byte temperature);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetDriverTempExt(byte temporature){
        SetDriverTempExt(this.proxyptr, temporature);
    }
    public native void SetDriverTempExt(long proxyptr, byte temporature);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetForwardDefrostOn(boolean on){
        SetForwardDefrostOn(this.proxyptr, on);
    }
    public native void SetForwardDefrostOn(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetForwardDefrostOnExt(boolean on){
        SetForwardDefrostOnExt(this.proxyptr, on);
    }
    public native void SetForwardDefrostOnExt(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetHvacPower(boolean on){
        SetHvacPower(this.proxyptr, on);
    }
    public native void SetHvacPower(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetHvacPowerExt(boolean on){
        SetHvacPowerExt(this.proxyptr, on);
    }
    public native void SetHvacPowerExt(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetPassengerMode(byte dir){
        SetPassengerMode(this.proxyptr, dir);
    }
    public native void SetPassengerMode(long proxyptr, byte dir);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetPassengerModeExt(byte dir){
        SetPassengerModeExt(this.proxyptr, dir);
    }
    public native void SetPassengerModeExt(long proxyptr, byte dir);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetPassengerTemp(byte temperature){
        SetPassengerTemp(this.proxyptr, temperature);
    }
    public native void SetPassengerTemp(long proxyptr, byte temperature);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetPassengerTempExt(byte temporature){
        SetPassengerTempExt(this.proxyptr, temporature);
    }
    public native void SetPassengerTempExt(long proxyptr, byte temporature);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetSync(boolean on){
        SetSync(this.proxyptr, on);
    }
    public native void SetSync(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void SetSyncExt(boolean on){
        SetSyncExt(this.proxyptr, on);
    }
    public native void SetSyncExt(long proxyptr, boolean on);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void StartExtJob_Hvac(){
        StartExtJob_Hvac(this.proxyptr);
    }
    public native void StartExtJob_Hvac(long proxyptr);

    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    public void StopExtJob_Hvac(){
        StopExtJob_Hvac(this.proxyptr);
    }
    public native void StopExtJob_Hvac(long proxyptr);

    /////////////////////////////////////////////////////////////////////////////////////////
	public SoaHvacJNI(SoaHvacBridgeListener listener, String instance, String connection,
            int timeout, int sender){
		this.proxyptr = start(instance, connection);
		this.listener = listener;
        this.timeout = timeout;
        this.sender = sender;
	}

}
