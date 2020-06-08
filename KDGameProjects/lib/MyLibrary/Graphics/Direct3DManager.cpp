#include "MyLibrary.h"

#include "Direct3DManager.h"

//初期化
bool Direct3DManager::Init(HWND hwnd)
{
	HRESULT hr = CreateDXGIFactory(IID_PPV_ARGS(&_pFactory));
	if (FAILED(hr))
	{
		return false;
	}

    UINT flags = 0;
#ifdef _DEBUG
    flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
    D3D_FEATURE_LEVEL pLevels[] = { D3D_FEATURE_LEVEL_11_0 };
    D3D_FEATURE_LEVEL level;

    RECT                rect;
    DXGI_SWAP_CHAIN_DESC scDesc;

    ::GetClientRect(hwnd, &rect);
    ::ZeroMemory(&scDesc, sizeof(scDesc));
    scDesc.BufferCount = 1;
    scDesc.BufferDesc.Width = rect.right;
    scDesc.BufferDesc.Height = rect.bottom;
    scDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scDesc.OutputWindow = hwnd;
    scDesc.SampleDesc.Count = 1;
    scDesc.SampleDesc.Quality = 0;
    scDesc.Windowed = TRUE;

    hr = D3D11CreateDeviceAndSwapChain(NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        flags,
        pLevels,
        1,
        D3D11_SDK_VERSION,
        &scDesc,
        &_pSwapChain,
        &_pDevice,
        &level,
        &_pContext);
    if (FAILED(hr)) return false;

    //バックバッファ作成
    ID3D11Texture2D* pBackBuffer;
    hr = _pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if (FAILED(hr)) return false;

    hr = _pDevice->CreateRenderTargetView(pBackBuffer, NULL, &_pRenderTargetView);
    pBackBuffer->Release();

    if (FAILED(hr)) return false;


    //ステンシルバッファ作成
    D3D11_TEXTURE2D_DESC txDesc;
    ZeroMemory(&txDesc, sizeof(txDesc));
    txDesc.Width = rect.right;
    txDesc.Height = rect.bottom;
    txDesc.MipLevels = 1;
    txDesc.ArraySize = 1;
    txDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    txDesc.SampleDesc.Count = 1;
    txDesc.SampleDesc.Quality = 0;
    txDesc.Usage = D3D11_USAGE_DEFAULT;
    txDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    txDesc.CPUAccessFlags = 0;
    txDesc.MiscFlags = 0;
    hr = _pDevice->CreateTexture2D(&txDesc, NULL, &_pDepthStencilTex);
    if (FAILED(hr)) return false;

    //
    D3D11_DEPTH_STENCIL_VIEW_DESC dsDesc;
    ZeroMemory(&dsDesc, sizeof(dsDesc));
    dsDesc.Format = txDesc.Format;
    dsDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    dsDesc.Texture2D.MipSlice = 0;
    hr = _pDevice->CreateDepthStencilView(_pDepthStencilTex, &dsDesc, &_pDepthStancilView);
    if (FAILED(hr)) return false;

    return true;
}

//解放
void Direct3DManager::Release()
{
    if (_pContext) _pContext->ClearState();
    if (_pRenderTargetView != NULL)
    {
        _pRenderTargetView->Release();
        _pRenderTargetView = NULL;
    }
    if (_pSwapChain != NULL)
    {
        _pSwapChain->Release();
        _pSwapChain = NULL;
    }
    if (_pContext != NULL)
    {
        _pContext->Release();
        _pContext = NULL;
    }
}

//描画
void Direct3DManager::Render()
{
    if (_pDevice == NULL ) return;
    if (_pContext == NULL) return;
    if (_pRenderTargetView == NULL) return;
    if (_pSwapChain == NULL) return;

    float bg[4] = { _r,_g,_b,_a };
    //描画
    _pContext->OMSetRenderTargets(1, &_pRenderTargetView, _pDepthStancilView);
    _pContext->ClearRenderTargetView(_pRenderTargetView,bg);
    _pContext->ClearDepthStencilView(_pDepthStancilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,1.0f,0);
    _pSwapChain->Present(0, 0);
}