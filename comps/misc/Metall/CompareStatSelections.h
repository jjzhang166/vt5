#pragma once
#include "\vt5\common2\action_main.h"
#include "resource.h"
#include <atlstr.h>

class CCompareStatSelections :
	public CAction,
	public _dyncreate_t<CCompareStatSelections>
{
public:
	route_unknown();
	CCompareStatSelections(void);
	~CCompareStatSelections(void);
	com_call DoInvoke();

protected:
	// ��������� ���� ���
	// pfrv1 � pfrv2 - ������� ��� �����: <�����_�����_k> - <��������_���_k> -> pfrv1[k] � pfrv[k + 1]
    double compare( double *pfrv1, int nsize_frv1, double *pfrv2, int nsize_frv2 ); 
};

//---------------------------------------------------------------------------
class CCompareStatSelectionsInfo : 
public _ainfo_t<ID_ACTION_COMPARE_STAT_SELECTIONS, _dyncreate_t<CCompareStatSelections>::CreateObject, 0>,
public _dyncreate_t<CCompareStatSelectionsInfo>
{
	route_unknown();
public:
	CCompareStatSelectionsInfo() { }
	arg *args() {return s_pargs;}
	static arg s_pargs[];
};
