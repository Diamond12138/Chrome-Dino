#ifndef log_hpp
#define log_hpp

#include "stringbuilder.hpp"

#include <iostream>
#include <string>
#include <sstream>

namespace Tyrannosaur
{
	typedef std::string LogLevel;
	const std::string INFO = "INFO";
	const std::string ERROR = "ERROR";
	
	void log(LogLevel) {}

	template<typename... Ts>
	void log(LogLevel level,Ts... contents)
	{
		std::cout << "[" << level << "]" << toStrings(contents...) << std::endl;
	}

	template<typename... Ts>
	void logi(Ts... contents)
	{
		log(INFO, contents...);
	}

	template<typename... Ts>
	void loge(Ts... contents)
	{
		log(ERROR, contents...);
	}
}

#endif
