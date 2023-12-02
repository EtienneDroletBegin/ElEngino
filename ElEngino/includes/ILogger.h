#pragma once
#include <string>

namespace engino {
	class ILogger
	{
	private:

	public:
		/// <summary>
		/// Logs the given message in the given format
		/// </summary>
		/// <param name="message">the message to log</param>
		virtual void Log(std::string message) = 0;
		/// <summary>
		/// returns an SDL_Error
		/// </summary>
		/// <returns>the SDL Error</returns>
		virtual std::string GetError() = 0;
		virtual void Shutdown() = 0;
		virtual ~ILogger() = default;

	};

}