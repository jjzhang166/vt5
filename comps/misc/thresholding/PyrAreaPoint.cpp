// PyrAreaPoint.cpp: implementation of the CPyrAreaPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PyrAreaPoint.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPyrAreaPoint::CPyrAreaPoint()
{
	m_nColor = 0;
	m_ConnectedPoint = NULL;
	m_nSum = 0;
	m_nCount = 0;
}

CPyrAreaPoint::~CPyrAreaPoint()
{

}
