#pragma once

//=================================================
// キャラクターオブジェクト
// ・キャラクターを作成するときの基底オブジェクト
//=================================================
class Character : public ObjectBase
{
public:
	//初期化
	virtual void Init();
	//更新処理
	virtual void Update();
	//2D描画
	virtual void Draw2D();
	//解放
	virtual void Release();

private:
	KdTexture _texture;
};