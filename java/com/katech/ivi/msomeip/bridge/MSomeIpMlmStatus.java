package com.katech.ivi.msomeip.bridge;

import android.os.Parcel;
import android.os.Parcelable;

public class MSomeIpMlmStatus implements Parcelable {
    public byte colorTableIndex;
    public int brightness;
    public byte isNormal;

    public MSomeIpMlmStatus() {}

    protected MSomeIpMlmStatus(Parcel in) {
        colorTableIndex = in.readByte();
        brightness = in.readInt();
        isNormal = in.readByte();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeByte(colorTableIndex);
        dest.writeInt(brightness);
        dest.writeByte(isNormal);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<MSomeIpMlmStatus> CREATOR = new Creator<MSomeIpMlmStatus>() {
        @Override
        public MSomeIpMlmStatus createFromParcel(Parcel in) {
            return new MSomeIpMlmStatus(in);
        }

        @Override
        public MSomeIpMlmStatus[] newArray(int size) {
            return new MSomeIpMlmStatus[size];
        }
    };
}
