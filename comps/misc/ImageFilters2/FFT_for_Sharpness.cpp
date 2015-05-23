#include "stdafx.h"
#include "fft_for_sharpness.h"


void CFFT_for_Sharpness::FFT_T(complex *Data, ulong Len, int Dir) {
	pfacc(Dir, Len, Data);	
};




///////////////////////////////////////////
// ����������� � ����������
CFFT_for_Sharpness::CFFT_for_Sharpness(void)
{
}

CFFT_for_Sharpness::~CFFT_for_Sharpness(void)
{
}

void CFFT_for_Sharpness::FFT2(CImg &img, long H, long W, int Dir)
{
	Dir = -Dir;
	// ���������� ����� �� �������	
	for(long i = 0; i < H; i++){
		FFT_T(img.Cmplx_image[i], W, Dir);
	};
	

	// ������������� �������
	CImg t_img(W, H);
	for(long i = 0; i < H; i++){
		for(long j = 0; j < W; j++){
			t_img.Cmplx_image[j][i] = img.Cmplx_image[i][j];
		}
	};

	// ���������� ����� �� ��������
	for(long j = 0; j < W; j++){
		FFT_T(t_img.Cmplx_image[j], H, Dir);
	};
	
	// ������ ������ �������� �����
	for(long i = 0; i < H; i++){
		for(long j = 0; j < W; j++){
			img.Cmplx_image[i][j] = t_img.Cmplx_image[j][i];
		}
    };
}
