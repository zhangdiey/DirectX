#include "Window.h"

Window* window = nullptr;

Window::Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		// window will be created
		window->onCreate();
		break;
	}
	case WM_DESTROY:
	{
		// window will be destroyed
		window->onDestroyed();
		::PostQuitMessage(0);
		break;
	}
	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
}

bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = 0;
	wc.lpfnWndProc = &WndProc;

	// if registration fails return false
	if (!::RegisterClassEx(&wc))
		return false;

	if (!window)
		window = this;
	
	// create the window
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, NULL, NULL, NULL);

	// if creation fails return false
	if (!m_hwnd)
		return false;

	// show the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	// set the flag to true indicating the window is running
	m_is_run = true;

	return true;
}

bool Window::broadcast()
{
	MSG msg;

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	window->onUpdate();

	Sleep(0);
		
	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

bool Window::release()
{
	// Destroy the window
	if (!::DestroyWindow(m_hwnd))
		return false;
		
	return true;
}

void Window::onDestroyed()
{
	m_is_run = false;
}

Window::~Window()
{
}
