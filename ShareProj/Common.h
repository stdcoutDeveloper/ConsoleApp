#pragma once
#include <iostream>
#include "ResourceGetter.h"
#include <boost/filesystem.hpp> // include boost library
#include <include/Arithmetic.h>

namespace Common
{
	class Calculator
	{
	public:
		inline int Add2Numbers(int number1st, int number2nd)
		{
			std::wcout << ResourceCommon::GetMessageInstallSuccessfully() << std::endl;
			return static_cast<int>(MathLibrary::Arithmetic::Add(number1st, number2nd));
			// return number1st + number2nd;
		}
	};
}
	
