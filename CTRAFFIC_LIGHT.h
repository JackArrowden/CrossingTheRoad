#pragma once
#include "ConsoleHandle.h"
#include "BitMap.h"


#define TRAFFICLIGHT_LINK_IMAGE "image\\gameWindow\\TRAFFIC_LIGHT.bmp"
class CTRAFFIC_LIGHT
{
private:
	bool isGreen;
public:
	void SetTime(); // Countdown for vehicle to run
	bool GetIsGreen(); // Return if this vehicle is ready for run
};