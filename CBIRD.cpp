#include "CBIRD.h"

const bitmapHandMake CBIRD::image(BIRD_LINK_IMAGE);

CBIRD::CBIRD(int startX, int startY, int direction)
{
    this->mX = startX;
    this->mY = startY;
    this->direc = direction;
    bottomY = BIRD_BOTTOM;
    topY = BIRD_TOP;
}

CBIRD::CBIRD()
{
    this->mX = 0;
    this->mY = 0;
    this->direc = 1;
    bottomY = BIRD_BOTTOM;
    topY = BIRD_TOP;
}

void CBIRD::tell()
{
    mciSendStringA("open Sound/BIRD.wav type waveaudio alias Bird", NULL, 0, 0);
    mciSendStringA("play Bird", NULL, 0, NULL);
}

void CBIRD::Move(int deltaX)
{
    mX += direc * deltaX;
    if (direc * vectorLimX * (direc + 1) < direc * (mX - direc * image.width / BIRD_PER))
    {
        mX = vectorLimX * (1 - direc);
    }
}

void CBIRD::draw(Render_State& screen)
{
    if (direc < 0) screen.drawImage(image, mX, mY, BIRD_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX - image.width / BIRD_PER, mY, BIRD_PER, DEFAULT_BACKGROUND_COLOR);
}

int CBIRD::getRightX() const 
{
    if (direc < 0) return mX + BIRD_RIGHT;
    return mX - BIRD_LEFT;
}

int CBIRD::getLeftX() const
{
    if (direc < 0) return mX + BIRD_LEFT;
    return mX - BIRD_RIGHT;
}