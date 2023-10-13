#pragma once
class CVEHICLE
{
private:
	int mX, mY;
public:
	virtual void Move(int, int) = 0;
	virtual void tell();

};


