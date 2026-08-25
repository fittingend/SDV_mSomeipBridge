package com.katech.ivi.msomeip.bridge;

import android.os.Parcel;
import android.os.Parcelable;

public class MSomeIpHvacTemps implements Parcelable {
    public byte inside;
    public byte outside;
    public byte duct;
    public byte evaporator;
    public byte driverVentDuct;
    public byte driverFloorDuct;
    public byte passengerVentDuct;
    public byte passengerFloorDuct;

    public MSomeIpHvacTemps() {}

    protected MSomeIpHvacTemps(Parcel in) {
        inside = in.readByte();
        outside = in.readByte();
        duct = in.readByte();
        evaporator = in.readByte();
        driverVentDuct = in.readByte();
        driverFloorDuct = in.readByte();
        passengerVentDuct = in.readByte();
        passengerFloorDuct = in.readByte();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeByte(inside);
        dest.writeByte(outside);
        dest.writeByte(duct);
        dest.writeByte(evaporator);
        dest.writeByte(driverVentDuct);
        dest.writeByte(driverFloorDuct);
        dest.writeByte(passengerVentDuct);
        dest.writeByte(passengerFloorDuct);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<MSomeIpHvacTemps> CREATOR = new Creator<MSomeIpHvacTemps>() {
        @Override
        public MSomeIpHvacTemps createFromParcel(Parcel in) {
            return new MSomeIpHvacTemps(in);
        }

        @Override
        public MSomeIpHvacTemps[] newArray(int size) {
            return new MSomeIpHvacTemps[size];
        }
    };
}
