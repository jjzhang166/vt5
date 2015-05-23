/********************************************************************
���� ������ ���������������� � �����������
********************************************************************/

#ifndef AP_H
#define AP_H

#include <stdlib.h>
#include <math.h>

/********************************************************************
���� ������, ���� ���������, ��������� �������� ������ ��������.

���� �� ���������, �� ��� ��������� � �������� ������� ��� ������ ���
������ �� ������������ �������� ������������ ����������� �������.

����  ������  ��  ���������,  ��  ���  ��������� � �������� ������� � 
�������� ������� ������������� ���������� ap_error

�������� ������ ������� ������ ��������� ����� ��������, �� ���������
������.
********************************************************************/
#define NO_AP_ASSERT


/********************************************************************
���� ������ ������������ ��� ���������� �����.

�� ����������� ��� � �� �������� �����������!
********************************************************************/
//#define UNSAFE_MEM_COPY


/********************************************************************
������������ ���� ����������� ���������� AlgoPascal
********************************************************************/
namespace ap
{


/********************************************************************
����� ����������, ������� ������������� ��� ��������� �������.

������� ������ �� ��������� ���������� �������, �� ������� ����������
���� �������������.
********************************************************************/
class ap_error
{
public:
    static void make_assertion(bool bClause)
        { if(!bClause) throw ap_error(); };
private:
};                      


/********************************************************************
�������� ���������� ����������� ���
********************************************************************/
static inline bool XOR(bool lhs, bool rhs)
{
    return (lhs && !rhs) || ( !lhs && rhs);
}


/********************************************************************
�����-������ ����������� ������������� �������


�������� ������ ������:

---------------------------------------------------------------------
template_1d_array()

�������� ������� �������.

---------------------------------------------------------------------
~template_1d_array()

�������� �������. ��� ���� ������������� ���������� ��� ������ ������

---------------------------------------------------------------------
template_1d_array(const template_1d_array &rhs)

�������� ����� �������. ��� ���� ���������� ��������� ������� ������,
� ������� ���������� ���������� �������-���������

---------------------------------------------------------------------
const template_1d_array& operator=(const template_1d_array &rhs)

������������ �������. ��� ���� ���������� �������-��������� ���������
� �������������  ���������� ��� ���� ������,  ����� ������ ���������� 
��������� ������� ������, � ������� ���������� ���������� ���������.

---------------------------------------------------------------------
      T& operator()(int i)
const T& operator()(int i) const

��������� � �������� ������� � ������� i

---------------------------------------------------------------------
void setbounds( int iLow, int iHigh )

��������� ������  ���  ������.  ���  ����  ������  ���������� �������
���������  � �������������  ���������� ��� ���� ������,  ����� ������ 
���������� ��������� ������� ������ ������� iHigh-iLow+1 ���������.

��������� ��������� � ����� ������� ���������� � iLow � �������������
iHigh. ���������� ������ ������� �� ����������.

---------------------------------------------------------------------
void setcontent( int iLow, int iHigh, const T *pContent )

�����  ����������  ������  setbounds()  �� ��� �����������, ��� ����� 
��������� ������ � �� ���������� ���������� ������� pContent[].

---------------------------------------------------------------------
      T* getcontent()
const T* getcontent() const

����� ��������� �������� ��������� �� ���������� �������. ������,  ��
������� ��������� ������������ ���������, ����� ��������, � ���  ����
��������� ���������� �������.

---------------------------------------------------------------------
int getlowbound()
int gethighbound()

������ ������������ ���  ���������  ����������  �  ������  �  �������
�������� �������.
********************************************************************/
template<class T>
class template_1d_array
{
public:
    template_1d_array()
    {
        m_Vec=0;
        m_iVecSize = 0;
    };

    ~template_1d_array()
    {
        if(m_Vec)
            delete[] m_Vec;
    };

    template_1d_array(const template_1d_array &rhs)
    {
        m_iVecSize = rhs.m_iVecSize;
        m_iLow = rhs.m_iLow;
        m_iHigh = rhs.m_iHigh;
        if(rhs.m_Vec)
        {
            m_Vec = new T[m_iVecSize];
            #ifndef UNSAFE_MEM_COPY
            for(int i=0; i<m_iVecSize; i++)
                m_Vec[i] = rhs.m_Vec[i];
            #else
            memcpy(m_Vec, rhs.m_Vec, m_iVecSize*sizeof(T));
            #endif
        }
        else
            m_Vec=0;
    };

