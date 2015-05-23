#if !defined(AFX_PREVIEWDIALOG_H__D0FA05B0_0443_4C3F_BF4F_E4327FBC9616__INCLUDED_)
#define AFX_PREVIEWDIALOG_H__D0FA05B0_0443_4C3F_BF4F_E4327FBC9616__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreviewDialog.h : header file
//

#include "BaseDialog.h"
#include "PreviewStatic.h"
#include "HistoDlg.h"
#include "input.h"




/////////////////////////////////////////////////////////////////////////////
// CPreviewDialog dialog

class CPreviewDialog : public CBaseDialog, public IInputPreviewSite //public CDriverPreview,
{
// Driver
	IInputPreview2Ptr m_sptrPrv;
	IDriver3Ptr m_sptrDrv;
	int m_nDev;
	CRect m_rcImage;
	bool m_bInitOk;
	bool m_bPreview;
	//sergey 23/01/06
   int m_nIdNewMeth,m_nIdDeleteMeth;
	//end
	

	int m_nAdditionalInit; // PIXERA GLUCK : auto white balance

	CBaseDialog *m_pDialog;
	void AddDialog(CBaseDialog *p, int idd);
	//sergey 27.12.05
    com_call OnCmdMsg(int nCode, UINT nID, long lHWND);	
	
    //end
// Construction
public:
	CPreviewDialog(IUnknown *punk, int nDevice, bool bPreview, CWnd* pParent = NULL);   // standard constructor
	~CPreviewDialog();

// Dialog Data
	//{{AFX_DATA(CPreviewDialog)
	enum { IDD = IDD_PREVIEW };
	CStatic	m_StaticPeriod;
	CPreviewStatic	m_Image;
	//}}AFX_DATA
//	CHistBox m_Histo;
	CHistoDlg m_HistoDlg;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreviewDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual void OnLayoutChanged();

	// Generated message map functions
	//{{AFX_MSG(CPreviewDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnLevel();
	afx_msg void OnColorBalance();
	afx_msg void OnBlackBalance();
	afx_msg void OnImagePage();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnDelayedRepaint(WPARAM wParam, LPARAM lParam);
	//sergey 23/01/06
	afx_msg LRESULT OnDelayedRepaint1(WPARAM wParam, LPARAM lParam);
	afx_msg void OnNew();
	//end

	com_call Invalidate();
	com_call OnChangeSize();
	STDMETHOD(QueryInterface)(REFIID riid, LPVOID FAR* ppvObj) {return S_FALSE;}
	STDMETHOD_(ULONG,AddRef)() {return 0;}
	STDMETHOD_(ULONG,Release)() {return 0;}
public:
	//sergey 11/01/06
	afx_msg void OnBnClickedSetting();
	afx_msg void OnBnClickedSetting11();
	//end
	afx_msg void OnStnClickedImage();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEWDIALOG_H__D0FA05B0_0443_4C3F_BF4F_E4327FBC9616__INCLUDED_)
