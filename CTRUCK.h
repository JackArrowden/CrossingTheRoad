#pragma once
#include "CVEHICLE.h"

#define TRUCK_TOP 72
#define TRUCK_BOTTOM 8
#define TRUCK_LEFT 15
#define TRUCK_RIGHT 330
#define TRUCK_PER 1
#define TRUCK_LINK_IMAGE "image\\gameWindow\\truck.bmp"

class CTRUCK : public CVEHICLE
{
	static const bitmapHandMake image;
public:
	CTRUCK(int startX, int startY, int direction);
	CTRUCK();
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
};

