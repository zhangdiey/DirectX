#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{
public:
	SwapChain();
	// Initialize the Swap Chain
	bool init(HWND hwnd, UINT width, UINT height);
	bool present(bool vsync);
	// Release the Swap Chain
	bool release();
	~SwapChain();
private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_rtv;
	friend class DeviceContext;
};

