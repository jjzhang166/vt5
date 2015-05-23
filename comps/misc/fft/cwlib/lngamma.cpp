/************************************************
���� ������ ������������ ������������ AlgoPascal.
************************************************/

#include "ap.h"

double lngamma(double x, double& sgngam);

/*************************************************************************
���������� ������������ ��������� ������ �����-�������.

������� ���������:
    x       -   �����, � ������� ��������� ��������:

�������� ���������:
    SgnGam  -   ����, ������� ����� �����-�������.
                ���� +1, ���� -1.

���������:
    ����������� �������� ������ �����-�������
    
���������� ��������:
    0 < X < 2.55e305
    -2.55e305 < X < 0, X �� �����.
    
�������� �������������:
    ��� 1 <= x <= 2 ����������� �� ��������� 10^-10
    ��� 2 < x <= 100 ����������� �� ��������� 10^-8
    
��� x<1 �������� �� �����������, �� � ������ ����, ��� ���
���������� �������� ���������� � ������� [2 ,3], ����������� ��
������ ������������ 10^-10, �� �����������, ���� �����,
������� ������������ �������.

Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1987, 1989, 1992, 2000 by Stephen L. Moshier
*************************************************************************/
double lngamma(double x, double& sgngam)
{
    double result;
    double a;
    double b;
    double c;
    double p;
    double q;
    double u;
    double w;
    double z;
    int i;
    double logpi;
    double ls2pi;
    double tmp;

    sgngam = 1;
    logpi = 1.14472988584940017414;
    ls2pi = 0.91893853320467274178;
    if( x<-34.0 )
    {
        q = -x;
        w = lngamma(q, tmp);
        p = floor(q);
        i = ap::round(p);
        if( i%2==0 )
        {
            sgngam = -1;
        }
        else
        {
            sgngam = 1;
        }
        z = q-p;
        if( z>0.5 )
        {
            p = p+1;
            z = p-q;
        }
        z = q*sin(ap::pi()*z);
        result = logpi-log(z)-w;
        return result;
    }
    if( x<13 )
    {
        z = 1;
        p = 0;
        u = x;
        while(u>=3)
        {
            p = p-1;
            u = x+p;
            z = z*u;
        }
        while(u<2)
        {
            z = z/u;
            p = p+1;
            u = x+p;
        }
        if( z<0 )
        {
            sgngam = -1;
            z = -z;
        }
        else
        {
            sgngam = 1;
        }
        if( u==2 )
        {
            result = log(z);
            return result;
        }
        p = p-2;
        x = x+p;
        b = -1378.25152569120859100;
        b = -38801.6315134637840924+x*b;
        b = -331612.992738871184744+x*b;
        b = -1162370.97492762307383+x*b;
        b = -1721737.00820839662146+x*b;
        b = -853555.664245765465627+x*b;
        c = 1;
        c = -351.815701436523470549+x*c;
        c = -17064.2106651881159223+x*c;
        c = -220528.590553854454839+x*c;
        c = -1139334.44367982507207+x*c;
        c = -2532523.07177582951285+x*c;
        c = -2018891.41433532773231+x*c;
        p = x*b/c;
        result = log(z)+p;
        return result;
    }
    q = (x-0.5)*log(x)-x+ls2pi;
    if( x>100000000 )
    {
        result = q;
        return result;
    }
    p = double(1)/double(x*x);
    if( x>=1000.0 )
    {
        q = q+((7.9365079365079365079365*0.0001*p-2.7777777777777777777778*0.001)*p+0.0833333333333333333333)/x;
    }
    else
    {
        a = 8.11614167470508450300*0.0001;
        a = -5.95061904284301438324*0.0001+p*a;
        a = 7.93650340457716943945*0.0001+p*a;
        a = -2.77777777730099687205*0.001+p*a;
        a = 8.33333333333331927722*0.01+p*a;
        q = q+a/x;
    }
    result = q;
    return result;
}

