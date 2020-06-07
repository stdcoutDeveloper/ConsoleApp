#include "Auto.h"
#include "UniformInitialization.h"
#include "Common.h"
#include "MoveSemantics.h"

int main(int argc, const char *argv[])
{
	using namespace ModernCpp;

	// ModernCpp::GotchasUsingAuto::TestFoo();
	// ModernCpp::UniformInitialization::NonStaticMemberInitialization();
	/*Common::Calculator c;
	std::cout << c.Add2Numbers(8, 9) << std::endl;*/

	MyStringConsumer cons("Move Semantics");
	cons.PrintOutMyString();

	return EXIT_SUCCESS;
}
