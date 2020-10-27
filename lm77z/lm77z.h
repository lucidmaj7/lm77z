#pragma once

#include <windef.h>

#ifdef _WIN64
#define kDllName "7z64.dll"
#else
#define kDllName "7z.dll"
#endif

#ifdef __cplusplus
EXTERN_C
{
#endif

#ifndef LM77Z_LIB
#ifdef LM77Z_EXPORTS
#define LM77Z_API __declspec(dllexport)
#else
#define LM77Z_API __declspec(dllimport)
#endif // _LM77ZLIB_BUILD
#else
#define LM77Z_API
#endif
	//
	int LM77Z_API LM77Z_Archive_Load7z(const PWCHAR pszArchiveFilePath, const PWCHAR * pPathArr, DWORD dwPathLen, DWORD dwPathCount, LPCTSTR lp7zDllPath , BOOL isUTF8);
	int LM77Z_API LM77Z_Archive(const PWCHAR pszArchiveFilePath, const PWCHAR* pPathArr, DWORD dwPathLen, DWORD dwPathCount, BOOL isUTF8);
	int LM77Z_API LM77Z_eXtract(const PWCHAR pszArchiveFilePath, const PWCHAR szExtractPath);
#ifdef __cplusplus
}
#endif
