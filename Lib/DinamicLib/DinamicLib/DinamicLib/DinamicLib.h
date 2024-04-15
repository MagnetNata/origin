#pragma once
#include <iostream>

#ifdef DINAMICLIB_EXPORTS
#define DLIBRARY_API __declspec(dllexport)
#else
#define DLIBRARY_API __declspec(dllimport)
#endif
namespace DinamicLib
{
	class Leaver
	{
	public:
		DLIBRARY_API std::string leave(std::string s);
	};
}