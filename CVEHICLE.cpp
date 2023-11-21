#include "CVEHICLE.h"

void CVEHICLE::tell()
{
    //PlaySound(TEXT("Sound/birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //const char* soundFilePath = "Sound\\birds.wav";

    // Use PlaySound to play the sound file
    if (PlaySound(TEXT("Sound\\TRUCK.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC)) 
    {
        // Sound started playing successfully
        // You can add additional code here if needed
    }
    else {
        // Error handling
        DWORD error = GetLastError();
        if (error != MMSYSERR_NOERROR) {
            // Handle the error
            // You can print an error message or perform other actions
        }
    }

}

pair<pair<int, int>, pair<int, int>> CVEHICLE::objectZone() const
{
    pair<pair<int, int>, pair<int, int>> res;
    res.first = make_pair(mX + leftX, mY + bottomY);
    res.second = make_pair(mX + rightX, mY + topY);
    return res;
}
