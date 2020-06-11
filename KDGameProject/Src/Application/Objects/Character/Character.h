#pragma once

#include "Objects/Object.h"

//=================================================
// �L�����N�^�[�I�u�W�F�N�g
// �E�L�����N�^�[���쐬����Ƃ��̊��I�u�W�F�N�g
//=================================================
class Character : public ObjectBase
{
public:
	//������
	virtual void Init();
	//�X�V����
	virtual void Update();
	//2D�`��
	virtual void Draw2D();
	//���
	virtual void Release();

protected:
	//�L�����N�^�[�̉摜
	KdTexture _texture;

	//�L�����N�^�[�̈ړ����x
	float _moveSpeed = 5.0f;
};