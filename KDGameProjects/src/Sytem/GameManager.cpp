#include "main.h"
#include "GameManager.h"

void GameManager::Init()
{

}

void GameManager::Run()
{
	//�G�X�P�[�v�L�[�ŃQ�[���I��
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		APP.EndGame();
	}
}