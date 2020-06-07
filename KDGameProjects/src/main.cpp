#include "main.h"

#include"Sytem/GameManager.h"

//���C��
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInit, LPSTR lpszArgs, int nWindMode)
{
	//���������[�N��m�点��
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//COM������
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//���{��Ή�
	setlocale(LC_ALL, "japanese");

	//�E�B���h�E�쐬
	if (APP.Init(hInstance, 1280, 720) == false)
	{
		return 0;
	}
	//���[�v
	APP.Loop();

	//�J��
	APP.Release();

	//COM�J��
	CoUninitialize();

	return 0;
}

bool Application::Init(HINSTANCE hInstance, int w, int h)
{
	//�C���X�^���X�n���h�����L��
	APP._hInstance = hInstance;

	//�E�B���h�E�쐬
	if (_gameWindow.Create(hInstance, w, h, "Window") == false)
	{
		MessageBox(nullptr, "�E�B���h�E�쐬�Ɏ��s", "�G���[", MB_OK);
		return false;
	}

	//�t���X�N���[���m�F
	bool bFullScreen = false;
	/*if (MessageBox(_gameWindow.GetHWnd(), "�t���X�N���[���ɂ��܂����H", "�m�F", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
	{
		bFullScreen = true;
	}*/

	//Directx������
	//���낢�돉��������K�v������

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

	//�Q�[�����[�v
	while (1)
	{
		DWORD st = timeGetTime();

		//�Q�[���I���w�肪����Ƃ�
		if (_gameEndFlg) break;

		//�E�B���h�E�֌W�̏���
		_gameWindow.ProcessMessage();

		//�E�B���h�E���j������Ă����烋�[�v�I��
		if (_gameWindow.IsCreated() == false) break;

		//�T�E���h�֌W

		//�Q�[������
		GAME_MGR.Run();

		//60FPS����

		DWORD et = timeGetTime();
		//FPS����
		int ms = 1000 / _maxFps;
		if (et - st < (DWORD)ms)
		{
			Sleep(ms - (et - st));
		}

		//FPS�v��
		count++;
		if (st - baseTime >= 1000)
		{
			_fps = (count * 1000) / (st - baseTime);
			baseTime = st;
			count = 0;
		}
	}
}