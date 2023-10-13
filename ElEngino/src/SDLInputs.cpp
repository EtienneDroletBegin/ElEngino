#include "SDLInputs.h"
#include <SDL.h>
using namespace engino;

void  SdlInput::Update()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;

		default:
			break;
		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
static int convert[] = {
	SDL_SCANCODE_A,
	SDL_SCANCODE_D,
	SDL_SCANCODE_S,
	SDL_SCANCODE_W
};
bool SdlInput::IsKeyDown(int keycode)
{
	return m_KeyStates[convert[keycode]];
}

bool SdlInput::IsButtonDown(int button)
{
	return false;
}

void SdlInput::GetMousePosition(int* x, int* y)
{
}
