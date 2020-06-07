#pragma once
#include <iostream>

namespace ModernCpp
{
	class MyString
	{
	public:
		MyString() = default;

		MyString(const char* str)
		{
			std::cout << "MyString is created!" << std::endl;
			size_ = strlen(str) + 1;
			str_ = new char[size_]; // dynamic allocation
			memcpy(str_, str, size_);
		}

		// copy constructor
		MyString(const MyString& other)
		{
			std::cout << "MyString is copied!" << std::endl;
			size_ = other.size_;
			str_ = new char[size_]; // dynamic allocation
			memcpy(str_, other.str_, size_);
		}

		// move constructor
		MyString(MyString&& other)
		{
			std::cout << "MyString is moved!" << std::endl;
			size_ = other.size_;
			str_ = other.str_; // steal data
			
			// hollow object
			other.size_ = 0;
			other.str_ = nullptr;
		}

		void PrintOutStr() const
		{
			std::cout << str_ << std::endl;
		}

		~MyString()
		{
			std::cout << "MyString is destroyed!" << std::endl;
			delete str_;
		}

	private:
		char* str_;
		int size_;
	};

	class MyStringConsumer
	{
	public:
		MyStringConsumer(const MyString& myStr) : myStr_(myStr)
		{
		}

		MyStringConsumer(MyString&& myStr) : myStr_(std::move(myStr)) // rvalue
		{
		}

		void PrintOutMyString() const
		{
			myStr_.PrintOutStr();
		}

	private:
		MyString myStr_;
	};
}