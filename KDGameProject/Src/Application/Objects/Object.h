#pragma once

//========================
// オブジェクト基本クラス
//========================
class ObjectBase
{
public:
	virtual ~ObjectBase() {}

	//初期化
	virtual void Init() {}
	//更新処理
	virtual void Update() {}
	//更新後処理
	virtual void LateUpdate() {}
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

protected:

	//合成後の行列
	KdMatrix _matrix;
	//移動行列
	KdMatrix _transMatrix;
	//回転行列
	KdMatrix _rotMatrix;
	//拡大行列
	KdMatrix _scaleMatrix;

	//このオブジェクトの表示・非表示
	bool isActive = true;
};
