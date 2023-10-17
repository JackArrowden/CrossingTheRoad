#include "CMOUSE.h"

void CMOUSE::tell()
{
    if (PlaySound(TEXT("Sound\\MOUSE.wav"), NULL, SND_FILENAME | SND_LOOP)) {
        // Sound started playing successfully
        // You can add additional code here if needed
    }
    else {
        // Error handling
        DWORD error = GetLastError();
        if (error != MMSYSERR_NOERROR) {
            // Handle the error
            // You can print an error message or perform other actions
            cout << "ERROR\n";
        }
    }
}