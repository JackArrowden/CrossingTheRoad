//#include "CGAME.h"

#pragma once
#pragma comment(lib, "winmm.lib")
#include "ConsoleHandle.h"
#include "BitMap.h"

using namespace std;
class CANIMAL {
protected:
    int mX;
    int mY;
    int direc;
    int topY;
    int bottomY;
public:
    virtual int getRightX() const = 0;
    virtual int getLeftX() const = 0;
    virtual void tell();
    virtual void Move(int deltaX) = 0;
    virtual void draw(Render_State& screen) = 0;
    pair<pair<int, int>, pair<int, int>> objectZone() const;
};

