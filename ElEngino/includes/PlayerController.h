#include "Component.h"
#include "IUpdatable.h"


namespace engino {
	class PlayerController : public Component, public IUpdatable
	{
	public:
		PlayerController() {};
		~PlayerController();
		virtual void Update(float dt) override;


	private:

	};

}

