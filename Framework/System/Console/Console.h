#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

namespace System {

	class Console {
	public:

		// # Set Console Title #
		static bool Title(const std::string &title);
		static bool Title(const std::wstring &title);

		// # Print Message To Console #
		static void Write(const std::string &message);
		
		// # Print Message To Console And New Line #
		static void WriteLine(const std::string &message);

		// # Get Message From Console #
		static std::string ReadLine(const std::string &message = "> ");

	private:

		//===== Console Handles =====//
		static HANDLE hOutput; // # Console Output Handle #
		static HANDLE hInput;  // # Console Input Handle #
		static HANDLE hError;  // # Console Error Handle #
		//===========================//

	};

}