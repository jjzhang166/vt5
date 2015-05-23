#pragma once

class CCellMeasGroup : 
	public CMeasParamGroupBase
{
	DECLARE_DYNCREATE(CCellMeasGroup)
	DECLARE_GROUP_OLECREATE(CCellMeasGroup);
public:
	CCellMeasGroup();           // protected constructor used by dynamic creation
	virtual ~CCellMeasGroup();
public:
	virtual bool CalcValues( IUnknown *punkCalcObject, IUnknown *punkSource );
	virtual bool GetUnit( long lKey, long lType, _bstr_t &bstrType, double &fCoeff );
	virtual bool LoadCreateParam();
	virtual bool OnInitCalculation();

	//IPersist
	virtual void GetClassID( CLSID* pClassID );	

private:
    int m_nPointsAverage;
	int m_nStepAverage; // ��������� ��� ��������� ���������� ������

	int m_nMarkovianEqualizeMethod; // ����� ����������� ��� ������� ���������� ����������:
	// 0 - �������
	// 1 - �� ���� ���� �������� (����� �������)
	// 2 - �� ���� ������
	// 3 - �������� �� ����������, �������� �� ����

	int m_nNucleiPhaseMin, m_nNucleiPhaseMax; // �������� ��� ��� ����
	// ������ �� ��������� Angles...
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
