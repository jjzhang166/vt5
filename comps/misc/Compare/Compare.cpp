// Compare.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Compare.h"
#include "Utils.h"

#include "PropPage.h"
#include "\vt5\awin\misc_module.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CCompareApp

BEGIN_MESSAGE_MAP(CCompareApp, CWinApp)
	//{{AFX_MSG_MAP(CCompareApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCompareApp construction

CCompareApp::CCompareApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCompareApp object

CCompareApp theApp;
module	_module( 0 );

/////////////////////////////////////////////////////////////////////////////
// CCompareApp initialization

BOOL CCompareApp::InitInstance()
{
	_module.init( m_hInstance );
	::AfxEnableControlContainer();
	VERIFY(LoadVTClass(this) == true);
	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// Special entry points required for inproc servers

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (NeedComponentInfo(rclsid, riid))
		return GetComponentInfo(ppv);
	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	COleObjectFactory::UpdateRegistryAll();

	CActionRegistrator	ra;
	ra.RegisterActions();

	CCompRegistrator	rp( szPluginPropertyPage );
//	rp.RegisterComponent( szComparePropPageProgID_4Reg );
//	rp.RegisterComponent( szModePropPageProgID_4Reg );
	rp.RegisterComponent( "Compare.CmpPage" );

	return S_OK;
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	COleObjectFactory::UpdateRegistryAll();

	CActionRegistrator	ra;
	ra.RegisterActions( false );

	CCompRegistrator	rp( szPluginPropertyPage );
	rp.UnRegisterComponent( szComparePropPageProgID_4Reg );
	rp.UnRegisterComponent( "Compare.CmpPage" );

	return S_OK;
}

