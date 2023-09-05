#pragma once

#include<string>
namespace engino {
	class Engine final {
	public:
		bool Init(const char* name, int w, int h);
		void Start();

	private:
		void ProccessInput(void);
		void Update(float dt);
		void Draw();
		void Shutdown();

		bool m_isRunning = false;
		bool m_isInit = false;
	};
}