#pragma once

#include <stdexcept>
#include <Windows.h>
#include <string>

#ifndef _WIN32
#error This SDK Works only on Windows
#else

namespace System {

	enum WindowStyle { WINDOWED, FULLSCREEN };
	
	class Window {
	public:

		Window(HINSTANCE hInstance);
		Window(const Window &other) = delete;

		/// <summary>Create Window</summary>
		/// <param name="WindowTitle">Window Title in Unicode</param>
		BOOL wCreateWindow(_In_ const std::wstring &WindowTitle,
			_In_ BOOL Windowed, _In_ int32_t X, _In_ int32_t Y,
			_In_ int32_t Width, _In_ int32_t Height);
		
		/// <summary>Main Message Loop</summary>
		/// <returns>Exit Code</returns>
		INT wMainLoop(void);

		~Window(void) noexcept;

	private:

		HINSTANCE m_hInstance; // # Program Instance #

		//===== WINDOW =====//
		HWND m_hWindow;
		POINT m_WindowPos;
		SIZE m_WindowSize;
		std::wstring m_WindowTitle;
		HICON m_WindowIcon;
		HCURSOR m_WindowCursor;
		//==================//

	private:



		// # Global Window Procedure #
		static LRESULT CALLBACK WindowProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);

	};

}

#endif // _WIN32