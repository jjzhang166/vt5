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

#if !defined(AFX_KEYASSIGN_H__283E6046_54C6_11D2_B110_D085EB8D1B3C__INCLUDED_)
#define AFX_KEYASSIGN_H__283E6046_54C6_11D2_B110_D085EB8D1B3C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// KeyAssign.h : header file
//
//*********************************************************
// The code is based on the Thierry Maurel's CKeyboardEdit:
//*********************************************************

////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 1998 by Thierry Maurel
// All rights reserved
//
// Distribute freely, except: don't remove my name from the source or
// documentation (don't take credit for my work), mark your changes (don't
// get me blamed for your possible bugs), don't alter or remove this
// notice.
// No warrantee of any kind, express or implied, is included with this
// software; use at your own risk, responsibility for damages (if any) to
// anyone resulting from the use of this software rests entirely with the
// user.
//
// Send bug reports, bug fixes, enhancements, requests, flames, etc., and
// I'll try to keep a version up to date.  I can be reached as follows:
//    tmaurel@caramail.com   (or tmaurel@hol.fr)
//
////////////////////////////////////////////////////////////////////////////////
// File    : KeyboardEdit.h
// Project : AccelsEditor
////////////////////////////////////////////////////////////////////////////////
// Version : 1.0                       * Authors : A.Lebatard + T.Maurel
// Date    : 17.08.98
//
// Remarks : 
//

#include "KeyHelper.h"

/////////////////////////////////////////////////////////////////////////////
// CKeyAssign window

class CKeyAssign : public CEdit
{
// Construction
public:
	CKeyAssign();

// Attributes
public:
	BOOL IsKeyDefined () const
	{
		return m_bKeyDefined;
	}

protected:
	BOOL		m_bKeyDefined;
	ACCEL		m_Accel;
	CKeyHelper	m_Helper;

// Operations
public:
	ACCEL const* GetAccel () const
	{
		return &m_Accel;
	}

	void ResetKey ();

protected:
	void SetAccelFlag (BYTE bFlag, BOOL bOn);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyAssign)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKeyAssign();

	// Generated message map functions
protected:
	//{{AFX_MSG(CKeyAssign)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg LRESULT OnGetDlgCode( WPARAM, LPARAM );

	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYASSIGN_H__283E6046_54C6_11D2_B110_D085EB8D1B3C__INCLUDED_)
