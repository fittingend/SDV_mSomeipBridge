package com.katech.ivi.msomeip.bridge;

import com.katech.ivi.msomeip.bridge.MSomeIpVehicleInfo;

interface IMSomeIpVehicleInfoListener {
    oneway void onVehicleInfoChanged(in MSomeIpVehicleInfo vehicleInfo);
}
