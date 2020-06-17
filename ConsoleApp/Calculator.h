#pragma once

namespace ModernCpp
{
	class Calculator
	{
	public:
		Calculator() = default;

		Calculator(int numb1, int numb2) : numb1_(numb1), numb2_(numb2)
		{
		}

		int DoubleANumber(int number)
		{
			return number * 2;
		}

	private:
		int numb1_;
		int numb2_;
	};

#define CAL(a, b) Calculator cal##a##b(a, b)

	void QuitCommand()
	{
	}

	void HelpCommand()
	{
	}

	static constexpr struct Command
	{
		const char* name;
		void(*function)();
	}commands[] = { {"Quit", QuitCommand}, {"Help", HelpCommand} };

	// using "token pasting"/"token concatenation"
#define COMMAND(name) {#name, name##Command} // # stringizing operator: creates a quoted string from the value of a preprocessor macro.

	struct Command coms[] = { COMMAND(Quit), COMMAND(Help) };
}
