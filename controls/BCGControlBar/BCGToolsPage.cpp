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

// BCGToolsPage.cpp : implementation file
//

#include "stdafx.h"
#include "bcgcontrolbar.h"
#include "bcglocalres.h"
#include "bcgbarres.h"
#include "BCGToolsPage.h"
#include "BCGUserToolsManager.h"
#include "CBCGToolbarCustomize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static const int iBtnNew = 0;
static const int iBtnDelete = 1;
static const int iBtnMoveUp = 2;
static const int iBtnMoveDn = 3;

/////////////////////////////////////////////////////////////////////////////
// CBCGToolsPage property page

#pragma warning (disable : 4355)

CBCGToolsPage::CBCGToolsPage() : 
	CPropertyPage(CBCGToolsPage::IDD),
	m_wndToolsList (this)
{
	//{{AFX_DATA_INIT(CBCGToolsPage)
	m_strCommand = _T("");
	m_strArguments = _T("");
	m_strInitialDirectory = _T("");
	//}}AFX_DATA_INIT

	m_pSelTool = NULL;
	m_pParentSheet = NULL;
}

#pragma warning (default : 4355)

CBCGToolsPage::~CBCGToolsPage()
{
}

void CBCGToolsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBCGToolsPage)
	DDX_Control(pDX, IDD_BCGBARRES_ARGUMENTS, m_wndArgumentsEdit);
	DDX_Control(pDX, IDD_BCGBARRES_INITIAL_DIRECTORY, m_wndInitialDirEdit);
	DDX_Control(pDX, IDD_BCGBARRES_COMMAND, m_wndCommandEdit);
	DDX_Control(pDX, IDD_BCGBARRES_BROWSE_COMMAND, m_wndBrowseBtn);
	DDX_Control(pDX, IDD_BCGBARRES_COMMANDS_LIST, m_wndToolsList);
	DDX_Text(pDX, IDD_BCGBARRES_COMMAND, m_strCommand);
	DDX_Text(pDX, IDD_BCGBARRES_ARGUMENTS, m_strArguments);
	DDX_Text(pDX, IDD_BCGBARRES_INITIAL_DIRECTORY, m_strInitialDirectory);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBCGToolsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CBCGToolsPage)
	ON_BN_CLICKED(IDD_BCGBARRES_BROWSE_COMMAND, OnBcgbarresBrowseCommand)
	ON_EN_UPDATE(IDD_BCGBARRES_ARGUMENTS, OnUpdateTool)
	ON_EN_UPDATE(IDD_BCGBARRES_COMMAND, OnUpdateTool)
	ON_EN_UPDATE(IDD_BCGBARRES_INITIAL_DIRECTORY, OnUpdateTool)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBCGToolsPage message handlers

