package com.katech.ivi.connected.app.jni;

public class SoaVehicleInfoJNI {

	static {
		System.loadLibrary("SoaVehicleInfo-Client");
	}

	public long proxyptr;
	public native long start(String instance, String connection);
	private final SoaVehicleInfoBridgeListener listener;
    private final int timeout;
    private final int sender;

    public static class VehicleInfo {
		int speed;
		byte gearState;
		byte accIn;
		byte ign1In;
		byte ign2In;

		public VehicleInfo(){}

		public VehicleInfo(int speed, byte gearState, byte accIn, byte ign1In, byte ign2In){
			this.speed = speed;
			this.gearState = gearState;
			this.accIn = accIn;
			this.ign1In = ign1In;
			this.ign2In = ign2In;
		}
	}
    public VehicleInfo VehicleInfoToCPP() {
        return new VehicleInfo();
    }
    int AttributeSoaVehicleInfoSubscription = -1;
    public void subscribeAttributeSoaVehicleInfo(){
        subAttributeSoaVehicleInfo(this.proxyptr);
        ++AttributeSoaVehicleInfoSubscription;
    }

    public VehicleInfo getAttributeSoaVehicleInfoValue(){
        return getAttributeSoaVehicleInfoValue(this.proxyptr, timeout, sender);
    }

    public native void subAttributeSoaVehicleInfo(long proxyptr);
    public void subAttributeSoaVehicleInfoHandler(VehicleInfo soaVehicleInfo){
        listener.onVehicleInfoChanged(soaVehicleInfo);
    }
    public native VehicleInfo getAttributeSoaVehicleInfoValue(long proxyptr, int timeout, int sender);
    public native void unsubAttributeSoaVehicleInfo(long proxyptr, int subscription);


    public void unsubscribeAttributeSoaVehicleInfo(){
        if(this.AttributeSoaVehicleInfoSubscription >= 0){
            unsubAttributeSoaVehicleInfo(this.proxyptr, this.AttributeSoaVehicleInfoSubscription--);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
	public SoaVehicleInfoJNI(SoaVehicleInfoBridgeListener listener, String instance,
            String connection, int timeout, int sender){
		this.proxyptr = start(instance, connection);
		this.listener = listener;
        this.timeout = timeout;
        this.sender = sender;
	}

}
