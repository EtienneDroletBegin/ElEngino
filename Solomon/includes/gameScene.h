#pragma once
#include "Engine.h"
#include "IScenes.h"


namespace engino {
	class gameScene : public IScenes
	{
	public:
		virtual void Load() override;
		virtual void Update(float dt) override;
	};

}