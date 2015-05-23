/******************************************************************************
Module:  APIHook.h
Notices: Copyright (c) 2000 Jeffrey Richter
******************************************************************************/


#pragma once


///////////////////////////////////////////////////////////////////////////////


class CAPIHook {
public:
	// Hook a function in all modules
  CAPIHook(PSTR pszCalleeModName, PSTR pszFuncName, PROC pfnHook, 
		BOOL fExcludeAPIHookMod);

	//CAPIHook(PSTR pszCalleeModName, PSTR pszFuncName, PROC pfnHook, 
 //  BOOL fExcludeAPIHookMod, PROC pfnOrig);

   // Unhook a function from all modules
   ~CAPIHook();

   // Returns the original address of the hooked function
   operator PROC() { return(m_pfnOrig); }


public:
   // Calls the real GetProcAddress 
   static FARPROC WINAPI GetProcAddressRaw(HMODULE hmod, PCSTR pszProcName);

   static CAPIHook* sm_pHead;    // Address of first object
   CAPIHook* m_pNext;            // Address of next  object
private:

   PCSTR m_pszCalleeModName;     // Module containing the function (ANSI)
   PCSTR m_pszFuncName;          // Function name in callee (ANSI)
   PROC  m_pfnOrig;              // Original function address in callee
   PROC  m_pfnHook;              // Hook function address
   BOOL  m_fExcludeAPIHookMod;   // Hook module w/CAPIHook implementation?

public:
   // Replaces a symbol's address in a module's import section
   static void WINAPI ReplaceIATEntryInAllMods(PCSTR pszCalleeModName, 
      PROC pfnOrig, PROC pfnHook, BOOL fExcludeAPIHookMod);

   // Replaces a symbol's address in all module's import sections
   static void WINAPI ReplaceIATEntryInOneMod(PCSTR pszCalleeModName, 
      PROC pfnOrig, PROC pfnHook, HMODULE hmodCaller);

//private:
   // Used when a DLL is newly loaded after hooking a function
   static void    WINAPI FixupNewlyLoadedModule(HMODULE hmod, DWORD dwFlags);

   // Used to trap when DLLs are newly loaded
   static HMODULE WINAPI LoadLibraryA(PCSTR  pszModulePath);
   static HMODULE WINAPI LoadLibraryW(PCWSTR pszModulePath);
   static HMODULE WINAPI LoadLibraryExA(PCSTR  pszModulePath, 
      HANDLE hFile, DWORD dwFlags);
   static HMODULE WINAPI LoadLibraryExW(PCWSTR pszModulePath, 
      HANDLE hFile, DWORD dwFlags);

   // Returns address of replacement function if hooked function is requested
   static FARPROC WINAPI GetProcAddress(HMODULE hmod, PCSTR pszProcName);

private:
   // Instantiates hooks on these functions
   static CAPIHook sm_LoadLibraryA;
   static CAPIHook sm_LoadLibraryW;
   static CAPIHook sm_LoadLibraryExA;
   static CAPIHook sm_LoadLibraryExW;
   static CAPIHook sm_GetProcAddress;
};

#define HOOKMACRO(DLL, FUNC_RET_TYPE, FUNC_NAME, FUNC_PARAMS) \
	typedef FUNC_RET_TYPE FN_##FUNC_NAME FUNC_PARAMS; \
	FN_##FUNC_NAME _##FUNC_NAME; \
	typedef FN_##FUNC_NAME* PFN_##FUNC_NAME; \
	CAPIHook g_##FUNC_NAME(DLL, #FUNC_NAME, (PROC)_##FUNC_NAME, FALSE); \
	FUNC_RET_TYPE _##FUNC_NAME FUNC_PARAMS

