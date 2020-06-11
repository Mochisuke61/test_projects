#include "main.h"

#include "Dragon.h"

void Dragon::Init()
{
	_texture.Load("dragon.png");
	_rotMatrix.CreateRotationZ(45);
	_transMatrix.CreateTranslation(0, 0, 0);
}

void Dragon::Update()
{
	//
	KdVec2 moveVec = { 0,0 };
	if (Input.GetKey(VK_RIGHT))
	{
		moveVec += KdVec2(1, 0);
	}
	if (Input.GetKey(VK_LEFT))
	{
		moveVec += KdVec2(-1, 0);
	}
	if (Input.GetKey(VK_UP))
	{
		moveVec += KdVec2(0, 1);
	}
	if (Input.GetKey(VK_DOWN))
	{
		moveVec += KdVec2(0, -1);
	}

	//回転
	float angle = 0;
	if (Input.GetKey(VK_SPACE))
	{
		angle += 10.0f;
	}

	//========================================
	// 行列操作
	//========================================

	//ベクトルで移動
	_transMatrix.Move((KdVec2)(moveVec.Normalize() * _moveSpeed));

	//回転
	_rotMatrix.RotateZ(angle);

	//行列合成
	_matrix = _rotMatrix * _transMatrix;
}

void Dragon::Draw2D()
{
	SHADER.m_spriteShader.DrawTex(&_texture, _matrix);
}

void Dragon::Release()
{
	_texture.Release();
}
