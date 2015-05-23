#if !defined(AFX_PUSHBUTTON_H__FAEB9636_A314_11D3_A53B_0000B493A187__INCLUDED_)
#define AFX_PUSHBUTTON_H__FAEB9636_A314_11D3_A53B_0000B493A187__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class COleFont;

/////////////////////////////////////////////////////////////////////////////
// CPushButton wrapper class

class CPushButton : public CWnd
{
protected:
	DECLARE_DYNCREATE(CPushButton)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x54a0bf86, 0x9a92, 0x11d3, { 0xb1, 0xc5, 0xeb, 0x19, 0xbd, 0xba, 0xba, 0x39 } };
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
	CString GetBMPFileName();
	void SetBMPFileName(LPCTSTR);
	short GetButtonWidth();
	void SetButtonWidth(short);
	short GetButtonHeight();
	void SetButtonHeight(short);
	BOOL GetAutoSize();
	void SetAutoSize(BOOL);
	short GetButtonDepth();
	void SetButtonDepth(short);
	BOOL GetDrawBorder();
	void SetDrawBorder(BOOL);
	BOOL GetFlatButton();
	void SetFlatButton(BOOL);
	BOOL GetDefaultButton();
	void SetDefaultButton(BOOL);
	BOOL GetThreeStateButton();
	void SetThreeStateButton(BOOL);
	BOOL GetMouseInPicColor();
	void SetMouseInPicColor(BOOL);
	BOOL GetMouseOutPicColor();
	void SetMouseOutPicColor(BOOL);
	BOOL GetMouseOutShadow();
	void SetMouseOutShadow(BOOL);
	BOOL GetButtonPressedPicColor();
	void SetButtonPressedPicColor(BOOL);
	BOOL GetButtonPressedShadow();
	void SetButtonPressedShadow(BOOL);
	BOOL GetMouseInShadow();
	void SetMouseInShadow(BOOL);
	BOOL GetDisabled();
	void SetDisabled(BOOL);
	BOOL GetDrawFocusRect();
	void SetDrawFocusRect(BOOL);
	BOOL GetStretch();
	void SetStretch(BOOL);
	CString GetButtonText();
	void SetButtonText(LPCTSTR);
	short GetTextAlign();
	void SetTextAlign(short);
	short GetOffsetTextFromBMP();
	void SetOffsetTextFromBMP(short);
	BOOL GetDrawFigures();
	void SetDrawFigures(BOOL);
	short GetFigureType();
	void SetFigureType(short);
	short GetFigureSize();
	void SetFigureSize(short);
	unsigned long GetColorTransparent();
	void SetColorTransparent(unsigned long);
	unsigned long GetColorFigure();
	void SetColorFigure(unsigned long);
	unsigned long GetColorFillFigure();
	void SetColorFillFigure(unsigned long);
	BOOL GetFillFigure();
	void SetFillFigure(BOOL);
	COleFont GetFont();
	void SetFont(LPDISPATCH);
	unsigned long GetActiveTextColor();
	void SetActiveTextColor(unsigned long);
	unsigned long GetInactiveTextColor();
	void SetInactiveTextColor(unsigned long);
	BOOL GetInnerRaised();
	void SetInnerRaised(BOOL);
	BOOL GetInnerSunken();
	void SetInnerSunken(BOOL);
	BOOL GetOuterRaised();
	void SetOuterRaised(BOOL);
	BOOL GetOuterSunken();
	void SetOuterSunken(BOOL);
	short GetFigureMaxSize();
	void SetFigureMaxSize(short);
	short GetFigureBound();
	void SetFigureBound(short);
	BOOL GetAdvancedShadow();
	void SetAdvancedShadow(BOOL);
	BOOL GetDarkShadow();
	void SetDarkShadow(BOOL);

// Operations
public:
	BOOL ResetPressedState();
	BOOL SetPressedState();
	BOOL IsPressed();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUSHBUTTON_H__FAEB9636_A314_11D3_A53B_0000B493A187__INCLUDED_)
