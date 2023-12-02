#pragma once
#include "ILogger.h"
#include <fstream>


namespace engino {

	class FileLogger : public ILogger
	{

	public:
		FileLogger();
		~FileLogger() = default;
		/// <summary>
		/// Logs a message in a file
		/// </summary>
		/// <param name="message">the message to log</param>
		virtual void Log(std::string message) override;
		/// <summary>
		/// returns an SDL_Error
		/// </summary>
		/// <returns>an SDL_Error</returns>
		virtual std::string GetError() override;
		/// <summary>
		/// Deletes the pointers to avoid memory leaks
		/// </summary>
		virtual void Shutdown() override;

	private:
		std::ofstream MyFile;
		int LogNumber;

	};

}