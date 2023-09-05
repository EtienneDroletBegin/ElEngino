#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"


void initGamePlay() {
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	engino::Engine theEngine;
	if (theEngine.Init("testgame", 800, 600))
	{
		initGamePlay();
		theEngine.Start();
	}
	return 0;
}

