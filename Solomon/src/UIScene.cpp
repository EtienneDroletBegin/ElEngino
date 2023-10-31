#include "UIScene.h"
#include <iostream>

void engino::UIScene::Load()
{
	std::cout << "UI";
}

void engino::UIScene::Draw()
{
}

void engino::UIScene::Update()
{
	if (engino::Engine::Get()->input().IsKeyDown(EKeycodes::Key_Space)) {
		engino::Engine::Get()->wrld().Load("Game");
	}
}

