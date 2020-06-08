#pragma once

//ゲームマネージャー
class GameManager
{
public:
	//初期設定
	void Init();

	//ゲーム処理
	void Run();

	//解放
	void Release();

private:
	GameManager(){}
public:
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}
};

#define GAME_MGR GameManager::GetInstance()