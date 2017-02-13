
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdarg.h>
#include <sstream>

namespace Utils
{

	class Log
	{
	public:
		static void DebugLog(const char* _text);
		static void DebugLog(int _argumentCount, ...);
		static std::vector<std::string> GetOutput();
		static std::vector<std::string> GetLastOutput(unsigned int _nbLines);

	private:
		static std::vector<std::string> output;
	};
}