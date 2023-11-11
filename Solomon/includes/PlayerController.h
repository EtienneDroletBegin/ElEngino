#include "Component.h"
#include "IUpdatable.h"


namespace engino {
	class PlayerController : public Component, public IUpdatable
	{
	public:
		PlayerController(Entity* parent) :Component(parent) {};
		PlayerController() = default;
		~PlayerController() = default;
		virtual void Update(float dt) override;


	private:
		void FireBall();

	};

}

