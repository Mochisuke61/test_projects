#pragma once

//ComPtr‚ğÈ—ª
template<class T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

// char•¶š—ñ‚©‚çAWideChar•¶š—ñ‚Ö•ÏŠ·
inline std::wstring ConvertStringToWString(const std::string& str)
{
	int len = str.length();
	std::wstring wStr;
	wStr.resize(len);
	size_t wLen;
	mbstowcs_s(&wLen, &wStr[0], len + 1, str.c_str(), _TRUNCATE);
	return wStr;
}
