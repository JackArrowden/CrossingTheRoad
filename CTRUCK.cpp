#include "CTRUCK.h"

const bitmapHandMake CTRUCK::image(TRUCK_LINK_IMAGE);

CTRUCK::CTRUCK(int startX, int startY, int direction)
{
    mX = startX;
    mY = startY;
    direc = direction;
    mode = STOP_MODE;
    rightX = TRUCK_RIGHT;
    leftX = TRUCK_LEFT;
    topY = TRUCK_TOP;
    bottomY = TRUCK_BOTTOM;
}

void CTRUCK::tell()
{
    //PlaySound(TEXT("Sound/birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //const char* soundFilePath = "Sound\\birds.wav";

    // Use PlaySound to play the sound file
    if (PlaySound(TEXT("Sound\\TRUCK.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
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

void CTRUCK::Move(int deltaX)
{
    deltaX += direc * deltaX;
}

void CTRUCK::draw(Render_State& screen)
{
    if (direc < 0) screen.drawImage(image, mX, mY, TRUCK_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX - image.width / TRUCK_PER, mY, TRUCK_PER, DEFAULT_BACKGROUND_COLOR);
}