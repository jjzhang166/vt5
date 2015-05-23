#if !defined(AFX_VTWIDTH_H__10CAEB08_B42A_403E_A429_E4940DEFAA66__INCLUDED_)
#define AFX_VTWIDTH_H__10CAEB08_B42A_403E_A429_E4940DEFAA66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CVTWidth wrapper class

class CVTWidth : public CWnd
{
protected:
	DECLARE_DYNCREATE(CVTWidth)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x5df91a6e, 0x34a7, 0x4ce0, { 0xa2, 0x31, 0x8e, 0xe, 0x7e, 0xf3, 0x40, 0xe5 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	long GetWidth();
	void SetWidth(long);
	BOOL GetChecked();
	void SetChecked(BOOL);
	long GetMin();
	void SetMin(long);
	long GetMax();
	void SetMax(long);
	BOOL GetOrientation();
	void SetOrientation(BOOL);
	BOOL GetVisible();
	void SetVisible(BOOL);
	unsigned long GetColorText();
	void SetColorText(unsigned long);
	unsigned long GetColorTextHighlight();
	void SetColorTextHighlight(unsigned long);
	unsigned long GetColorSlider();
	void SetColorSlider(unsigned long);
	unsigned long GetColorSliderArrows();
	void SetColorSliderArrows(unsigned long);
	unsigned long GetColorTextScale();
	void SetColorTextScale(unsigned long);
	unsigned long GetColorSliderArrowsHighlight();
	void SetColorSliderArrowsHighlight(unsigned long);

// Operations
public:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VTWIDTH_H__10CAEB08_B42A_403E_A429_E4940DEFAA66__INCLUDED_)
