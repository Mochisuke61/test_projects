#pragma once

#include<Windows.h>
#include<stdio.h>

#include"MyLibrary.h"
#include"Sytem/GameWindow.h"
#include"Sytem/GameManager.h"

//===============================
// アプリケーションクラス
//===============================

class Application
{
public:
	//アプリケーション初期化
	bool Init(HINSTANCE hInstance, int w, int h);

	//ゲームループ
	void Loop();

	//解放
	void Release();

	//ゲーム終了
	void EndGame() { _gameEndFlg = true; }

	//ゲームウィンドウ
	GameWindow _gameWindow;

	HINSTANCE _hInstance = nullptr;

	int _fps = 0;
	int _maxFps = 60;

private:
	//trueでゲーム終了
	bool _gameEndFlg = false;

	Application(){}

public:
	static Application& GetInstance()
	{
		static Application Instance;
		return Instance;
	}
};

#define APP Application::GetInstance()