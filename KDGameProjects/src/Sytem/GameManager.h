#pragma once

//�Q�[���}�l�[�W���[
class GameManager
{
public:
	//�����ݒ�
	void Init();

	//�Q�[������
	void Run();

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