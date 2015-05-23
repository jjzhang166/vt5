#pragma once

const int nEqualColors=16; // ���������� ������� ����� �����������
// (��� ������� ������� ���������� �������������)

class CMarkovParamCalculator
{
public:
	CMarkovParamCalculator(void);
	~CMarkovParamCalculator(void);
	void CalcLevels(color **ppc, byte **ppm, int cx, int cy, int phase=0x7F80); // ���������� ������ ��� equalize
	void CalcMatrix(color **ppc, byte **ppm, int cx, int cy, int phase=0x7F80); // ������ ������� ���������
	// �������� phase: ������� ���� - ����� ��������� ����
	// ������� ���� - ������� ���, ������� c ���������, ���������, ����� 1
	// �.�. ����������� ��������� ���� �� low �� low+high
	// ���� phase<256 - �� ��� ������ ����� ����
	// 0x7F80 - ��� ����, ������������� ������� (>=128)
	void CalcParams(); // ��������� ��������� �� ��� ������� �������

	// ������� ������
	int m_Hist[256]; // ����������� - ��� ���������
	int m_LevelNum[256]; // ������ ������� ��� 256 ������
	int m_Matrix[nEqualColors*nEqualColors]; // ���������� �������

	int m_nLevelsPhases;

	// ���������
	double m_fInertia, m_fEnergy, m_fEntropy,
		m_fCorrelation, m_fHomogenity;
};
