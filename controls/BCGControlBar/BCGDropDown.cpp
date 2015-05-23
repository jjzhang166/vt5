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

// BCGDropDown.cpp : implementation file
//

#include "stdafx.h"
#include <afxpriv.h>
#include "mmsystem.h"
#include "BCGDropDown.h"
#include "globals.h"
#include "BCGToolbarMenuButton.h"
#include "BCGMDIFrameWnd.h"
#include "BCGFrameWnd.h"
#include "BCGMenuBar.h"
#include "bcgsound.h"
#include "BCGToolbarMenuButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static const UINT uiShowBarTimerId = 1;
static const UINT uiShowBarDelay = 500;	// ms
static const int nArrowSize = 7;

IMPLEMENT_SERIAL(CBCGDropDownToolBar, CBCGToolBar, 1)

extern CObList	gAllToolbars;

BOOL CBCGDropDownToolBar::OnSendCommand(const CBCGToolbarButton* pButton)
{
	ASSERT_VALID (pButton);
	
	if ((pButton->m_nStyle & TBBS_DISABLED) != 0 ||
		pButton->m_nID < 0 || pButton->m_nID == (UINT)-1)
	{
		return FALSE;
	}
	
	CBCGDropDownFrame* pParent = (CBCGDropDownFrame*)GetParent();
	ASSERT_KINDOF(CBCGDropDownFrame, pParent);
	
	pParent->m_pParentBtn->SetDefaultCommand (pButton->m_nID);
	
	//----------------------------------
	// Send command to the parent frame:
	//----------------------------------
	CFrameWnd* pParentFrame = GetParentFrame ();
	ASSERT_VALID (pParentFrame);
	
	GetOwner()->PostMessage(WM_COMMAND, pButton->m_nID);
	pParentFrame->DestroyWindow ();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CBCGDropDownToolBar, CBCGToolBar)
