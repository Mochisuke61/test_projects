#include "main.h"
#include "GameWindow.h"

bool GameWindow::Create(HINSTANCE hInstance, int clientWidth, int clientHeight, const std::string& windowClassName)
{
	//===============================
	// メインウィンドウ作成
	//===============================


	//ウィンドウクラスの定義
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = 0;
	windowClass.lpfnWndProc = &GameWindow::callWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.lpszMenuName = nullptr;
	windowClass.lpszClassName = windowClassName.c_str();

	//ウィンドウクラスの登録
	if (!RegisterClassEx(&windowClass)) return false;

	//ウィンドウの作成
	_hWnd = CreateWindow(
		windowClassName.c_str(),
		"KDテストプロジェクト",
		WS_OVERLAPPEDWINDOW - WS_THICKFRAME,
		0,
		0,
		clientWidth,
		clientHeight,
		nullptr,
		nullptr,
		hInstance,
		this);
	if (_hWnd == nullptr) return false;

	//ウィンドウサイズを設定
	SetClientSize(clientWidth, clientHeight);

	//===============================
	// ウィンドウの表示
	//===============================
	ShowWindow(_hWnd, SW_SHOW);
	//ウィンドウの更新
	UpdateWindow(_hWnd);

	//timeGetTime関数の制度を1msに設定
	timeBeginPeriod(1);

	return true;
}

void GameWindow::Release()
{
	if (_hWnd)
	{
		DestroyWindow(_hWnd);
		_hWnd = nullptr;
	}
}

bool GameWindow::ProcessMessage()
{
	MSG msg;
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		//
		if (msg.message == WM_QUIT) return false;

		//メッセージ処理
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

//ウィンドウ関数
LRESULT CALLBACK GameWindow::callWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//GameWindowのインスタンスを取得
	GameWindow* pThis = (GameWindow*)GetProp(hWnd, "GameWindowInstance");

	if (pThis == nullptr)
	{
		switch (message)
		{
		case WM_CREATE:
		{
			CREATESTRUCT* createStruct = (CREATESTRUCT*)lParam;
			GameWindow* window = (GameWindow*)createStruct->lpCreateParams;

			//なんかわからんけど大事ポイント
			SetProp(hWnd, "GameWindowInstance", window);
		}
		return 0;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}

	//インスタンス側のWindow関数を実行する
	return pThis->WindowProc(hWnd, message, wParam, lParam);
}

//ウィンドウ関数
LRESULT GameWindow::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	//ホイールがスクロールされた
	case WM_MOUSEHWHEEL:
		_mouseWheelValue = (short)HIWORD(wParam);
		break;
	//×ボタンが押された
	case WM_CLOSE:
		Release();
		break;
	case WM_DESTROY:
		RemoveProp(hWnd, "GameWindowInstance");
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

//ウィンドウのサイズを指定サイズにする
void GameWindow::SetClientSize(int w, int h)
{
	RECT rcWnd, rcCli;

	GetWindowRect(_hWnd, &rcWnd);
	GetClientRect(_hWnd, &rcCli);

	MoveWindow(
		_hWnd,
		rcWnd.left, rcWnd.top,
		w + (rcWnd.right - rcWnd.left) - (rcCli.right - rcCli.left),
		h + (rcWnd.bottom - rcWnd.top) - (rcCli.bottom - rcCli.top),
		TRUE);
}