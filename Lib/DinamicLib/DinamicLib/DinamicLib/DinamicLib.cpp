#include "DinamicLib.h"

namespace DinamicLib
{
	std::string Leaver::leave(std::string s)
	{
		std::string s1;
		s1 = "До свидания, " + s + "!";
		return s1;
	}
}