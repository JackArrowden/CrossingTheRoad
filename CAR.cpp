#include "CAR.h"

const bitmapHandMake CAR::image(CAR_LINK_IMAGE);

CAR::CAR(int startX, int startY, char direction) 
{
    this->mX = startX;
    this->mY = startY;
    this->mode = 0;
    this->direc = direction;
}

void CAR::tell()
{
    //PlaySound(TEXT("Sound/birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //const char* soundFilePath = "Sound\\birds.wav";

    // Use PlaySound to play the sound file
    if (PlaySound(TEXT("Sound\\CAR.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
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

void CAR::Move(int deltaX)
{
    mX += direc * deltaX;
}
