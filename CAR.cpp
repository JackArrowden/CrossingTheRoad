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

CAR::CAR()
{
    mode = MOVE_MODE;
    bottomY = CAR_BOTTOM;
    topY = CAR_TOP;
    mX = 0;
    mY = 0;
    direc = 1;
}

void CAR::tell()
{
    mciSendStringA("open Sound/CAR.wav type waveaudio alias Car", NULL, 0, 0);
    mciSendStringA("play Car", NULL, 0, NULL);
}

void CAR::Move(int deltaX)
{
    mX += mode * direc * deltaX;
    if (direc * vectorLimX * (direc + 1) < direc * (mX - direc * image.width / CAR_PER))
    {
        mX = vectorLimX * (1 - direc);
    }
}

void CAR::draw(Render_State& screen)
{
    if (direc < 0) screen.drawReverseImage(CAR::image, mX, mY, CAR_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawImage(CAR::image, mX - image.width / CAR_PER, mY, CAR_PER, DEFAULT_BACKGROUND_COLOR);
}

int CAR::getRightX() const 
{
    if (direc < 0) return mX + CAR_RIGHT;
    return mX - CAR_LEFT;
}

int CAR::getLeftX() const
{
    if (direc < 0) return mX + CAR_LEFT;
    return mX - CAR_RIGHT;
}