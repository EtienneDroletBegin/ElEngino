#include "Engine.h"
#include "Time.h"
#include <SDL.h>

static SDL_Renderer* renderer = NULL;
static SDL_Window* Window = NULL;

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
	m_isInit = true;

	return true;
}

void engino::Engine::Start() {
	if (!m_isInit) {
		if (!Init("unknown", 800,600))
		{
			return;
		}
	}
	m_isRunning = true;

	clock_t _end = clock();

	while (m_isRunning) {
		const clock_t _start = clock();
		float dt = (_start - _end) * 0.001;
		ProccessInput();
		Update(dt);
		Draw();

		_end = _start;
	}

}

static const Uint8* _keystates = NULL;
void engino::Engine::ProccessInput(void)
{


	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;



		default:
			break;
		}
	}
	_keystates = SDL_GetKeyboardState(nullptr);
}

static float x = 0.0f;
static float y = 0.0f;
static float speed = 100;
void engino::Engine::Update(float dt)
{
	if (_keystates[SDL_SCANCODE_D])
	{
		x += speed*dt;
	}
	if (_keystates[SDL_SCANCODE_A])
	{
		x -= speed * dt;
	}	
	if (_keystates[SDL_SCANCODE_W])
	{
		y -= speed * dt;
	}	
	if (_keystates[SDL_SCANCODE_S])
	{
		y += speed * dt;
	}
}

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

void engino::Engine::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
