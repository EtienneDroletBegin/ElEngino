#include "Animation.h"
#include "BoxCollider.h"
#include "IClonable.h"


namespace engino {
	/// <summary>
	/// A bottle that gives the player an extra fireball
	/// </summary>
	class Bottle : public Component, public IClonable, public IUpdatable
	{
	public:
		Bottle(Entity* parent) :Component(parent) {
			parent->AddComponent<SpriteRenderer>()->Init("assets/bottle.png", 40, 40);
			parent->AddComponent<BoxCollider>()->Init(21,28);
		}
		void Update(float dt) override;
		virtual IClonable* Clone(float x, float y, int index) override;


	private:
		float m_speed = 200;
		int m_dir;
	};

}