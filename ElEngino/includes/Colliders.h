#pragma once

#include "Engine.h"
#include "Component.h"

namespace engino {
	class Colliders : public Component, public IUpdatable
	{
	private:

	public:
		//void Update(float dt) override;
		Colliders(Entity* parent):Component(parent) {};
		~Colliders() = default;
		virtual float getH() = 0;
		virtual float getW() = 0;


		//void AddOnEnter(std::function);

		//std::vector<std::function> colliderEvents;

	};
}