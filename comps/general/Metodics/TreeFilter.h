#pragma once
#include <string>
#include <map>
#include <list>
#include "MethodDataUtil.h"

class CTreeFilterLevel;

typedef map<wstring, CTreeFilterLevel> CTreeFilterLevelMap;

class CTreeFilterLevel
{
	CTreeFilterLevelMap* m_pKeys; // ���������� ��� ����������� ������
	CTreeFilterLevel* m_pParent; // Level ������� ����

public:
	enum TL_USE
	{
		tlDefault,
		tlUseLeft,
		tlUseRight,
		tlUseNone,
	} m_Usage; // ������������ ��� ������� ����� �������� �����
	// ������������ ����� ��� ������

public:
	CTreeFilterLevel(CTreeFilterLevel* pParent=0, TL_USE usage=tlDefault);
	virtual ~CTreeFilterLevel();

	bool Set(list<wstring> &words, TL_USE value); // ���������� ��������� ��� ����������� �����
	bool Set(wstring path, TL_USE value); // ���������� ��������� ��� ����������� �����
	TL_USE Get(list<wstring> &words); // �������� ���������; � ������ tlDefault - �������� � �������

	bool Load(const char* szFileName); // ��������� �� �����
	bool Save(const char* szFileName); // ��������� � ����
	bool Save(wofstream &out, list<wstring> &path);

	CTreeFilterLevel* Find(wstring s); // ����� ����� ������ �������, ��������������� ������ s
	CTreeFilterLevel* Find(list<wstring> &words, bool bInsert=false); // �� �� �����, �� ������ ��� ��������� �� ������
	// ���� bInsert - �� ��� ���������� ������ ����� ������ ������� ��

	bool Merge(INamedData* pLeft, INamedData* pRight, INamedData* pResult, TL_USE FilterBy, CSubstMap* pLeftMap=0, CSubstMap* pRightMap=0); // ����� ��� Named Data
	bool RecursiveMerge(INamedData* pLeft, INamedData* pRight, INamedData* pResult, TL_USE FilterBy, _bstr_t bstrPath, CSubstMap* pLeftMap=0, CSubstMap* pRightMap=0); // ���������� �-�

public:
	CTreeFilterLevel(const CTreeFilterLevel &arg);
	const CTreeFilterLevel& operator=(const CTreeFilterLevel& arg);
};


class CTreeFilter : public CTreeFilterLevel
{
public:
	CTreeFilter();
	virtual ~CTreeFilter();
};
