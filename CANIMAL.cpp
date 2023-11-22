#include "CANIMAL.h"

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