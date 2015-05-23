#pragma once
#include "..\awin\misc_ptr.h"
#include "ActionHelper.h"
#include "vector"
#include "list"

class CViewsLock
{
public:
	void AddView(IUnknown* pView);
	void Clear();
protected:
	struct XViewLock
	{
		IDataContext3Ptr sptrView; // �����
		BOOL bPrevLock; // �� ���������� ���������
	};
	list<XViewLock> m_locks;
};

class CViewState
{ // ��������� ���������� ����� - ��� � ��� �����������
public:
	void Push(IDataContext3Ptr sptrDC);
	void Pop(IDataContext3Ptr sptrDC);
	vector<IUnknownPtr> m_SelectionList;
};

class CDocumentState
{
public:
	void CreateEmpty(); // ������� ������
	void GetFrom(INamedDataPtr sptrND, IDataContext3Ptr sptrDC);
	void PutTo(INamedDataPtr sptrND, IDataContext3Ptr sptrDC, bool bClearUndo=false);
	INamedDataPtr m_sptrND; // NamedData (���������)
	IUnknownPtr m_ptrUndoPos; // ������� � Undo List
	list<CViewState> m_ViewsStates;
	//CViewState m_ViewState;
};

// Impl ��� CActionHelper2: ������������ �������, ����������� FormManager
// ��� ��������������� ������� ��������
class CActionHelper2
{
public:
	CActionHelper2(void);
	~CActionHelper2(void);
	void	Init( CActiveXSite *psite, IUnknownPtr ptrDoc, int nStates=2 );
	void	DeInit();

	// ������ � �����������:
	bool SaveState(int index); // low level - ��������� State
	bool LoadState(int index, bool bClearUndo); // low level - ��������� State
	bool Invalidate(int index); // �������� State ��� Invalid
	void Cancel(); // �������� ����������
	void Ok(); // ��������� ����������
	bool UpdateStates(); // ��������� ��� Invalid States
	inline int GetStatesCount() { return m_States.size(); };
	inline IDocumentSitePtr GetDocument() { return m_sptrDoc; };

protected:
	CActiveXSite			*m_psite;
	IDocumentSitePtr	m_sptrDoc;

	CViewsLock m_ViewsLock;
	void LockAllViews();
	void UnlockAllViews();

	_ptr_t<CDocumentState> m_States; // ��������� ��������������� ���������
	// m_States[0] - ���������
	// m_States[m_States.size()-1] - ��������
	int m_nFirstInvalidState; // ����� ������� ��������������� �����;
	// ����� �������� ������ OnProcess
	
	enum { ah2Cancel, ah2Ok, ah2Continue } m_Action; // ����� �������� ������ OnProcess
	// �� Ok � Cancel Preview ���������������, �������������� �������� ������ ��� ������� �� ���������

	bool m_bRunning; // ����, ������������� �� ����� ����������.
	// ���� true - ����� ������ ������ m_Action � m_nFirstInvalidState

	class XLock
	{
	public:
		XLock( bool* pbLock )
		{ m_pbLock = pbLock; m_bStore = *pbLock; *pbLock = true; }
		~XLock()
		{ *m_pbLock = m_bStore;}
	protected:
		bool *m_pbLock;
		bool m_bStore;
	};
};
