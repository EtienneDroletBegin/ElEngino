#include "WorldService.h"
#include "SDL_ttf.h"
#include "IScenes.h"
#include "Engine.h"
#include <iostream>
#include "BoxCollider.h"


engino::Entity* engino::WorldService::Find(std::string name)
{
	if (m_entityMap->count(name) > 0)
	{
		return m_entityMap->at(name);
	}
	else {
		return nullptr;
	}
}



void engino::WorldService::Load(std::string scene)
{
	if (m_scenes->count(scene) > 0) {
		Unload();
		m_CurrentScene = m_scenes->at(scene);
		m_CurrentScene->Load();
		
	}
}

void engino::WorldService::Register(std::string name, IScenes* scene)
{
	if (m_scenes->count(name) == 0) {
		m_scenes->emplace(name, scene);
	}

}

void engino::WorldService::Unload()
{
	for (auto entity : *m_entitiesInWorld)
	{
		entity->Destroy();
		delete entity;
	}
	m_entitiesInWorld->clear();

	for (auto entity : *m_EntityToStart)
	{
		entity->Destroy();
		delete entity;
	}
	m_EntityToStart->clear();

	for (auto entity : *m_EntityToRemove)
	{
		entity->Destroy();
		delete entity;
	}
	m_EntityToRemove->clear();

	m_entityMap->clear();
	CleanEntities();
	//for(auto coll : *m_colliders){
	//	BoxCollider* box = (BoxCollider*)coll;
	//	delete box;
	//}
	m_colliders->clear();

}



void engino::WorldService::Add(Entity* added)
{
	m_entitiesInWorld->emplace_back(added);
	m_entityMap->emplace(added->getName(), added);
}

engino::Entity* engino::WorldService::Create(std::string name, float x = 0, float y = 0)
{
	Entity* _e = new Entity(name, x, y);
	Add(_e);
	_e->start();
	return _e;
}


void engino::WorldService::Remove(Entity* _entity)
{
	if (m_entityMap->count(_entity->getName()) > 0)
	{
		for (size_t i = 0; i < m_entitiesInWorld->size(); i++)
		{
			Entity* entity = m_entitiesInWorld->at(i);
			if (entity->getName() == _entity->getName())
			{
				m_EntityToRemove->emplace_back(entity);
				m_entitiesInWorld->erase(m_entitiesInWorld->begin()+i);
				break;
			}
		}
	}
}

void engino::WorldService::Start()
{

	for (int i = 0; i < m_entitiesInWorld->size(); i++)
	{
		m_entitiesInWorld->at(i)->start();
	}
}

void engino::WorldService::Update(float dt)
{
	m_CurrentScene->Update(dt);
	for (int i = 0; i < m_entitiesInWorld->size(); i++)
	{
		m_entitiesInWorld->at(i)->update(dt);
	}
}

void engino::WorldService::AddCollider(Colliders* col)
{
	m_colliders->push_back(col);
}

void engino::WorldService::Draw()
{

	for (int i = 0; i < m_entitiesInWorld->size(); i++)
	{
		
		m_entitiesInWorld->at(i)->draw();
	}
}

void engino::WorldService::Exit()
{
	Unload();

	for (auto scene : *m_scenes)
	{
		delete scene.second;
	}
	m_scenes->clear();
	delete m_scenes;
	delete m_colliders;
	delete m_entitiesInWorld;
	delete m_EntityToRemove;
	delete m_EntityToStart;
	delete m_entityMap;
}

void engino::WorldService::CleanEntities()
{
	if (m_EntityToRemove->size() > 0)
	{
		std::vector<Entity*> _trash = *m_EntityToRemove;
		m_EntityToRemove->clear();

		for (auto entity : _trash)
		{
			m_entityMap->erase(entity->getName());
			entity->Destroy();

			for (auto it = m_entitiesInWorld->begin(); it != m_entitiesInWorld->end(); ++it)
			{
				if (entity == *it)
				{
					m_entitiesInWorld->erase(it);
					delete entity;
					break;
				}
			}
		}

		_trash.clear();
	}
}

