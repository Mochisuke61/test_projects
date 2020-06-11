#pragma once

//===========================================
// 入力関係を制御するクラス
// 統一のためにKdと書いてありますが、
// 学校のライブラリではありません
//===========================================
class KdInput
{
public:
	//キー入力を取得(押している間ずっと)
	bool GetKey(int key);

	//キー入力を取得(押した瞬間だけ)
	bool GetKeyDown(int key);

	//キー入力を取得(押した後離した瞬間だけ)
	bool GetKeyUp(int key);

private:
	KdInput(){}

public:
	static KdInput& GetInstance()
	{
		static KdInput instance;
		return instance;
	}
};

#define Input KdInput::GetInstance()