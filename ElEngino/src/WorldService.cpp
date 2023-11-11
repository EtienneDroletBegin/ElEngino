#include "WorldService.h"
#include "SDL_ttf.h"
#include "IScenes.h"
#include "Engine.h"
#include <iostream>


engino::Entity* engino::WorldService::Find(const char* name)
{
	if (m_entityMap.count(name) > 0)
	{
		return m_entityMap[name];
	}
	else {
		return nullptr;
	}
}


engino::WorldService::~WorldService()
{
	Unload();
	delete m_CurrentScene;
	m_colliders.clear();
}

void engino::WorldService::Load(const char* scene)
{
	if (m_scenes.count(scene) > 0) {
		Unload();
		m_CurrentScene = m_scenes[scene];
		m_CurrentScene->Load();
		
	}
}

void engino::WorldService::Register(const char* name, IScenes* scene)
{
	if (m_scenes.count(name) == 0) {
		m_scenes[name] = scene;
	}

}

void engino::WorldService::Unload()
{
	if (m_CurrentScene != nullptr) {
		for (auto entity : m_entitiesInWorld) {
			entity->Destroy();
			delete entity;
		}
		m_entityMap.clear();
		m_entitiesInWorld.clear();
	}
}



void engino::WorldService::Add(Entity* added)
{
	m_entitiesInWorld.emplace_back(added);
	m_entityMap.emplace(added->getName(), added);
}

engino::Entity* engino::WorldService::Create(const char* name, float x = 0, float y = 0)
{
	Entity* _e = new Entity(name, x, y);
	Add(_e);
	_e->start();
	return _e;
}


void engino::WorldService::Remove(Entity* entity)
{
	for (auto it = m_entitiesInWorld.begin(); it != m_entitiesInWorld.end(); ++it)
	{
		if (*it == entity) {
			m_entitiesInWorld.erase(it);
			delete entity;
			break;
		}
	}
	m_entityMap.erase(entity->getName());
}

void engino::WorldService::Start()
{

	for (int i = 0; i < m_entitiesInWorld.size(); i++)
	{
		m_entitiesInWorld[i]->start();
	}
}

void engino::WorldService::Update(float dt)
{
	m_CurrentScene->Update();
	for (int i = 0; i < m_entitiesInWorld.size(); i++)
	{
		m_entitiesInWorld[i]->update(dt);
	}
}

void engino::WorldService::AddCollider(Colliders* col)
{
	m_colliders.push_back(col);
}

void engino::WorldService::Draw()
{

	for (int i = 0; i < m_entitiesInWorld.size(); i++)
	{
		
		m_entitiesInWorld[i]->draw();
	}
}
