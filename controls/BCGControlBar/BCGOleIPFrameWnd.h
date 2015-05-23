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

#if !defined(AFX_BCGOLEIPFRAMEWND_H__1E1CDCA3_DD9E_11D2_A70E_0090274409AC__INCLUDED_)
#define AFX_BCGOLEIPFRAMEWND_H__1E1CDCA3_DD9E_11D2_A70E_0090274409AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BCGOleIPFrameWnd.h : header file
//

#include "BCGFrameImpl.h"
#include "bcgcontrolbar.h"

class CBCGMenuBar;
class CBCGToolbarMenuButton;
class CBCGToolbarButton;

/////////////////////////////////////////////////////////////////////////////
// CBCGOleIPFrameWnd window

class BCGCONTROLBARDLLEXPORT CBCGOleIPFrameWnd : public COleIPFrameWnd
{
	friend class CBCGMenuBar;
	friend class CToolbarsPage;
	friend class CBCGWorkspace;
	friend class CBCGPopupMenu;

	DECLARE_DYNCREATE(CBCGOleIPFrameWnd)

// Construction
protected:
	CBCGOleIPFrameWnd();           // protected constructor used by dynamic creation

// Attributes
public:
	BOOL IsMenuBarAvailable () const
	{
		return m_Impl.GetMenuBar () != NULL;
	}

	virtual BOOL CanShowMenuBar()
	{
		return TRUE;
	}


	const CBCGMenuBar* GetMenuBar () const
	{
		return m_Impl.GetMenuBar ();
	}

	UINT GetDefaultResId () const
	{
		return m_Impl.m_nIDDefaultResource;
	}

	CBCGPopupMenu*	GetActivePopup () const
	{
		return m_Impl.m_pActivePopupMenu;
	}

protected:
	BOOL			m_bIsTlbCustMode;
	HMENU			m_hmenuWindow;
	CBCGFrameImpl	m_Impl;
	BOOL			m_bContextHelp;

// Operations
public:
	void EnableDocking (DWORD dwDockStyle);
	void DockControlBarLeftOf (CControlBar* pBar, CControlBar* pLeftOf);
	void SetupToolbarMenu (	CMenu& menu,
							const UINT uiViewUserToolbarCmdFirst,
							const UINT uiViewUserToolbarCmdLast)
	{
		m_Impl.SetupToolbarMenu (menu, uiViewUserToolbarCmdFirst, uiViewUserToolbarCmdLast);
	}

protected:

// Implementation:
	void InitUserToobars (LPCTSTR lpszRegEntry, UINT uiUserToolbarFirst, UINT uiUserToolbarLast)
	{
		m_Impl.InitUserToobars (lpszRegEntry, uiUserToolbarFirst, uiUserToolbarLast);
	}

	void LoadUserToolbars ()
	{
		m_Impl.LoadUserToolbars ();
	}

	void SaveUserToolbars ()
	{
		m_Impl.SaveUserToolbars ();
	}

	BOOL IsDockStateValid (const CDockState& state)
	{
		return m_Impl.IsDockStateValid (state);
	}

	CBCGToolBar* GetUserBarByIndex (int iIndex) const
	{
		return m_Impl.GetUserBarByIndex (iIndex);
	}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGOleIPFrameWnd)
	public:
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBCGOleIPFrameWnd();

	BOOL OnSetMenu (HMENU hmenu);
	BOOL ShowPopupMenu (CBCGPopupMenu* pMenuPopup);

public:
	virtual BOOL OnShowPopupMenu (CBCGPopupMenu* /*pMenuPopup*/)
	{
		return TRUE;
	}

	virtual void OnClosePopupMenu (CBCGPopupMenu* pMenuPopup);
	virtual BOOL OnDrawMenuImage (	CDC* /*pDC*/, 
									const CBCGToolbarMenuButton* /*pMenuButton*/, 
									const CRect& /*rectImage*/)
	{
		return FALSE;
	}

	virtual BOOL OnMenuButtonToolHitTest (CBCGToolbarButton* /*pButton*/, TOOLINFO* /*pTI*/)
	{
		return FALSE;
	}

	virtual BOOL GetToolbarButtonToolTipText (CBCGToolbarButton* /*pButton*/, CString& /*strTTText*/)
	{
		return FALSE;
	}

	// Generated message map functions
protected:
	//{{AFX_MSG(CBCGOleIPFrameWnd)
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnClose();
	//}}AFX_MSG
	afx_msg LRESULT OnSetMenu (WPARAM wp, LPARAM);
	afx_msg LRESULT OnToolbarCreateNew(WPARAM,LPARAM);
	afx_msg LRESULT OnToolbarDelete(WPARAM,LPARAM);
	afx_msg void OnContextHelp ();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGOLEIPFRAMEWND_H__1E1CDCA3_DD9E_11D2_A70E_0090274409AC__INCLUDED_)
