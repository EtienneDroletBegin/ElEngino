#pragma once

namespace engino {
	class Entity;
	class IWorld
	{
	private:

	public:

		void virtual Add() = 0;
		virtual void Remove(Entity* entity) = 0;
		void virtual Start() = 0;
		void virtual Update(float dt) = 0;
		void virtual Draw() = 0;

	};

}