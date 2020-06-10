#include "main.h"
#include "Scene.h"

void Scene::Init()
{
	//FIXME:
	//

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
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
