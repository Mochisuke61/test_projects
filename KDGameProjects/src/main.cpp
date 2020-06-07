#include "main.h"

#include"Sytem/GameManager.h"

//メイン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInit, LPSTR lpszArgs, int nWindMode)
{
	//メモリリークを知らせる
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//COM初期化
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//日本語対応
	setlocale(LC_ALL, "japanese");

	//ウィンドウ作成
	if (APP.Init(hInstance, 1280, 720) == false)
	{
		return 0;
	}
	//ループ
	APP.Loop();

	//開放
	APP.Release();

	//COM開放
	CoUninitialize();

	return 0;
}

bool Application::Init(HINSTANCE hInstance, int w, int h)
{
	//インスタンスハンドルを記憶
	APP._hInstance = hInstance;

	//ウィンドウ作成
	if (_gameWindow.Create(hInstance, w, h, "Window") == false)
	{
		MessageBox(nullptr, "ウィンドウ作成に失敗", "エラー", MB_OK);
		return false;
	}

	//フルスクリーン確認
	bool bFullScreen = false;
	/*if (MessageBox(_gameWindow.GetHWnd(), "フルスクリーンにしますか？", "確認", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
	{
		bFullScreen = true;
	}*/

	//Directx初期化
	//いろいろ初期化する必要がある

	return true;
}

void Application::Release()
{
	_gameWindow.Release();
}

void Application::Loop()
{
	GAME_MGR.Init();

	DWORD baseTime = timeGetTime();
	int count = 0;

	//ゲームループ
	while (1)
	{
		DWORD st = timeGetTime();

		//ゲーム終了指定があるとき
		if (_gameEndFlg) break;

		//ウィンドウ関係の処理
		_gameWindow.ProcessMessage();

		//ウィンドウが破棄されていたらループ終了
		if (_gameWindow.IsCreated() == false) break;

		//サウンド関係

		//ゲーム処理
		GAME_MGR.Run();

		//60FPS制御

		DWORD et = timeGetTime();
		//FPS制御
		int ms = 1000 / _maxFps;
		if (et - st < (DWORD)ms)
		{
			Sleep(ms - (et - st));
		}

		//FPS計測
		count++;
		if (st - baseTime >= 1000)
		{
			_fps = (count * 1000) / (st - baseTime);
			baseTime = st;
			count = 0;
		}
	}
}