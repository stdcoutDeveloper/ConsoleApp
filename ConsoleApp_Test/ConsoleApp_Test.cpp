#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "Calculator.h"
#include "Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConsoleAppTest
{
	TEST_CLASS(ConsoleAppTest)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			std::streambuf *const cout_buf_ = std::cout.rdbuf(); // Backup streambuffers of cout 

			const std::ostringstream out_buf_; // Output string stream
			std::cout.rdbuf(out_buf_.rdbuf()); // assign streambuf to cout (Redirect cout to output string stream)

			ModernCpp::Calculator c;
			Assert::AreEqual(20, c.DoubleANumber(10), L"result should be 20");
			// std::cout << "Message here will be printed out to output windows!" << std::endl; // cout

			Common::Calculator cal;
			Assert::AreEqual(17, cal.Add2Numbers(8, 9), L"result should be 17");

			const auto out = out_buf_.str(); // access directly sequence of characters of output string stream
			Logger::WriteMessage(out.c_str()); // write to output windows

			std::cout.rdbuf(cout_buf_); // restore cout's original streambuf (Redirect cout back to screen)
		}
	};
}
