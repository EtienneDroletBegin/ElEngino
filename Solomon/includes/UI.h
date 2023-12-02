#include "Observer.h"
#include "Text.h"
#include "Entity.h"
#include "Action.h"

namespace engino {
	/// <summary>
	/// like the basic text component but made to be an observer
	/// </summary>
	class UI : public Observer<int> , public Text 
	{
	public:
		UI(Entity* parent) :Text(parent) {};
		virtual ~UI() = default;

		virtual void OnNotify(const int& value) override
		{
			SetText(to_string(value));
		}
	};

}
