#pragma once

#include "System/Console/Console.h"
#include "System/Window/Window.h"

using namespace System::Windows;

int32_t main(int32_t argc, const char **argv) {

	Console::Title("Console");

	Console::ReadLine();

	wchar_t key = getwc(stdin); // # Debug Pause #

	return EXIT_SUCCESS;

}
