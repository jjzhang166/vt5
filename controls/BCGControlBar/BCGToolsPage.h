//*******************************************************************************
// COPYRIGHT NOTES
// ---------------
// This source code is a part of BCGControlBar library.
// You may use, compile or redistribute it as part of your application 
// for free. You cannot redistribute it as a part of a software development 
// library without the agreement of the author. If the sources are 
// distributed along with the application, you should leave the original 
// copyright notes in the source code without any changes.
// This code can be used WITHOUT ANY WARRANTIES on your own risk.
// 
// For the latest updates to this library, check my site:
// http://welcome.to/bcgsoft
// 
// Stas Levin <bcgsoft@yahoo.com>
//*******************************************************************************

#if !defined(AFX_BCGTOOLSPAGE_H__80D80813_B943_11D3_A713_009027900694__INCLUDED_)
#define AFX_BCGTOOLSPAGE_H__80D80813_B943_11D3_A713_009027900694__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BCGToolsPage.h : header file
//

#include "BCGEditListBox.h"

class CBCGToolbarCustomize;
class CBCGToolsPage;
class CBCGUserTool;

class CToolsList : public CBCGEditListBox
{
public:
	CToolsList(CBCGToolsPage* pParent) :
		m_pParent (pParent) {}
		
	virtual void OnSelectionChanged ();
	virtual BOOL OnBeforeRemoveItem (int iItem);
	virtual void OnAfterAddItem (int iItem);
	virtual void OnAfterRenameItem (int iItem);
	virtual void OnAfterMoveItemUp (int iItem);
	virtual void OnAfterMoveItemDown (int iItem);

	CBCGToolsPage* m_pParent;
};

/////////////////////////////////////////////////////////////////////////////
// CBCGToolsPage dialog

class CBCGToolsPage : public CPropertyPage
{
	friend class CToolsList;

// Construction
public:
	CBCGToolsPage();
	~CBCGToolsPage();

// Dialog Data
	//{{AFX_DATA(CBCGToolsPage)
	enum { IDD = IDD_BCGBARRES_PROPPAGE7 };
	CEdit	m_wndArgumentsEdit;
	CEdit	m_wndInitialDirEdit;
	CEdit	m_wndCommandEdit;
	CButton	m_wndBrowseBtn;
	CToolsList	m_wndToolsList;
	CString	m_strCommand;
	CString	m_strArguments;
	CString	m_strInitialDirectory;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBCGToolsPage)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CBCGToolsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnBcgbarresBrowseCommand();
	afx_msg void OnUpdateTool();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CBCGUserTool* CreateNewTool ();
	void EnableControls ();

	CBCGUserTool*			m_pSelTool;
	CBCGToolbarCustomize*	m_pParentSheet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGTOOLSPAGE_H__80D80813_B943_11D3_A713_009027900694__INCLUDED_)
