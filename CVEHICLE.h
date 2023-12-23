#pragma once
#include "ConsoleHandle.h"
#include "BitMap.h"
#pragma comment(lib, "winmm.lib")

#ifndef MOVE_MODE 
#define	MOVE_MODE 1
#endif // !MOVE_MODE 

#ifndef STOP_MODE
#define STOP_MODE 0
#endif // !STOP_MODE

using namespace std;

class CVEHICLE {
protected:
	int mX, mY;
	int mode;
	int direc;
	int topY;
	int bottomY;
	static int vectorLimX;
public:
	static void setLim(unsigned int newLim);
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);
	void setDirection(int newDirec);
	
	virtual int getRightX() const = 0;
	virtual int getLeftX() const = 0;
	virtual void Move(int deltaX) = 0;
	virtual void tell() = 0;
	virtual void draw(Render_State& screen) = 0;
	pair<pair<int, int>, pair<int, int>> objectZone() const;
	
	friend istream& operator>>(istream& in, CVEHICLE& x);
	friend ostream& operator<<(ostream& out, const CVEHICLE& x);
};