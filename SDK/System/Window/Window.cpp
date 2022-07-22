#include "Window.h"

#ifdef _WIN32

namespace System {

	Window::Window(HINSTANCE hInstance) : m_hInstance(hInstance) { /*...*/ }

	BOOL Window::wCreateWindow(_In_ const std::wstring &WindowTitle,
		_In_ BOOL Windowed, _In_ int32_t X, _In_ int32_t Y,
		_In_ int32_t Width, _In_ int32_t Height) {



		return TRUE;

	}

	INT Window::wMainLoop(void) {

		MSG Msg = { 0 }; // # Message Structure #

		while (GetMessage(&Msg, NULL, 0, 0) > 0) {
			// # Translates keyboard messages #
			TranslateMessage(&Msg);
			// # Dispatch messages to window procedure #
			DispatchMessage(&Msg);
		}

		return static_cast<INT>(Msg.wParam);

	}

	Window::~Window(void) noexcept { /*...*/ }

	LRESULT Window::WindowProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		
		if (uMsg == WM_CREATE) {

			LPCREATESTRUCTW create = reinterpret_cast<LPCREATESTRUCTW>(lParam);

			Window *Instance = reinterpret_cast<Window*>(create->lpCreateParams);

		}


		switch (uMsg) {
		case WM_CREATE:



			return 0;
		default:
			return DefWindowProc(hWindow, uMsg, wParam, lParam);
		}

	}

}

#endif // _WIN32
