#pragma once

#include "iInput.h"
#include "ILogger.h"
#include "iGraphics.h"
#include "IAudio.h"
#include "IWorld.h"
#include<string>

namespace engino {
	class Engine final {

	protected:

	public:


		static Engine* Get() {
			static Engine* m_instance;
			if (m_instance == nullptr) {
				m_instance = new Engine();
			}

			return m_instance;
		}
		bool Init(const char* name, int w, int h);
		void Start();
		IInput& input() { return *m_input; }
		IGraphics& gfx() { return *m_graphics; }
		IWorld& wrld() { return *m_world; }
		bool _isRunning() { return m_isRunning; }
		void Stop() { m_isRunning = false; }
	private:
		Engine();

		void ProccessInput(void);
		void Update(float dt);
		void Draw();
		void Shutdown();

		ILogger* m_log;
		IInput* m_input;
		IGraphics* m_graphics;
		IAudio* m_mixer;
		IWorld* m_world;
		bool m_isRunning = false;
		bool m_isInit = false;
	};
}