//{{AFX_MSG_MAP(CBCGDropDownToolBar)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CBCGDropDownToolBar::OnMouseMove(UINT /*nFlags*/, CPoint point)
{
	if (m_ptLastMouse != CPoint (-1, -1) &&
		abs (m_ptLastMouse.x - point.x) < 1 &&
		abs (m_ptLastMouse.y - point.y) < 1)
	{
		m_ptLastMouse = point;
		return;
	}
	
	m_ptLastMouse = point;
	
	int iPrevHighlighted = m_iHighlighted;
	m_iHighlighted = HitTest (point);
	
	CBCGToolbarButton* pButton = m_iHighlighted == -1 ?
		NULL : GetButton (m_iHighlighted);
	if (pButton != NULL &&
		(pButton->m_nStyle & TBBS_SEPARATOR || 
		(pButton->m_nStyle & TBBS_DISABLED && !AllowSelectDisabled ())))
	{
		m_iHighlighted = -1;
	}
	
	if (!m_bTracked)
	{
		m_bTracked = TRUE;
		
		TRACKMOUSEEVENT trackmouseevent;
		trackmouseevent.cbSize = sizeof(trackmouseevent);
		trackmouseevent.dwFlags = TME_LEAVE;
		trackmouseevent.hwndTrack = GetSafeHwnd();
		trackmouseevent.dwHoverTime = HOVER_DEFAULT;
		_TrackMouseEvent (&trackmouseevent);	
	}
	
	if (iPrevHighlighted != m_iHighlighted)
	{
		BOOL bNeedUpdate = FALSE;
		
		m_iButtonCapture = m_iHighlighted;
		if (iPrevHighlighted != -1)
		{
			CBCGToolbarButton* pTBBCapt = GetButton (iPrevHighlighted);
			ASSERT (pTBBCapt != NULL);
			ASSERT (!(pTBBCapt->m_nStyle & TBBS_SEPARATOR));
			
			UINT nNewStyle = (pTBBCapt->m_nStyle & ~TBBS_PRESSED);
			
			if (nNewStyle != pTBBCapt->m_nStyle)
			{
				SetButtonStyle (iPrevHighlighted, nNewStyle);
			}
			
		}
		
		if (m_iButtonCapture != -1)
		{
			CBCGToolbarButton* pTBBCapt = GetButton (m_iButtonCapture);
			ASSERT (pTBBCapt != NULL);
			ASSERT (!(pTBBCapt->m_nStyle & TBBS_SEPARATOR));
			
			UINT nNewStyle = (pTBBCapt->m_nStyle & ~TBBS_PRESSED);
			if (m_iHighlighted == m_iButtonCapture)
			{
				nNewStyle |= TBBS_PRESSED;
			}
			
			if (nNewStyle != pTBBCapt->m_nStyle)
			{
				SetButtonStyle (m_iButtonCapture, nNewStyle);
				bNeedUpdate = TRUE;
			}
		}
		
		if ((m_iButtonCapture == -1 || 
			iPrevHighlighted == m_iButtonCapture) &&
			iPrevHighlighted != -1)
		{
			InvalidateButton (iPrevHighlighted);
			bNeedUpdate = TRUE;
		}
		
		if ((m_iButtonCapture == -1 || 
			m_iHighlighted == m_iButtonCapture) &&
			m_iHighlighted != -1)
		{
			InvalidateButton (m_iHighlighted);
			bNeedUpdate = TRUE;
		}
		
		if (bNeedUpdate)
		{
			UpdateWindow ();
		}
		
		if (m_iHighlighted != -1 && 
			(m_iHighlighted == m_iButtonCapture || m_iButtonCapture == -1))
		{
			ASSERT (pButton != NULL);
			ShowCommandMessageString (pButton->m_nID);
		}
		else if (m_iButtonCapture == -1 && m_hookMouseHelp == NULL)
		{
			GetOwner()->SendMessage (WM_SETMESSAGESTRING, AFX_IDS_IDLEMESSAGE);
		}
		
		OnChangeHot (m_iHighlighted);
	}
}
//****************************************************************************************
void CBCGDropDownToolBar::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CRect rectClient;
	GetClientRect (&rectClient);
	
	if (!m_bCustomizeMode && 
		!rectClient.PtInRect (point))
	{
		CFrameWnd* pParentFrame = GetParentFrame ();
		ASSERT_VALID (pParentFrame);
		
		pParentFrame->DestroyWindow ();
		return;
	}
	
	if (!m_bCustomizeMode && m_iHighlighted >= 0)
	{
		m_iButtonCapture = m_iHighlighted;
	}
	
	CBCGToolBar::OnLButtonUp (nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
// CBCGDropDownFrame

static const int iBorderSize = 2;

CString	CBCGDropDownFrame::m_strClassName;

IMPLEMENT_SERIAL(CBCGDropDownFrame, CMiniFrameWnd, VERSIONABLE_SCHEMA | 1)

CBCGDropDownFrame::CBCGDropDownFrame()
{
	m_x = m_y = 0;
	m_pParentBtn = NULL;
	m_bAutoDestroyParent = TRUE;
	m_bAutoDestroy = TRUE;
	m_uiResId = 0;
}
//****************************************************************************************
CBCGDropDownFrame::~CBCGDropDownFrame()
{
	if (m_bAutoDestroy)
	{
		m_wndToolBar.DestroyWindow();
	}
}

BEGIN_MESSAGE_MAP(CBCGDropDownFrame, CMiniFrameWnd)
//{{AFX_MSG_MAP(CBCGDropDownFrame)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_MOUSEACTIVATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_ACTIVATEAPP()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBCGDropDownFrame message handlers

BOOL CBCGDropDownFrame::Create (CWnd* pWndParent, int x, int y, UINT uiResId)
{
	ASSERT (uiResId != 0);
	ASSERT (pWndParent != NULL);
	
	BCGPlaySystemSound (BCGSOUND_MENU_POPUP);
	
	if (m_strClassName.IsEmpty ())
	{
		m_strClassName = ::AfxRegisterWndClass (
			CS_SAVEBITS,
			::LoadCursor(NULL, IDC_ARROW),
			(HBRUSH)(COLOR_BTNFACE + 1), NULL);
	}

	m_uiResId = uiResId;

	if (x == -1 && y == -1)	// Undefined position
	{
		if (pWndParent != NULL)
		{
			CRect rectParent;
			pWndParent->GetClientRect (&rectParent);
			pWndParent->ClientToScreen (&rectParent);
			
			m_x = rectParent.left + 5;
			m_y = rectParent.top + 5;
		}
		else
		{
			m_x = 0;
			m_y = 0;
		}
	}
	else
	{
		m_x = x;
		m_y = y;
	}
	
	DWORD dwStyle = WS_POPUP;
	
	CRect rect (x, y, x, y);
	BOOL bCreated = CMiniFrameWnd::CreateEx (
		0,
		m_strClassName, m_strCaption,
		dwStyle, rect,
		pWndParent->GetOwner () == NULL ? 
			pWndParent : pWndParent->GetOwner ());
	if (!bCreated)
	{
		return FALSE;
	}
	
	ShowWindow (SW_SHOWNOACTIVATE);
	return TRUE;
}
//****************************************************************************************
int CBCGDropDownFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMiniFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	int iRes = 0;

	CBCGToolBar* pParentBar = m_pParentBtn == NULL ? NULL :
	DYNAMIC_DOWNCAST (CBCGToolBar, m_pParentBtn->m_pWndParent);
	
	BOOL bHorz = (pParentBar->m_dwStyle & CBRS_ORIENT_HORZ) != 0;
	DWORD style = bHorz? CBRS_ORIENT_VERT : CBRS_ORIENT_HORZ;
	
	HINSTANCE hInstRes = AfxFindResourceHandle (MAKEINTRESOURCE (m_uiResId), RT_TOOLBAR);
	ASSERT (hInstRes != NULL);

	HINSTANCE hInstOld = AfxGetResourceHandle ();
	AfxSetResourceHandle (hInstRes);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | style, 
		CRect(1, 1, 1, 1), AFX_IDW_TOOLBAR+39) ||
		!m_wndToolBar.LoadToolBar (m_uiResId))
	{
		TRACE(_T("Can't create toolbar bar\n"));
		iRes = -1;
	}
	else
	{
		m_wndToolBar.m_dwStyle &= ~CBRS_GRIPPER;
		m_wndToolBar.SetOwner (GetParent ());
		
		RecalcLayout ();
		::ReleaseCapture();
		m_wndToolBar.SetCapture ();
	}

	AfxSetResourceHandle (hInstOld);
	return iRes;
}
//****************************************************************************************
void CBCGDropDownFrame::OnSize(UINT nType, int cx, int cy) 
{
	CMiniFrameWnd::OnSize(nType, cx, cy);
	
	if (m_wndToolBar.GetSafeHwnd () != NULL)
	{
		m_wndToolBar.SetWindowPos (NULL, iBorderSize, iBorderSize, 
			cx - iBorderSize * 2, cy - iBorderSize * 2, 
			SWP_NOZORDER | SWP_NOACTIVATE);
	}
}
//****************************************************************************************
void CBCGDropDownFrame::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rectClient;	// Client area rectangle
	GetClientRect (&rectClient);
	
	dc.Draw3dRect (rectClient, 
		globalData.clrBtnLight, 
		globalData.clrBtnDkShadow);
	rectClient.DeflateRect (1, 1);
	dc.Draw3dRect (rectClient, 
		globalData.clrBtnHilite,
		globalData.clrBtnShadow);
}
//****************************************************************************************
int CBCGDropDownFrame::OnMouseActivate(CWnd* /*pDesktopWnd*/, UINT /*nHitTest*/, UINT /*message*/) 
{
	return MA_NOACTIVATE;
}
//****************************************************************************************
void CBCGDropDownFrame::RecalcLayout (BOOL /*bNotify*/) 
{
#ifdef _DEBUG
	if (m_pParentBtn != NULL)
	{
		ASSERT_VALID (m_pParentBtn);
		ASSERT (m_pParentBtn->m_pPopupMenu == this);
	}
#endif // _DEBUG
	
	if (!::IsWindow (m_hWnd) ||
		!::IsWindow (m_wndToolBar.m_hWnd))
	{
		return;
	}
	
	CBCGToolBar* pParentBar = m_pParentBtn == NULL ? NULL :
	DYNAMIC_DOWNCAST (CBCGToolBar, m_pParentBtn->m_pWndParent);
	
	BOOL bHorz = (pParentBar->m_dwStyle & CBRS_ORIENT_HORZ) != 0;
	
	CSize size = m_wndToolBar.CalcSize(bHorz);
	size.cx += iBorderSize * 3;
	size.cy += iBorderSize * 3;
	
	//---------------------------------------------
	// Adjust the menu position by the screen size:
	//---------------------------------------------
	if (m_x + size.cx > ::GetSystemMetrics (SM_CXFULLSCREEN))
	{
		//-----------------------------------------------------
		// Menu can't be overlapped with the parent popup menu!
		//-----------------------------------------------------
		CBCGToolBar* pParentBar = m_pParentBtn == NULL ? NULL :
	DYNAMIC_DOWNCAST (CBCGToolBar, m_pParentBtn->m_pWndParent);
	
	if (pParentBar != NULL && 
		(pParentBar->m_dwStyle & CBRS_ORIENT_HORZ) == 0)
	{
		//------------------------------------------------
		// Parent menu bar is docked vertical, place menu 
		// in the left or right side of the parent frame:
		//------------------------------------------------
		CRect rectParent;
		pParentBar->GetWindowRect (rectParent);
		
		m_x = rectParent.left - size.cx;
	}
	else
	{
		m_x = ::GetSystemMetrics (SM_CXFULLSCREEN) - size.cx - 1;
	}
	}
	
	if (m_y + size.cy > ::GetSystemMetrics (SM_CYFULLSCREEN))
	{
		m_y -= size.cy;
		
		if (m_pParentBtn != NULL)
		{
			m_y -= m_pParentBtn->m_rect.Height () + 4;
		}
		else if (m_y < 0)
		{
			m_y = 0;
		}
	}
	
	SetWindowPos (NULL, m_x, m_y, size.cx, size.cy,
		SWP_NOZORDER | SWP_NOACTIVATE);
}
//****************************************************************************************
void CBCGDropDownFrame::OnDestroy() 
{
	if (m_pParentBtn != NULL)
	{
		ASSERT (m_pParentBtn->m_pPopupMenu == this);
		
		m_pParentBtn->m_pPopupMenu = NULL;
		m_pParentBtn->m_nStyle = m_pParentBtn->m_nStyle & ~TBBS_PRESSED;
		
		CBCGToolBar* pparentBar = DYNAMIC_DOWNCAST(CBCGToolBar, m_pParentBtn->m_pWndParent);
		if (pparentBar)
		{
			CPoint point;
			::GetCursorPos(&point);
			
			pparentBar->ScreenToClient(&point);
			pparentBar->SendMessage(WM_LBUTTONUP, NULL, MAKELONG(point.x, point.y));
		}
	}
	
	CMiniFrameWnd::OnDestroy();
}
//****************************************************************************************
void CBCGDropDownFrame::PostNcDestroy() 
{
	if (m_pParentBtn != NULL)
	{
		m_pParentBtn->OnCancelMode ();
	}
	
	CMiniFrameWnd::PostNcDestroy();
}
//****************************************************************************************
void CBCGDropDownFrame::SaveState ()
{
	if (!CBCGToolBar::IsCustomizeMode ())
	{
		return;
	}
	
	if (m_pParentBtn == NULL)
	{
		return;
	}
}
//****************************************************************************************
void CBCGDropDownFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	ASSERT_VALID (this);
	
	CMiniFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
