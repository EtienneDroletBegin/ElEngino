#pragma once
#include "IWorld.h"
#include "Entity.h"
#include "IScenes.h"
#include "Colliders.h"
#include <map>
#include <string>


namespace engino {

	class WorldService final : public IWorld
	{
	public:
		WorldService() = default;
		~WorldService() = default;

		virtual void Load(std::string scene) override;
		virtual void Register(std::string name, IScenes* scene) override;
		std::map<std::string, IScenes*> *m_scenes = new std::map<std::string, IScenes*>();
		void Unload();

		std::string getName(void) {};
		Entity* Find(std::string name);
		void Add(Entity* added) override;
		virtual Entity* Create(std::string name, float x, float y) override;
		virtual void Remove(Entity* entity)override;
		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void AddCollider(Colliders* col) override;
		virtual std::vector<Colliders*> GetColliders()override { return *m_colliders; }
		virtual Entity* GetEntity(std::string name) override {
			if (m_entityMap->at(name) != nullptr) {
				return m_entityMap->at(name);
			}
			else
			{
				return nullptr;
			};
		}
		void virtual Draw() override;
		void virtual Exit() override;
	protected:




	private:
		void CleanEntities();
		IScenes* m_CurrentScene = nullptr;
		std::vector<Entity*> *m_entitiesInWorld = new std::vector<Entity*>();
		std::vector<Colliders*> *m_colliders = new std::vector<Colliders*>();
		std::map<std::string, Entity*> *m_entityMap = new std::map<std::string, Entity*>();
		std::vector<Entity*> *m_EntityToRemove = new std::vector<Entity*>();
		std::vector<Entity*> *m_EntityToStart = new std::vector<Entity*>();

	};

}