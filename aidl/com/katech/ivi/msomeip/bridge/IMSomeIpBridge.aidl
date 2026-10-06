package com.katech.ivi.msomeip.bridge;

import com.katech.ivi.msomeip.bridge.IMSomeIpHvacListener;
import com.katech.ivi.msomeip.bridge.IMSomeIpMlmListener;
import com.katech.ivi.msomeip.bridge.IMSomeIpVehicleInfoListener;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacStatus;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacTemps;
import com.katech.ivi.msomeip.bridge.MSomeIpMlmStatus;
import com.katech.ivi.msomeip.bridge.MSomeIpVehicleInfo;

interface IMSomeIpBridge {
    void registerVehicleInfoListener(IMSomeIpVehicleInfoListener listener);
    void unregisterVehicleInfoListener(IMSomeIpVehicleInfoListener listener);
    MSomeIpVehicleInfo getVehicleInfo();

    void registerHvacListener(IMSomeIpHvacListener listener);
    void unregisterHvacListener(IMSomeIpHvacListener listener);
    byte getHvacSwVersion();
    byte getHvacDeviceNormal();
    MSomeIpHvacStatus getHvacSetting();
    MSomeIpHvacStatus getHvacStatus();
    MSomeIpHvacTemps getHvacTemps();
    oneway void setAcOnOff(in boolean on);
    oneway void setAcOnOffExt(in boolean on);
    oneway void setAirSource(in byte src);
    oneway void setAirSourceExt(in byte src);
    oneway void setAutoTemp(in boolean on);
    oneway void setAutoTempExt(in boolean on);
    oneway void setBackwardDefrostOn(in boolean on);
    oneway void setBackwardDefrostOnExt(in boolean on);
    oneway void setBlowingDirection(in byte dir);
    oneway void setBlowingDirectionExt(in byte dir);
    oneway void setBlowingForce(in byte force);
    oneway void setBlowingForceExt(in byte force);
    oneway void setDriverMode(in byte dir);
    oneway void setDriverModeExt(in byte dir);
    oneway void setDriverTemp(in byte temperature);
    oneway void setDriverTempExt(in byte temperature);
    oneway void setForwardDefrostOn(in boolean on);
    oneway void setForwardDefrostOnExt(in boolean on);
    oneway void setHvacPower(in boolean on);
    oneway void setHvacPowerExt(in boolean on);
    oneway void setPassengerMode(in byte dir);
    oneway void setPassengerModeExt(in byte dir);
    oneway void setPassengerTemp(in byte temperature);
    oneway void setPassengerTempExt(in byte temperature);
    oneway void setSync(in boolean on);
    oneway void setSyncExt(in boolean on);
    oneway void startExtJobHvac();
    oneway void stopExtJobHvac();

    void registerMlmListener(IMSomeIpMlmListener listener);
    void unregisterMlmListener(IMSomeIpMlmListener listener);
    MSomeIpMlmStatus getMlmStatus();
    byte getMlmSwVersion();
    oneway void requestMlmSetBrightness(in int brightness);
    oneway void requestMlmSetBrightnessExt(in int brightness);
    oneway void requestMlmSetMode(in byte mood);
    oneway void requestMlmSetModeExt(in byte mood);
    oneway void requestMlmSetRgbColor(in byte colorTableIndex);
    oneway void requestMlmSetRgbColorExt(in byte colorTableIndex);
    oneway void startExtJobMlm();
    oneway void stopExtJobMlm();

    // Cinema phase 1: normal SOA controls only.
    oneway void requestMoveDrvSeatSlide(in byte dir);
    oneway void requestMoveDrvSeatRecline(in byte dir);
    oneway void requestMoveDrvSeatHeight(in byte dir);
    oneway void setAllOpacities(in byte opacity);
    oneway void requestWiperOperation(in byte mode);
}
