#include "CTRUCK.h"

const bitmapHandMake CTRUCK::image(TRUCK_LINK_IMAGE);

CTRUCK::CTRUCK(int startX, int startY, int direction)
{
    mX = startX;
    mY = startY;
    direc = direction;
    mode = MOVE_MODE;
    topY = TRUCK_TOP;
    bottomY = TRUCK_BOTTOM;
}

CTRUCK::CTRUCK()
{
    mX = 0;
    mY = 0;
    direc = 1;
    mode = MOVE_MODE;
    topY = TRUCK_TOP;
    bottomY = TRUCK_BOTTOM;
}

void CTRUCK::tell()
{
    mciSendStringA("open Sound/TRUCK.wav type waveaudio alias Truck", NULL, 0, 0);
    mciSendStringA("play Truck", NULL, 0, NULL);
}

void CTRUCK::Move(int deltaX)
{
    mX += mode * direc * deltaX;
    if (direc * vectorLimX * (direc + 1) < direc * (mX - direc * image.width / TRUCK_PER))
    {
        mX = vectorLimX * (1 - direc);
    }
}

void CTRUCK::draw(Render_State& screen)
{
    if (direc < 0) screen.drawReverseImage(image, mX , mY, TRUCK_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawImage(image, mX - image.width / TRUCK_PER, mY, TRUCK_PER, DEFAULT_BACKGROUND_COLOR);
}

int CTRUCK::getRightX() const
{
    if (direc < 0) return mX + TRUCK_RIGHT;
    return mX - TRUCK_LEFT;
}

int CTRUCK::getLeftX() const
{
    if (direc < 0) return mX + TRUCK_LEFT;
    return mX - TRUCK_RIGHT;
}