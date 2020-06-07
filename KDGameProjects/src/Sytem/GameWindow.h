#pragma once

//===============================
//
//ゲームウィンドウ作成クラス
//
//===============================
class GameWindow
{
public:
	//ウィンドウハンドル取得
	HWND GetHWnd() const { return _hWnd; }
	//ウィンドウが存在するか
	bool IsCreated() const { return _hWnd ? true : false; }
	//マウスホイールの変化量を取得
	int GetMouseWheelVal() const { return _mouseWheelValue; }
	//ウィンドウ作成
	bool Create(HINSTANCE hInstance, int clientWidth, int clientHeight, const std::string& windowClassName);

	//開放
	void Release();
	//ウィンドウメッセージ
	bool ProcessMessage();
	//ウィンドウサイズを設定
	void SetClientSize(int w, int h);

	//
	~GameWindow()
	{
		Release();
	}
private:
	//ウィンドウハンドル
	HWND _hWnd = nullptr;

	int _mouseWheelValue = 0;

	//ウィンドウ関数
	static LRESULT CALLBACK callWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};