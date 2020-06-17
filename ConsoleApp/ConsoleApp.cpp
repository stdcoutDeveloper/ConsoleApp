#include "Auto.h"
#include "UniformInitialization.h"
#include "Common.h"
#include "MoveSemantics.h"
#include "Calculator.h"
#include <MathLibrary.h>

int main(int argc, const char *argv[])
{
	using namespace ModernCpp;

	// ModernCpp::GotchasUsingAuto::TestFoo();
	// ModernCpp::UniformInitialization::NonStaticMemberInitialization();
	/*Common::Calculator c;
	std::cout << c.Add2Numbers(8, 9) << std::endl;

	MyStringConsumer cons("Move Semantics");
	cons.PrintOutMyString();*/

	// Initialize a Fibonacci relation sequence.
	fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	CAL(7, 8);
	CAL(8, 9);

	return EXIT_SUCCESS;
}
