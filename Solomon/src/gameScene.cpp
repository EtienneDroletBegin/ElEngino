#include "gameScene.h"
#include "PlayerController.h"
#include <iostream>

void engino::gameScene::Load()
{
	std::cout << "game loaded";
	Entity* _e = Engine::Get()->wrld().Create("player");
	_e->AddComponent<PlayerController>();
}

void engino::gameScene::Draw()
{

}

void engino::gameScene::Update()
{
}
