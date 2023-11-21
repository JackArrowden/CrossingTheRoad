#include "CANIMAL.h"

pair<pair<int, int>, pair<int, int>> CANIMAL::objectZone() const
{
    pair<pair<int, int>, pair<int, int>> res;
    res.first = make_pair(mX + leftX, mY + bottomY);
    res.second = make_pair(mX + rightX, mY + topY);
    return res;
}


void CANIMAL::tell()
{
	PlaySound(TEXT("birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
}