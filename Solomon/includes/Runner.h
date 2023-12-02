#pragma once
#include "Monster.h"



namespace engino {
	/// <summary>
	/// the basic enemy, he runs
	/// </summary>
	class Runner : public Monster
	{
	public:
		Runner(Entity* parent) :Monster(parent) {
			parent->AddComponent<Animation>()->Init("assets/mnstrSprite.png",1,1);
			parent->GetComponent<Animation>()->AddClip("walk", 0, 4, 0.1f);
			parent->GetComponent<Animation>()->InitAnim(12, 15,3);
			parent->GetComponent<Animation>()->Play("walk", true);
			parent->GetComponent<Animation>()->SetCol(1);
			parent->AddComponent<BoxCollider>()->Init(40, 40);
		}
		virtual ~Runner() = default;
		virtual void Init(float speed) override;
		virtual Runner* Clone(float x, float y, int index) override;

		virtual void Update(float dt) override;

	protected:

	};

}