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
	// Get window size
	RECT getClientWindowRect();
	void setHWND(HWND hwnd);
	// events
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

