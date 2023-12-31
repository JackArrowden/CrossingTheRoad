#include "CMOUSE.h"

const bitmapHandMake CMOUSE::image(MOUSE_LINK_IMAGE);

CMOUSE::CMOUSE(int startX, int startY, int direction)
{
    mX = startX;
    mY = startY;
    direc = direction;
    topY = MOUSE_TOP;
    bottomY = MOUSE_BOTTOM;
}

CMOUSE::CMOUSE()
{
    mX = 0;
    mY = 0;
    direc = 0;
    topY = MOUSE_TOP;
    bottomY = MOUSE_BOTTOM;
}

void CMOUSE::tell()
{
    mciSendStringA("open Sound/MOUSE.wav type waveaudio alias Mouse", NULL, 0, 0);
    mciSendStringA("play Mouse", NULL, 0, NULL);
}

void CMOUSE::Move(int deltaX)
{
    mX += direc * deltaX;
    if (direc * vectorLimX * (direc + 1) < direc * (mX - direc * image.width / MOUSE_PER))
    {
        mX = vectorLimX * (1 - direc);
    }
}

void CMOUSE::draw(Render_State& screen)
{
    if (direc < 0) screen.drawReverseImage(image, mX, mY, MOUSE_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawImage(image, mX - image.width / MOUSE_PER, mY, MOUSE_PER, DEFAULT_BACKGROUND_COLOR);
}

int CMOUSE::getRightX() const
{
    if (direc < 0) return mX + MOUSE_RIGHT;
    return mX - MOUSE_LEFT;
}

int CMOUSE::getLeftX() const
{
    if (direc < 0) return mX + MOUSE_LEFT;
    return  mX - MOUSE_RIGHT;
}