#pragma once
#include "gameScene.h"
#include "PlayerController.h"
#include "Spawner.h"
#include "BoxCollider.h"
#include "Atlas.h"
#include "Tilemap.h"
#include "Fireball.h"
#include "Runner.h"
#include "GameManager.h"
#include "Text.h"
#include "Bottle.h"
#include <iostream>

void engino::gameScene::Load()
{
	Engine::Get()->Aduio()->LoadSound("assets/BGM.wav");
	Engine::Get()->Aduio()->LoadSound("assets/place.wav");
	Engine::Get()->Aduio()->LoadSound("assets/break.wav");
	Engine::Get()->Aduio()->LoadSound("assets/blockNotPlaced.wav");
	Engine::Get()->Aduio()->LoadSound("assets/powerup.wav");
	Engine::Get()->Aduio()->LoadSound("assets/shoot.wav");

	Entity* manager = Engine::Get()->wrld().Create("spnwr", 0, 0);
	manager->AddComponent<GameManager>();
	Spawner* spnr = manager->GetComponent<GameManager>()->spwnr();

	Entity* bottle1 = Engine::Get()->wrld().Create("bottle1", 7 * 48, 5 * 48);
	spnr->AddPrototype("bottle", bottle1->AddComponent<Bottle>());

	spnr->Spawn("bottle", 6 * 48, 13 * 48);

	Entity* map = Engine::Get()->wrld().Create("map", 0, 0);
	map->AddComponent<Tilemap>()->Load("assets/maps/tileset.png", 240, 256, 16, 16);

	map->GetComponent<Tilemap>()->ReadCSV("assets/maps/map1_Door.csv", "Door");
	//map->GetComponent<Tilemap>()->ReadCSV("assets/maps/map1_BG.csv", "bg");

	Entity* uitexts = Engine::Get()->wrld().Create("UI", 0, 50);
	uitexts->AddComponent<UI>()->Init("assets/Roboto-Regular.ttf", "00000", 1);
	Entity* uitexts4 = Engine::Get()->wrld().Create("UI4", 0, 0);
	uitexts4->AddComponent<Text>()->Init("assets/Roboto-Regular.ttf", "Life", 1);

	Entity* uitexts2 = Engine::Get()->wrld().Create("UI2", 300, 50);
	uitexts2->AddComponent<UI>()->Init("assets/Roboto-Regular.ttf", "0", 1);
	Entity* uitexts3 = Engine::Get()->wrld().Create("UI3", 300, 0);
	uitexts3->AddComponent<Text>()->Init("assets/Roboto-Regular.ttf", "Fireballs", 1);


	Entity* _e = Engine::Get()->wrld().Create("player", 200, 200);
	_e->AddComponent<PlayerController>();

	Entity* fire = Engine::Get()->wrld().Create("fireball", -100, -100);
	fire->AddComponent<Fireball>();
	spnr->AddPrototype("fireballPrototype", fire->GetComponent<Fireball>());

	Runner* runProto = Engine::Get()->wrld().Create("runPrototype", 500, 500)->AddComponent<Runner>();
	runProto->Init(50);

	spnr->AddPrototype("RunnerPrototype", runProto);
	spnr->Spawn("RunnerPrototype",500,600);
	spnr->Spawn("RunnerPrototype",430, 450);
	spnr->Spawn("RunnerPrototype",260, 450);
	spnr->Spawn("RunnerPrototype", 100, 550);


	Entity* key = Engine::Get()->wrld().Create("key", (10*16)*3, (11*16)*3);
	key->AddComponent<SpriteRenderer>()->Init("assets/key.png",40,40);
	key->AddComponent<BoxCollider>()->Init(40,40);


	map->GetComponent<Tilemap>()->ReadCSV("assets/maps/map1_breakable.csv", "breakables");
	map->GetComponent<Tilemap>()->ReadCSV("assets/maps/map1_map.csv", "map");

}
void engino::gameScene::Update(float dt)
{
	
}
