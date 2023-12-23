#include "CTRAIN.h"

const bitmapHandMake CTRAIN::imageCarrige(CARRIGE_LINK_IMAGE);
const bitmapHandMake CTRAIN::imageLocomotive(LOCOMOTIVE_LINK_IMAGE);

CTRAIN::CTRAIN(int startX, int startY, int direction, int numCarriges)
{
    mX = startX;
    mY = startY;
    direc = direction;
    mode = MOVE_MODE;
    this->numCarriges = numCarriges;
    bottomY = TRAIN_BOTTOM;
    topY = TRAIN_TOP;
}

CTRAIN::CTRAIN()
{
    mX = 0;
    mY = 0;
    direc = 1;
    mode = MOVE_MODE;
    numCarriges = 0;
    bottomY = TRAIN_BOTTOM;
    topY = TRAIN_TOP;
}

bool CTRAIN::setCarriges(int numCarriges)
{
    if (numCarriges < 0) return false;
    this->numCarriges = numCarriges;
    return true;
}

void CTRAIN::tell()
{
    mciSendStringA("open Sound/TRAIN.wav type waveaudio alias Train", NULL, 0, 0);
    mciSendStringA("play Train", NULL, 0, NULL);
}

void CTRAIN::Move(int deltaX)
{
    mX += deltaX * direc * mode;
    if ( direc * vectorLimX * (direc + 1) < direc * (mX - direc * (imageLocomotive.width / TRAIN_PER + imageCarrige.width / TRAIN_PER * numCarriges)))
    {
        mX = vectorLimX * (1 - direc);
    }
}

void CTRAIN::draw(Render_State& screen)
{
    if (direc < 0)
    {
        screen.drawImage(CTRAIN::imageLocomotive, mX, mY, TRAIN_PER, DEFAULT_BACKGROUND_COLOR);
        for (int i = 0; i < numCarriges; i++)
            screen.drawImage(CTRAIN::imageCarrige, mX + imageLocomotive.width / TRAIN_PER + i * imageCarrige.width / TRAIN_PER, mY, TRAIN_PER, DEFAULT_BACKGROUND_COLOR);
    }
    else
    {
        screen.drawReverseImage(CTRAIN::imageLocomotive, mX - imageLocomotive.width / TRAIN_PER, mY, TRAIN_PER, DEFAULT_BACKGROUND_COLOR);
        for (int i = 0; i < numCarriges; i++)
            screen.drawReverseImage(CTRAIN::imageCarrige, mX - imageLocomotive.width / TRAIN_PER - (i + 1) * imageCarrige.width / TRAIN_PER, mY, TRAIN_PER, DEFAULT_BACKGROUND_COLOR);
    }
}

int CTRAIN::getRightX() const
{
    if (direc < 0) return mX + imageLocomotive.width / TRAIN_PER + numCarriges * imageCarrige.width / TRAIN_PER - TRAIN_RIGHT;
    return mX - TRAIN_RIGHT;
}

int CTRAIN::getLeftX() const
{
    if (direc < 0) return mX + TRAIN_LEFT;
    return mX - imageLocomotive.width / TRAIN_PER - numCarriges * imageCarrige.width / TRAIN_PER + TRAIN_LEFT;
}

istream& operator>>(istream& in, CTRAIN& x)
{
    int direc, numCarriges;
    in >> x.mX >> x.mY >> direc >> numCarriges;
    x.setDirection(direc);
    x.setCarriges(numCarriges);
    return in;
}

ostream& operator<<(ostream& out, const CTRAIN& x)
{
    out << x.mX << ' ' << x.mY << ' ' << x.direc << ' ' << x.numCarriges;
    return out;
}