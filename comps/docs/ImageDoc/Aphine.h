#ifndef __APHINE_H__
#define __APHINE_H__

void Rotate(CPoint *Ret,CPoint *Cent, float Angle);
struct CAphineParams
{
	CPoint	ptCenter;	//�����, ������������ ������� ����������� ��������������
	CPoint	ptCenterNew;//�� ��������� �� ����� �����������
	double	fKx, fKy;	//������������ ����������/������ �� x � y
	double	fAngle;		//���� �������� (0 - 2*PI)
	BOOL    bFillOutside;//��������� �� ����� �� ����� ����������� ���
	                     //�������.
public:
	CAphineParams()		//������������� �� ��������� - ������ �� ������
	{
		ptCenter = CPoint( 0, 0 );
		ptCenterNew = CPoint( 0, 0 );
		fKx = fKy = 1;
		fAngle = 0;
		bFillOutside = FALSE;
	}
						//���������
	CRect CalcSize( CRect rc );
};

BOOL DoAphineTransform( CImageWrp &imgNew, CImageWrp &img, CAphineParams &params, void (*pfnCallBack)(int) = 0 );
BOOL DoAphineTransformFast( CImageWrp &imgNew, CImageWrp &img, CAphineParams &params, void (*pfnCallBack)(int) = 0 );

#endif //__APHINE_H__