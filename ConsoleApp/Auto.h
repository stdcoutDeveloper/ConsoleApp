#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>

namespace ModernCpp
{
	/**
	 * \brief Using "auto" keyword whenever possible 
	 */
	namespace HowUsingAuto
	{
		// local variables
		auto i = 42;
		auto d = 42.5;
		auto s = "text"; // const char*
		auto v = { 1, 2, 3 };
		// commit to a specific type
		auto b = new char[10]{ 0 };
		auto s1 = std::string{ "text" };
		auto v1 = std::vector<int>{ 1, 2, 3 };
		auto p = std::make_shared<int>(42);

		// lambda expressions
		auto upper = [](char const c) {
			return toupper(c); // to uppercase
		};

		auto add = [](auto const a, auto const b) {
			return a + b;
		};

		// template
		template <typename F, typename T>
		auto Apply(F&& f, T value)
		{
			return f(value);
		}
	}

	// benefits of using "auto"
	namespace BenefitUsingAuto
	{
		auto GetSizeOfVector()
		{
			auto v = std::vector<int>{ 1, 2, 3 };
			int size1 = v.size(); // implicit conversion, possible loss of data
			auto size2 = v.size();
			// auto size3 = int{ v.size() }; // error, narrowing conversion
		}

		auto IterateMap()
		{
			std::map<int, std::string> m;
			for (std::map<int, std::string>::const_iterator it = m.cbegin();
				it != m.cend(); ++it)
			{
				/*...*/
			}

			for (auto it = m.cbegin(); it != m.cend(); ++it)
			{
				/*...*/
			}
		}
	}

	namespace GotchasUsingAuto
	{
		auto l1 = long long{ 42 }; // error
		typedef long long llong;
		auto l2 = llong{ 42 }; // OK
		auto l3 = 42LL; // OK

		class Foo
		{
		private:
			int x_;
		public:
			Foo(const int x = 0) : x_(x) {}

			int& Get()
			{
				return x_;
			}
		};

		auto TestFoo()
		{
			Foo f(42);
			auto x = f.Get();
			x = 100;
			std::cout << f.Get() << std::endl; // prints 42
		}

		auto ladd = [](const auto a, const auto b)
		{
			return a + b;
		};

		struct Addition
		{
			template <typename T, typename U>
			auto operator () (const T a, const U b) const
			{
				return a + b;
			}
		};

		auto i = ladd(40, 2);

		using namespace std::string_literals;
		auto s = ladd("forty"s, " two"s);
	}
}