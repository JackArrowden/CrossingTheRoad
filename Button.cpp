#include "Button.h"

Button::Button(const string& imageFile, int leftX, int bottomY, int per)
{
	image.readBitmapFile(imageFile);
	mX = leftX;
	mY = bottomY;
	this->per = per;
}

void Button::draw(Render_State& screen)
{
	screen.drawImage(image, mX, mY, per, DEFAULT_BACKGROUND_COLOR);
}