    const template_1d_array& operator=(const template_1d_array &rhs)
    {
        if( this==&rhs )
            return *this;

        m_iLow = rhs.m_iLow;
        m_iHigh = rhs.m_iHigh;
        m_iVecSize = rhs.m_iVecSize;
        if(m_Vec)
            delete[] m_Vec;
        if(rhs.m_Vec)
        {
            m_Vec = new T[m_iVecSize];
            #ifndef UNSAFE_MEM_COPY
            for(int i=0; i<m_iVecSize; i++)
                m_Vec[i] = rhs.m_Vec[i];
            #else
            memcpy(m_Vec, rhs.m_Vec, m_iVecSize*sizeof(T));
            #endif
        }
        else
            m_Vec=0;
        return *this;
    };

    const T& operator()(int i) const
    {
        #ifndef NO_AP_ASSERT
        ap_error::make_assertion(i>=m_iLow && i<=m_iHigh);
        #endif
        return m_Vec[ i-m_iLow ];
    };

    T& operator()(int i)
    {
        #ifndef NO_AP_ASSERT
        ap_error::make_assertion(i>=m_iLow && i<=m_iHigh);
        #endif
        return m_Vec[ i-m_iLow ];
    };

    void setbounds( int iLow, int iHigh )
    {
        if(m_Vec)
            delete[] m_Vec;
        m_iLow = iLow;
        m_iHigh = iHigh;
        m_iVecSize = iHigh-iLow+1;
        m_Vec = new T[m_iVecSize];
    };

    void setcontent( int iLow, int iHigh, const T *pContent )
    {
        setbounds(iLow, iHigh);
        for(int i=iLow; i<=iHigh; i++)
            (*this)(i) = pContent[i-iLow];
    };

    T* getcontent()
    {
        return m_Vec;
    };

    const T* getcontent() const
    {
        return m_Vec;
    };

    int getlowbound(int iBoundNum = 0) const
    {
        return m_iLow;
    };

    int gethighbound(int iBoundNum = 0) const
    {
        return m_iHigh;
    };
private:
    T         *m_Vec;
    long      m_iVecSize;
    long      m_iLow, m_iHigh;
};



/********************************************************************
�����-������ ����������� ������������� �������


�������� ������ ������:

---------------------------------------------------------------------
template_2d_array()

�������� ������� �������.

---------------------------------------------------------------------
~template_2d_array()

�������� �������. ��� ���� ������������� ���������� ��� ������ ������

---------------------------------------------------------------------
template_2d_array(const template_2d_array &rhs)

�������� ����� �������. ��� ���� ���������� ��������� ������� ������,
� ������� ���������� ���������� �������-���������

---------------------------------------------------------------------
const template_2d_array& operator=(const template_2d_array &rhs)

������������ �������. ��� ���� ���������� �������-��������� ���������
� �������������  ���������� ��� ���� ������,  ����� ������ ���������� 
��������� ������� ������, � ������� ���������� ���������� ���������.

---------------------------------------------------------------------
      T& operator()(int i1, int i2)
const T& operator()(int i1, int i2) const

��������� � �������� ������� � �������� [i1,i2]

---------------------------------------------------------------------
void setbounds( int iLow1, int iHigh1, int iLow2, int iHigh2 )

���������  ������   ���   ������.    ���   ����   ������   ����������
�������   ���������   �  �������������  ����������  ���  ����  ������, 
�����   ������   ����������   ���������   �������   ������   �������� 
(iHigh1-iLow1+1)*(iHigh2-iLow2+1) ���������.

���������  ��������� � ����� ������� �� ������ ����������� ���������� 
� iLow1 � ������������� iHigh1, ���������� ��� ������ �����������.

���������� ������ ������� �� ����������.

---------------------------------------------------------------------
void setcontent( int iLow1, int iHigh1, int iLow2, int iHigh2, 
    const T *pContent )

�����  ����������  ������  setbounds()  �� ��� �����������, ��� ����� 
��������� ������ � �� ���������� ���������� ������� pContent[].

������ pContent �������� ���������� ������, ���������� ���������, �.�.
������ ���� ������� [iLow1, iLow2], ����� [iLow1, iLow2+1] � �.�.

---------------------------------------------------------------------
      T* getcontent()
const T* getcontent() const

����� ��������� �������� ��������� �� ���������� �������. ������,  ��
������� ��������� ������������ ���������, ����� ��������, � ���  ����
��������� ���������� �������.

---------------------------------------------------------------------
int getlowbound(int iBoundNum)
int gethighbound(int iBoundNum)

������ ������������ ���  ���������  ����������  �  ������  �  �������
�������� ������� �� ����������� � ���������� �������.
********************************************************************/
template<class T>
class template_2d_array
{
public:
    template_2d_array()
    {
        m_Vec=0;
        m_iVecSize=0;
    };

