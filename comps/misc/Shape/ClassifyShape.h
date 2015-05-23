#pragma once




struct POLYNODE
{
	int x;
	int y;
	double cosine;
	double length;
	double curvature;
	int number;
};

class CShapeDescriptor:
	public CList<POLYNODE>
{
public:
	//������� ���������� ����� �� ������ ������������ ����� �������������
	void CreateDescriptor();
	//���������� � ���� ������
	CString ToString();
};

//���������� ����� � �������� � ����� ptCurrent
void CalculatePolynode(POLYNODE plnPrev, POLYNODE* plnCurrent, POLYNODE plnNext, double eps);
//���������� �� ����� pt �� ������ (pt1, pt2);
double DistancePointToSL(ContourPoint pt, ContourPoint pt1, ContourPoint pt2);

class CPolygonalApprox
{
	IMeasureObject2Ptr mo;
	Contour* m_pc;
	double m_eps;
	CString m_strDescriptor;
	POINT Center();
	int MaxDistPoint();
	CArray<double> m_pointsDist;
	double m_caliber;
public:
	CPolygonalApprox(){/*m_eps =.5;*/};
	~CPolygonalApprox(){};
	CShapeDescriptor m_sd;
	bool CalculateDescriptor();
	bool CreatePolygone(IUnknown* object);
	void Print();
	void NormalizeContour();
	void ViewContour();
	double GetAverageEdge();
	double GetContourSize();
	
};



class CClassifyShape :
	public CFilterBase
{
	DECLARE_DYNCREATE(CClassifyShape)
	GUARD_DECLARE_OLECREATE(CClassifyShape)

	CStringArray m_strClassNames;
	void read_class_file();
public:
		
	CClassifyShape(void);
	~CClassifyShape(void);

	virtual bool InvokeFilter();
};

inline long get_object_class( ICalcObject *pcalc, const char *szClassifierName);