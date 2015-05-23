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


typedef unsigned long CRItem;	// ������� ������

typedef struct					// ����������
{
	CRItem	low, high;
} CrBlock;

#ifdef _cplusplus
	extern "C" {
#endif

// ���������� ������� �����
void __cdecl ExpCht(CRItem * source,		//   ������� �������� ��
					CRItem * target);		//   ������� ����������� ��

// ����� ���������� �����
void __cdecl ExpandKey (CRItem * source,	//   ������� ��������� �����
						CRItem * target,	//   ������� ��������. �����
						DWORD_PTR    KeyLength,	//   ������ �����
						DWORD_PTR    KeyRepeat,	//   ����� ���������� �����
						DWORD_PTR    RepeatMask,
						...);				//   ����� ���������� �����

// ������������ ������
void __cdecl gamma (CRItem * key,			//   ����� �����
					CRItem * synchro,		//   ����� �������������
					void *	 xcht,			//   ����� ������� �����
					void *   data,			//   ����� ����������� ������
					DWORD_PTR    blocks,		//   ����� ��������� ������
					DWORD_PTR    keylen);       //   ����� ����� � ���������

// ��������� �����
void __cdecl gamme (CRItem * key,			//   ����� �����
					CRItem * synchro,		//   ����� �������������
					void *   xcht,			//   ����� ������� �����
					void *   data,			//   ����� ����������� ������
					DWORD_PTR    blocks,		//   ����� ��������� ������
					DWORD_PTR    keylen);		//   ����� ����� � ���������

// ������������-������. � ��
void __cdecl gammaLE(CRItem * key,			//   ����� �����
					 CRItem * synchro,		//   ����� �������������
					 void *   xcht,			//   ����� ������� �����
					 void *   data,			//   ����� ����������� ������
					 DWORD_PTR    blocks,		//   ����� ��������� ������
					 DWORD_PTR    keylen);		//   ����� ����� � ���������

// �������������-������. � ��
void __cdecl gammaLD(CRItem * key,			//   ����� �����
					 CRItem * synchro,		//   ����� �������������
					 void *   xcht,			//   ����� ������� �����
					 void *   data,			//   ����� ����������� ������
					 DWORD_PTR    blocks,		//   ����� ��������� ������
					 DWORD_PTR    keylen);		//   ����� ����� � ���������


// ���������� ������� �������
void __cdecl simple(CRItem * key,		//   ����� �����
					void*   data,							//   ����� ��������� ������
					void*   xcht,							//   ����� ������� �����
					DWORD_PTR    blocks,			//   ����� ��������� ������
					DWORD_PTR    keylen);			//   ����� ����� � ���������

// ���������� ��������������
CRItem __cdecl imito(CRItem * key,			//   ����� �����
					 CRItem * combine,		//   ����� ��������� ����������
					 void *   xcht,			//   ����� ������� �����
					 void *   data,			//   ����� ����������� ������
					 DWORD_PTR    blocks,		//   ����� ������
					 DWORD_PTR    keylen);		//   ����� ����� � ���������

#ifdef _cplusplus
}  
#endif



#endif// __GOST_H
