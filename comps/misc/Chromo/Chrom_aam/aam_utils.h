#include <limits.h>

const int NC=256;
const double hist_smooth_level=0.5;

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
