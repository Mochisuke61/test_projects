#pragma once

#include "Objects/Object.h"

class Scene
{
public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	//3D描画処理
	void Draw3D();

	//2D描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	//ImGuiで表示するデバッグデータを追加する
	void AddDebugLog(std::string key, float value);

private:
	//メンバ
	//全オブジェクトリスト
	std::list<std::shared_ptr<ObjectBase>> _objetList;

	//ImGui関係
	//FIXME: floatしか使えんカスデータなのでテンプレートでうまいことできるように修正必要
	std::map<std::string, float> _debugLogList {};

private:
	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()

// 点とOBBとの最近接点を求める
inline void PointToBox(const Math::Vector2& point, const Math::Vector2& obbCenterPos, const Math::Vector2& obbHalfSize, const Math::Matrix& obbMat, Math::Vector2& outNearestPos)
{
	// ※参考:[書籍]「ゲームプログラミングのためのリアルタイム衝突判定」
	Math::Vector2 d = point - obbCenterPos;
	// ボックスの中心における結果から開始、そのから段階的に進める。
	outNearestPos = obbCenterPos;
	// 各OBBの軸に対して
	for (int i = 0; i < 2; i++)
	{
		// dをその軸に投影して
		// ボックスの中心からdの軸に沿った距離を得る
		float dist = d.Dot((Math::Vector2&)obbMat.m[i]);
		// ボックスの範囲よりも距離が大きい場合、ボックスまでクランプ
		if (dist > (&obbHalfSize.x)[i]) dist = (&obbHalfSize.x)[i];
		if (dist < -(&obbHalfSize.x)[i]) dist = -(&obbHalfSize.x)[i];
		// ワールド座標を得るためにその距離だけ軸に沿って進める
		outNearestPos += dist * (Math::Vector2&)obbMat.m[i];
	}

}
