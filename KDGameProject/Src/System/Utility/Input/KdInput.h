#pragma once

//===========================================
// ���͊֌W�𐧌䂷��N���X
// ����̂��߂�Kd�Ə����Ă���܂����A
// �w�Z�̃��C�u�����ł͂���܂���
//===========================================
class KdInput
{
public:
	//�L�[���͂��擾(�����Ă���Ԃ�����)
	bool GetKey(int key);

	//�L�[���͂��擾(�������u�Ԃ���)
	bool GetKeyDown(int key);

	//�L�[���͂��擾(�������㗣�����u�Ԃ���)
	bool GetKeyUp(int key);

private:
	KdInput(){}

public:
	static KdInput& GetInstance()
	{
		static KdInput instance;
		return instance;
	}
};

#define Input KdInput::GetInstance()