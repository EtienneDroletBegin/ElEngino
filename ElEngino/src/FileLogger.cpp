#include "FileLogger.h"
#include "SDL.h"

engino::FileLogger::FileLogger() : LogNumber(0)
{
	MyFile.open("ErrorLog.txt");
}

engino::FileLogger::~FileLogger()
{
	MyFile.close();
}

void engino::FileLogger::Log(const char* message)
{
	MyFile << LogNumber << " " << message << std::endl;
	LogNumber++;
}

const char* engino::FileLogger::GetError()
{
	return SDL_GetError();
}


