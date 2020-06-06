#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace ModernCpp
{
	namespace UniformInitialization
	{
		std::string s1("test"); // direct initialization
		std::string s2 = "test"; // copy initialization

		// direct list initialization
		std::vector<int> v{ 1, 2, 3 };
		std::map<int, std::string> m{ {1, "one"}, { 2, "two" } };
		int* arr2 = new int[3]{ 1, 2, 3 };
		int arr1[3]{ 1, 2, 3 };
		int i{ 42 };
		double d{ 1.2 };
		// User-defined types
		class Foo
		{
			int a_;
			double b_;
		public:
			Foo() :a_(0), b_(0) 
			{
			}

			Foo(int a, double b = 0.0) :a_(a), b_(b) 
			{
			}
		};

		Foo f1{};
		Foo f2{ 42, 1.2 };
		Foo f3{ 42 };

		struct Bar 
		{ 
			int a_; 
			double b_; 
		};

		Bar b{ 42, 1.2 };

		// copy list initialization
		std::vector<int> myVector = { 1, 2, 3 };
		int myArray[] = { 1, 2, 3 };

		enum class TextVerticalAligment 
		{ Top, Middle, Bottom };

		enum class TextHorizontalAligment 
		{ Left, Center, Right };

		auto NonStaticMemberInitialization()
		{
			struct Control
			{
				const int DefaultHeigh = 14; // [1]
				const int DefaultWidth = 80; // [2]
				TextVerticalAligment valign_ = TextVerticalAligment::Middle; // [3]
				TextHorizontalAligment halign_ = TextHorizontalAligment::Left; // [4]

				std::string text_;
				Control(const std::string& t) : text_(t) {} // [5]

				Control(const std::string& t, const TextVerticalAligment va, const TextHorizontalAligment ha) :
					text_(t), valign_(va), halign_(ha) // [6]  
				{}
			};

			struct Point
			{
				double x_, y_;
				Point(double const x = 0.0, double const y = 0.0) : x_(x), y_(y)
				{
				}
			};

			struct Foo
			{
				Foo()
				{
					std::cout << "default constructor" << std::endl;
				}

				Foo(const std::string & text)
				{
					std::cout << "constructor '" << text << "'" << std::endl;
				}

				Foo(const Foo& other)
				{
					std::cout << "copy constructor" << std::endl;
				}

				Foo(Foo&& other)
				{
					std::cout << "move constructor" << std::endl;
				}

				Foo& operator=(const Foo& other)
				{
					std::cout << "assignment" << std::endl;
					return *this;
				}

				Foo& operator=(Foo&& other)
				{
					std::cout << "move assignment" << std::endl;
					return *this;
				}

				~Foo()
				{
					std::cout << "destructor" << std::endl;
				}
			};

			struct Bar
			{
				Foo f_;
				Bar(const Foo& value) : f_(value)
				{
					// f_ = value;
				}
			};

			Foo f;
			Bar b(f);
		}
	}
}
