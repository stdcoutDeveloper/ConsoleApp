#pragma once
#include "boost/optional.hpp"
#pragma comment(lib, "MyOwnMathLib.lib")

namespace MathLibrary
{
	class Arithmetic
	{
	public:

		static double Add(double a, double b);

		static double Subtract(double a, double b);

		static double Multiply(double a, double b);

		// @return none: can not divide because of b = 0, double: a / b
		static boost::optional<double> Divide(double a, double b);
	};
}


