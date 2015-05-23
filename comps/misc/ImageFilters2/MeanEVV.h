// MeanEVFilter.h: interface for the COpenByReconstructionFilter class.
//
//////////////////////////////////////////////////////////////////////
#include "action_filter.h"
#include "FilterMorphoBase.h"
#include "image5.h"
#include "misc_utils.h"

#include "nameconsts.h"
#include "clone.h"
#include "clonedata.h"
#include "resource.h"

#include "ImagePane.h"
/*
#pragma once
*/
/////////////////////////////////////////////////////////////////////////////
class CMeanEVVF : public CFilterMorphoBase,
					public _dyncreate_t<CMeanEVVF>
{
public:
	route_unknown();
public:
	int m_MaskSize; // ������ �����
	int m_Param; // �������� �������
    int m_PaneCount; // ���������� �������� �����
    SIZE m_size; // ������ �����������
	int m_mean; // ������� ������� �� �����������
	int m_dev; // �������� �� �����������
	double m_coeffGaus; // ����������� ��� ����� ����������� �������� �� ������������
	double m_coeffSigmai; // ����������� ��� ����� ����������������� ���� ����
	int m_ROADnum; // ���������� ����������� ���������
	color** pMaskRowsL;
	color** pMaskRowsR;

	CMeanEVVF()
	{
		m_MaskSize = 10; m_Param = 100; m_mean = 0; m_dev = 0;
		m_PaneCount = 1; m_size.cx = 100; m_size.cy = 100;
		m_coeffGaus = 6; m_coeffSigmai = 1; m_ROADnum = 4;
		//m_coeffGaus = 6; m_coeffSigmai = 1; m_ROADnum = 2;
	}
    bool InitHist(int y,color** pRows,long *pAprHist);
	bool MeanEV(CImagePaneCache *pImageSrcPC, IImage2* pImageDst);
    color BrDst(color* pSrc, color* pTemp, int* pROADsumArray, double* pexpArray, double* pGaussian, int pTempStep);
	bool ROADsum(color* pSrc, int* pROADsumArray, long *pAprHist);
	virtual bool InvokeFilter();
protected:
};


/////////////////////////////////////////////////////////////////////////////
class CMeanEVVInfo : public _ainfo_t<ID_ACTION_MEAN_EVV, _dyncreate_t<CMeanEVVF>::CreateObject, 0>,
							public _dyncreate_t<CMeanEVVInfo>
{
	route_unknown();
public:
	CMeanEVVInfo()
	{
	}
	arg	*args()	{return s_pargs;}
	virtual _bstr_t target()			{return "anydoc";}
	static arg	s_pargs[];
};
