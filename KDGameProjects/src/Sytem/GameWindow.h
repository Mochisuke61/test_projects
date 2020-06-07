#pragma once

//===============================
//
//�Q�[���E�B���h�E�쐬�N���X
//
//===============================
class GameWindow
{
public:
	//�E�B���h�E�n���h���擾
	HWND GetHWnd() const { return _hWnd; }
	//�E�B���h�E�����݂��邩
	bool IsCreated() const { return _hWnd ? true : false; }
	//�}�E�X�z�C�[���̕ω��ʂ��擾
	int GetMouseWheelVal() const { return _mouseWheelValue; }
	//�E�B���h�E�쐬
	bool Create(HINSTANCE hInstance, int clientWidth, int clientHeight, const std::string& windowClassName);

	//�J��
	void Release();
	//�E�B���h�E���b�Z�[�W
	bool ProcessMessage();
	//�E�B���h�E�T�C�Y��ݒ�
	void SetClientSize(int w, int h);

	//
	~GameWindow()
	{
		Release();
	}
private:
	//�E�B���h�E�n���h��
	HWND _hWnd = nullptr;

	int _mouseWheelValue = 0;

	//�E�B���h�E�֐�
	static LRESULT CALLBACK callWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};