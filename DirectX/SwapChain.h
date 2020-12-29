#pragma once
#include <d3d11.h>

class SwapChain
{
public:
	SwapChain();
	// Initialize the Swap Chain
	bool init(HWND hwnd, UINT width, UINT height);
	// Release the Swap Chain
	bool release();
	~SwapChain();
private:
	IDXGISwapChain* m_swap_chain;
};

