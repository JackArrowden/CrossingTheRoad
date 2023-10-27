#include "CTRAIN.h"

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