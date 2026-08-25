package com.katech.ivi.msomeip.bridge;

import android.os.Parcel;
import android.os.Parcelable;

public class MSomeIpHvacStatus implements Parcelable {
    public boolean powerOn;
    public boolean acOnOff;
    public boolean autoMode;
    public boolean syncMode;
    public byte driverTemp;
    public byte passengerTemp;
    public byte blowingForce;
    public byte blowingDir;
    public byte airSrc;
    public boolean forwardFrostOn;
    public boolean backwardFrostOn;
    public byte driverMode;
    public byte passengerMode;

    public MSomeIpHvacStatus() {}

    protected MSomeIpHvacStatus(Parcel in) {
        powerOn = in.readByte() != 0;
        acOnOff = in.readByte() != 0;
        autoMode = in.readByte() != 0;
        syncMode = in.readByte() != 0;
        driverTemp = in.readByte();
        passengerTemp = in.readByte();
        blowingForce = in.readByte();
        blowingDir = in.readByte();
        airSrc = in.readByte();
        forwardFrostOn = in.readByte() != 0;
        backwardFrostOn = in.readByte() != 0;
        driverMode = in.readByte();
        passengerMode = in.readByte();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeByte((byte) (powerOn ? 1 : 0));
        dest.writeByte((byte) (acOnOff ? 1 : 0));
        dest.writeByte((byte) (autoMode ? 1 : 0));
        dest.writeByte((byte) (syncMode ? 1 : 0));
        dest.writeByte(driverTemp);
        dest.writeByte(passengerTemp);
        dest.writeByte(blowingForce);
        dest.writeByte(blowingDir);
        dest.writeByte(airSrc);
        dest.writeByte((byte) (forwardFrostOn ? 1 : 0));
        dest.writeByte((byte) (backwardFrostOn ? 1 : 0));
        dest.writeByte(driverMode);
        dest.writeByte(passengerMode);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<MSomeIpHvacStatus> CREATOR = new Creator<MSomeIpHvacStatus>() {
        @Override
        public MSomeIpHvacStatus createFromParcel(Parcel in) {
            return new MSomeIpHvacStatus(in);
        }

        @Override
        public MSomeIpHvacStatus[] newArray(int size) {
            return new MSomeIpHvacStatus[size];
        }
    };
}
