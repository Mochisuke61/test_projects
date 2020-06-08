#pragma once

//ComPtrを省略
template<class T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

// char文字列から、WideChar文字列へ変換
inline std::wstring ConvertStringToWString(const std::string& str)
{
	int len = str.length();
	std::wstring wStr;
	wStr.resize(len);
	size_t wLen;
	mbstowcs_s(&wLen, &wStr[0], len + 1, str.c_str(), _TRUNCATE);
	return wStr;
}
