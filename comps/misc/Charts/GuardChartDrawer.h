// GuardChartDrawer.h: interface for the CGuardChartDrawer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GUARDCHARTDRAWER_H__93D4DC4C_1626_4C23_91E0_112CC65436A0__INCLUDED_)
#define AFX_GUARDCHARTDRAWER_H__93D4DC4C_1626_4C23_91E0_112CC65436A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "chartdrawer.h"

class CGuardChartDrawer : public CCmdTargetEx
{
	CChartDrawer m_Chart;

	DECLARE_DYNCREATE(CGuardChartDrawer);
	GUARD_DECLARE_OLECREATE(CGuardChartDrawer);

	DECLARE_INTERFACE_MAP();
	ENABLE_MULTYINTERFACE()
public:
	CGuardChartDrawer();
	virtual ~CGuardChartDrawer();

	BEGIN_INTERFACE_PART(Attributes, IChartAttributes )
		com_call SetColor( DWORD lColor, CommonChartColors dwFlag );
		com_call GetColor( DWORD *lColor, CommonChartColors dwFlag );

		com_call SetChartColor( long nID, DWORD lColor, ChartColors dwFlag );
		com_call GetChartColor( long nID, DWORD *lColor, ChartColors dwFlag );

		// ��������/��������� ������ �����. 
		com_call SetStyle( CommonChartViewParam dwFlag );
		com_call GetStyle( CommonChartViewParam *dwFlag );

		com_call SetChartStyle(long nID, ChartViewParam dwFlag );
		com_call GetChartStyle(long nID, ChartViewParam *dwFlag );

		// ��������/��������� ����� �����.
		com_call SetLineStyle( ULONG lStyle, CommonChartLineStyles dwFlag );
		com_call GetLineStyle( ULONG *lStyle, CommonChartLineStyles dwFlag );

		com_call SetChartLineStyle(long nID, ULONG lStyle, ChartLineStyles dwFlag );
		com_call GetChartLineStyle(long nID, ULONG *lStyle, ChartLineStyles dwFlag );

		// ��������/��������� ���o���� �����. 
		// ChartLineThickness
		com_call SetLineThick( long nThick,   CommonChartLineThickness dwFlag );
		com_call GetLineThick( long *nThick, CommonChartLineThickness dwFlag );

		com_call SetChartLineThick(long nID, long nThick,   ChartLineThickness dwFlag );
		com_call GetChartLineThick(long nID, long *nThick, ChartLineThickness dwFlag );

		// ������� ������� �� ������� ����� ��������
		com_call SetChartRange(long nID, double lfMin, double lfMax, ChartRange dwFlag );
		com_call GetChartRange(long nID, double *lfMin, double *lfMax, ChartRange dwFlag );

		com_call SetRangeState(long nID, int bEnable, ChartRange dwFlag );
		com_call GetRangeState(long nID, int *bEnable, ChartRange dwFlag );

		// �������� ��������� ������.
		com_call SetTargetPos( POINT ptPos );

		// �������� ������� ������ ������.
		com_call SetTextFormat( long nID, BSTR bstrFormat, ChartTextFormat dwFlag );

		// ������� ������ � ������ ��������� � ���.
		com_call RemoveChart( long nID );

		// ������� ������ � ������ ��������� � ���.
		com_call ShowChart( long nID, int bShow );

		// ��������/��������� ����������� ����.
		com_call SetAxisText( long nID, BSTR bstrText, ChartAxis dwFlag );
		com_call GetAxisText( long nID, BSTR *bstrText, ChartAxis dwFlag );

		// ��������/��������� ��������� ����������.
		com_call SetConstParams( long nVal, CommonChartConst dwFlag );
		com_call GetConstParams( long *nVal, CommonChartConst dwFlag );

