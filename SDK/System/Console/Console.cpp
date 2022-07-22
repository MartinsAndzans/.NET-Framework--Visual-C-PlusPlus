#include "Console.h"

namespace System { namespace Windows {

	Console::Console() {

		if (AllocConsole()) {
			FILE *OutputStream = nullptr, *InputStream = nullptr, *ErrorStream = nullptr;
			freopen_s(&OutputStream, "CONOUT$", "w", stdout);
			freopen_s(&InputStream, "CONIN$", "r", stdin);
			freopen_s(&ErrorStream, "CONOUT$", "w", stderr);
		}

		//===== Console Handles =====//
		m_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		m_hInput = GetStdHandle(STD_INPUT_HANDLE);
		m_hError = GetStdHandle(STD_ERROR_HANDLE);
		//===========================//

	}

	bool Console::TitleImpl(const std::string &Title) {
		bool Error = SetConsoleTitleA(Title.c_str());
		return Error;
	}

	bool Console::TitleImpl(const std::wstring &Title) {
		bool Error = SetConsoleTitleW(Title.c_str());
		return Error;
	}
	
	void Console::WriteImpl(const std::string &Message) {
		
		
		
	}
	
	void Console::WriteLineImpl(const std::string &Message) {
		
		
		
	}
	
	std::string Console::ReadLineImpl(const std::string &Message/*= "> "*/) {
		
		fflush(stdin);
		std::cout << Message;
		std::string Input = { 0 };
		std::getline(std::cin, Input);

		return Input;
		
	}

}}
