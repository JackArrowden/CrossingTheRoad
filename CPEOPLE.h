#pragma once
#include "CANIMAL.h"
#include "CVEHICLE.h"

#define PEOPLE_LEFT 22
#define PEOPLE_RIGHT 60
#define PEOPLE_BOTTOM 5
#define PEOPLE_TOP 30
#define PEOPLE_LINK_IMAGE "image\\person.bmp"

class CPEOPLE {
	static const bitmapHandMake image;
	int mX, mY;
	bool mState; // State == 0: DEAD
	bool isInRange(int l, int val, int r);
public:
	bool isImpact(CVEHICLE* x);
	bool isImpact(CANIMAL* x);
	bool isDead() const;
	void setDead();
	CPEOPLE();
	int GetmX() const;
	int GetmY() const;
	int getRight() const;
	int getLeft() const;
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	void draw(Render_State& screen);

	friend istream& operator>>(istream& in, CPEOPLE& x);
	friend ostream& operator<<(ostream& out, const CPEOPLE& x);
};