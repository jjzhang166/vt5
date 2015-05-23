#pragma once
#include "vlistctrl.h"
#include "_list_idx_t.h"

class CListCtrl_ :
	public CVListCtrl
{

	struct XCell
	{
		TPOS	lColumnPos;	// ������� ������� � ������ ��������
		TPOS	lRowPos;	// ������� ������ � ������ �����
		ListCellAdditionInfo*	lpInfo;		// ��������� �� �����-�

		XCell()
		{
			lColumnPos = 0;
			lRowPos = 0;
			lpInfo = 0;
		}
	};

	_list_idx_t<long>	m_Columns;
	_list_idx_t<long>	m_Rows;
	_list_idx_t<XCell>	m_Cells;


	BOOL delete_cells_info( int iRow, int iColumn );		// �������� ���������� � ������(��): ���� (-1) - �������� ���� �����
	TPOS find_cell( int iRow, int iColumn ); 
	
public:
	CListCtrl_(void);
	virtual ~CListCtrl_(void);

	virtual bool create_ex( DWORD style, const RECT &rect, const _char *pszTitle = 0, HWND parent = 0, HMENU hmenu = 0, const _char *pszClass = 0, DWORD ex_style = 0 );

	// ������ �� ���������
	int		AddColumn( int iColumn );		// ���������� ������ �������
	BOOL	DeleteColumn( int iColumn );	// �������� �������
	
	// ������ �� ��������
	int		AddRow( int iRow );								// ���������� �����
	BOOL	DeleteRow( int iRow );							// �������� �����
	BOOL	SetRowCount( int iCount, DWORD dwOption = 0 );	// ���������� ���������� �����, dwOption - only for virtual list

	// ������ � ����������� ������
	virtual BOOL	SetCellProp( int iRow, int iColumn, const ListCellInfo * pLCInfo );	// ������� ������� ������
	virtual	BOOL	GetCellProp( int iRow, int iColumn, ListCellInfo * pLCInfo );		// ��������� ������� ������

	// ��������� ��������� �����
	virtual LRESULT	on_destroy();

	virtual	LRESULT	OnInsertColumn(int iCol, const LPLVCOLUMN pcol);
	virtual	LRESULT	OnDeleteColumn(int iCol);
	virtual	LRESULT	OnInsertRow(const LPLVITEM prow);
	virtual	long	OnDeleteRow( int iRow );
	virtual	long	OnDeleteAllRows( );

};
