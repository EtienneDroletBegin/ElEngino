#include "gameScene.h"
#include "PlayerController.h"
#include "SpriteRenderer.h"
#include <iostream>

void engino::gameScene::Load()
{
	std::cout << "game loaded";
	Entity* _e = Engine::Get()->wrld().Create("player");
	_e->AddComponent<PlayerController>();
	_e->AddComponent<SpriteRenderer>();
}

void engino::gameScene::Draw()
{

}

void engino::gameScene::Update()
{
}
