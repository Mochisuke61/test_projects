#include "main.h"
#include "GameManager.h"

void GameManager::Init()
{

}

void GameManager::Run()
{
	//エスケープキーでゲーム終了
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		APP.EndGame();
	}
}