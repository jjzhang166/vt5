// ImageDoc.h : main header file for the IMAGEDOC DLL
//

#if !defined(AFX_IMAGEDOC_H__2D8A463B_4323_11D3_A60F_0090275995FE__INCLUDED_)
#define AFX_IMAGEDOC_H__2D8A463B_4323_11D3_A60F_0090275995FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern int nInterpolationMethod; //����� ������������ ��� ����������
// 0 - �� ��������� �������, 1 - ����������
// -1 - ��������� �������� �� shell.data
extern int nMaskInterpolationMethod; //����� ������������ ����� ��� ����������
// 0 - ����������, 1 - ��� ������ 90 � 45 ��������
// �������� ������ ��� nInterpolationMethod=1

/////////////////////////////////////////////////////////////////////////////
// CImageDocApp
// See ImageDoc.cpp for the implementation of this class
//

class CImageDocApp : public CWinApp
{
public:
	CImageDocApp();
	~CImageDocApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageDocApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CImageDocApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEDOC_H__2D8A463B_4323_11D3_A60F_0090275995FE__INCLUDED_)
