#pragma once
#include "bitmap.h"

class Button
{
	bitmapHandMake image;
	int mX;
	int mY;
	unsigned int per;
public:
	Button(const string& imageFile, int leftX, int bottomY, int per);
	void draw(Render_State& screen);
};

