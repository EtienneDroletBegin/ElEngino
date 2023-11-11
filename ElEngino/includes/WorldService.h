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
		~WorldService();

		virtual void Load(const char* scene) override;
		virtual void Register(const char* name, IScenes* scene) override;
		std::map<std::string, IScenes*> m_scenes; 
		void Unload();

		const char* getName(void) {};
		Entity* Find(const char* name);
		void Add(Entity* added) override;
		virtual Entity* Create(const char* name, float x, float y) override;
		virtual void Remove(Entity* entity)override;

		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void AddCollider(Colliders* col) override;
		virtual std::vector<Colliders*> GetColliders()override { return m_colliders; }
		virtual Entity* GetEntity(const char* name) override {
			if (m_entityMap[name] != nullptr) {
				return m_entityMap[name];
			}
			else
			{
				return nullptr;
			};
		}
		void virtual Draw() override;
	protected:




	private:
		IScenes* m_CurrentScene = nullptr;
		std::vector<Entity*> m_entitiesInWorld;
		std::vector<Colliders*> m_colliders;
		std::map<std::string, Entity*> m_entityMap;

	};

}