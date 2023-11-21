#include "CTRAIN.h"

const bitmapHandMake CTRAIN::imageCarrige(CARRIGE_LINK_IMAGE);
const bitmapHandMake CTRAIN::imageLocomotive(LOCOMOTIVE_LINK_IMAGE);


CTRAIN::CTRAIN(int startX, int startY, int direction, int numCarriges)
{
    mX = startX;
    mY = startY;
    direc = direction;
    mode = STOP_MODE;
    this->numCarriges = numCarriges;
    bottomY = TRAIN_BOTTOM;
    topY = TRAIN_TOP;
    leftX = TRAIN_LEFT;
    rightX = LOCOMOTIVE_WIDTH + numCarriges * CARRIGE_WIDTH;
}

void CTRAIN::tell()
{
    if (PlaySound(TEXT("Sound\\TRAIN.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
    {
        // Sound started playing successfully
        // You can add additional code here if needed
    }
    else {
        // Error handling
        DWORD error = GetLastError();
        if (error != MMSYSERR_NOERROR) {
            cout << "ERROR\n";
        }
    }

}

void CTRAIN::Move(int deltaX)
{
    mX += deltaX * direc * mode;
}

void CTRAIN::draw(Render_State& screen)
{
    if (direc < 0)
    {
        screen.drawImage(CTRAIN::imageLocomotive, mX, mY, 1, DEFAULT_BACKGROUND_COLOR);
        for (int i = 0; i < numCarriges; i++)
            screen.drawImage(CTRAIN::imageCarrige, mX + LOCOMOTIVE_WIDTH + i * CARRIGE_WIDTH, mY, DEFAULT_BACKGROUND_COLOR);
    }
    else
    {
        screen.drawReverseImage(CTRAIN::imageLocomotive, mX - LOCOMOTIVE_WIDTH, mY, 1, DEFAULT_BACKGROUND_COLOR);
        for (int i = 0; i < numCarriges; i++)
            screen.drawReverseImage(CTRAIN::imageCarrige, mX - LOCOMOTIVE_WIDTH - (i + 1) * CARRIGE_WIDTH, mY, 1, DEFAULT_BACKGROUND_COLOR);
    }
}
