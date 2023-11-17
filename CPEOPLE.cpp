#include "CPEOPLE.h"

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
	mX -= x;
}

void CPEOPLE::Down(int y)
{
	mY -= y;
}
