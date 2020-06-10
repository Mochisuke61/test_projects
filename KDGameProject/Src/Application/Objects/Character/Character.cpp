#include "main.h"

#include "Objects/Object.h"

#include "Character.h"

void Character::Init()
{
	_texture.Load("dragon.png");
	_matrix.CreateTranslation(0, 0,0);
	_matrix.CreateRotationZ(45);
}

void Character::Update()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		_matrix.Move(1, 0, 0);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		_matrix.Move(-1, 0, 0);
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		_matrix.Move(0, 1, 0);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		_matrix.Move(0, -1, 0);
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		_matrix.RotateZ(10);
	}
}

void Character::Draw2D()
{
	SHADER.m_spriteShader.DrawTex(&_texture,_matrix);
}

void Character::Release()
{
	_texture.Release();
}
