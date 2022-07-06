#include "Console.h"

namespace System {

	//===== Get Console Handles =====//
	HANDLE Console::hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE Console::hInput = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE Console::hError = GetStdHandle(STD_ERROR_HANDLE);
	//===============================//

	bool Console::Title(const std::string &title) {
		bool Error = SetConsoleTitleA(title.c_str());
		return Error;
	}

	bool Console::Title(const std::wstring &title) {
		bool Error = SetConsoleTitleW(title.c_str());
		return Error;
	}
	
	void Console::Write(const std::string &message) {
		
		 
		
	}
	
	void Console::WriteLine(const std::string &message) {
		
		
		
	}
	
	std::string Console::ReadLine(const std::string &message/*= "> "*/) {
		
		fflush(stdin);
		std::cout << message;
		std::string input = { 0 };
		std::getline(std::cin, input);

		return input;
		
	}

}
