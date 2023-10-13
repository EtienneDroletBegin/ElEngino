#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"
//#include <vld.h>

using namespace engino;
void initGamePlay() {
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	Engine* theEngine = Engine::Get();
	if (theEngine->Init("As i walk through the valley of the shadow of death.", 800, 600))
	{
		initGamePlay();
		theEngine->Start();
	}
	return 0;
}

