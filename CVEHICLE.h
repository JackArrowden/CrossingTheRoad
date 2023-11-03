#pragma once
#include "ConsoleHandle.h"
#pragma comment(lib, "winmm.lib")


using namespace std;

class CVEHICLE
{
private:
	int mX, mY;
public:
	//virtual void Move(int, int) = 0;
	virtual void tell();

};


