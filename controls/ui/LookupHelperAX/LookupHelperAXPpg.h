#if !defined(AFX_LOOKUPHELPERAXPPG_H__2E0A4E91_4590_47B0_801C_A426BEA6D976__INCLUDED_)
#define AFX_LOOKUPHELPERAXPPG_H__2E0A4E91_4590_47B0_801C_A426BEA6D976__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// LookupHelperAXPpg.h : Declaration of the CLookupHelperAXPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CLookupHelperAXPropPage : See LookupHelperAXPpg.cpp.cpp for implementation.

class CLookupHelperAXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLookupHelperAXPropPage)
	GUARD_DECLARE_OLECREATE_CTRL(CLookupHelperAXPropPage)

// Constructor
public:
	CLookupHelperAXPropPage();

// Dialog Data
	//{{AFX_DATA(CLookupHelperAXPropPage)
	enum { IDD = IDD_PROPPAGE_LOOKUPHELPERAX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CLookupHelperAXPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOOKUPHELPERAXPPG_H__2E0A4E91_4590_47B0_801C_A426BEA6D976__INCLUDED)
