#include "CTRUCK.h"

const bitmapHandMake CTRUCK::image(TRUCK_LINK_IMAGE);

CTRUCK::CTRUCK(int startX, int startY, int direction)
{
    mX = startX;
    mY = startY;
    direc = direction;
    mode = MOVE_MODE;
    topY = TRUCK_TOP;
    bottomY = TRUCK_BOTTOM;
}

CTRUCK::CTRUCK()
{
    mX = 0;
    mY = 0;
    direc = 1;
    mode = MOVE_MODE;
    topY = TRUCK_TOP;
    bottomY = TRUCK_BOTTOM;
}

void CTRUCK::tell()
{
    //PlaySound(TEXT("Sound/birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //const char* soundFilePath = "Sound\\birds.wav";

    // Use PlaySound to play the sound file
    //if (PlaySound(TEXT("Sound\\TRUCK.wav"), NULL, SND_FILENAME | SND_LOOP)) //| SND_ASYNC)) 
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
    mciSendStringA("open Sound/TRUCK.wav type waveaudio alias Truck", NULL, 0, 0);
    // Play the audio
    mciSendStringA("play Truck", NULL, 0, NULL);
    // mciSendStringA("close Truck", NULL, 0, NULL);
}

void CTRUCK::Move(int deltaX)
{
    mX += direc * deltaX;
}

void CTRUCK::draw(Render_State& screen)
{
    screen.drawReac2P(getLeftX(), getRightX(), mY + bottomY, mY + topY, 1348109);
    if (direc < 0) screen.drawReverseImage(image, mX , mY, TRUCK_PER, DEFAULT_BACKGROUND_COLOR);
    else screen.drawImage(image, mX - image.width / TRUCK_PER, mY, TRUCK_PER, DEFAULT_BACKGROUND_COLOR);
}

int CTRUCK::getRightX() const
{
    if (direc < 0) return mX + TRUCK_RIGHT;
    return mX - TRUCK_LEFT;
}

int CTRUCK::getLeftX() const
{
    if (direc < 0) return mX + TRUCK_LEFT;
    return mX - TRUCK_RIGHT;
}