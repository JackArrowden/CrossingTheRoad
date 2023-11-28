#include "CANIMAL.h"

int CANIMAL::vectorLimX = 640;

void CANIMAL::setLim(unsigned int newLim)
{
    vectorLimX = newLim;
}

int CANIMAL::getX()
{
    return mX;
}

int CANIMAL::getY()
{
    return mY;
}

void CANIMAL::setX(int newX)
{
    mX = newX;
}

void CANIMAL::setY(int newY)
{
    mY = newY;
}

void CANIMAL::setDirection(int newDirec)
{
    if (newDirec != -1 && newDirec != 1) return;
    direc = newDirec;
}



pair<pair<int, int>, pair<int, int>> CANIMAL::objectZone() const
{
    pair<pair<int, int>, pair<int, int>> res;
    res.first = make_pair(getLeftX(), mY + bottomY);
    res.second = make_pair(getRightX(), mY + topY);
    return res;
}


void CANIMAL::tell()
{
	PlaySound(TEXT("birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

istream& operator>>(istream& in, CANIMAL& x)
{
    int mX, mY, direc;
    in >> mX >> mY >> direc;
    x.setDirection(direc);
    x.setX(mX);
    x.setY(mY);
    return in;
}

ostream& operator<<(ostream& out, const CANIMAL& x)
{
    out << x.mX << ' ' << x.mY << ' ' << x.direc;
    return out;
}
