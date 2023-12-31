#include "Engine.h"
#include "Time.h"
#include "Windows.h"
#include <iostream>
#include "Color.h"
#include"SDLInputs.h"
#include"SDLGraphics.h"
#include"mixer.h"
#include "WorldService.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"

static SDL_Renderer* renderer = NULL;
static SDL_Window* Window = NULL;
#define MS_PER_FRAME 16.666f


engino::Engine::Engine() :m_graphics(nullptr),
m_input(nullptr),
m_log(nullptr),
m_mixer(nullptr),
m_world(nullptr)
{

}


/// <summary>
/// Initiate the essential Variables and important functions
/// </summary>
/// <param name="name">the windows name</param>
/// <param name="w">the width of the window opened</param>
/// <param name="h">the height of the open window</param>
/// <returns></returns>
bool engino::Engine::Init(std::string name, int w, int h) {
	m_log = new ConsoleLogger();
	//m_log = new FileLogger();

	m_graphics = new SDLGraphics();
	m_input = new SdlInput();
	m_world = new WorldService();
	m_mixer = new AudioMixer();
	if (!m_graphics->Initialize(name, w, h)) {
		m_log->Log(m_log->GetError());
	}
	m_isInit = true;
	return true;
}

/// <summary>
/// function executed when the game is initiated
/// </summary>
void engino::Engine::Start() {
	if (!m_isInit) {
		if (!Init("unknown", 800,600))
		{
			return;
		}
	}
	m_isRunning = true;

	clock_t _end = clock();
	m_world->Start();
	//m_mixer->PlaySFX(m_mixer->LoadSound("assets/loaded.wav"), 0);
	
	while (m_isRunning && !m_input->_quit()) {
		const clock_t _start = clock();
		float dt = (_start - _end) * 0.001f;
		ProccessInput();
		Update(dt);
		Draw();


		float elapsedMS = _end -(_start + MS_PER_FRAME);
		if (elapsedMS > 0)
		{
			Sleep(static_cast<DWORD>(elapsedMS * 0.001));

		}
		_end = _start;
	}
	Shutdown();

}

//static const Uint8* _keystates = NULL;
void engino::Engine::ProccessInput(void)
{
	m_input->Update();
}

/// <summary>
/// Function executed every frame
/// </summary>
/// <param name="dt">the time elapsed between the current frame and the last</param>
void engino::Engine::Update(float dt)
{
#if _DEBUG
	if (m_input->IsKeyDown(EKeycodes::Key_Esc)) {
		Stop();
	}
#endif

	m_world->Update(dt);

}

/// <summary>
/// Renders the elemnts on the screen by clearing the last render and creating a new one every frame
/// </summary>
void engino::Engine::Draw()
{
	m_graphics->Clear();

	//m_graphics->DrawFont(0, 0, 200, 200, m_graphics->LoadFont("assets/Roboto-Regular.ttf", 160), "TEST", Color::RED);
	m_world->Draw();

	m_graphics->Present();
}

/// <summary>
/// shuts down the program.
/// </summary>
void engino::Engine::Shutdown()
{
	if (m_world != nullptr)
	{
		m_world->Exit();
		delete m_world;
	}	
	if (m_input != nullptr)
	{
		delete m_input;
	}
	if (m_mixer != nullptr)
	{
		m_mixer->Destroy();
		delete m_mixer;
	}
	if (m_graphics != nullptr)
	{
		m_graphics->Exit();
		delete m_graphics;
	}
	if (m_log != nullptr)
	{
		m_log->Shutdown();
		delete m_log;
	}

	//SDL_Quit();
}
