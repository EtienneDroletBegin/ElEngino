#include "ConsoleLogger.h"
#include "SDL.h"
#include <iostream>
#include <Windows.h>

engino::ConsoleLogger::ConsoleLogger() {
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, 12);
}
void engino::ConsoleLogger::Log(std::string message)
{
	//std::cout << "ERROR: " << message << std::endl;
}

std::string engino::ConsoleLogger::GetError()
{
	return SDL_GetError();
}

void engino::ConsoleLogger::Shutdown()
{
	FreeConsole();
}