    ~template_2d_array()
    {
        if(m_Vec)
            delete[] m_Vec;
    };

    template_2d_array(const template_2d_array &rhs)
    {
        m_iVecSize = rhs.m_iVecSize;
        m_iLow1 = rhs.m_iLow1;
        m_iLow2 = rhs.m_iLow2;
        m_iHigh1 = rhs.m_iHigh1;
        m_iHigh2 = rhs.m_iHigh2;
        m_iConstOffset = rhs.m_iConstOffset;
        m_iLinearMember = rhs.m_iLinearMember;
        if(rhs.m_Vec)
        {
            m_Vec = new T[m_iVecSize];
            #ifndef UNSAFE_MEM_COPY
            for(int i=0; i<m_iVecSize; i++)
                m_Vec[i] = rhs.m_Vec[i];
            #else
            memcpy(m_Vec, rhs.m_Vec, m_iVecSize*sizeof(T));
            #endif
        }
        else
            m_Vec=0;
    };
    const template_2d_array& operator=(const template_2d_array &rhs)
    {
        if( this==&rhs )
            return *this;

        m_iLow1 = rhs.m_iLow1;
        m_iLow2 = rhs.m_iLow2;
        m_iHigh1 = rhs.m_iHigh1;
        m_iHigh2 = rhs.m_iHigh2;
        m_iConstOffset = rhs.m_iConstOffset;
        m_iLinearMember = rhs.m_iLinearMember;
        m_iVecSize = rhs.m_iVecSize;
        if(m_Vec)
            delete[] m_Vec;
        if(rhs.m_Vec)
        {
            m_Vec = new T[m_iVecSize];
            #ifndef UNSAFE_MEM_COPY
            for(int i=0; i<m_iVecSize; i++)
                m_Vec[i] = rhs.m_Vec[i];
            #else
            memcpy(m_Vec, rhs.m_Vec, m_iVecSize*sizeof(T));
            #endif
        }
        else
            m_Vec=0;
        return *this;
    };

    const T& operator()(int i1, int i2) const
    {
        #ifndef NO_AP_ASSERT
        ap_error::make_assertion(i1>=m_iLow1 && i1<=m_iHigh1);
        ap_error::make_assertion(i2>=m_iLow2 && i2<=m_iHigh2);
        #endif
        return m_Vec[ m_iConstOffset + i2 +i1*m_iLinearMember];
    };

    T& operator()(int i1, int i2)
    {
        #ifndef NO_AP_ASSERT
        ap_error::make_assertion(i1>=m_iLow1 && i1<=m_iHigh1);
        ap_error::make_assertion(i2>=m_iLow2 && i2<=m_iHigh2);
        #endif
        return m_Vec[ m_iConstOffset + i2 +i1*m_iLinearMember];
    };

    void setbounds( int iLow1, int iHigh1, int iLow2, int iHigh2 )
    {
        if(m_Vec)
            delete[] m_Vec;
        m_iVecSize = (iHigh1-iLow1+1)*(iHigh2-iLow2+1);
        m_Vec = new T[m_iVecSize];
        m_iLow1  = iLow1;
        m_iHigh1 = iHigh1;
        m_iLow2  = iLow2;
        m_iHigh2 = iHigh2;
        m_iConstOffset = -m_iLow2-m_iLow1*(m_iHigh2-m_iLow2+1);
        m_iLinearMember = (m_iHigh2-m_iLow2+1);
    };

