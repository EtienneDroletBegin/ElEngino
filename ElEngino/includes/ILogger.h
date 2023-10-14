#pragma once

namespace engino {
	class ILogger
	{
	private:

	public:
		virtual void Log(const char* message) = 0;
		virtual const char* GetError() = 0;

	protected:
		virtual ~ILogger() = default;
	};

}