#include "CAT.h"

const bitmapHandMake CAT::image(CAT_LINK_IMAGE);

CAT::CAT(int startX, int startY, int direction)
{
    this->mX = startX;
    this->mY = startY;
    this->direc = direction;
    bottomY = CAT_BOTTOM;
    topY = CAT_TOP;
    rightX = CAT_RIGHT;
    leftX = CAT_LEFT;
}

void CAT::tell()
{
    if (PlaySound(TEXT("Sound\\CAT.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
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

void CAT::Move(int deltaX)
{
    mX += direc * deltaX;
}

void CAT::draw(Render_State& screen)
{
    if (direc < 0) screen.drawImage(image, mX, mY, CAT_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX, mY - image.width / CAT_PER, CAT_PER, DEFAULT_BACKGROUND_COLOR);    
}
