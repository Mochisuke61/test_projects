#pragma once

#include "Character.h"

class Dragon : public Character
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
};