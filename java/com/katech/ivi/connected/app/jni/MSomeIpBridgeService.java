package com.katech.ivi.connected.app.jni;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteCallbackList;
import android.os.RemoteException;
import android.util.Log;

import com.katech.ivi.msomeip.bridge.IMSomeIpBridge;
import com.katech.ivi.msomeip.bridge.IMSomeIpHvacListener;
import com.katech.ivi.msomeip.bridge.IMSomeIpMlmListener;
import com.katech.ivi.msomeip.bridge.IMSomeIpVehicleInfoListener;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacStatus;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacTemps;
import com.katech.ivi.msomeip.bridge.MSomeIpMlmStatus;
import com.katech.ivi.msomeip.bridge.MSomeIpVehicleInfo;

import java.util.concurrent.atomic.AtomicInteger;

public class MSomeIpBridgeService extends Service implements SoaVehicleInfoBridgeListener,
        SoaHvacBridgeListener, SoaMlmBridgeListener {
    public static final String ACTION_BIND =
            "com.katech.ivi.msomeip.bridge.action.BIND";
    private static final String TAG = "MSomeIpBridgeService";

    private final Object mVehicleInfoLock = new Object();
    private final Object mHvacLock = new Object();
    private final Object mMlmLock = new Object();

    private SoaVehicleInfoJNI mVehicleInfoProxy;
    private SoaHvacJNI mHvacProxy;
    private SoaMlmJNI mMlmProxy;

    private final Object mDriverSeatLock = new Object();
    private SoaDriverSeatJNI mDriverSeatProxy;
    private final Object mSmartFilmLock = new Object();
    private SoaSmartFilmJNI mSmartFilmProxy;
    private final Object mWiperLock = new Object();
    private SoaWiperJNI mWiperProxy;

    private final AtomicInteger mVehicleInfoListenerCount = new AtomicInteger();
    private final AtomicInteger mHvacListenerCount = new AtomicInteger();
    private final AtomicInteger mMlmListenerCount = new AtomicInteger();

    private final RemoteCallbackList<IMSomeIpVehicleInfoListener> mVehicleInfoListeners =
            new RemoteCallbackList<IMSomeIpVehicleInfoListener>() {
                @Override
                public void onCallbackDied(IMSomeIpVehicleInfoListener callback) {
                    if (mVehicleInfoListenerCount.decrementAndGet() == 0) {
                        unsubscribeVehicleInfo();
                    }
                }
            };

    private final RemoteCallbackList<IMSomeIpHvacListener> mHvacListeners =
            new RemoteCallbackList<IMSomeIpHvacListener>() {
                @Override
                public void onCallbackDied(IMSomeIpHvacListener callback) {
                    if (mHvacListenerCount.decrementAndGet() == 0) {
                        unsubscribeHvac();
                    }
                }
            };

    private final RemoteCallbackList<IMSomeIpMlmListener> mMlmListeners =
            new RemoteCallbackList<IMSomeIpMlmListener>() {
                @Override
                public void onCallbackDied(IMSomeIpMlmListener callback) {
                    if (mMlmListenerCount.decrementAndGet() == 0) {
                        unsubscribeMlm();
                    }
                }
            };

    private final IMSomeIpBridge.Stub mBinder = new IMSomeIpBridge.Stub() {
        @Override
        public void requestMoveDrvSeatSlide(byte dir) throws RemoteException {
            synchronized (mDriverSeatLock) {
                if (mDriverSeatProxy == null) mDriverSeatProxy = new SoaDriverSeatJNI();
                if (mDriverSeatProxy.proxyptr == 0) throw new RemoteException("DriverSeat proxy connection failed");
                mDriverSeatProxy.RequestMoveDrvSeatSlide(dir);
            }
        }

        @Override
        public void requestMoveDrvSeatRecline(byte dir) throws RemoteException {
            synchronized (mDriverSeatLock) {
                if (mDriverSeatProxy == null) mDriverSeatProxy = new SoaDriverSeatJNI();
                if (mDriverSeatProxy.proxyptr == 0) throw new RemoteException("DriverSeat proxy connection failed");
                mDriverSeatProxy.RequestMoveDrvSeatRecline(dir);
            }
        }

        @Override
        public void requestMoveDrvSeatHeight(byte dir) throws RemoteException {
            synchronized (mDriverSeatLock) {
                if (mDriverSeatProxy == null) mDriverSeatProxy = new SoaDriverSeatJNI();
                if (mDriverSeatProxy.proxyptr == 0) throw new RemoteException("DriverSeat proxy connection failed");
                mDriverSeatProxy.RequestMoveDrvSeatHeight(dir);
            }
        }

        @Override
        public void setAllOpacities(byte opacity) throws RemoteException {
            synchronized (mSmartFilmLock) {
                if (mSmartFilmProxy == null) mSmartFilmProxy = new SoaSmartFilmJNI();
                if (mSmartFilmProxy.proxyptr == 0) throw new RemoteException("SmartFilm proxy connection failed");
                mSmartFilmProxy.SetAllOpacities(opacity);
            }
        }

        @Override
        public void requestWiperOperation(byte mode) throws RemoteException {
            synchronized (mWiperLock) {
                if (mWiperProxy == null) mWiperProxy = new SoaWiperJNI();
                if (mWiperProxy.proxyptr == 0) throw new RemoteException("Wiper proxy connection failed");
                mWiperProxy.RequestWiperOperation(mode);
            }
        }

        @Override
        public void registerVehicleInfoListener(IMSomeIpVehicleInfoListener listener)
                throws RemoteException {
            if (listener == null) {
                return;
            }
            synchronized (mVehicleInfoLock) {
                ensureVehicleInfoProxyLocked();
                if (mVehicleInfoListeners.register(listener)
                        && mVehicleInfoListenerCount.incrementAndGet() == 1) {
                    mVehicleInfoProxy.subscribeAttributeSoaVehicleInfo();
                }
            }
        }

        @Override
        public void unregisterVehicleInfoListener(IMSomeIpVehicleInfoListener listener) {
            if (listener == null) {
                return;
            }
            synchronized (mVehicleInfoLock) {
                if (mVehicleInfoListeners.unregister(listener)
                        && mVehicleInfoListenerCount.decrementAndGet() == 0) {
                    unsubscribeVehicleInfo();
                }
            }
        }

        @Override
        public MSomeIpVehicleInfo getVehicleInfo() throws RemoteException {
            synchronized (mVehicleInfoLock) {
                ensureVehicleInfoProxyLocked();
                return toBridgeVehicleInfo(mVehicleInfoProxy.getAttributeSoaVehicleInfoValue());
            }
        }

        @Override
        public void registerHvacListener(IMSomeIpHvacListener listener) throws RemoteException {
            if (listener == null) {
                return;
            }
            synchronized (mHvacLock) {
                ensureHvacProxyLocked();
                if (mHvacListeners.register(listener)
                        && mHvacListenerCount.incrementAndGet() == 1) {
                    mHvacProxy.subscribeAttributeSoaHvacSwVersion();
                    mHvacProxy.subscribeAttributeSoaHvacDeviceNormal();
                    mHvacProxy.subscribeAttributeSoaHvacSetting();
                    mHvacProxy.subscribeAttributeSoaHvacStatus();
                    mHvacProxy.subscribeAttributeSoaHvacTemps();
                }
            }
        }

        @Override
        public void unregisterHvacListener(IMSomeIpHvacListener listener) {
            if (listener == null) {
                return;
            }
            synchronized (mHvacLock) {
                if (mHvacListeners.unregister(listener)
                        && mHvacListenerCount.decrementAndGet() == 0) {
                    unsubscribeHvac();
                }
            }
        }

        @Override
        public byte getHvacSwVersion() throws RemoteException {
            synchronized (mHvacLock) {
                ensureHvacProxyLocked();
                return mHvacProxy.getAttributeSoaHvacSwVersionValue();
            }
        }

        @Override
        public byte getHvacDeviceNormal() throws RemoteException {
            synchronized (mHvacLock) {
                ensureHvacProxyLocked();
                return mHvacProxy.getAttributeSoaHvacDeviceNormalValue();
            }
        }

        @Override
        public MSomeIpHvacStatus getHvacSetting() throws RemoteException {
            synchronized (mHvacLock) {
                ensureHvacProxyLocked();
                return toBridgeHvacStatus(mHvacProxy.getAttributeSoaHvacSettingValue());
            }
        }

        @Override
        public MSomeIpHvacStatus getHvacStatus() throws RemoteException {
            synchronized (mHvacLock) {
                ensureHvacProxyLocked();
                return toBridgeHvacStatus(mHvacProxy.getAttributeSoaHvacStatusValue());
            }
        }

        @Override
        public MSomeIpHvacTemps getHvacTemps() throws RemoteException {
            synchronized (mHvacLock) {
                ensureHvacProxyLocked();
                return toBridgeHvacTemps(mHvacProxy.getAttributeSoaHvacTempsValue());
            }
        }

        @Override
        public void setAcOnOff(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetAcOnOff(on)); }
        @Override
        public void setAcOnOffExt(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetAcOnOffExt(on)); }
        @Override
        public void setAirSource(byte src) throws RemoteException { withHvac(proxy -> proxy.SetAirSource(src)); }
        @Override
        public void setAirSourceExt(byte src) throws RemoteException { withHvac(proxy -> proxy.SetAirSourceExt(src)); }
        @Override
        public void setAutoTemp(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetAutoTemp(on)); }
        @Override
        public void setAutoTempExt(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetAutoTempExt(on)); }
        @Override
        public void setBackwardDefrostOn(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetBackwardDefrostOn(on)); }
        @Override
        public void setBackwardDefrostOnExt(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetBackwardDefrostOnExt(on)); }
        @Override
        public void setBlowingDirection(byte dir) throws RemoteException { withHvac(proxy -> proxy.SetBlowingDirection(dir)); }
        @Override
        public void setBlowingDirectionExt(byte dir) throws RemoteException { withHvac(proxy -> proxy.SetBlowingDirectionExt(dir)); }
        @Override
        public void setBlowingForce(byte force) throws RemoteException { withHvac(proxy -> proxy.SetBlowingForce(force)); }
        @Override
        public void setBlowingForceExt(byte force) throws RemoteException { withHvac(proxy -> proxy.SetBlowingForceExt(force)); }
        @Override
        public void setDriverMode(byte dir) throws RemoteException { withHvac(proxy -> proxy.SetDriverMode(dir)); }
        @Override
        public void setDriverModeExt(byte dir) throws RemoteException { withHvac(proxy -> proxy.SetDriverModeExt(dir)); }
        @Override
        public void setDriverTemp(byte temperature) throws RemoteException { withHvac(proxy -> proxy.SetDriverTemp(temperature)); }
        @Override
        public void setDriverTempExt(byte temperature) throws RemoteException { withHvac(proxy -> proxy.SetDriverTempExt(temperature)); }
        @Override
        public void setForwardDefrostOn(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetForwardDefrostOn(on)); }
        @Override
        public void setForwardDefrostOnExt(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetForwardDefrostOnExt(on)); }
        @Override
        public void setHvacPower(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetHvacPower(on)); }
        @Override
        public void setHvacPowerExt(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetHvacPowerExt(on)); }
        @Override
        public void setPassengerMode(byte dir) throws RemoteException { withHvac(proxy -> proxy.SetPassengerMode(dir)); }
        @Override
        public void setPassengerModeExt(byte dir) throws RemoteException { withHvac(proxy -> proxy.SetPassengerModeExt(dir)); }
        @Override
        public void setPassengerTemp(byte temperature) throws RemoteException { withHvac(proxy -> proxy.SetPassengerTemp(temperature)); }
        @Override
        public void setPassengerTempExt(byte temperature) throws RemoteException { withHvac(proxy -> proxy.SetPassengerTempExt(temperature)); }
        @Override
        public void setSync(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetSync(on)); }
        @Override
        public void setSyncExt(boolean on) throws RemoteException { withHvac(proxy -> proxy.SetSyncExt(on)); }
        @Override
        public void startExtJobHvac() throws RemoteException { withHvac(SoaHvacJNI::StartExtJob_Hvac); }
        @Override
        public void stopExtJobHvac() throws RemoteException { withHvac(SoaHvacJNI::StopExtJob_Hvac); }

        @Override
        public void registerMlmListener(IMSomeIpMlmListener listener) throws RemoteException {
            if (listener == null) {
                return;
            }
            synchronized (mMlmLock) {
                ensureMlmProxyLocked();
                if (mMlmListeners.register(listener)
                        && mMlmListenerCount.incrementAndGet() == 1) {
                    mMlmProxy.subscribeAttributeSoaMlmStatus();
                    mMlmProxy.subscribeAttributeSoaMlmSwVersion();
                }
            }
        }

        @Override
        public void unregisterMlmListener(IMSomeIpMlmListener listener) {
            if (listener == null) {
                return;
            }
            synchronized (mMlmLock) {
                if (mMlmListeners.unregister(listener)
                        && mMlmListenerCount.decrementAndGet() == 0) {
                    unsubscribeMlm();
                }
            }
        }

        @Override
        public MSomeIpMlmStatus getMlmStatus() throws RemoteException {
            synchronized (mMlmLock) {
                ensureMlmProxyLocked();
                return toBridgeMlmStatus(mMlmProxy.getAttributeSoaMlmStatusValue());
            }
        }

        @Override
        public byte getMlmSwVersion() throws RemoteException {
            synchronized (mMlmLock) {
                ensureMlmProxyLocked();
                return mMlmProxy.getAttributeSoaMlmSwVersionValue();
            }
        }

        @Override
        public void requestMlmSetBrightness(int brightness) throws RemoteException {
            Log.i(TAG, "AIDL MLM command received: brightness=" + brightness);
            withMlm(proxy -> proxy.RequestMlmSetBrightness(brightness));
        }

        @Override
        public void requestMlmSetBrightnessExt(int brightness) throws RemoteException {
            withMlm(proxy -> proxy.RequestMlmSetBrightnessExt(brightness));
        }

        @Override
        public void requestMlmSetMode(byte mood) throws RemoteException {
            withMlm(proxy -> proxy.RequestMlmSetMode(mood));
        }

        @Override
        public void requestMlmSetModeExt(byte mood) throws RemoteException {
            withMlm(proxy -> proxy.RequestMlmSetModeExt(mood));
        }

        @Override
        public void requestMlmSetRgbColor(byte colorTableIndex) throws RemoteException {
            Log.i(TAG, "AIDL MLM command received: colorTableIndex="
                    + Byte.toUnsignedInt(colorTableIndex));
            withMlm(proxy -> proxy.RequestMlmSetRgbColor(colorTableIndex));
        }

        @Override
        public void requestMlmSetRgbColorExt(byte colorTableIndex) throws RemoteException {
            withMlm(proxy -> proxy.RequestMlmSetRgbColorExt(colorTableIndex));
        }

        @Override
        public void startExtJobMlm() throws RemoteException { withMlm(SoaMlmJNI::StartExtJob_Mlm); }
        @Override
        public void stopExtJobMlm() throws RemoteException { withMlm(SoaMlmJNI::StopExtJob_Mlm); }
    };

    @Override
    public void onCreate() {
        super.onCreate();
        Log.i(TAG, "MSomeIpBridgeService created");
    }

    @Override
    public IBinder onBind(Intent intent) {
        return mBinder;
    }

    @Override
    public void onDestroy() {
        unsubscribeVehicleInfo();
        unsubscribeHvac();
        unsubscribeMlm();
        mVehicleInfoListeners.kill();
        mHvacListeners.kill();
        mMlmListeners.kill();
        synchronized (mDriverSeatLock) {
            if (mDriverSeatProxy != null) mDriverSeatProxy.close();
        }
        synchronized (mSmartFilmLock) {
            if (mSmartFilmProxy != null) mSmartFilmProxy.close();
        }
        synchronized (mWiperLock) {
            if (mWiperProxy != null) mWiperProxy.close();
        }
        super.onDestroy();
    }

    @Override
    public void onVehicleInfoChanged(SoaVehicleInfoJNI.VehicleInfo vehicleInfo) {
        final int count = mVehicleInfoListeners.beginBroadcast();
        try {
            MSomeIpVehicleInfo parcel = toBridgeVehicleInfo(vehicleInfo);
            for (int i = 0; i < count; i++) {
                mVehicleInfoListeners.getBroadcastItem(i).onVehicleInfoChanged(parcel);
            }
        } catch (RemoteException e) {
            Log.w(TAG, "VehicleInfo callback failed", e);
        } finally {
            mVehicleInfoListeners.finishBroadcast();
        }
    }

    @Override
    public void onHvacSwVersionChanged(byte swVersion) {
        broadcastHvac(listener -> listener.onHvacSwVersionChanged(swVersion));
    }

    @Override
    public void onHvacDeviceNormalChanged(byte deviceNormal) {
        broadcastHvac(listener -> listener.onHvacDeviceNormalChanged(deviceNormal));
    }

    @Override
    public void onHvacSettingChanged(SoaHvacJNI.SoaHvacStatus setting) {
        MSomeIpHvacStatus parcel = toBridgeHvacStatus(setting);
        broadcastHvac(listener -> listener.onHvacSettingChanged(parcel));
    }

    @Override
    public void onHvacStatusChanged(SoaHvacJNI.SoaHvacStatus status) {
        MSomeIpHvacStatus parcel = toBridgeHvacStatus(status);
        broadcastHvac(listener -> listener.onHvacStatusChanged(parcel));
    }

    @Override
    public void onHvacTempsChanged(SoaHvacJNI.SoaHvacTemps temps) {
        MSomeIpHvacTemps parcel = toBridgeHvacTemps(temps);
        broadcastHvac(listener -> listener.onHvacTempsChanged(parcel));
    }

    @Override
    public void onMlmStatusChanged(SoaMlmJNI.SoaMlmStatus status) {
        MSomeIpMlmStatus parcel = toBridgeMlmStatus(status);
        broadcastMlm(listener -> listener.onMlmStatusChanged(parcel));
    }

    @Override
    public void onMlmSwVersionChanged(byte swVersion) {
        broadcastMlm(listener -> listener.onMlmSwVersionChanged(swVersion));
    }

    private void ensureVehicleInfoProxyLocked() throws RemoteException {
        if (mVehicleInfoProxy == null) {
            mVehicleInfoProxy = new SoaVehicleInfoJNI(this,
                    MSomeIpBridgeConfig.VEHICLE_INFO_INSTANCE,
                    MSomeIpBridgeConfig.VEHICLE_INFO_CONNECTION,
                    MSomeIpBridgeConfig.DEFAULT_TIMEOUT_MS,
                    MSomeIpBridgeConfig.DEFAULT_SENDER_ID);
        }
        if (mVehicleInfoProxy.proxyptr == 0) {
            throw new RemoteException("VehicleInfo proxy connection failed");
        }
    }

    private void ensureHvacProxyLocked() throws RemoteException {
        if (mHvacProxy == null) {
            mHvacProxy = new SoaHvacJNI(this,
                    MSomeIpBridgeConfig.HVAC_INSTANCE,
                    MSomeIpBridgeConfig.HVAC_CONNECTION,
                    MSomeIpBridgeConfig.DEFAULT_TIMEOUT_MS,
                    MSomeIpBridgeConfig.DEFAULT_SENDER_ID);
        }
        if (mHvacProxy.proxyptr == 0) {
            throw new RemoteException("HVAC proxy connection failed");
        }
    }

    private void ensureMlmProxyLocked() throws RemoteException {
        if (mMlmProxy == null) {
            mMlmProxy = new SoaMlmJNI(this,
                    MSomeIpBridgeConfig.MLM_INSTANCE,
                    MSomeIpBridgeConfig.MLM_CONNECTION,
                    MSomeIpBridgeConfig.DEFAULT_TIMEOUT_MS,
                    MSomeIpBridgeConfig.DEFAULT_SENDER_ID);
        }
        if (mMlmProxy.proxyptr == 0) {
            throw new RemoteException("MLM proxy connection failed");
        }
    }

    private void unsubscribeVehicleInfo() {
        if (mVehicleInfoProxy != null) {
            mVehicleInfoProxy.unsubscribeAttributeSoaVehicleInfo();
        }
    }

    private void unsubscribeHvac() {
        if (mHvacProxy != null) {
            mHvacProxy.unsubscribeAttributeSoaHvacSwVersion();
            mHvacProxy.unsubscribeAttributeSoaHvacDeviceNormal();
            mHvacProxy.unsubscribeAttributeSoaHvacSetting();
            mHvacProxy.unsubscribeAttributeSoaHvacStatus();
            mHvacProxy.unsubscribeAttributeSoaHvacTemps();
        }
    }

    private void unsubscribeMlm() {
        if (mMlmProxy != null) {
            mMlmProxy.unsubscribeAttributeSoaMlmStatus();
            mMlmProxy.unsubscribeAttributeSoaMlmSwVersion();
        }
    }

    private void withHvac(HvacCall call) throws RemoteException {
        synchronized (mHvacLock) {
            ensureHvacProxyLocked();
            call.run(mHvacProxy);
        }
    }

    private void withMlm(MlmCall call) throws RemoteException {
        synchronized (mMlmLock) {
            ensureMlmProxyLocked();
            call.run(mMlmProxy);
        }
    }

    private void broadcastHvac(HvacBroadcast broadcast) {
        final int count = mHvacListeners.beginBroadcast();
        try {
            for (int i = 0; i < count; i++) {
                broadcast.send(mHvacListeners.getBroadcastItem(i));
            }
        } catch (RemoteException e) {
            Log.w(TAG, "HVAC callback failed", e);
        } finally {
            mHvacListeners.finishBroadcast();
        }
    }

    private void broadcastMlm(MlmBroadcast broadcast) {
        final int count = mMlmListeners.beginBroadcast();
        try {
            for (int i = 0; i < count; i++) {
                broadcast.send(mMlmListeners.getBroadcastItem(i));
            }
        } catch (RemoteException e) {
            Log.w(TAG, "MLM callback failed", e);
        } finally {
            mMlmListeners.finishBroadcast();
        }
    }

    private static MSomeIpVehicleInfo toBridgeVehicleInfo(SoaVehicleInfoJNI.VehicleInfo src) {
        MSomeIpVehicleInfo dst = new MSomeIpVehicleInfo();
        dst.speed = src.speed;
        dst.gearState = src.gearState;
        dst.accIn = src.accIn;
        dst.ign1In = src.ign1In;
        dst.ign2In = src.ign2In;
        return dst;
    }

    private static MSomeIpHvacStatus toBridgeHvacStatus(SoaHvacJNI.SoaHvacStatus src) {
        MSomeIpHvacStatus dst = new MSomeIpHvacStatus();
        dst.powerOn = src.powerOn;
        dst.acOnOff = src.acOnOff;
        dst.autoMode = src.autoMode;
        dst.syncMode = src.syncMode;
        dst.driverTemp = src.driverTemp;
        dst.passengerTemp = src.passengerTemp;
        dst.blowingForce = src.blowingForce;
        dst.blowingDir = src.blowingDir;
        dst.airSrc = src.airSrc;
        dst.forwardFrostOn = src.forwardFrostOn;
        dst.backwardFrostOn = src.backwardFrostOn;
        dst.driverMode = src.driverMode;
        dst.passengerMode = src.passengerMode;
        return dst;
    }

    private static MSomeIpHvacTemps toBridgeHvacTemps(SoaHvacJNI.SoaHvacTemps src) {
        MSomeIpHvacTemps dst = new MSomeIpHvacTemps();
        dst.inside = src.inside;
        dst.outside = src.outside;
        dst.duct = src.duct;
        dst.evaporator = src.evaporator;
        dst.driverVentDuct = src.driverVentDuct;
        dst.driverFloorDuct = src.driverFloorDuct;
        dst.passengerVentDuct = src.passengerVentDuct;
        dst.passengerFloorDuct = src.passengerFloorDuct;
        return dst;
    }

    private static MSomeIpMlmStatus toBridgeMlmStatus(SoaMlmJNI.SoaMlmStatus src) {
        MSomeIpMlmStatus dst = new MSomeIpMlmStatus();
        dst.colorTableIndex = src.colorTableIndex;
        dst.brightness = src.brightness;
        dst.isNormal = src.isNormal;
        return dst;
    }

    private interface HvacCall {
        void run(SoaHvacJNI proxy);
    }

    private interface MlmCall {
        void run(SoaMlmJNI proxy);
    }

    private interface HvacBroadcast {
        void send(IMSomeIpHvacListener listener) throws RemoteException;
    }

    private interface MlmBroadcast {
        void send(IMSomeIpMlmListener listener) throws RemoteException;
    }
}
