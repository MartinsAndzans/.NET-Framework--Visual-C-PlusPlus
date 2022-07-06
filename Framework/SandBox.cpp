#pragma once

#include "System/Console/Console.h"

using namespace System;

int32_t main(int32_t argc, const char **argv) {

	Console::Title("# Console Test #");
	
	std::string Input = Console::ReadLine();



	wchar_t key = getwc(stdin); // # Debug Pause #

	return EXIT_SUCCESS;

}
