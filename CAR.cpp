#include "CAR.h"

const bitmapHandMake CAR::image(CAR_LINK_IMAGE);

CAR::CAR(int startX, int startY, int direction) 
{
    this->mX = startX;
    this->mY = startY;
    this->mode = STOP_MODE;
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
    mX += mode * direc * deltaX;
}

void CAR::draw(Render_State& screen)
{
    if (direc < 0) screen.drawReverseImage(CAR::image, mX, mY, 1, DEFAULT_BACKGROUND_COLOR);
    else screen.drawImage(CAR::image, mX - CAR_WIDTH, mY, 1, DEFAULT_BACKGROUND_COLOR);
}
