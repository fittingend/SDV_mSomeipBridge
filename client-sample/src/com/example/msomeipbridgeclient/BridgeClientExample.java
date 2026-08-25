package com.example.msomeipbridgeclient;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import com.katech.ivi.msomeip.bridge.IMSomeIpBridge;
import com.katech.ivi.msomeip.bridge.IMSomeIpHvacListener;
import com.katech.ivi.msomeip.bridge.IMSomeIpVehicleInfoListener;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacStatus;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacTemps;
import com.katech.ivi.msomeip.bridge.MSomeIpVehicleInfo;

public class BridgeClientExample {
    private static final String TAG = "BridgeClientExample";

    private IMSomeIpBridge mBridge;

    private final IMSomeIpVehicleInfoListener mVehicleInfoListener =
            new IMSomeIpVehicleInfoListener.Stub() {
                @Override
                public void onVehicleInfoChanged(MSomeIpVehicleInfo vehicleInfo) {
                    Log.i(TAG, "Vehicle speed=" + vehicleInfo.speed
                            + " gear=" + vehicleInfo.gearState);
                }
            };

    private final IMSomeIpHvacListener mHvacListener = new IMSomeIpHvacListener.Stub() {
        @Override
        public void onHvacSwVersionChanged(byte swVersion) {
            Log.i(TAG, "HVAC swVersion=" + swVersion);
        }

        @Override
        public void onHvacDeviceNormalChanged(byte deviceNormal) {
            Log.i(TAG, "HVAC deviceNormal=" + deviceNormal);
        }

        @Override
        public void onHvacSettingChanged(MSomeIpHvacStatus setting) {
            Log.i(TAG, "HVAC setting driverTemp=" + setting.driverTemp);
        }

        @Override
        public void onHvacStatusChanged(MSomeIpHvacStatus status) {
            Log.i(TAG, "HVAC status power=" + status.powerOn);
        }

        @Override
        public void onHvacTempsChanged(MSomeIpHvacTemps temps) {
            Log.i(TAG, "HVAC insideTemp=" + temps.inside);
        }
    };

    private final ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            mBridge = IMSomeIpBridge.Stub.asInterface(service);
            try {
                mBridge.registerVehicleInfoListener(mVehicleInfoListener);
                mBridge.registerHvacListener(mHvacListener);
                MSomeIpVehicleInfo info = mBridge.getVehicleInfo();
                Log.i(TAG, "Initial speed=" + info.speed);
                mBridge.setHvacPower(true);
                mBridge.setDriverTemp((byte) 22);
            } catch (RemoteException e) {
                Log.e(TAG, "Bridge call failed", e);
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            mBridge = null;
        }
    };

    public void bind(Context context) {
        Intent intent = new Intent("com.katech.ivi.msomeip.bridge.action.BIND");
        intent.setPackage("com.katech.ivi.msomeip.bridge");
        context.bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
    }

    public void unbind(Context context) {
        if (mBridge != null) {
            try {
                mBridge.unregisterVehicleInfoListener(mVehicleInfoListener);
                mBridge.unregisterHvacListener(mHvacListener);
            } catch (RemoteException e) {
                Log.w(TAG, "Failed to unregister listeners", e);
            }
        }
        context.unbindService(mConnection);
    }
}