    void setcontent( int iLow1, int iHigh1, int iLow2, int iHigh2, const T *pContent )
    {
        setbounds(iLow1, iHigh1, iLow2, iHigh2);
        for(int i=0; i<m_iVecSize; i++)
            m_Vec[i]=pContent[i];
    };

    T* getcontent()
    {
        return m_Vec;
    };

    const T* getcontent() const
    {
        return m_Vec;
    };

    int getlowbound(int iBoundNum) const
    {
        return iBoundNum==1 ? m_iLow1 : m_iLow2;
    };

    int gethighbound(int iBoundNum) const
    {
        return iBoundNum==1 ? m_iHigh1 : m_iHigh2;
    };
private:
    T           *m_Vec;
    long        m_iVecSize;
    long        m_iLow1, m_iLow2, m_iHigh1, m_iHigh2;
    long        m_iConstOffset, m_iLinearMember;
};


typedef template_1d_array<int>    integer_1d_array;
typedef template_1d_array<double> real_1d_array;
typedef template_1d_array<int>   boolean_1d_array;
typedef template_2d_array<int>    integer_2d_array;
typedef template_2d_array<double> real_2d_array;
typedef template_2d_array<int>   boolean_2d_array;


/********************************************************************
��������� � �������, ����������� � ALGOPASCAL
********************************************************************/
static double machineepsilon = 5E-16;
static double maxrealnumber = 1E300;
static double minrealnumber = 1E-300;

static double sign(double x)
{
    if( x>0 ) return  1.0;
    if( x<0 ) return -1.0;
    return 0;
}

static double randomreal()
{
    int i = rand();
    while(i==RAND_MAX)
        i =rand();
    return double(i)/double(RAND_MAX);
}

static int randominteger(int maxv)
{  return rand()%maxv; }

static double round(double x)
{ return floor(x+0.5); }

static double trunc(double x)
{ return x>0 ? floor(x) : ceil(x); }

static double pi()
{ return 3.14159265358979323846; }

static double sqr(double x)
{ return x*x; }

static int maxint(int m1, int m2)
{
    return m1>m2 ? m1 : m2;
}

static int minint(int m1, int m2)
{
    return m1>m2 ? m2 : m1;
}

static double maxreal(double m1, double m2)
{
    return m1>m2 ? m1 : m2;
}

static double minreal(double m1, double m2)
{
    return m1>m2 ? m2 : m1;
}

};//namespace ap

extern "C"{
__declspec(dllexport) double lngamma(double x, double& sgngam);
__declspec(dllexport) double incompletebeta(double a, double b, double x);
__declspec(dllexport) double invincompletebeta(double a, double b, double y);
__declspec(dllexport) double invnormaldistribution(double y0);
__declspec(dllexport) double incompletegamma(double a, double x);
__declspec(dllexport) double invincompletegammac(double a, double y0);
__declspec(dllexport) double incompletegammac(double a, double x);
__declspec(dllexport) double gamma(double x);
__declspec(dllexport) double chisquarecdistribution(double v, double x);
__declspec(dllexport) double chisquaredistribution(double v, double x);
__declspec(dllexport) double invchisquaredistribution(double v, double y);
__declspec(dllexport) double studenttdistribution(int k, double t);
__declspec(dllexport) double invstudenttdistribution(int k, double p);
}
//#pragma comment(linker, "/include:_lngamma")
//#pragma comment(linker, "/include:_incompletebeta")
//#pragma comment(linker, "/include:_invincompletebeta")
//#pragma comment(linker, "/include:_invnormaldistribution")
//#pragma comment(linker, "/include:_incompletegamma")
//#pragma comment(linker, "/include:_invincompletegammac")
//#pragma comment(linker, "/include:_incompletegammac")
//#pragma comment(linker, "/include:_gamma")
//#pragma comment(linker, "/include:_chisquarecdistribution")
//#pragma comment(linker, "/include:_chisquaredistribution")
//#pragma comment(linker, "/include:_invchisquaredistribution")
//#pragma comment(linker, "/include:_studenttdistribution")
//#pragma comment(linker, "/include:_invstudenttdistribution")

#endif
