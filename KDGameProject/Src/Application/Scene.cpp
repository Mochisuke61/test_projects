#include "main.h"
#include "Scene.h"

void Scene::Init()
{
	//FIXME:
	//

	//�S�I�u�W�F�N�g�̍X�V����
	for (auto object : _objetList)
	{
		object->Init();
	}
}

void Scene::Update()
{
	//�S�I�u�W�F�N�g�̍X�V����
	for (auto object : _objetList)
	{
		object->Update();
	}
}

void Scene::Draw3D()
{
	//�S�I�u�W�F�N�g�̍X�V����
	for (auto object : _objetList)
	{
		object->Draw3D();
	}
}

void Scene::Draw2D()
{
	//�S�I�u�W�F�N�g�̍X�V����
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

	// �f�o�b�O�E�B���h�E
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
