#pragma once
#include "ConsoleHandle.h"
#include "BitMap.h"
#pragma comment(lib, "winmm.lib")


using namespace std;

class CVEHICLE
{
protected:
	int mX, mY;
	int mode;
	int direc;
	
public:
	virtual void Move(int) = 0;
	virtual void tell() = 0;
	virtual void draw(Render_State& screen) = 0;

};


