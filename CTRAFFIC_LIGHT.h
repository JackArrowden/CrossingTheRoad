#pragma once
#include "CGAME.h"

#define TRAFFICLIGHT_LINK_IMAGE "image\\gameWindow\\TRAFFIC_LIGHT.bmp"
class CTRAFFIC_LIGHT
{
private:
	bool isGreen;
public:
	void SetTime(); // đếm ngược thời gian phát tín hiệu cho tàu chạy
	bool GetIsGreen(); // trả về kết quả là thời điểm hiện tại tàu được chạy qua chưa
};

