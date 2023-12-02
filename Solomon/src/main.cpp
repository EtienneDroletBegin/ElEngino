#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"
#include "gameScene.h"
#include "LoseScene.h"
#include "WinScene.h"
#include "UIScene.h"
#include <vld.h>

using namespace engino;
void initGamePlay() {
	gameScene* temp = new gameScene();
	UIScene* temp2 = new UIScene();
	WinScene* temp3 = new WinScene();
	LoseScene* temp4 = new LoseScene();
	Engine::Get()->wrld().Register("Game", temp);
	Engine::Get()->wrld().Register("UI", temp2);
	Engine::Get()->wrld().Register("Win", temp3);
	Engine::Get()->wrld().Register("Lose", temp4);
	Engine::Get()->wrld().Load("UI");
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	Engine* theEngine = Engine::Get();
	if (theEngine->Init("Solomon's key", 720, 768))
	{
		initGamePlay();
		theEngine->Start();
	}
	delete theEngine;
	return 0;
}

