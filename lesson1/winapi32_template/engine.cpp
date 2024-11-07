/*
* scheduler, time slice, multitasking - multithreading
* process = program
* thread
* 
* 
* fiber - Windows specific
* 
* Windows
*	multitasking
*	event-driven (windows os is event driven);		event - message
* 
* windows procedure
*/

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
// windows.h
// windowsx.h
// WINDOWS.H

#include "engine.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT mesage, WPARAM wParam, LPARAM lParam);

// hungary notation (for naming types)
// WINAPI - calling convention
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
) {
	/*
	* _In_
	* _Out_
	* _In_opt_
	*/

	/*
	* HINSTANCE - handle to an instance
	* LPSTR - long pointer to a string L P STR
	* 
	* hInstance - handle to an instance OF THE APPLICATION (our application)
	* hPrevInstance - no longer used
	* lpCmdLine - equivalent of char *argv; command line
	* nShowCmd
	* 
	*/

	message_box("My first window application");
	//MessageBoxA vs MessageBoxW
	// A - ASCII
	// W - wide characters, wchar_t, Unicode

	// WM_....			WM_SIZE WM_CREATE WM_DESTROY

	return 0;
}

void message_box(const char* msg) {
	MessageBoxA(nullptr, msg, "Information", 0);
}

/*
* LRESULT - long integer
* CALLBACK - calling convention
* 
* HWND hwnd - handle to a window
* WM_
* 
* lParam, wParam - data came with message
* 
*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;

	switch (message) {
	case WM_CREATE:
		// initialization code
		return 0;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0); // WM_QUIT
		return 0;
	case WM_PAINT:
		BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}