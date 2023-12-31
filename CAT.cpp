#include "CAT.h"

const bitmapHandMake CAT::image(CAT_LINK_IMAGE);

CAT::CAT(int startX, int startY, int direction)
{
    this->mX = startX;
    this->mY = startY;
    this->direc = direction;
    bottomY = CAT_BOTTOM;
    topY = CAT_TOP;
}

CAT::CAT()
{
    this->mX = 0;
    this->mY = 0;
    this->direc = 1;
    bottomY = CAT_BOTTOM;
    topY = CAT_TOP;
}

void CAT::tell()
{
    mciSendStringA("open Sound/CAT.wav type waveaudio alias Cat", NULL, 0, 0);
    mciSendStringA("play Cat", NULL, 0, NULL);
}

void CAT::Move(int deltaX)
{
    mX += direc * deltaX;
    if (direc * vectorLimX * (direc + 1) < direc * (mX - direc * image.width / CAT_PER))
    {
        mX = vectorLimX * (1 - direc);
    }
}

void CAT::draw(Render_State& screen)
{
    if (direc < 0) screen.drawImage(image, mX, mY, CAT_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX - image.width / CAT_PER, mY, CAT_PER, DEFAULT_BACKGROUND_COLOR);
}

int CAT::getRightX() const
{
    if (direc < 0) return mX + CAT_RIGHT;
    return mX - CAT_LEFT;
}

int CAT::getLeftX() const
{
    if (direc < 0) return mX + CAT_LEFT;
    return mX - CAT_RIGHT;
}