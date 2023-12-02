#pragma once
#include "Engine.h"
#include "IScenes.h"


namespace engino {
	class WinScene : public IScenes
	{
	public:
		virtual void Load() override;
		virtual void Update(float dt) override;
	};

}