package com.katech.ivi.msomeip.bridge;

import android.os.Parcel;
import android.os.Parcelable;

public class MSomeIpVehicleInfo implements Parcelable {
    public int speed;
    public byte gearState;
    public byte accIn;
    public byte ign1In;
    public byte ign2In;

    public MSomeIpVehicleInfo() {}

    protected MSomeIpVehicleInfo(Parcel in) {
        speed = in.readInt();
        gearState = in.readByte();
        accIn = in.readByte();
        ign1In = in.readByte();
        ign2In = in.readByte();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(speed);
        dest.writeByte(gearState);
        dest.writeByte(accIn);
        dest.writeByte(ign1In);
        dest.writeByte(ign2In);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<MSomeIpVehicleInfo> CREATOR = new Creator<MSomeIpVehicleInfo>() {
        @Override
        public MSomeIpVehicleInfo createFromParcel(Parcel in) {
            return new MSomeIpVehicleInfo(in);
        }

        @Override
        public MSomeIpVehicleInfo[] newArray(int size) {
            return new MSomeIpVehicleInfo[size];
        }
    };
}