BOOL CBCGToolsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	VERIFY (g_pUserToolsManager != NULL);

	m_pParentSheet = DYNAMIC_DOWNCAST (CBCGToolbarCustomize, GetParent ());
	ASSERT (m_pParentSheet != NULL);

	//-------------
	// Add buttons:
	//-------------
	m_wndToolsList.SetStandardButtons ();

	//------------
	// Fill tools:
	//------------
	const CObList& lstTools = g_pUserToolsManager->GetUserTools ();
	for (POSITION pos = lstTools.GetHeadPosition (); pos != NULL;)
	{
		CBCGUserTool* pTool = (CBCGUserTool*) lstTools.GetNext (pos);
		ASSERT_VALID (pTool);

		m_wndToolsList.AddItem (pTool->m_strLabel, (DWORD) pTool);
	}

	m_pParentSheet->OnInitToolsPage ();
	EnableControls ();	// By Andreas Roth

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
//***************************************************************************
BOOL CToolsList::OnBeforeRemoveItem (int iItem)
{
	CBCGUserTool* pTool = (CBCGUserTool*) GetItemData (iItem);
	ASSERT_VALID (pTool);

	g_pUserToolsManager->RemoveTool (pTool);
	m_pParent->m_pSelTool = NULL;

	return TRUE;
}
//***************************************************************************
void CToolsList::OnAfterAddItem (int iItem)
{
	CBCGUserTool* pTool = m_pParent->CreateNewTool ();
	if (pTool == NULL)
	{
		RemoveItem (iItem);
		return;
	}

	ASSERT_VALID (pTool);

	pTool->m_strLabel = GetItemText (iItem);
	SetItemData (iItem, (DWORD) pTool);
}
//***************************************************************************
void CToolsList::OnAfterRenameItem (int iItem)
{
	CBCGUserTool* pTool = (CBCGUserTool*) GetItemData (iItem);
	ASSERT_VALID (pTool);

	pTool->m_strLabel = GetItemText (iItem);
}
//***************************************************************************
void CToolsList::OnAfterMoveItemUp (int iItem)
{
	CBCGUserTool* pTool = (CBCGUserTool*) GetItemData (iItem);
	ASSERT_VALID (pTool);

	g_pUserToolsManager->MoveToolUp (pTool);
}
//***************************************************************************
void CToolsList::OnAfterMoveItemDown (int iItem)
{
	CBCGUserTool* pTool = (CBCGUserTool*) GetItemData (iItem);
	ASSERT_VALID (pTool);

	g_pUserToolsManager->MoveToolDown (pTool);
}
//**************************************************************************
void CToolsList::OnSelectionChanged ()
{
	int iSelItem = GetSelItem ();
	CBCGUserTool* pSelTool = (iSelItem < 0) ? 
		NULL : (CBCGUserTool*) GetItemData (iSelItem);

	if (pSelTool == NULL)
	{
		m_pParent->m_strCommand.Empty ();
		m_pParent->m_strArguments.Empty ();
		m_pParent->m_strInitialDirectory.Empty ();
	}
	else
	{
		ASSERT_VALID (pSelTool);

		m_pParent->m_strCommand = pSelTool->GetCommand ();
		m_pParent->m_strArguments = pSelTool->m_strArguments;
		m_pParent->m_strInitialDirectory = pSelTool->m_strInitialDirectory;
	}

	ASSERT_VALID (m_pParent->m_pParentSheet);
	m_pParent->m_pParentSheet->OnBeforeChangeTool (m_pParent->m_pSelTool);

	m_pParent->m_pSelTool = pSelTool;
	m_pParent->UpdateData (FALSE);

	m_pParent->EnableControls ();

	m_pParent->m_pParentSheet->OnAfterChangeTool (m_pParent->m_pSelTool);
}
//**************************************************************************
void CBCGToolsPage::OnBcgbarresBrowseCommand() 
{
	CFileDialog dlg (TRUE, g_pUserToolsManager->GetDefExt (), NULL, 0,
		g_pUserToolsManager->GetFilter (), this, _FILE_OPEN_SIZE_ );
	if (dlg.DoModal () == IDOK)
	{
		m_strCommand = dlg.GetPathName ();
		UpdateData (FALSE);
		OnUpdateTool();
	}
}
//**************************************************************************
void CBCGToolsPage::OnUpdateTool() 
{
	UpdateData ();

	int iSelItem = m_wndToolsList.GetSelItem ();
	CBCGUserTool* pSelTool = (iSelItem >= 0) ?
		(CBCGUserTool*) m_wndToolsList.GetItemData (iSelItem) : NULL;

	if (pSelTool == NULL)
	{
		m_strCommand.Empty ();
		m_strArguments.Empty ();
		m_strInitialDirectory.Empty ();

		UpdateData (FALSE);
	}
	else
	{
		ASSERT_VALID (pSelTool);

		pSelTool->SetCommand (m_strCommand);
		pSelTool->m_strArguments = m_strArguments;
		pSelTool->m_strInitialDirectory = m_strInitialDirectory;
	}

	EnableControls ();	// By Andreas Roth
}
//******************************************************************************
CBCGUserTool* CBCGToolsPage::CreateNewTool ()
{
	ASSERT_VALID (m_pParentSheet);

	const int nMaxTools = g_pUserToolsManager->GetMaxTools ();

	if (g_pUserToolsManager->GetUserTools ().GetCount () == nMaxTools)
	{
		CBCGLocalResource locaRes;
		
		CString strError;
		strError.Format (IDS_BCGBARRES_TOO_MANY_TOOLS_FMT, nMaxTools);
		MessageBox (strError);

		return NULL;
	}

	CBCGUserTool* pTool = g_pUserToolsManager->CreateNewTool ();
	ASSERT_VALID (pTool);

	return pTool;
}
//*******************************************************************************
void CBCGToolsPage::OnOK() 
{
	OnUpdateTool();
	CPropertyPage::OnOK();
}
//******************************************************************************
void CBCGToolsPage::EnableControls ()
{
	//----------------
	// By Andreas Roth
	//----------------
	BOOL bEnableItemProps = (m_wndToolsList.GetSelItem () >= 0);

	m_wndCommandEdit.EnableWindow (bEnableItemProps);
	m_wndArgumentsEdit.EnableWindow (bEnableItemProps);
	m_wndInitialDirEdit.EnableWindow (bEnableItemProps);
	m_wndBrowseBtn.EnableWindow (bEnableItemProps);
/*
	GetDlgItem(IDD_BCGBBCGRES_COMMAND_TEXT)->EnableWindow(TRUE);
	GetDlgItem(IDD_BCGBBCGRES_BCGGUMENTS)->EnableWindow(TRUE);
	GetDlgItem(IDD_BCGBBCGRES_INITIAL_DIRECTORY_TEXT)->EnableWindow(TRUE);*/
}

