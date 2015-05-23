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

// BCGUserToolsManager.h: interface for the CBCGUserToolsManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGUSERTOOLSMANAGER_H__9AF9D216_BD4C_11D3_A716_009027900694__INCLUDED_)
#define AFX_BCGUSERTOOLSMANAGER_H__9AF9D216_BD4C_11D3_A716_009027900694__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "bcgcontrolbar.h"
#include "BCGUserTool.h"

class BCGCONTROLBARDLLEXPORT CBCGUserToolsManager : public CObject
{
public:
	//--------------
	// Construction:
	//--------------
	CBCGUserToolsManager (	const UINT uiCmdToolsDummy,
							const UINT uiCmdFirst, const UINT uiCmdLast,
							CRuntimeClass* pToolRTC = RUNTIME_CLASS (CBCGUserTool));
	virtual ~CBCGUserToolsManager();

	//------------
	// Operations:
	//------------
	BOOL LoadState (LPCTSTR lpszProfileName = NULL);
	BOOL SaveState (LPCTSTR lpszProfileName = NULL);

	CBCGUserTool* CreateNewTool ();
	BOOL RemoveTool (CBCGUserTool* pTool);
	
	BOOL MoveToolUp (CBCGUserTool* pTool);
	BOOL MoveToolDown (CBCGUserTool* pTool);

	BOOL IsUserToolCmd (UINT uiCmdId) const
	{
		return uiCmdId >= m_uiCmdFirst && uiCmdId <= m_uiCmdLast;
	}

	UINT GetToolsEntryCmd () const
	{
		return m_uiCmdToolsDummy;
	}

	BOOL InvokeTool (UINT uiCmdId);
	CBCGUserTool* FindTool (UINT uiCmdId) const;

	//------------
	// Attributes:
	//------------
public:
	const CObList& GetUserTools () const
	{
		return m_lstUserTools;
	}

	int GetMaxTools () const
	{
		return m_uiCmdLast - m_uiCmdFirst + 1; 
	}

	void SetFilter (const CString& strFilter)
	{
		m_strFilter = strFilter;
	}

	const CString& GetFilter () const
	{
		return m_strFilter;
	}

	void SetDefExt (const CString& strDefExt)
	{
		m_strDefExt = strDefExt;
	}

	const CString& GetDefExt () const
	{
		return m_strDefExt;
	}

protected:
	CObList				m_lstUserTools;		// List of CBCGUserTool-derived objects
	const UINT			m_uiCmdToolsDummy;	// Will be replaced by the tools list
	const UINT			m_uiCmdFirst;		// First user tool command
	const UINT			m_uiCmdLast;		// Last user tool command
	CRuntimeClass*		m_pToolRTC;
	CString				m_strFilter;		// "Add tool" file dilaog filter
	CString				m_strDefExt;		// Default tool file extension
};

extern CBCGUserToolsManager*	g_pUserToolsManager;

#endif // !defined(AFX_BCGUSERTOOLSMANAGER_H__9AF9D216_BD4C_11D3_A716_009027900694__INCLUDED_)
