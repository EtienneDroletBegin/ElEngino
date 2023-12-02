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
		virtual ~Colliders() = default;
		/// <summary>
		/// returns the height of the collider
		/// </summary>
		/// <returns>the height of the collider</returns>
		virtual float getH() = 0;
		/// <summary>
		/// returns the width of the collider
		/// </summary>
		/// <returns></returns>
		virtual float getW() = 0;
	protected:
		virtual void Init(float _w, float _h) = 0;

	};
}