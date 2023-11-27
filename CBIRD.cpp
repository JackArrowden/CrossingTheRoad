#include "CBIRD.h"

const bitmapHandMake CBIRD::image(BIRD_LINK_IMAGE);

CBIRD::CBIRD(int startX, int startY, int direction)
{
    this->mX = startX;
    this->mY = startY;
    this->direc = direction;
    bottomY = BIRD_BOTTOM;
    topY = BIRD_TOP;
}

CBIRD::CBIRD()
{
    this->mX = 0;
    this->mY = 0;
    this->direc = 1;
    bottomY = BIRD_BOTTOM;
    topY = BIRD_TOP;
}

void CBIRD::tell()
{
	//PlaySound(TEXT("Sound/birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //const char* soundFilePath = "Sound\\birds.wav";

    // Use PlaySound to play the sound file
    //if (PlaySound(TEXT("Sound\\BIRD.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
    //{
    //    // Sound started playing successfully
    //    // You can add additional code here if needed
    //}
    //else {
    //    // Error handling
    //    DWORD error = GetLastError();
    //    if (error != MMSYSERR_NOERROR) {
    //        // Handle the error
    //        // You can print an error message or perform other actions
    //    }
    //}
    mciSendStringA("open Sound/BIRD.wav type waveaudio alias Bird", NULL, 0, 0);
    // Play the audio
    mciSendStringA("play Bird", NULL, 0, NULL);
    // mciSendStringA("close Bird", NULL, 0, NULL);
}

void CBIRD::Move(int deltaX)
{
    mX += direc * deltaX;
}

void CBIRD::draw(Render_State& screen)
{
    screen.drawReac2P(getLeftX(), getRightX(), mY + bottomY, mY + topY, 1348109);
    if (direc < 0) screen.drawImage(image, mX, mY, BIRD_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawReverseImage(image, mX - image.width / BIRD_PER, mY, BIRD_PER, DEFAULT_BACKGROUND_COLOR);
}


int CBIRD::getRightX() const 
{
    if (direc < 0) return mX + BIRD_RIGHT;
    return mX - BIRD_LEFT;
}

int CBIRD::getLeftX() const
{
    if (direc < 0) return mX + BIRD_LEFT;
    return mX - BIRD_RIGHT;
}