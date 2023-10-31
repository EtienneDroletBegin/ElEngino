#pragma once

#include "IWorld.h";
#include "Entity.h";
#include "IScenes.h";

#include <vector>
#include <map>
#include <string>


namespace engino {

	class WorldService final : public IWorld
	{
	public:
		WorldService();
		~WorldService();

		virtual void Load(const char* scene) override;
		virtual void Register(const char* name, IScenes* scene) override;
		std::map<std::string, IScenes*> m_scenes; 
		void Unload();



		const char* getName(void) {};
		Entity* Find(const std::string& name);
		void Add(Entity* added) override;
		virtual Entity* Create(const char* name) override;
		virtual void Remove(Entity* entity)override;

		virtual void Start() override;
		virtual void Update(float dt) override;

		void virtual Draw() override;
	protected:




	private:
		IScenes* m_CurrentScene = nullptr;
		std::vector<Entity*> m_entitiesInWorld;
		std::map<std::string, Entity*> m_entityMap;

	};

}