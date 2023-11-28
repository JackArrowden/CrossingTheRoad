#pragma once
#include "CANIMAL.h"
#include "CVEHICLE.h"

#define PEOPLE_LEFT 22
#define PEOPLE_RIGHT 60
#define PEOPLE_BOTTOM 5
#define PEOPLE_TOP 50
#define PEOPLE_LINK_IMAGE "image\\person.bmp"

class CPEOPLE {
	static const bitmapHandMake image;
	int mX, mY;
	bool mState; // DEAD = 0

	bool isInRange(int l, int val, int r);
public:
	bool isImpact(const CVEHICLE*&x);
	bool isImpact(const CANIMAL*&x);
	//bool isFinish();
	//bool isDead();
	CPEOPLE();
	int GetmX() const;
	int GetmY() const;
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	void draw(Render_State& screen);

	friend istream& operator>>(istream& in, CPEOPLE& x);
	friend ostream& operator<<(ostream& out, const CPEOPLE& x);
};

