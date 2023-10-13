#include "WorldService.h"
#include "SDL_ttf.h"

//Entity* engino::WorldService::Find(const std::string& name)
//{
//	if (m_entityMap.count(name) > 0)
//	{
//		return m_entityMap[name];
//	}
//}

void engino::WorldService::Add()
{
	Entity* added = new Entity("allo");

	Entities.emplace_back(added);
	m_entityMap.emplace(added->getName(), added);
}

void engino::WorldService::Remove(Entity* entity)
{
	for (auto it = Entities.begin(); it != Entities.end(); ++it)
	{
		if (*it == entity) {
			Entities.erase(it);
			break;
		}
	}

	m_entityMap.erase(entity->getName());
}

void engino::WorldService::Start()
{
	Add();

	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->start();
	}
}

void engino::WorldService::Update(float dt)
{
	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->update(dt);
	}
}

void engino::WorldService::Draw()
{

	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->draw();
	}
}