		// ��������/��������� ��������� ����������.
		com_call SetColorizedMap( long nID,DWORD lColor, double lfMinX, double lfMinY, double lfMaxX, double lfMaxY );
		com_call ClearColorized( long nID );
		com_call EnableGridLines( CommonChartGrid dwFlags );
		com_call SetGridLines( double *fGridVals, long lCount, CommonChartGrid dwFlags );
		com_call SetScaleLabels( long nID, double *pfVals, long lCount, ChartAxis dwFlags );
		com_call SetScaleTextLabels( long nID, double *pfVals, double *pfLabels, long lCount, ChartAxis dwFlags );

		com_call SetAxisTextFont( long nID, BYTE *plfFont, ChartAxis dwFlags, ChartFont dwFlag2 );

		com_call RemoveHints(/* [in] */long nID );
		com_call SetHintText( long nID, double fX, double fY, BSTR bstrHint, int nAlign, int XOffsetInPixel, int YOffsetInPixel  );
		com_call SetHintFont( long nID, BYTE *plfFont );

		com_call SetTextZoom( double fZoom );
		com_call GetTextZoom( double *pfZoom );
		
		com_call SetPixelUnit( /*[in]*/ int nUnit );
	END_INTERFACE_PART(Attributes);

	BEGIN_INTERFACE_PART(ChartDrawer, IChartDrawer )
		//��������� ������ ������.
		com_call SetData(long nID, double*pValues, long nCount, ChartDataType dwFlag );
		com_call GetData(long nID, double**pValues, long * nCount, ChartDataType dwFlag );

		//��������� ������ ������ ������ �� Y, �������� ��������� �. 
		com_call SetData2(long nID, VARIANT PtrToFunct, double lfMinX, double lfMaxX, double lfStep );
		
		// ������ �� ����������. ��� ������ ��������� �� ������� �������
		com_call SetExternData(long nID, double*pValues, long nCount, ChartDataType dwFlag );

		//��������� �������(��)
		com_call Draw( DWORD hDC,  RECT rcDraw ); 

		// ���������� �������� ��� ptMiceInDC.
		com_call GetToolTipValue( long nID, POINT ptMiceInDC, double *pX, double *pY, short bYfromX, int nHalfHotZone );

		// C����������. 
		com_call SmoothChart(long nID, double fSmoothParam, short bYFromX, ChartLineSmooth dwFlag );

		com_call ClearAll();
		com_call LogarifmScale( ChartDataType dwFlag );

		com_call AddMarker( double fX, double fY, long nPixelInSize, COLORREF clColor, ChartMarker dwFlag );
	END_INTERFACE_PART(ChartDrawer);

	BEGIN_INTERFACE_PART(SmartChartDrawer, ISmartChartDrawer )
		//��������� � ������ ���������. 
		com_call CalcValues( long nID, BSTR bstrExpr, double fMin, double fMax, double fStep );

		//��������� �������(��)
		com_call Draw( DWORD hDC,  RECT rcDraw ); 

		// ���������� �������� ��� ptMiceInDC.
		com_call GetToolTipValue( long nID, POINT ptMiceInDC, double *pX, double *pY, short bYfromX, int nHalfHotZone );

		com_call SmoothChart(long nID, double fSmoothParam, short bYFromX, ChartLineSmooth dwFlag );
		com_call ClearAll();
		com_call LogarifmScale( ChartDataType dwFlag );
	END_INTERFACE_PART(SmartChartDrawer);

	BEGIN_INTERFACE_PART(ChartMiscHelper, IChartMiscHelper )
		//��������� � ������ ���������. 
		com_call LPtoDP( DWORD hDC, POINT *pt );
		com_call DPtoLP( DWORD hDC, POINT *pt );

		com_call ConvertToDC( long nID, RECT rcDraw, double x, double y, POINT *pt );
	END_INTERFACE_PART(ChartMiscHelper);
};

#endif // !defined(AFX_GUARDCHARTDRAWER_H__93D4DC4C_1626_4C23_91E0_112CC65436A0__INCLUDED_)
