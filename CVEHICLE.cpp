#include "CVEHICLE.h"

int CVEHICLE::vectorLimX = 640;

void CVEHICLE::setLim(unsigned int newLim)
{
    vectorLimX = newLim;
}

int CVEHICLE::getX()
{
    return mX;
}

int CVEHICLE::getY()
{
    return mY;
}

void CVEHICLE::setX(int newX)
{
    mX = newX;
}

void CVEHICLE::setY(int newY)
{
    mY = newY;
}

void CVEHICLE::setDirection(int newDirec)
{
    if (newDirec != -1 && newDirec != 1) return;
    direc = newDirec;
}

void CVEHICLE::tell()
{
    if (PlaySound(TEXT("Sound\\TRUCK.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC)) 
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
        }
    }
}

pair<pair<int, int>, pair<int, int>> CVEHICLE::objectZone() const
{
    pair<pair<int, int>, pair<int, int>> res;
    res.first = make_pair(getLeftX(), mY + bottomY);
    res.second = make_pair(getRightX(), mY + topY);
    return res;
}

istream& operator>>(istream& in, CVEHICLE& x)
{
    int mX, mY, direc;
    in >> mX >> mY >> direc;
    x.setDirection(direc);
    x.setX(mX);
    x.setY(mY);
    return in;
}

ostream& operator<<(ostream& out, const CVEHICLE& x)
{
    out << x.mX << ' ' << x.mY << ' ' << x.direc;
    return out;
}