#pragma once

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

private:
	KdTexture _texture;
};