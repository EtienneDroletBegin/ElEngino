#include "gameScene.h"
#include <iostream>

void engino::gameScene::Load()
{
	std::cout << "game loaded";
	Engine::Get()->wrld().Create("player");
}

void engino::gameScene::Draw()
{

}

void engino::gameScene::Update()
{
}
