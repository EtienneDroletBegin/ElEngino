#pragma once
#include "Engine.h"
#include "IScenes.h"


namespace engino {
	class UIScene : public IScenes
	{
	public:
		virtual void Load() override;
		virtual void Update(float dt) override;

	private:
		bool canStart=false;
		bool ticking = true;
		float startTime=0;
	};

}

