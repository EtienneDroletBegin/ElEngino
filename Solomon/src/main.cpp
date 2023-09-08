#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"


void initGamePlay() {
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	engino::Engine theEngine;
	if (theEngine.Init(" Fènwa anndan an pral pran sou, pa gen anyen ou ka fè sou li, ou pral tranble epi mwen pral fè wout mwen.", 800, 600))
	{
		initGamePlay();
		theEngine.Start();
	}
	return 0;
}

