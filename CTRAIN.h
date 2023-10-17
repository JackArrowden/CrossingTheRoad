#pragma once
#include "CVEHICLE.h"
#include "CTRAFFIC_LIGHT.h"
class CTRAIN : public CVEHICLE
{
public:
	void tell();
	//void Move(int, int);
	//bool IsGreen(CTRAFFIC_LIGHT); // đèn tín hiệu đã cho phép tàu được chạy chưa
};

