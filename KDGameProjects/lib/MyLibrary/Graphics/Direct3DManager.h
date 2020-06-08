#pragma once

class Direct3DManager
{
public:
	//‰Šú‰»
	bool Init(HWND hwnd);

	//‰ğ•ú
	void Release();

	//•`‰æˆ—
	void Render();

private:
	Direct3DManager() {}
public:
	static Direct3DManager& GetInstance()
	{
		static Direct3DManager instance;
		return instance;
	}

private:
	IDXGIFactory*			_pFactory		   = nullptr;
	IDXGISwapChain*			_pSwapChain		   = nullptr;
	ID3D11Device*			_pDevice		   = nullptr;
	ID3D11DeviceContext*	_pContext		   = nullptr;
	ID3D11RenderTargetView*	_pRenderTargetView = nullptr;
	ID3D11Texture2D*		_pDepthStencilTex  = nullptr;
	ID3D11DepthStencilView* _pDepthStancilView = nullptr;

	//”wŒiF
	float _a = 1.0f;
	float _r = 0.0f;
	float _g = 0.0f;
	float _b = 0.0f;

public:
	//”wŒiF‚ğİ’è
	void SetBackGroudColor(float a,float r,float g,float b)
	{ 
		_a = a;
		_r = r;
		_g = g;
		_b = b;
	}
};

#define D3DManager Direct3DManager::GetInstance()