#include "main.h"

#include "KdInput.h"

bool KdInput::GetKey(int key)
{
	return GetAsyncKeyState(key) & 0x8000;
}

bool KdInput::GetKeyDown(int key)
{
	static bool isFirst = true;
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (isFirst)
		{
			isFirst = false;
			return true;
		}
	}
	else
	{
		isFirst = true;
	}
	return false;
}

bool KdInput::GetKeyUp(int key)
{
	static bool isPut = false;
	if (GetAsyncKeyState(key) & 0x8000)
	{
		isPut = true;
	}
	else
	{
		if (isPut == true)
		{
			isPut = false;
			return true;
		}
		isPut = false;
	}
	return false;
}
