#include "CMOUSE.h"

const bitmapHandMake CMOUSE::image(MOUSE_LINK_IMAGE);

CMOUSE::CMOUSE(int startX, int startY, int direction)
{
    mX = startX;
    mY = startY;
    direc = direction;
    topY = MOUSE_TOP;
    bottomY = MOUSE_BOTTOM;
    rightX = MOUSE_RIGHT;
    leftX = MOUSE_LEFT;
}

void CMOUSE::tell()
{
    if (PlaySound(TEXT("Sound\\MOUSE.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
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
            cout << "ERROR\n";
        }
    }
}

void CMOUSE::Move(int deltaX)
{
    mX += direc * deltaX;
}

void CMOUSE::draw(Render_State& screen)
{
    if (direc < 0) screen.drawImage(image, mX, mY, MOUSE_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX - image.width / MOUSE_PER, mY, MOUSE_PER, DEFAULT_BACKGROUND_COLOR);
}