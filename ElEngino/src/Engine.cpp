#include "Engine.h"
#include "Time.h"
#include "Windows.h"
#include <SDL.h>
#include <iostream>
#include "SDL_image.h";
#include "Color.h";

#include"SDLInputs.h"
#include"SDLGraphics.h"
#include"mixer.h"
#include "WorldService.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"

static SDL_Renderer* renderer = NULL;
static SDL_Window* Window = NULL;
#define MS_PER_FRAME 16.666f


engino::Engine::Engine()
{

}


/// <summary>
/// Initiate the essential Variables and important functions
/// </summary>
/// <param name="name">the windows name</param>
/// <param name="w">the width of the window opened</param>
/// <param name="h">the height of the open window</param>
/// <returns></returns>
bool engino::Engine::Init(const char* name, int w, int h) {
	m_log = new ConsoleLogger();
	//m_log = new FileLogger();

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		m_log->Log(SDL_GetError());
		return false;
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_TOOLTIP;
	Window = SDL_CreateWindow(name, _x, _y, w, h, _flag);

	_flag = SDL_RENDERER_ACCELERATED;
	renderer = SDL_CreateRenderer(Window, -1, _flag);

	if (!Window)
	{
		m_log->Log(SDL_GetError());
		return false;
	}

	if (!renderer) {
		m_log->Log(SDL_GetError());
		return false;
	}
	m_input = new SdlInput();
	m_graphics = new SDLGraphics(renderer);
	m_world = new WorldService();
	m_mixer = new AudioMixer();
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
	std::cout << m_mixer->LoadSound("assets/loaded.wav");
	m_mixer->PlaySFX(m_mixer->LoadSound("assets/loaded.wav"), 0);
	
	while (m_isRunning && !m_input->_quit()) {
		const clock_t _start = clock();
		float dt = (_start - _end) * 0.001;
		ProccessInput();
		Update(dt);
		Draw();


		float elapsedMS = _end -(_start + MS_PER_FRAME);
		if (elapsedMS > 0)
		{
			Sleep(elapsedMS * 0.001f);

		}
		_end = _start;
	}
	Shutdown();

}

static const Uint8* _keystates = NULL;
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
	if (m_input->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
		Stop();
	}

	m_world->Update(dt);

}

/// <summary>
/// Renders the elemnts on the screen by clearing the last render and creating a new one every frame
/// </summary>
void engino::Engine::Draw()
{
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	m_graphics->DrawFont(0, 0, 200, 200, m_graphics->LoadFont("assets/Roboto-Regular.ttf", 160), "TEST", Color::RED);
	m_world->Draw();

	SDL_RenderPresent(renderer);

}

/// <summary>
/// shuts down the program.
/// </summary>
void engino::Engine::Shutdown()
{
	if (m_input != nullptr)
	{
		delete m_input;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(Window);
	FreeConsole();
	SDL_Quit();
}
