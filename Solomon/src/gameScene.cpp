#pragma once
#include "gameScene.h"
#include "PlayerController.h"
#include "BoxCollider.h"
#include "Atlas.h"
#include "Animation.h"
#include "Text.h"
#include <iostream>

void engino::gameScene::Load()
{

	Entity* _e = Engine::Get()->wrld().Create("player", 0, 0);
	Entity* _e2 = Engine::Get()->wrld().Create("block", 200, 200);
	_e->AddComponent<PlayerController>();
	_e->AddComponent<Animation>()->Init("assets/walkLeft.png");
	_e->GetComponent<Animation>()->AddClip("walk", 1, 4, 0.1);
	_e->GetComponent<Animation>()->AddClip("idle", 0, 1, 1);
	

	_e->AddComponent<BoxColliders>();

	_e2->AddComponent<SpriteRenderer>()->Init("assets/berdman.png");
	_e2->AddComponent<BoxColliders>();


	Entity* _e3 = Engine::Get()->wrld().Create("Info", 100, 50);
	_e3->AddComponent<Text>();
	_e3->GetComponent<Text>()->Init("assets/Roboto-Regular.ttf", "Press [Space] to drop fireballs", 0.5);

	Entity* _e4 = Engine::Get()->wrld().Create("Col", 100, 500);
	_e4->AddComponent<Text>()->Init("assets/Roboto-Regular.ttf", "PRESS T TO WALK AND Y TO STOP", 0.4);

	Entity* _e5 = Engine::Get()->wrld().Create("detroyable", 100, 500);
	_e4->AddComponent<SpriteRenderer>()->Init("assets/berdman.png");
}
void engino::gameScene::Update()
{
	
}
