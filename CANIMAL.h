#pragma once
class CANIMAL
{
private:
    int mX, mY;
    
public:
    
    virtual void tell();
    virtual void Move(int, int) = 0;
};

