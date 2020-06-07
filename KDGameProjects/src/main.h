#pragma once

#include<Windows.h>
#include<stdio.h>

#include"MyLibrary.h"
#include"Sytem/GameWindow.h"
#include"Sytem/GameManager.h"

//===============================
// �A�v���P�[�V�����N���X
//===============================

class Application
{
public:
	//�A�v���P�[�V����������
	bool Init(HINSTANCE hInstance, int w, int h);

	//�Q�[�����[�v
	void Loop();

	//���
	void Release();

	//�Q�[���I��
	void EndGame() { _gameEndFlg = true; }

	//�Q�[���E�B���h�E
	GameWindow _gameWindow;

	HINSTANCE _hInstance = nullptr;

	int _fps = 0;
	int _maxFps = 60;

private:
	//true�ŃQ�[���I��
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