#include "StatLib.h"

namespace StatLib
{
	std::string Greeter::greet(std::string s)
	{
		std::string s1;
		s1 = "Здравствуйте, " + s + "!";
		return s1;
	}
}