//****************************************************************************************
CBCGDropDownFrame* CBCGDropDownFrame::GetParentPopupMenu () const
{
	if (m_pParentBtn == NULL)
	{
		return NULL;
	}
	
	CBCGPopupMenuBar* pParentBar = 
		DYNAMIC_DOWNCAST (CBCGPopupMenuBar, m_pParentBtn->m_pWndParent);
	if (pParentBar != NULL)
	{
		CBCGDropDownFrame* pParentMenu =
			DYNAMIC_DOWNCAST (CBCGDropDownFrame, pParentBar->GetParentFrame ());
		ASSERT_VALID (pParentMenu);
		
		return pParentMenu;
	}
	else
	{
		return NULL;
	}
}
//****************************************************************************************
CBCGMenuBar* CBCGDropDownFrame::GetParentMenuBar () const
{
	if (m_pParentBtn == NULL)
	{
		return NULL;
	}
	
	CBCGMenuBar* pParentBar = 
		DYNAMIC_DOWNCAST (CBCGMenuBar, m_pParentBtn->m_pWndParent);
	return pParentBar;
}
//****************************************************************************************
BOOL CBCGDropDownFrame::OnEraseBkgnd(CDC* pDC) 
{
	CRect rectClient;	// Client area rectangle
	GetClientRect (&rectClient);
	
	pDC->FillSolidRect (rectClient, globalData.clrBtnFace);
	return TRUE;
}
//************************************************************************************
#if _MSC_VER >= 1300
	void CBCGDropDownFrame::OnActivateApp(BOOL bActive, DWORD /*hTask*/) 
