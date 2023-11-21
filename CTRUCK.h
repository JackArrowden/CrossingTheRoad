#pragma once
#include "CVEHICLE.h"

#define TRUCK_TOP 10
#define TRUCK_BOTTOM 1
#define TRUCK_LEFT 10
#define TRUCK_RIGHT 20
#define TRUCK_PER 1
#define TRUCK_LINK_IMAGE "image\\gameWindow\\truck.bmp"

class CTRUCK : protected CVEHICLE
{
	static const bitmapHandMake image;
public:
	CTRUCK(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
};

