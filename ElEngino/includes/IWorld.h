#pragma once

namespace engino {
	class Entity;
	class IScenes;
	class IWorld
	{
	private:

	public:

		virtual Entity* Create(const char* name) = 0;
		void virtual Add(Entity* added) = 0;
		virtual void Remove(Entity* entity) = 0;
		void virtual Start() = 0;
		void virtual Update(float dt) = 0;
		void virtual Draw() = 0;
		void virtual Load(const char* scene) = 0;
		virtual void Register(const char* name, IScenes* scene) = 0;

	};

}