#else
	void CBCGDropDownFrame::OnActivateApp(BOOL bActive, HTASK /*hTask*/) 
#endif
{
	if (!bActive && !CBCGToolBar::IsCustomizeMode ())
	{
		SendMessage (WM_CLOSE);
	}
}

IMPLEMENT_SERIAL(CBCGDropDownToolbarButton, CBCGToolbarButton, VERSIONABLE_SCHEMA | 1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBCGDropDownToolbarButton::CBCGDropDownToolbarButton()
{
	m_pToolBar = NULL;
	m_pPopupMenu = NULL;
	m_uiTimer = 0;
	m_bLocked = TRUE;
	m_iSelectedImage = 0;
}
//*****************************************************************************************
CBCGDropDownToolbarButton::CBCGDropDownToolbarButton (LPCTSTR lpszName, CBCGDropDownToolBar* pToolBar)
{
	ASSERT (lpszName != NULL);
	m_strName = lpszName;

	m_uiTimer = 0;

	ASSERT_VALID (pToolBar);
	m_pToolBar = pToolBar;

	CBCGToolbarButton* pbutton = pToolBar->GetButton (0);
	if (pbutton == NULL)	// Toolbar is empty!
	{
		ASSERT (FALSE);
	}
	else
	{
		CBCGToolbarButton::CopyFrom (*pbutton);
	}

	m_iSelectedImage = 0;
}
//*****************************************************************************************
CBCGDropDownToolbarButton::~CBCGDropDownToolbarButton()
{
}
//****************************************************************************************
void CBCGDropDownToolbarButton::SetDefaultCommand (UINT uiCmd)
{
	ASSERT_VALID (m_pToolBar);

	m_nID = uiCmd;

	//------------------
	// Find image index:
	//------------------
	int iImage = 0;
	m_iSelectedImage = -1;

	for (int i = 0; i < m_pToolBar->GetCount (); i ++)
	{
		CBCGToolbarButton* pButton = m_pToolBar->GetButton (i);
		ASSERT_VALID (pButton);

		if (pButton->m_nStyle & TBBS_SEPARATOR)
		{
			continue;
		}

		if (pButton->m_nID == uiCmd)
		{
			m_iSelectedImage = iImage;
			break;
		}

		iImage ++;
	}

	if (m_iSelectedImage == -1)
	{
		ASSERT (FALSE);
		m_iSelectedImage = 0;
	}
}

//////////////////////////////////////////////////////////////////////
// Overrides:

void CBCGDropDownToolbarButton::CopyFrom (const CBCGToolbarButton& s)
{
	const CBCGDropDownToolbarButton& src = (const CBCGDropDownToolbarButton&) s;

	m_pToolBar = src.m_pToolBar;
	m_strName = src.m_strName;
	m_iSelectedImage = src.m_iSelectedImage;

	m_bDragFromCollection = FALSE;
}
//*****************************************************************************************
void CBCGDropDownToolbarButton::Serialize (CArchive& ar)
{
	CBCGToolbarButton::Serialize (ar);
	
	UINT uiToolbarResID = 0;

	if (ar.IsLoading ())
	{
		m_pToolBar = NULL;

		ar >> uiToolbarResID;
		ar >> m_strName;
		ar >> m_iSelectedImage;

		// Find toolbar with required resource ID:
		for (POSITION pos = gAllToolbars.GetHeadPosition (); pos != NULL;)
		{
			CBCGDropDownToolBar* pToolBar = DYNAMIC_DOWNCAST (CBCGDropDownToolBar,
				gAllToolbars.GetNext (pos));

			if (pToolBar != NULL &&
				CWnd::FromHandlePermanent (pToolBar->m_hWnd) != NULL)
			{
				ASSERT_VALID (pToolBar);
				if (pToolBar->m_uiOriginalResID == uiToolbarResID)
				{
					m_pToolBar = pToolBar;
					break;
				}
			}
		}
	}
	else
	{
		if (m_pToolBar == NULL)
		{
			ASSERT (FALSE);
		}
		else
		{
			ASSERT_VALID (m_pToolBar);
			uiToolbarResID = m_pToolBar->m_uiOriginalResID;
		}

		ar << uiToolbarResID;
		ar << m_strName;
		ar << m_iSelectedImage;
	}
}
//*****************************************************************************************
void CBCGDropDownToolbarButton::OnDraw (CDC* pDC, const CRect& rect, CBCGToolBarImages* /*pImages*/,
										BOOL bHorz, BOOL bCustomizeMode, BOOL bHighlight, BOOL bDrawBorder, BOOL bGrayDisabledButtons)
{
	CRect rectParent = rect;
	rectParent.right -= nArrowSize / 2 + 1;

	if (m_pToolBar != NULL)
	{
		CBCGDrawState ds;
		m_pToolBar->m_ImagesLocked.PrepareDrawImage (ds);

		BOOL bImage = m_bImage;

		m_iImage = m_iSelectedImage;
		m_bImage = TRUE;
		CBCGToolbarButton::OnDraw (pDC, rectParent, 
									&m_pToolBar->m_ImagesLocked, bHorz, bCustomizeMode, bHighlight, 
									FALSE/*bDrawBorder*/, bGrayDisabledButtons);
		m_iImage = -1;
		m_bImage = bImage;
		m_pToolBar->m_ImagesLocked.EndDrawImage (ds);
	}

	int offset = (m_nStyle & TBBS_PRESSED)? 1 : 0;
	int nHalfArrowSize = nArrowSize / 2 + 1;
	
	CPoint triang [] = 
	{
		CPoint( rect.right - nArrowSize + offset - 1, rect.bottom - nHalfArrowSize + offset + 1),
		CPoint (rect.right - nHalfArrowSize + offset + 1, rect.bottom - nHalfArrowSize + offset + 1),
		CPoint (rect.right - nHalfArrowSize + offset + 1, rect.bottom - nArrowSize + offset - 1)
	};
	
	CPen* pOldPen = (CPen*) pDC->SelectStockObject (NULL_PEN);
	ASSERT (pOldPen != NULL);

	CBrush* pOldBrush = (CBrush*) pDC->SelectObject (&globalData.brBlack);
	ASSERT (pOldBrush != NULL);

	pDC->Polygon (triang, 3);

	if (bDrawBorder)
	{
		if (m_pPopupMenu != NULL)
		{
			//-----------------------
			// Pressed in or checked:
			//-----------------------
			if (m_nID != 0 && m_nID != (UINT) -1)
			{
				pDC->Draw3dRect (&rect,
					globalData.clrBtnShadow,
					globalData.clrBtnHilite);
			}
			else
			{
				pDC->Draw3dRect (&rect,
					globalData.clrBtnShadow,
					globalData.clrBtnHilite);
			}
		}
		else if (bHighlight && !(m_nStyle & TBBS_DISABLED) &&
			!(m_nStyle & (TBBS_CHECKED | TBBS_INDETERMINATE)))
		{
			if (m_nStyle & TBBS_PRESSED)
			{
				pDC->Draw3dRect (&rect, globalData.clrBtnShadow,
					globalData.clrBtnHilite);
			}
			else
			{
				pDC->Draw3dRect (&rect, globalData.clrBtnHilite,
					globalData.clrBtnShadow);
				
			}
		}
	}
	
	pDC->SelectObject (pOldPen);
	pDC->SelectObject (pOldBrush);
}

static CBCGDropDownToolbarButton* g_pButtonDown = NULL;

static void CALLBACK EXPORT TimerProc(HWND hWnd, UINT, UINT_PTR, DWORD)
{
	CWnd* pwnd = CWnd::FromHandle (hWnd);
	if (g_pButtonDown != NULL)
	{
		g_pButtonDown->OnClick (pwnd, FALSE);
	}
}
//*****************************************************************************************
BOOL CBCGDropDownToolbarButton::OnClick (CWnd* pWnd, BOOL bDelay)
{
	ASSERT_VALID (pWnd);
	if (m_uiTimer == 0)
	{
		m_uiTimer = m_pWndParent->SetTimer (uiShowBarTimerId, uiShowBarDelay, TimerProc);
		g_pButtonDown = this;
		return CBCGToolbarButton::OnClick (pWnd, bDelay);
	}
	
	m_pWndParent->KillTimer (m_uiTimer);
	m_uiTimer = 0;
	g_pButtonDown = NULL;
	
	CBCGMenuBar* pMenuBar = DYNAMIC_DOWNCAST (CBCGMenuBar, m_pWndParent);
	
	if (m_pPopupMenu != NULL)
	{
		//-----------------------------------------------------
		// Second click to the popup menu item closes the menu:
		//-----------------------------------------------------		
		ASSERT_VALID(m_pPopupMenu);
		
		m_pPopupMenu->m_bAutoDestroyParent = FALSE;
		m_pPopupMenu->DestroyWindow ();
		m_pPopupMenu = NULL;
		
		if (pMenuBar != NULL)
		{
			pMenuBar->SetHot (NULL);
		}
	}
	else
	{
		CBCGPopupMenuBar* pParentMenu =
			DYNAMIC_DOWNCAST (CBCGPopupMenuBar, m_pWndParent);
		if (bDelay && pParentMenu != NULL && !CBCGToolBar::IsCustomizeMode ())
		{
		}
		else
		{
			DropDownToolbar(pWnd);
		}
		
		if (pMenuBar != NULL)
		{
			pMenuBar->SetHot (this);
		}
	}
	
	if (m_pWndParent != NULL)
	{
		m_pWndParent->InvalidateRect (m_rect);
	}
	
	return FALSE;
}
//****************************************************************************************
BOOL CBCGDropDownToolbarButton::OnClickUp()
{
	CBCGMenuBar* pMenuBar = DYNAMIC_DOWNCAST (CBCGMenuBar, m_pWndParent);
	
	if (m_uiTimer)
	{
		m_pWndParent->KillTimer (m_uiTimer);
		m_uiTimer = 0;
		g_pButtonDown = NULL;
		return FALSE;
	}
	
	if (m_pPopupMenu != NULL)
	{
		//-----------------------------------------------------
		// Second click to the popup menu item closes the menu:
		//-----------------------------------------------------		
		ASSERT_VALID(m_pPopupMenu);
		
		m_pPopupMenu->m_bAutoDestroyParent = FALSE;
		m_pPopupMenu->DestroyWindow ();
		m_pPopupMenu = NULL;
		
		if (pMenuBar != NULL)
		{
			pMenuBar->SetHot (NULL);
		}
	}
	
	return TRUE;
}
//****************************************************************************************
void CBCGDropDownToolbarButton::OnChangeParentWnd (CWnd* pWndParent)
{
	m_pWndParent = pWndParent;
	m_bText = FALSE;
	m_strText.Empty ();
	m_bUserButton = FALSE;
}
//****************************************************************************************
void CBCGDropDownToolbarButton::OnCancelMode ()
{
	if (m_pWndParent != NULL && ::IsWindow (m_pWndParent->m_hWnd))
	{
		m_pWndParent->InvalidateRect (m_rect);
		m_pWndParent->UpdateWindow ();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBCGDropDownToolbarButton diagnostics

#ifdef _DEBUG
void CBCGDropDownToolbarButton::AssertValid() const
{
	CObject::AssertValid();
}

//******************************************************************************************
void CBCGDropDownToolbarButton::Dump(CDumpContext& dc) const
{
	CObject::Dump (dc);
}

#endif

//****************************************************************************************
BOOL CBCGDropDownToolbarButton::DropDownToolbar (CWnd* pWnd)
{
	if (m_pToolBar == NULL)
	{
		ASSERT (FALSE);
		return FALSE;
	}

	if (m_pPopupMenu != NULL)
	{
		return FALSE;
	}
	
	if (pWnd == NULL)
	{
		pWnd = m_pWndParent;
	}
	
	ASSERT (pWnd != NULL);
	
	//---------------------------------------------------------------
	// Define a new menu position. Place the menu in the right side
	// of the current menu in the poup menu case or under the current 
	// item by default:
	//---------------------------------------------------------------
	CPoint point;
	
	CBCGToolBar* pParentBar =
		DYNAMIC_DOWNCAST (CBCGToolBar, m_pWndParent);
	
	if (pParentBar != NULL && 
		(pParentBar->m_dwStyle & CBRS_ORIENT_HORZ) == 0)
	{
		//------------------------------------------------
		// Parent menu bar is docked vertical, place menu 
		// in the left or right side of the parent frame:
		//------------------------------------------------
		point = CPoint (m_rect.right + 1, m_rect.top);
		pWnd->ClientToScreen (&point);
	}
	else
	{
		point = CPoint (m_rect.left - 1, m_rect.bottom);
		pWnd->ClientToScreen (&point);
	}
	
	m_pPopupMenu = new CBCGDropDownFrame;
	m_pPopupMenu->m_pParentBtn = this;
	
	return m_pPopupMenu->Create (pWnd, point.x, point.y, 
		m_pToolBar->m_uiOriginalResID);
}
//*********************************************************************************
SIZE CBCGDropDownToolbarButton::OnCalculateSize (CDC* pDC, const CSize& sizeDefault, BOOL bHorz)
{
	if (m_nID == 0 && m_pToolBar != NULL)
	{
		ASSERT_VALID (m_pToolBar);

		CBCGToolbarButton* pButton = m_pToolBar->GetButton (0);
		if (pButton == NULL)	// Toolbar is empty!
		{
			ASSERT (FALSE);
		}
		else
		{
			SetDefaultCommand (pButton->m_nID);
		}
	}

	BOOL bImage = m_bImage;

	m_iImage = m_iSelectedImage;
	m_bImage = TRUE;

	CSize sizeBtn = CBCGToolbarButton::OnCalculateSize (pDC, sizeDefault, bHorz);

	m_iImage = -1;
	m_bImage = bImage;

	sizeBtn.cx += nArrowSize / 2 + 1;

	return sizeBtn;
}
//*************************************************************************************
BOOL CBCGDropDownToolbarButton::ExportToMenuButton (CBCGToolbarMenuButton& menuButton) const
{
	if (m_pToolBar == NULL)
	{
		ASSERT (FALSE);
		return FALSE;
	}

	if (!CBCGToolbarButton::ExportToMenuButton (menuButton))
	{
		return FALSE;
	}

	//------------------------------------
	// Create a popup menu with all items:
	//------------------------------------
	CMenu menu;
	menu.CreatePopupMenu ();

	for (POSITION pos = m_pToolBar->m_Buttons.GetHeadPosition (); pos != NULL;)
	{
		CBCGToolbarButton* pButton = (CBCGToolbarButton*) m_pToolBar->m_Buttons.GetNext (pos);
		ASSERT (pButton != NULL);

		if (pButton->m_nStyle & TBBS_SEPARATOR)
		{
			menu.AppendMenu (MF_SEPARATOR);
		}
		else if (pButton->m_nID != 0 && pButton->m_nID != (UINT) -1)// Ignore sub-menus
		{
			CString strItem = pButton->m_strText;
			if (strItem.IsEmpty ())
			{
				CString strMessage;
				int iOffset;

				if (strMessage.LoadString (pButton->m_nID) &&
					(iOffset = strMessage.Find (_T('\n'))) != -1)
				{
					strItem = strMessage.Mid (iOffset + 1);
				}
			}

			menu.AppendMenu (MF_STRING, pButton->m_nID, strItem);
		}
	}

	menuButton.m_nID = 0;
	menuButton.m_strText = m_strName;
	menuButton.SetImage (-1);
	menuButton.m_bImage = FALSE;
	menuButton.CreateFromMenu (menu);

	menu.DestroyMenu ();
	return TRUE;
}
//*************************************************************************************
int CBCGDropDownToolbarButton::OnDrawOnCustomizeList (CDC* pDC, const CRect& rect, 
										BOOL bSelected)
{
	CString strText = m_strText;
	m_strText = m_strName;

	int iResult = CBCGToolbarButton::OnDrawOnCustomizeList (
					pDC, rect, bSelected);

	m_strText = strText;
	return iResult;
}
