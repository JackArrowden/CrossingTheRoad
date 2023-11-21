#include "CBIRD.h"

const bitmapHandMake CBIRD::image(BIRD_LINK_IMAGE);

CBIRD::CBIRD(int startX, int startY, int direction)
{
    this->mX = startX;
    this->mY = startY;
    this->direc = direction;
    bottomY = BIRD_BOTTOM;
    topY = BIRD_TOP;
    rightX = BIRD_RIGHT;
    leftX = BIRD_LEFT;
}

void CBIRD::tell()
{
	//PlaySound(TEXT("Sound/birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //const char* soundFilePath = "Sound\\birds.wav";

    // Use PlaySound to play the sound file
    if (PlaySound(TEXT("Sound\\BIRD.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
    {
        // Sound started playing successfully
        // You can add additional code here if needed
    }
    else {
        // Error handling
        DWORD error = GetLastError();
        if (error != MMSYSERR_NOERROR) {
            // Handle the error
            // You can print an error message or perform other actions
        }
    }

}

void CBIRD::Move(int deltaX)
{
    mX += direc * deltaX;
}

void CBIRD::draw(Render_State& screen)
{
    if (direc < 0) screen.drawImage(image, mX, mY, BIRD_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX - image.width / BIRD_PER, mY, BIRD_PER, DEFAULT_BACKGROUND_COLOR);
}
