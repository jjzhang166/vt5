#ifndef __GOST_H
#define __GOST_H

#include <BaseTsd.h>

/*----------------------------------------------------
  gost.h -- �������� ������ �  ��������� ������� ���-
	    ������� �� ���� 28147-89.
  ----------------------------------------------------
  ������ 2.01 �� 05.07.98, (c)1994,1998 ��������� �.�.
  ----------------------------------------------------
  �������� ����������:
  ������ VarKey:
  - ���� �� ���������, ����� ����� � �������� �����-
    ����� ����������� � �� ���������� ��� ��������;
  - ���� ���������, ����� ����� ���������� ��� ����-
    ���� � ������� ����������;
  ������ CryptoImport:
  - ���� ���������, ������������� ����������� ���
    __import - �������.
  ----------------------------------------------------
*/
#include <windows.h>

typedef unsigned long CrItem;	// ������� ������

typedef struct					// ����������
{
	CrItem	low, high;
} CrBlock;

#ifdef __cplusplus
	extern "C" {
#endif

// ���������� ������� �����
void __cdecl ExpCht(CrItem * source,		//   ������� �������� ��
					CrItem * target);		//   ������� ����������� ��

// ����� ���������� �����
void __cdecl ExpandKey (CrItem * source,	//   ������� ��������� �����
						CrItem * target,	//   ������� ��������. �����
						DWORD    KeyLength,	//   ������ �����
						DWORD    KeyRepeat,	//   ����� ���������� �����
						DWORD    RepeatMask,
						...);				//   ����� ���������� �����

// ������������ ������
void __cdecl gamma (CrItem * key,			//   ����� �����
					CrItem * synchro,		//   ����� �������������
					void *	 xcht,			//   ����� ������� �����
					void *   data,			//   ����� ����������� ������
					DWORD_PTR    blocks,		//   ����� ��������� ������
					DWORD    keylen);       //   ����� ����� � ���������

// ��������� �����
void __cdecl gamme (CrItem * key,			//   ����� �����
					CrItem * synchro,		//   ����� �������������
					void *   xcht,			//   ����� ������� �����
					void *   data,			//   ����� ����������� ������
					DWORD_PTR    blocks,		//   ����� ��������� ������
					DWORD    keylen);		//   ����� ����� � ���������

// ������������-������. � ��
void __cdecl gammaLE(CrItem * key,			//   ����� �����
					 CrItem * synchro,		//   ����� �������������
					 void *   xcht,			//   ����� ������� �����
					 void *   data,			//   ����� ����������� ������
					 DWORD_PTR    blocks,		//   ����� ��������� ������
					 DWORD    keylen);		//   ����� ����� � ���������

// �������������-������. � ��
void __cdecl gammaLD(CrItem * key,			//   ����� �����
					 CrItem * synchro,		//   ����� �������������
					 void *   xcht,			//   ����� ������� �����
					 void *   data,			//   ����� ����������� ������
					 DWORD_PTR    blocks,		//   ����� ��������� ������
					 DWORD    keylen);		//   ����� ����� � ���������


// ���������� ������� �������
void __cdecl simple(CrItem * key,			//   ����� �����
					void *   data,			//   ����� ��������� ������
					void *   xcht,			//   ����� ������� �����
					DWORD_PTR    blocks,		//   ����� ��������� ������
					DWORD    keylen);		//   ����� ����� � ���������

// ���������� ��������������
CrItem __cdecl imito(CrItem * key,			//   ����� �����
					 CrItem * combine,		//   ����� ��������� ����������
					 void *   xcht,			//   ����� ������� �����
					 void *   data,			//   ����� ����������� ������
					 DWORD_PTR    blocks,		//   ����� ������
					 DWORD    keylen);		//   ����� ����� � ���������

#ifdef __cplusplus
}  
#endif

//#define _GOST_LIBRARY "xgost32s.lib"
//#pragma comment(lib, _GOST_LIBRARY)
//#pragma message("gost 32 library linking with " _GOST_LIBRARY)



#endif// __GOST_H
