#if !defined(__Comm_H__)
#define __Comm_H__

#include <comdef.h>

struct CCoordData
{
	unsigned x,y,o,z;
};

class CComm
{
	HANDLE m_hFile;
public:
	CComm();
	~CComm();
	// ��������� ������� �� ��������� g_Comm.
	void Open();
	void Close();
	bool IsOpened() {return m_hFile != INVALID_HANDLE_VALUE;}
	// ������������ true ���� ReadFile ������ true � ��������� ������ 
	// ����� ����.
	bool Read(unsigned nBytes, LPBYTE lpByte);
	// ������������ true ���� ReadFile ������ true. ����� ����������� 
	// ���� ����������� �� ������ pnRead.
	bool ReadEx(unsigned nBytes, LPBYTE lpByte, DWORD *pnRead);
	// ������������ true ���� WriteFile ������ true � �������� ������ 
	// ����� ����.
	bool Write(unsigned nBytes, LPBYTE lpByte);
	// ��������� ������ COM-�����.
	void Purge();
};


extern CComm g_Comm;

#endif