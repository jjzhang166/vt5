#pragma once
#include <math.h>
// ������� ������ ��� ��� ��������� ����������

static double inline sqr(double x)
{ return x*x; }

//static inline int round(double x)
//{
//	return int(floor(x+0.5));
//}

#define round(a) iround(a)
//
//static inline int iround(double x)
//{
//	return int(floor(x + 0.5));
//}
