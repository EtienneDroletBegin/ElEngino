#pragma once
#include "ILogger.h"
#include <fstream>


namespace engino {

	class FileLogger : public ILogger
	{

	public:
		FileLogger();
		~FileLogger();

		virtual void Log(const char* message) override;
		virtual const char* GetError() override;

	private:
		std::ofstream MyFile;
		int LogNumber;

	};

}