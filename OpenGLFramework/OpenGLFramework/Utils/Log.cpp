#include "Log.h"

namespace Utils
{

	std::vector<std::string> Log::output;

	void Log::DebugLog(const char* _text)
	{
		output.push_back(std::string(_text));
	}

	void Log::DebugLog(int _argumentCount, ...)
	{
		va_list ap;
		std::ostringstream oss;
		va_start(ap, _argumentCount);
		for (int j = 0; j<_argumentCount; j++)
			oss << va_arg(ap, const char*);
		va_end(ap);
		output.push_back(std::string(oss.str().c_str()));
	}

	std::vector<std::string> Log::GetOutput()
	{
		return output;
	}


	std::vector<std::string> Log::GetLastOutput(unsigned int _nbLines)
	{
		std::vector<std::string> result;
		for (int i = output.size() - 1; result.size() <= _nbLines && i >= 0; i--)
			result.insert(result.begin(), output[i]);
		return result;
	}

}