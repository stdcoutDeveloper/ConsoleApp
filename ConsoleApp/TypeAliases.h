#pragma once

#include <vector>

namespace ModernCpp
{
	namespace TypeAliases
	{
		/**
		 * \brief Type alias: a name for another already declared type
		 */

		// type aliases
		using byte = unsigned char;
		using pbyte = unsigned char*;
		using array_t = int[10]; // array of 10 int
		using fn = void(byte, double); // function pointer

		void func(byte b, double d)
		{
			/*...*/
		}

		byte b{ 42 };
		pbyte pb = new byte[10]{ 0 };
		array_t a{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		fn* f = func;

		// alias templates
		template <class T>
		class CustomAllocator
		{
			/*...*/
		};

		template <typename T>
		using vec_t = std::vector<T, CustomAllocator<T>>;

		vec_t<int> vi;
		vec_t<std::string> vs;

		template<typename T>
		class Foo 
		{
			typedef T value_type;
		};
		auto TypeDefAliases()
		{
			typedef unsigned char byte;
			typedef unsigned char * pbyte;
			typedef int array_t[10];
			typedef void(*fn)(byte, double);
			
			typedef std::vector<int> vint_t;
		}
	}
}
