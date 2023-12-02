#include "UIScene.h"
#include <iostream>
#include "Engine.h"
#include "SpriteRenderer.h"

void engino::UIScene::Load()
{
	ticking = true;
	Entity* _e = Engine::Get()->wrld().Create("UITitle", 0, 0);
	_e->AddComponent<SpriteRenderer>()->Init("assets/title.png", 720,551);

}

void engino::UIScene::Update(float dt)
{
	if (canStart)
	{
		if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::Key_Space)) {
			engino::Engine::Get()->wrld().Load("Game");
			startTime = 0;
			ticking = false;
		}
	}

	startTime += dt;
	if (startTime > 1) {
		canStart = true;
	}

}