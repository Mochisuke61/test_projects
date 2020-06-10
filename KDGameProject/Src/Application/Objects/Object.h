#pragma once

//========================
// オブジェクト基本クラス
//========================
class ObjectBase
{
protected:

	KdMatrix _matrix;
	bool isActive = true;

public:
	virtual ~ObjectBase() {}

	//初期化
	virtual void Init() {}
	//更新処理
	virtual void Update() {}
	//3D描画
	virtual void Draw3D() {}
	//2D描画
	virtual void Draw2D() {}
	//解放
	virtual void Release() {}
	//表示・非表示を切り替え
	virtual void SetActive(bool flg) { isActive = flg; }

	virtual bool HitTest_Circle(const Math::Vector2& pos, float radius, Math::Vector2* hitPos)
	{
		return false;
	}

	//デバッグ描画
	virtual void DebugDraw() {}
};
