#pragma once

#include<string>
#include "iInput.h"
namespace engino {
	class Engine final {
	public:
		bool Init(const char* name, int w, int h);
		void Start();
		IInput& input() { return *m_input; }
		bool _isRunning() { return m_isRunning; }
		void Stop() { m_isRunning = false; }
	private:
		void ProccessInput(void);
		void Update(float dt);
		void Draw();
		void Shutdown();

		IInput* m_input;
		bool m_isRunning = false;
		bool m_isInit = false;
	};
}