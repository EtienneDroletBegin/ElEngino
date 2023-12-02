#pragma once

#include "ILogger.h"

namespace engino {
	class ConsoleLogger : public ILogger
	{
	private:

	public:
		ConsoleLogger();
		/// <summary>
		/// logs the given message in in the console
		/// </summary>
		/// <param name="message">the message to print</param>
		virtual void Log(std::string message) override;
		/// <summary>
		/// returns an SDL error
		/// </summary>
		/// <returns>an SDL Error</returns>
		virtual std::string GetError() override;
		/// <summary>
		/// Deletes the necessary pointers to avoid memory leaks
		/// </summary>
		virtual void Shutdown() override;
		virtual ~ConsoleLogger() = default;
	};

}