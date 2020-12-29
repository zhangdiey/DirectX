#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	// Initialize the window
	bool init();
	bool broadcast();
	bool isRun();
	// Release the window
	bool release();
	// events
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroyed();
	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

