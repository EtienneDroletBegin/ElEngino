#include "FileLogger.h"
#include "SDL.h"

engino::FileLogger::FileLogger() : LogNumber(0)
{
	MyFile.open("ErrorLog.txt");
}


void engino::FileLogger::Log(std::string message)
{
	MyFile << LogNumber << " " << message << std::endl;
	LogNumber++;
}

std::string engino::FileLogger::GetError()
{
	return SDL_GetError();
}

void engino::FileLogger::Shutdown()
{
	MyFile.close();
}


