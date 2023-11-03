//#include "CGAME.h"

#pragma once
#pragma comment(lib, "winmm.lib")
#include "ConsoleHandle.h"

using namespace std;
class CANIMAL
{
private:
    int mX, mY;
    
public:
    
    virtual void tell();
   
    //virtual void Move(int, int) = 0;
};

