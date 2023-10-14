#pragma once

#include "ILogger.h"

namespace engino {
	class ConsoleLogger : public ILogger
	{
	private:

	public:
		ConsoleLogger();
		virtual void Log(const char* message) override;
		virtual const char* GetError() override;
		virtual ~ConsoleLogger();
	};

}