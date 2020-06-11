#pragma once

//========================
// �I�u�W�F�N�g��{�N���X
//========================
class ObjectBase
{
public:
	virtual ~ObjectBase() {}

	//������
	virtual void Init() {}
	//�X�V����
	virtual void Update() {}
	//�X�V�㏈��
	virtual void LateUpdate() {}
	//3D�`��
	virtual void Draw3D() {}
	//2D�`��
	virtual void Draw2D() {}
	//���
	virtual void Release() {}
	//�\���E��\����؂�ւ�
	virtual void SetActive(bool flg) { isActive = flg; }

	virtual bool HitTest_Circle(const Math::Vector2& pos, float radius, Math::Vector2* hitPos)
	{
		return false;
	}

	//�f�o�b�O�`��
	virtual void DebugDraw() {}

protected:

	//������̍s��
	KdMatrix _matrix;
	//�ړ��s��
	KdMatrix _transMatrix;
	//��]�s��
	KdMatrix _rotMatrix;
	//�g��s��
	KdMatrix _scaleMatrix;

	//���̃I�u�W�F�N�g�̕\���E��\��
	bool isActive = true;
};
