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
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			m_MouseStates[_buttonDown.button] = true;
			break;

		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			m_MouseStates[_buttonUp.button] = true;
			break;

		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			m_MouseX = _motion.x;
			m_MouseY = _motion.y;
			break;

		case SDL_KEYUP:
		case SDL_KEYDOWN:
			m_KeyStates = SDL_GetKeyboardState(nullptr);
			break;
		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
static int convert[] = {
	SDL_SCANCODE_A,
	SDL_SCANCODE_D,
	SDL_SCANCODE_S,
	SDL_SCANCODE_W,
	SDL_SCANCODE_ESCAPE,
	SDL_SCANCODE_SPACE,
	SDL_SCANCODE_RETURN,
	SDL_SCANCODE_R,
	SDL_SCANCODE_T,
	SDL_SCANCODE_Y,
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
