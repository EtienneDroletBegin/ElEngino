#include "WorldService.h"
#include "SDL_ttf.h"
#include "IScenes.h"


//Entity* engino::WorldService::Find(const std::string& name)
//{
//	if (m_entityMap.count(name) > 0)
//	{
//		return m_entityMap[name];
//	}
//}

engino::WorldService::WorldService()
{
	
}

engino::WorldService::~WorldService()
{
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
		m_entitiesInWorld.clear();
		m_entityMap.clear();
	}
}

void engino::WorldService::Add(Entity* added)
{
	m_entitiesInWorld.emplace_back(added);
	m_entityMap.emplace(added->getName(), added);
}

engino::Entity* engino::WorldService::Create(const char* name)
{
	Entity* _e = new Entity(name);
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

void engino::WorldService::Draw()
{

	for (int i = 0; i < m_entitiesInWorld.size(); i++)
	{
		
		m_entitiesInWorld[i]->draw();
	}
}
