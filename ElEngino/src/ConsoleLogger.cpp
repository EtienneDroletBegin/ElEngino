#include "ConsoleLogger.h";
#include "SDL.h";
#include <iostream>
#include <Windows.h>

engino::ConsoleLogger::ConsoleLogger() {
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, 12);
}

engino::ConsoleLogger::~ConsoleLogger() {
	FreeConsole();
}

void engino::ConsoleLogger::Log(const char* message)
{
	//std::cout << "ERROR: " << message << std::endl;
}

const char* engino::ConsoleLogger::GetError()
{
	return SDL_GetError();
}
