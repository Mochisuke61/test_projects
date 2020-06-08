#pragma once

class Object : public std::enable_shared_from_this<Object>
{
public:
	virtual ~Object() {}
private:
	//更新処理
	virtual void Update() {}
	//描画前処理
	virtual void Draw() {}
public:
	//更新処理
	virtual void UpdateObject();
	//描画処理
	virtual void DrawObject();
};
