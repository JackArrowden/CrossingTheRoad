#include "CAR.h"

const bitmapHandMake CAR::image(CAR_LINK_IMAGE);

CAR::CAR(int startX, int startY, int direction) 
{
    mX = startX;
    mY = startY;
    mode = MOVE_MODE;
    direc = direction;
    bottomY = CAR_BOTTOM;
    topY = CAR_TOP;
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
    screen.drawReac2P(CAR::getLeftX(), CAR::getRightX(), mY + bottomY, mY + topY, 1348109);
    if (direc < 0) screen.drawReverseImage(CAR::image, mX, mY, CAR_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawImage(CAR::image, mX - image.width / CAR_PER, mY, CAR_PER, DEFAULT_BACKGROUND_COLOR);
}

int CAR::getRightX() {

    if (direc < 0) return mX + CAR_RIGHT;
    return mX - CAR_LEFT;
}

int CAR::getLeftX()
{
    if (direc < 0) return mX + CAR_LEFT;
    return mX - CAR_RIGHT;
}



