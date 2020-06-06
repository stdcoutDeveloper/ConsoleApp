#include "Auto.h"
#include "UniformInitialization.h"
#include "Common.h"

int main(int argc, const char *argv[])
{
	// ModernCpp::GotchasUsingAuto::TestFoo();
	// ModernCpp::UniformInitialization::NonStaticMemberInitialization();
	Common::Calculator c;
	std::cout << c.Add2Numbers(8, 9) << std::endl;

	return EXIT_SUCCESS;
}
