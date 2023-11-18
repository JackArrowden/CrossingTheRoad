#pragma once
#include "CVEHICLE.h"


#define CAR_TOP 10
#define CAR_BOTTOM 1
#define CAR_WIDTH 20
#define CAR_LINK_IMAGE "car.bmp"

class CAR final : protected CVEHICLE
{
public:
	static const bitmapHandMake image;
	CAR(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
};

