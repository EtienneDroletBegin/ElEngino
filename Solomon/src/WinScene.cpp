#include "WinScene.h"
#include "Text.h"

void engino::WinScene::Load()
{
	Entity* _e = Engine::Get()->wrld().Create("UITitle", 100, 50);
	_e->AddComponent<Text>();
	_e->GetComponent<Text>()->Init("assets/Roboto-Regular.ttf", "You Win", 2);

	Entity* _e2 = Engine::Get()->wrld().Create("UIText1", 50, 500);
	_e2->AddComponent<Text>();
	_e2->GetComponent<Text>()->Init("assets/Roboto-Regular.ttf", "Press [Enter] to return to title screen", 1);
}

void engino::WinScene::Update(float dt)
{
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::Key_Enter)) {
		engino::Engine::Get()->wrld().Load("UI");
	}
}
