#pragma once
#include "CANIMAL.h"
#include "CVEHICLE.h"
class CPEOPLE {
	int mX, mY;
	bool mState; 
public:
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

