#pragma once
class CANIMAL
{
private:
    int mX, mY;
    bool isBig;
public:
    bool GetSize();
    virtual void tell();
    virtual void Move(int, int) = 0;
};

