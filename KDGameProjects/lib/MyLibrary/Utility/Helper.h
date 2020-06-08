#pragma once

//ComPtr���ȗ�
template<class T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

// char�����񂩂�AWideChar������֕ϊ�
inline std::wstring ConvertStringToWString(const std::string& str)
{
	int len = str.length();
	std::wstring wStr;
	wStr.resize(len);
	size_t wLen;
	mbstowcs_s(&wLen, &wStr[0], len + 1, str.c_str(), _TRUNCATE);
	return wStr;
}
