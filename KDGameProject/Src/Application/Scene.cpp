#include "main.h"
#include "Scene.h"
#include "Objects/Character/Character.h"

void Scene::Init()
{
	//FIXME: ������Json���炤�܂��擾�ł���悤�ɕύX���Ă�������
	//�I�u�W�F�N�g��ǉ����鏈��
	std::shared_ptr<Character> dragon = std::make_shared<Character>();
	_objetList.push_back(dragon);

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
	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// �f�o�b�O�E�B���h�E
	ImGui::Begin("Debug Window");
	ImGui::Text("FPS : %d", APP.m_fps);

	//�f�o�b�O�\��
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
