#pragma once

#include "Character.h"

class Dragon : public Character
{
public:
	//‰Šú‰»
	virtual void Init();
	//XVˆ—
	virtual void Update();
	//2D•`‰æ
	virtual void Draw2D();
	//‰ğ•ú
	virtual void Release();
};