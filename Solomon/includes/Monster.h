#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Tilemap.h"
#include "Animation.h"
#include "BoxCollider.h"
#include "IClonable.h"


namespace engino {
	/// <summary>
	/// mother class of the enemy entities in the game
	/// </summary>
	class Monster : public Component, public IUpdatable, public IClonable
	{
	public:
		Monster(Entity* parent) : Component(parent) {
			m_tiles = Engine::Get()->wrld().GetEntity("map")->GetComponent<Tilemap>();
		};
		virtual ~Monster() = default;
		/// <summary>
		/// sets the speed for the monster
		/// </summary>
		/// <param name="speed">the given speed at creation</param>
		virtual void Init(float speed) = 0;
		virtual void Update(float dt) override;

	protected:
		int m_Health;
		float m_Speed;
		Tilemap* m_tiles;
		float lastX;
		float lastY;
	private:
	};

}