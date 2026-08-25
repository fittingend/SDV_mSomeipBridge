package com.katech.ivi.connected.app.jni;

import android.os.SystemProperties;

public final class MSomeIpBridgeConfig {
    public static final int DEFAULT_TIMEOUT_MS = 1000;
    public static final int DEFAULT_SENDER_ID = 5555;
    public static final String VEHICLE_INFO_INSTANCE =
            SystemProperties.get("persist.vendor.msomeip.vehicle_info.instance", "");
    public static final String VEHICLE_INFO_CONNECTION =
            SystemProperties.get("persist.vendor.msomeip.vehicle_info.connection", "");
    public static final String HVAC_INSTANCE =
            SystemProperties.get("persist.vendor.msomeip.hvac.instance", "");
    public static final String HVAC_CONNECTION =
            SystemProperties.get("persist.vendor.msomeip.hvac.connection", "");
    public static final String MLM_INSTANCE =
            SystemProperties.get("persist.vendor.msomeip.mlm.instance", "");
    public static final String MLM_CONNECTION =
            SystemProperties.get("persist.vendor.msomeip.mlm.connection", "");

    private MSomeIpBridgeConfig() {}
}
