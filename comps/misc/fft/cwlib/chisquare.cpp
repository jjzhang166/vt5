/************************************************
���� ������ ������������ ������������ AlgoPascal.
************************************************/

#include "ap.h"

/*-----------------------------------------------
��� ������������ ������ ���������� �����������:

double incompletegammac(double a, double x);
double incompletegamma(double a, double x);
double invincompletegammac(double a, double y0);
-----------------------------------------------*/


/*************************************************************************
������� ��� ������ "�������" ������� ������� ��������� �����������
������������� ��-������� � v ��������� �������

Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1987, 2000 by Stephen L. Moshier
*************************************************************************/
double chisquarecdistribution(double v, double x)
{
    double result;

    ap::ap_error::make_assertion(x>=0&&v>=1);
    result = incompletegammac(v/2.0, x/2.0);
    return result;
}


/*************************************************************************
������� ��� ����� "�������" ������� ������� ��������� �����������
������������� ��-������� � v ��������� �������

Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1987, 2000 by Stephen L. Moshier
*************************************************************************/
double chisquaredistribution(double v, double x)
{
    double result;

    ap::ap_error::make_assertion(x>=0&&v>=1);
    result = incompletegamma(v/2.0, x/2.0);
    return result;
}


/*************************************************************************
������� ����� x, ��� ������� ��� ������ "�������" ������� ������� ���������
����������� ������������� ��-������� � v ��������� ������� ����� y.

Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1987, 2000 by Stephen L. Moshier
*************************************************************************/
double invchisquaredistribution(double v, double y)
{
    double result;

    ap::ap_error::make_assertion(y>=0&&y<=1&&v>=1);
    result = 2*invincompletegammac(0.5*v, y);
    return result;
}


