#include "main.h"
#include "Scene.h"
#include "Objects/Character/Character.h"

void Scene::Init()
{
	//FIXME: ここはJsonからうまく取得できるように変更しておきたい
	//オブジェクトを追加する処理
	std::shared_ptr<Character> dragon = std::make_shared<Character>();
	_objetList.push_back(dragon);

	//全オブジェクトの更新処理
	for (auto object : _objetList)
	{
		object->Init();
	}
}

void Scene::Update()
{
	//全オブジェクトの更新処理
	for (auto object : _objetList)
	{
		object->Update();
	}
}

void Scene::Draw3D()
{
	//全オブジェクトの更新処理
	for (auto object : _objetList)
	{
		object->Draw3D();
	}
}

void Scene::Draw2D()
{
	//全オブジェクトの更新処理
	for (auto object : _objetList)
	{
		object->Draw2D();
	}
}


void Scene::Release()
{
	for (auto object : _objetList)
	{
		object->Release();
	}
}

void Scene::ImGuiUpdate()
{
	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	ImGui::Begin("Debug Window");
	ImGui::Text("FPS : %d", APP.m_fps);

	//デバッグ表示
	for (const auto& [key,value] : _debugLogList)
	{
		ImGui::Text("%s : %f",key.c_str(),value);
	}
	ImGui::End();
}

void Scene::AddDebugLog(std::string key, float value)
{
	_debugLogList.insert(std::make_pair(key,value));
}
