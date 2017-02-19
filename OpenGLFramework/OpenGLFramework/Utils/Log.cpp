#include "Log.h"

namespace Utils
{

	std::vector<std::string> Log::m_output;

	void Log::DebugLog(const char* _text)
	{
		m_output.push_back(std::string(_text));
	}

	void Log::DebugLog(const int _argumentCount, ...)
	{
		va_list ap;
		std::ostringstream oss;
		va_start(ap, _argumentCount);
		for (int j = 0; j<_argumentCount; j++)
			oss << va_arg(ap, const char*);
		va_end(ap);
		std::cout << std::string(oss.str().c_str()) << std::endl;
		m_output.push_back(std::string(oss.str().c_str()));
	}

	const std::vector<std::string> Log::GetOutput()
	{
		return m_output;
	}


	const std::vector<std::string> Log::GetLastOutput(const unsigned int _nbLines)
	{
		std::vector<std::string> result;
		for (int i = m_output.size() - 1; result.size() <= _nbLines && i >= 0; i--)
			result.insert(result.begin(), m_output[i]);
		return result;
	}

}