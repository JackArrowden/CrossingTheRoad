#include "CANIMAL.h"

void CANIMAL::tell()
{
	PlaySound(TEXT("birds.wav"), NULL, SND_FILENAME | SND_ASYNC);
}