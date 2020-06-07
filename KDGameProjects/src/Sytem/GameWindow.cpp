#include "main.h"
#include "GameWindow.h"

bool GameWindow::Create(HINSTANCE hInstance, int clientWidth, int clientHeight, const std::string& windowClassName)
{
	//===============================
	// ���C���E�B���h�E�쐬
	//===============================


	//�E�B���h�E�N���X�̒�`
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

	//�E�B���h�E�N���X�̓o�^
	if (!RegisterClassEx(&windowClass)) return false;

	//�E�B���h�E�̍쐬
	_hWnd = CreateWindow(
		windowClassName.c_str(),
		"KD�e�X�g�v���W�F�N�g",
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

	//�E�B���h�E�T�C�Y��ݒ�
	SetClientSize(clientWidth, clientHeight);

	//===============================
	// �E�B���h�E�̕\��
	//===============================
	ShowWindow(_hWnd, SW_SHOW);
	//�E�B���h�E�̍X�V
	UpdateWindow(_hWnd);

	//timeGetTime�֐��̐��x��1ms�ɐݒ�
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

		//���b�Z�[�W����
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

//�E�B���h�E�֐�
LRESULT CALLBACK GameWindow::callWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//GameWindow�̃C���X�^���X���擾
	GameWindow* pThis = (GameWindow*)GetProp(hWnd, "GameWindowInstance");

	if (pThis == nullptr)
	{
		switch (message)
		{
		case WM_CREATE:
		{
			CREATESTRUCT* createStruct = (CREATESTRUCT*)lParam;
			GameWindow* window = (GameWindow*)createStruct->lpCreateParams;

			//�Ȃ񂩂킩��񂯂Ǒ厖�|�C���g
			SetProp(hWnd, "GameWindowInstance", window);
		}
		return 0;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}

	//�C���X�^���X����Window�֐������s����
	return pThis->WindowProc(hWnd, message, wParam, lParam);
}

//�E�B���h�E�֐�
LRESULT GameWindow::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	//�z�C�[�����X�N���[�����ꂽ
	case WM_MOUSEHWHEEL:
		_mouseWheelValue = (short)HIWORD(wParam);
		break;
	//�~�{�^���������ꂽ
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

//�E�B���h�E�̃T�C�Y���w��T�C�Y�ɂ���
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