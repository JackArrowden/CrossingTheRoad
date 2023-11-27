#pragma once
#include "CVEHICLE.h"


#define CAR_TOP 60
#define CAR_BOTTOM 20
#define CAR_RIGHT 190
#define CAR_LEFT 3
#define CAR_PER 1
#define CAR_LINK_IMAGE "image\\gameWindow\\car.bmp"

class CAR : public CVEHICLE
{
public:
	static const bitmapHandMake image;
	CAR(int startX, int startY, int direction);
	CAR();
	void tell();
	void Move(int deltaX);
	void draw(Render_State& screen);
	int getRightX() const;
	int getLeftX() const;
};

