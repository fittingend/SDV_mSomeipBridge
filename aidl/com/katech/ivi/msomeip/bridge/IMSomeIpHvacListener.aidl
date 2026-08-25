package com.katech.ivi.msomeip.bridge;

import com.katech.ivi.msomeip.bridge.MSomeIpHvacStatus;
import com.katech.ivi.msomeip.bridge.MSomeIpHvacTemps;

interface IMSomeIpHvacListener {
    oneway void onHvacSwVersionChanged(byte swVersion);
    oneway void onHvacDeviceNormalChanged(byte deviceNormal);
    oneway void onHvacSettingChanged(in MSomeIpHvacStatus setting);
    oneway void onHvacStatusChanged(in MSomeIpHvacStatus status);
    oneway void onHvacTempsChanged(in MSomeIpHvacTemps temps);
}
