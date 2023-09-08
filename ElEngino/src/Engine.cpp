#include "Engine.h"
#include "Time.h"
#include <SDL.h>

#include"SDLInputs.h"

static SDL_Renderer* renderer = NULL;
static SDL_Window* Window = NULL;

/// <summary>
/// Initiate the essential Variables and important functions
/// </summary>
/// <param name="name">the windows name</param>
/// <param name="w">the width of the window opened</param>
/// <param name="h">the height of the open window</param>
/// <returns></returns>
bool engino::Engine::Init(const char* name, int w, int h) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log(SDL_GetError());
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
		SDL_Log(SDL_GetError());
		return false;
	}

	if (!renderer) {
		SDL_Log(SDL_GetError());
		return false;
	}
	m_input = new SdlInput();
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

	while (m_isRunning && !m_input->_quit()) {
		Uint64 frameStart = SDL_GetPerformanceCounter();
		const clock_t _start = clock();
		float dt = (_start - _end) * 0.001;
		ProccessInput();
		Update(dt);
		Draw();

		_end = _start;
		Uint64 frameend = SDL_GetPerformanceCounter();
		float elapsedMS = (frameend - frameStart) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(floor(16.666f - elapsedMS));
	}
	Shutdown();

}

static const Uint8* _keystates = NULL;
void engino::Engine::ProccessInput(void)
{
	m_input->Update();
}

static float x = 0.0f;
static float y = 0.0f;
static float speed = 100;

/// <summary>
/// Function executed every frame
/// </summary>
/// <param name="dt">the time elapsed between the current frame and the last</param>
void engino::Engine::Update(float dt)
{
	if (m_input->IsKeyDown(SDL_SCANCODE_D)) {
		x = x + speed * dt;
	}
	if (m_input->IsKeyDown(SDL_SCANCODE_A)) {
		x = x - speed * dt;
	}
	if (m_input->IsKeyDown(SDL_SCANCODE_S)) {
		y = y + speed * dt;
	}
	if (m_input->IsKeyDown(SDL_SCANCODE_W)) {
		y = y - speed * dt;
	}
	if (m_input->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
		Stop();
	}


}

/// <summary>
/// Renders the elemnts on the screen by clearing the last render and creating a new one every frame
/// </summary>
void engino::Engine::Draw()
{
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = y;
	get_rect.h = 100;
	get_rect.w = 100;
	SDL_RenderDrawRect(renderer, &get_rect);

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
	SDL_Quit();
}
