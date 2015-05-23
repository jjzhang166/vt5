#include <limits.h>
#include <atlstr.h>
#include "image5.h"

const int NC=256;
extern double hist_smooth_level;

void CalcHist(color **src, int cx, int cy, int *hist);
//� hist ������ ���� NC ��������� �����

void CalcHistMasked(color **src, byte **bin, byte bin_val, int cx, int cy, int *hist);
//� hist ������ ���� NC ��������� �����

void CalcHistMaskedSqr(color **src, byte **bin, byte bin_val, int cx, int cy, int *hist, int x0, int y0, int x1, int y1);
//� hist ������ ���� NC ��������� �����
//(x0,y0)-(x1,y1) - ������� �������������

int OrderValue(int *x, int n, int order, int xmin=INT_MIN, int xmax=INT_MAX);
//������� order'th �������� �� ���������������� �������
//���� ������ xmin, xmax - ������� ��������


// [vanek]
// ������������ ������, ���������� ��������  ���
BOOL FormingFRVString( double fkoeff, double *pfFRVchord, int nsize, double fCalibr, CString *pstr_out );
// 
BOOL ParseFRVString( CString *pstrFRV, double *pfFRVchord, int *pnsize );
