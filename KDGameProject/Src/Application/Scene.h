#pragma once

#include "Objects/Object.h"

class Scene
{
public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	//3D�`�揈��
	void Draw3D();

	//2D�`�揈��
	void Draw2D();

	// GUI����
	void ImGuiUpdate();

	//ImGui�ŕ\������f�o�b�O�f�[�^��ǉ�����
	void AddDebugLog(std::string key, float value);

private:
	//�����o
	//�S�I�u�W�F�N�g���X�g
	std::list<std::shared_ptr<ObjectBase>> _objetList;

	//ImGui�֌W
	//FIXME: float�����g����J�X�f�[�^�Ȃ̂Ńe���v���[�g�ł��܂����Ƃł���悤�ɏC���K�v
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

// �_��OBB�Ƃ̍ŋߐړ_�����߂�
inline void PointToBox(const Math::Vector2& point, const Math::Vector2& obbCenterPos, const Math::Vector2& obbHalfSize, const Math::Matrix& obbMat, Math::Vector2& outNearestPos)
{
	// ���Q�l:[����]�u�Q�[���v���O���~���O�̂��߂̃��A���^�C���Փ˔���v
	Math::Vector2 d = point - obbCenterPos;
	// �{�b�N�X�̒��S�ɂ����錋�ʂ���J�n�A���̂���i�K�I�ɐi�߂�B
	outNearestPos = obbCenterPos;
	// �eOBB�̎��ɑ΂���
	for (int i = 0; i < 2; i++)
	{
		// d�����̎��ɓ��e����
		// �{�b�N�X�̒��S����d�̎��ɉ����������𓾂�
		float dist = d.Dot((Math::Vector2&)obbMat.m[i]);
		// �{�b�N�X�͈̔͂����������傫���ꍇ�A�{�b�N�X�܂ŃN�����v
		if (dist > (&obbHalfSize.x)[i]) dist = (&obbHalfSize.x)[i];
		if (dist < -(&obbHalfSize.x)[i]) dist = -(&obbHalfSize.x)[i];
		// ���[���h���W�𓾂邽�߂ɂ��̋����������ɉ����Đi�߂�
		outNearestPos += dist * (Math::Vector2&)obbMat.m[i];
	}

}
