#pragma once
#include "Engine.h"
#include "IScenes.h"


namespace engino {
	class UIScene : public IScenes
	{
	public:
		virtual void Load() override;
		virtual void Draw() override;
		virtual void Update() override;
	};

}

