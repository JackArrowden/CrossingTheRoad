#include "CPEOPLE.h"

const bitmapHandMake CPEOPLE::image(PEOPLE_LINK_IMAGE);

bool CPEOPLE::isInRange(int l, int val, int r)
{
	return l <= val && val <= r;
}

bool CPEOPLE::isImpact(const CVEHICLE*& x)
{
	pair<pair<int, int>, pair<int, int>> zone = x->objectZone();
	bool res = isInRange(mX + PEOPLE_LEFT, zone.first.first, mX + PEOPLE_RIGHT) || isInRange(mX + PEOPLE_LEFT, zone.second.first, mX + PEOPLE_RIGHT);
	res = res && (isInRange(mY + PEOPLE_BOTTOM, zone.first.second, mY + PEOPLE_TOP) || isInRange(mY + PEOPLE_BOTTOM, zone.second.second, mY + PEOPLE_TOP));
	return res;
}

bool CPEOPLE::isImpact(const CANIMAL*& x)
{
	pair<pair<int, int>, pair<int, int>> zone = x->objectZone();
	bool res = isInRange(mX + PEOPLE_LEFT, zone.first.first, mX + PEOPLE_RIGHT) || isInRange(mX + PEOPLE_LEFT, zone.second.first, mX + PEOPLE_RIGHT);
	res = res && (isInRange(mY + PEOPLE_BOTTOM, zone.first.second, mY + PEOPLE_TOP) || isInRange(mY + PEOPLE_BOTTOM, zone.second.second, mY + PEOPLE_TOP));
	return res;
}

CPEOPLE::CPEOPLE()
{
	mY = 0;
	mX = 300;
	mState = true;
}

int CPEOPLE::GetmX()
{
	return mX;
}

int CPEOPLE::GetmY()
{
	return mY;
}

void CPEOPLE::Up(int y)
{
	mY += y;

}

void CPEOPLE::Left(int x)
{
	mX -= x;
}

void CPEOPLE::Right(int x)
{
	mX += x;
}

void CPEOPLE::Down(int y)
{
	mY -= y;
}

void CPEOPLE::draw(Render_State& screen)
{
	screen.drawImage(image, mX, mY, 4, DEFAULT_BACKGROUND_COLOR);
	screen.drawReac2P(mX + PEOPLE_LEFT, mX + PEOPLE_RIGHT, mY + PEOPLE_BOTTOM, mY + PEOPLE_TOP, 1348109);
}
