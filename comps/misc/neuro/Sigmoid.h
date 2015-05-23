#pragma once

#include "math.h"

class CSigmoid
{
public:
	CSigmoid(void) {};
	~CSigmoid(void) {};
	double Value(double x) //��������� ��������
	{ return tanh(x); };
	double Derivative(double x) //��������� �����������
	{ double c=cosh(x); return 1/(c*c); };
};
