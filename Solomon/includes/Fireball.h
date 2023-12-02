#pragma once
#include "Engine.h"
#include "Animation.h"
#include "BoxCollider.h"
#include "TileMap.h"
#include "IClonable.h"


namespace engino {
	/// <summary>
	/// the player's projectile
	/// </summary>
	class Fireball : public Component, public IUpdatable, public IClonable
	{
	public:
		Fireball(Entity* parent) :Component(parent) {
			parent->AddComponent<Animation>()->Init("assets/fireball.png",1,1);
			parent->GetComponent<Animation>()->InitAnim(20,18,1);
			parent->GetComponent<Animation>()->AddClip("normal", 0, 2, 0.1f);
			parent->GetComponent<Animation>()->Play("normal", true);
			parent->AddComponent<BoxCollider>()->Init(20, 18);
			m_map = Engine::Get()->wrld().GetEntity("map")->GetComponent<Tilemap>();;
		}
		/// <summary>
		/// initiates the fireball's direction
		/// </summary>
		/// <param name="_dir">the given direction based on the player's direction</param>
		void Init(int _dir);
		virtual void Update(float dt) override;
		virtual IClonable* Clone(float x, float y, int index) override;


	private:
		float m_speed = 200;
		Tilemap* m_map;
		int m_dir;

	};

}