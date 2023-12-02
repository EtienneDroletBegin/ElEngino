#pragma once

#include "iInput.h"
#include "ILogger.h"
#include "iGraphics.h"
#include "IAudio.h"
#include "IWorld.h"
#include "Entity.h"

namespace engino {
	class Engine final {

	protected:

	public:

		/// <summary>
		/// returns the engine instance
		/// </summary>
		/// <returns>Engine Instance</returns>
		static Engine* Get() {
			static Engine* m_instance;
			if (m_instance == nullptr) {
				m_instance = new Engine();
			}

			return m_instance;
		}
		/// <summary>
		/// initiates the necessary variables
		/// </summary>
		/// <param name="name">the name of the window</param>
		/// <param name="w">the width of the window</param>
		/// <param name="h">the height of the window</param>
		/// <returns>true if the engine is initialized</returns>
		bool Init(std::string name, int w, int h);
		void Start();
		/// <summary>
		/// returns m_input
		/// </summary>
		/// <returns>an SDL Input</returns>
		IInput& input() { return *m_input; }
		/// <summary>
		/// returns m_graphics
		/// </summary>
		/// <returns>an SDL_Graphics</returns>
		IGraphics& gfx() { return *m_graphics; }
		/// <summary>
		/// returns a world service
		/// </summary>
		/// <returns>the World Service</returns>
		IWorld& wrld() { return *m_world; }
		/// <summary>
		/// returns if the engine is running
		/// </summary>
		/// <returns>true if the engine is running</returns>
		bool _isRunning() { return m_isRunning; }
		/// <summary>
		/// turns m_isRunning to false
		/// </summary>
		void Stop() { m_isRunning = false; }

		/// <summary>
		/// returns the Audio mixer for use anywhere
		/// </summary>
		/// <returns>the audio mixer</returns>
		IAudio* Aduio() { return m_mixer; }
	private:
		Engine();

		/// <summary>
		/// interracts with SDL input to return the inputs
		/// </summary>
		/// <param name=""></param>
		void ProccessInput(void);
		/// <summary>
		/// called every frame
		/// </summary>
		/// <param name="dt">the time between each frames</param>
		void Update(float dt);
		void Draw();
		/// <summary>
		/// deletes the pointers to avoid memory leaks
		/// </summary>
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