#include "UIScene.h"
#include <iostream>
#include "Engine.h"
#include "Text.h"

void engino::UIScene::Load()
{
	Entity* _e = Engine::Get()->wrld().Create("UITitle", 100, 50);
	_e->AddComponent<Text>();
	_e->GetComponent<Text>()->Init("assets/Roboto-Regular.ttf","Solomon's Key",1);

	Entity* _e2 = Engine::Get()->wrld().Create("UIText1", 100, 500);
	_e2->AddComponent<Text>();
	_e2->GetComponent<Text>()->Init("assets/Roboto-Regular.ttf", "Press [space] to play",0.5);
}


void engino::UIScene::Update()
{
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::Key_Space)) {
		engino::Engine::Get()->wrld().Load("Game");
	}
}

