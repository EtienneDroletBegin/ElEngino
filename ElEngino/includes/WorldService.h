#pragma once

#include "IWorld.h";
#include "Entity.h";

#include <vector>
#include <map>
#include <string>


namespace engino {

	class WorldService final : public IWorld
	{
	public:
		WorldService()
		{
		}

		const char* getName(void) {};



		Entity* Find(const std::string& name);

		void Add() override;



		virtual void Remove(Entity* entity)override;

		virtual void Start() override;
		virtual void Update(float dt) override;

		void virtual Draw() override;
	protected:




	private:
		std::vector<Entity*> Entities;
		std::map<std::string, Entity*> m_entityMap;

	};

}