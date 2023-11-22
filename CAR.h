#pragma once
#include "CVEHICLE.h"


#define CAR_TOP 100
#define CAR_BOTTOM 40
#define CAR_RIGHT 200
#define CAR_LEFT 10
#define CAR_PER 1
#define CAR_LINK_IMAGE "image\\gameWindow\\car.bmp"

class CAR final : protected CVEHICLE
{
public:
	static const bitmapHandMake image;
	CAR(int startX, int startY, int direction);
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
};

