package com.katech.ivi.msomeip.bridge;

import com.katech.ivi.msomeip.bridge.MSomeIpMlmStatus;

interface IMSomeIpMlmListener {
    oneway void onMlmStatusChanged(in MSomeIpMlmStatus status);
    oneway void onMlmSwVersionChanged(byte swVersion);
}
