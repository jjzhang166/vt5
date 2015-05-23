#pragma once

#include <vector>
#include <string>

class CSimilarityHelper
{
public:
	CSimilarityHelper(void);
	~CSimilarityHelper(void);

	void Init(IUnknown* punkList); // ��������� ��� ������ �� ������
	void DeInit();

	void ProcessObject(IUnknown* punkObject); // ��������� ��� ��� �������; ������ ���� ��� ������ Init

	int GetSimilar(); // ������� ����� �������� ��������
	int GetSimilarInClass(int nClass); // ������� ����� �������� �������� � ������ ������
	int GetSimilarInOwnClass(); // ������� ����� �������� �������� � ����������� ������

	int GetClassSimilar(); // ������� ����� ������ �������� ��������

	double _GetParamDistanceSqrByIndex(int iParam, int jObject); // ������� "����������" �� ���������� ��������� �� ������� �������
	// ������� �������� ������������ �� �������!
	double GetParamDistance(int nParam, int jObject); // ������� "����������" �� ���������� ��������� �� ������� �������
	double GetParamDistance(int nParam); // ������� "����������" �� ���������� ��������� �� ������� �������

	void WriteObjectReport(const wchar_t* wszFileName); // ��������� ����� �� �������

	void ProcessObjectError(); // ��������� ��� ������� ���������� ���������� ����������;
	// ������ ���� ��� ������ Process

	void TestObjectList(IUnknown* punkList); // �������������� �� Object List -
	// ����� ������� �������� ������������� � �������� ����������
	void TestObjectList2(IUnknown* punkList); // �������������� �� Object List -
	// ����� ������� �������� ������������� � �������� ����������
	void WriteTestReport(const wchar_t* wszFileName); // ��������� ����� �� ������������

	double CalcError(IUnknown* punkList); // ��������� ������ �� ������� OL

	double GetError2(); // �������� ������, ������� ���� ��� TestObjectList2
	double Improve2(); // ���� ��� �����������, ����������, �� ������� �����������������; ������ ����� TestObjectList2

protected:
	long nClasses, nObjects, nParams;

	// �������� ������ � Object List
	vector<long> params;
	vector<wstring> param_names;
	vector<double> params_weight;
	vector<double> values;
	vector<long> classes;
	vector<double> classes_weight;

	// ������������� ������ - ����������
	vector<int> num;
	vector<double>avg;
	vector<double> disp;
	vector<int> num_total;
	vector<double> disp_total;

	// �������� ������ � �������
	vector<double> values_obj;
	int nObjectClass;

	// ���������� �� �������
	vector<double> classes_best_d; // ������ ���������� �� �������
	vector<int> classes_best_j; // ������ ������� �� �������
	int best_class; // ������ �����
	int best_j; // ������ ������

	// ���������� �� ���� ��������
	vector<int> error_matrix; // ������� ������, [nClasses*nClasses], �� ��������� - ��������� ������������������
	// �������� - error_matrix[old_class*nClasses+new_class]

	// ���������� �� TestObjectList2
	double current_error; // ������� ������
	vector<double> params_error; // ������ ��� ������ ����������, [nParams]

	// ������� ��������������
	bool bInited; // ��������� ��� ������
	bool bProcessed; // ��� ��������� ������ - ���� ���������� �� ����
	bool bErrorInited; // ���� ���� �����-�� ������ ProcessObjectError
	bool bTestObjectList2Done; // ���� ������ TestObjectList2
};
