#ifndef string_builder_hpp
#define string_builder_hpp

#include "log.hpp"

#include <string>
#include <sstream>
#include <fstream>

namespace Tyrannosaur
{
	std::string loadStringFromStream(std::istream& is)
	{
		std::stringstream sstr;
		std::string temp;
		while (getline(is, temp))
		{
			sstr << temp << std::endl;
		}
		return sstr.str();
	}

	std::string loadStringFromFile(std::string filename)
	{
		std::ifstream fin;
		fin.open(filename);
		if (fin.fail())
		{
			std::stringstream sstr;
			sstr << "[ERROR]Unable to open file:\"" << filename << "\"";
			std::cout << sstr.str() << std::endl;
			return std::string();
		}
		std::string result = loadStringFromStream(fin);
		fin.close();
		return result;
	}

	template<typename T>
	std::string toString(T arg)
	{
		std::stringstream sstr;
		sstr << arg;
		return sstr.str();
	}

	std::string toStrings()
	{
		return std::string();
	}

	template<typename T, typename... Ts>
	std::string toStrings(T arg, Ts... args)
	{
		return toString(arg) + toStrings(args...);
	}
}

#endif
