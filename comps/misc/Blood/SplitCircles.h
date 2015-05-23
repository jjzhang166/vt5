#pragma once

#include "action_filter.h"
#include "image5.h"
#include "misc_utils.h"

#include "nameconsts.h"
#include "clone.h"
#include "clonedata.h"
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
class CSplitCircles : public CFilter,
        public _dyncreate_t<CSplitCircles>
{
public:
	route_unknown();
	CSplitCircles(void);
	virtual ~CSplitCircles(void);
	virtual bool InvokeFilter();
protected:
	IImage3Ptr CreateImageCopy(IImage3Ptr ptrSrc, _rect rect=NORECT, bool bCopyMask=true); // ������� ����� ����� �����������
	IImage3Ptr CreateImagePart(IImage3Ptr ptrSrc, int i1, int i2); // �������� ����� ������� ������ �� ����� i1 � ����� i2
	bool SplitImage(IImage3* image, IUnknown** ppDst1, IUnknown** ppDst2); // ��������� �� ���, false - �� �������
	long m_lMaxSplits; // ������������ ����� �������� �� �������
	double m_fMinArea; // ����������� ������� �������
	long m_lMaxPerimeter; // ������������ �������� ������� (����� �� ������ ��� ������������
	long m_lMinAngleDetector; // ����������� ����� �������, ���������������� ��� ���������� �����
	double m_fAngleDetectorChordCoeff; // ����� ������� = min + coeff*chord
	double m_fAngleThreshold; // ����������� ���� (������� ����������) �� ����� �������
	_bstr_t m_bstrClassification; //�������������, ������������ ��� ������� �� ������� (1) / ����� (0)
	long m_lClassWhole; // ����� ��� �����, -2 - �� �����������
	long m_lClassSplitted; // ����� ��� �����������, -2 - �� �����������
private:
	ContourPoint *m_pcont; //��������� �� ������� �������������� ������
	int m_len; //����� �������� �������
	double CalcAngle(int i, int step);
};

//---------------------------------------------------------------------------
class CSplitCirclesInfo : public _ainfo_t<ID_ACTION_SPLITCIRCLES, _dyncreate_t<CSplitCircles>::CreateObject, 0>,
public _dyncreate_t<CSplitCirclesInfo>
{
        route_unknown();
public:
        CSplitCirclesInfo() { }
        arg *args() {return s_pargs;}
        virtual _bstr_t target()  {return "anydoc";}
        static arg s_pargs[];
};
