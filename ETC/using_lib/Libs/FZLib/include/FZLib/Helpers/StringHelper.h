#pragma once
#ifndef __FZ_LIBRARY_STRING_HELPER__
#define __FZ_LIBRARY_STRING_HELPER__

#ifdef FZLIB_USAGE_DLL
	#ifdef FZLIB_EXPORTS
		#define FZLIB_API __declspec(dllexport)
	#else
		#define FZLIB_API __declspec(dllimport)
	#endif
#else
	#define FZLIB_API
#endif

// Standard include headers
#include <string>

extern "C" {
	namespace FZLib {

		class FZLIB_API StringHelper
		{
		public:
			/**
			 * @brief	std::string�� LPCWSTR�� ��ȯ
			 * @param[in]	str	: ��ȯ��ų �Ķ����
			 * @return	std::wstring	: ��ȯ�� LPCWSTR Ÿ���� wstring
			 */
			static std::wstring StringToWString(const std::string& str);
		};

	} // namespace FZLib
}
#endif