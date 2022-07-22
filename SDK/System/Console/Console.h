#pragma once

#define WIN32_LEAN_AND_MEAN

#ifndef _WIN32
#error This SDK Works only on Windows
#endif

//===== HEADERS =====//
#include <stdexcept>
#include <Windows.h>
#include <iostream>
#include <string>
//===================//

namespace System { namespace Windows {

	class Console {
	public:

		// # Set Console Title #
		static bool Title(const std::string &Title) {
			return get_instance().TitleImpl(Title);
		}
		
		static bool Title(const std::wstring &Title) {
			return get_instance().TitleImpl(Title);
		}

		// # Read User Input From Console #
		static std::string ReadLine(const std::string &Message = "> ") {
			return get_instance().ReadLineImpl(Message);
		}

	private:
		
		Console();
		Console(const Console &other) = delete;
		
		// # Set Console Title #
		bool TitleImpl(const std::string &Title);
		bool TitleImpl(const std::wstring &Title);

		// # Print Message To Console #
		void WriteImpl(const std::string &Message);
		
		// # Print Message To Console And New Line #
		void WriteLineImpl(const std::string &Message);

		// # Read User Input From Console #
		std::string ReadLineImpl(const std::string &Message = "> ");

		static Console& get_instance() {
			static Console Instance;
			return Instance;
		}
		
	private:

		//===== Console Handles =====//
		HANDLE m_hOutput; // # Console Output Handle #
		HANDLE m_hInput;  // # Console Input Handle #
		HANDLE m_hError;  // # Console Error Handle #
		//===========================//

	};
	
}}
