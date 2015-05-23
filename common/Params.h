#ifndef __Params_h__
#define __Params_h__

////////////	Params Sections	////////////

////// measurements params 
#define	secMeasurement "\\measurement"

#define	sMainMeasParamsSection	"\\measurement\\parameters"

////// statistics params 
#define sMainStatParamsSection	"\\StatUI\\StatParams"

///////////		End Params Sections	////////////


///////////     Params Types Section
#define sParamsTypesSection		"\\measurement\\types"


//////////		Params Types	//////////		
#define	sUndefined				"Undefined"
#define	sLinear					"Linear"
#define	sCounter				"Counter"
#define	sAngle					"Angle"
//////////		End Params Types	//////////		

 
////////////	Params Keys		////////////

////// common keys
#define	sEnable					"Enable"
#define sUserName				"UserName"
#define	sFormat					"Format"
#define	sKey					"Key"
//////	

////// users defined params keys
#define	sExprString				"ExprString"
#define	sGreekSymbol			"GreekSymbol"
#define	sUpperIndex				"UpperIndex"
#define	sLowerIndex				"LowerIndex"
#define sGraphics				"Graphics"
/// statistics 
#define sClassifier				"Classifier"
//////

////////////	End Params Keys		////////////


#ifndef USERKEY 
#define USERKEY 0xF000
#endif //USERKEY        

#ifndef MANUAL_PARAMS_FIRST_KEY 
#define MANUAL_PARAMS_FIRST_KEY         2000
#endif //MANUAL_PARAMS_FIRST_KEY        

#ifndef MANUAL_PARAMS_LAST_KEY  
#define MANUAL_PARAMS_LAST_KEY          USERKEY-1
#endif //MANUAL_PARAMS_LAST_KEY 



#define KEY_AREA                        0
#define KEY_INT_AREA					1
#define KEY_PERIMETER					2
#define KEY_INT_PERIMETER				3
#define KEY_PCONCAVE					4
#define KEY_PCONVEX                     5

#define KEY_FEREMIN                     6
#define KEY_FEREMAX                     7
#define KEY_FEREAVRG					8
#define KEY_ELPSMAX                     9
#define KEY_ELPSMIN                     10
#define KEY_DECV                        11

#define KEY_LENGTH                      12
#define KEY_WIDTH                       13
#define KEY_XLEN                        14
#define KEY_YLEN                        15
#define KEY_AVRCHORD					16
#define KEY_LINEL                       17
#define KEY_LINEW                       18
#define KEY_RIBBONL                     19
#define KEY_RIBBONW                     20
#define KEY_NOUN                        21
#define KEY_DIM                         22

#define KEY_XCOORD                      23
#define KEY_YCOORD                      24
                                                         
#define KEY_CIRCLE                      25
#define KEY_ELLIPSE                     26
#define KEY_ROUNDISH					27
#define KEY_ANGLE                       28

#define KEY_BRIAVR                      29
#define KEY_BRIDEV                      30
#define KEY_BRIMIN                      31
#define KEY_BRIMAX                      32
#define KEY_BRIINT                      33
#define KEY_BRIINTEGRAL					34

#define KEY_RED                         35
#define KEY_GREEN                       36
#define KEY_BLUE                        37
#define KEY_HUE                         38
#define KEY_SATURATION                  39

#define KEY_SPEED                       41
#define KEY_OBJID                       43
#define KEY_TIME                        42

#define KEY_MANUAL_LENGTH				47
#define KEY_MANUAL_RADIUS				48
#define KEY_MANUAL_ANGLE				49
#define KEY_MANUAL_FREE_LENGTH			52

#define KEY_OPTICAL_DENS				50
#define KEY_INT_OD						51

#define KEY_SKELETONPERIMETERRATIO		53	// �������� ������� / 2*��������
#define KEY_CIRCLE2                     54	// ������ ������ ����� ����� (������ �� �������)
#define KEY_LC                          55  // ������ ��������� ����������
#define KEY_COMPACTNESS                 56  // ������ ������������
#define KEY_EXT_PERIMETER               57  // �������� - ��� ����� �����
#define KEY_BRIORDERED                  58  // N-� �� ������� �������� �������
#define KEY_CONCAVE_PERCENT				59  // ������� �������� �������� �� �������

#define KEY_BASE_CHROMOS                100
#define KEY_BASE_MULTIOBJ               120
#define KEY_BASE_SPEED                  130
#define KEY_BASE_OPTICAL                140
#define KEY_BASE_CELL					200
//200-299 reserved for cell parameters

#define KEY_BASE_PARTICLES              300
#define KEY_END_PARTICLES				349
//300-349 reserved for sperm

#define KEY_BASE_SPERM					350
#define KEY_END_SPERM					399
//350-399 reserved for sperm morphology

#define KEY_BASE_PHASE					400
#define KEY_END_PHASE					499
//400-499 reserved for phase params

#define KEY_BASE_CHORD					500
#define KEY_END_CHORD					599
//500-599 reserved for chord params

#define KEY_BASE_METALL					600
#define KEY_END_METALL					699

#define KEY_BASE_COMPOSITE				700
#define KEY_END_COMPOSITE				799

#define KEY_BASE_SHAPE					800
#define KEY_END_SHAPE					899

#define KEY_BASE_CHROMOS_EX				1000
#define KEY_END_CHROMOS_EX				1099

#define KEY_BASE_CELL2					1100
#define KEY_END_CELL2					1199

#define KEY_BASE_USER                   5000

enum KEYS_CELL
{
        KEY_CELLAREA=KEY_BASE_CELL+0, // ������� ������
        KEY_CELLNUCLEUSAREA, // ������� ���� ������
        KEY_CELLPERIMETER, // �������� ���� ������
        KEY_CELLNUCLEUSPERIMETER, // �������� ���� ������
        KEY_CELLCIRCULARITY, // 1 - �������, <1 - ���
        KEY_CELLNUCLEUSCIRCULARITY, // 1 - ���� �������, <1 - ���
        KEY_CELLELLIPTICITY, // 0 - ����, >0 - ������
        KEY_CELLNUCLEUSELLIPTICITY, // 0 - ����, >0 - ������
        KEY_CELLNUCLEUSAREAPERCENT, // ������� ����/������� ������

        KEY_CELLNUCLEUSMOMENT1, // ������ ������ �������
        KEY_CELLNUCLEUSMOMENT2, // ������ ������ �������
        KEY_CELLNUCLEUSMOMENT3, // ������ ������ �������
        KEY_CELLCITOPLASMAMOMENT1, // ������ ������ �������
        KEY_CELLCITOPLASMAMOMENT2, // ������ ������ �������
        KEY_CELLCITOPLASMAMOMENT3, // ������ ������ �������

        KEY_CELLNUCLEUSGRADIENT, // ������������������ �������� �������
        KEY_CELLCITOPLASMAGRADIENT, // ������������������ �������� �������


        KEY_CELLNUCLEISEGMENTS1, // ����� ��������� � ���� ����� erode 1
        KEY_CELLNUCLEISEGMENTS2, // ����� ��������� � ���� ����� erode 2
        KEY_CELLNUCLEISEGMENTS3, // ����� ��������� � ���� ����� erode 3
        KEY_CELLNUCLEISEGMENTS4, // ����� ��������� � ���� ����� erode 4
        KEY_CELLNUCLEISEGMENTS5, // ����� ��������� � ���� ����� erode 5

        KEY_CELLNUCLEUSMOMENT1R,
        KEY_CELLNUCLEUSMOMENT2R,
        KEY_CELLNUCLEUSMOMENT3R,
        KEY_CELLCITOPLASMAMOMENT1R,
        KEY_CELLCITOPLASMAMOMENT2R,
        KEY_CELLCITOPLASMAMOMENT3R,

        KEY_CELLNUCLEUSMOMENT1B,
        KEY_CELLNUCLEUSMOMENT2B,
        KEY_CELLNUCLEUSMOMENT3B,
        KEY_CELLCITOPLASMAMOMENT1B,
        KEY_CELLCITOPLASMAMOMENT2B,
        KEY_CELLCITOPLASMAMOMENT3B,

		KEY_CELLNUCLEUS_INERTIA,
		KEY_CELLNUCLEUS_ENERGY,
		KEY_CELLNUCLEUS_ENTROPY,
		KEY_CELLNUCLEUS_CORRELATION,
		KEY_CELLNUCLEUS_HOMOGENITY,

		KEY_CELLCITOPLASMA_INERTIA,
		KEY_CELLCITOPLASMA_ENERGY,
		KEY_CELLCITOPLASMA_ENTROPY,
		KEY_CELLCITOPLASMA_CORRELATION,
		KEY_CELLCITOPLASMA_HOMOGENITY,

		KEY_CELL_INERTIA,
		KEY_CELL_ENERGY,
		KEY_CELL_ENTROPY,
		KEY_CELL_CORRELATION,
		KEY_CELL_HOMOGENITY,

		KEY_NUCLEUS_F0=KEY_BASE_CELL+70,
		KEY_NUCLEUS_F1,
		KEY_NUCLEUS_F2,
		KEY_NUCLEUS_F3,
		KEY_NUCLEUS_F4,
		KEY_NUCLEUS_F5,
		KEY_NUCLEUS_F6,
		KEY_NUCLEUS_F7,
		KEY_NUCLEUS_F8,

		KEY_CELL_DUMMY,

		KEY_HOLLOWFACTOR=KEY_BASE_CELL+80,
		KEY_BRIGHTNESSMOMENT1,
		KEY_BRIGHTNESSMOMENT2,
		KEY_BRIGHTNESSMOMENT3,
		KEY_BORDERWIDTH,
		KEY_BORDERHEIGHT,
        KEY_CELL_DUMMY2,


		KEY_ANGLES_PLUS_N = KEY_BASE_CELL2, // ���������� �������� ����� "��������������", ��������������� ����
		KEY_ANGLES_MINUS_N, // ���������� �������� ����� "��������������", ��������������� ����
		KEY_ANGLES_N, // ����� ���������� ����� "��������������", ��������������� ����
		KEY_ANGLES_RATIO_N, // ������� �������� �����
		KEY_ANGLES_SUM_PLUS_N,
		KEY_ANGLES_SUM_MINUS_N,
		KEY_ANGLES_SUM_RATIO_N,
		KEY_ANGLES_SUM_RATIO2_N,
};

enum KEYS_PARTICLES
{
        KEY_PARTICLES_NFRAMES=KEY_BASE_PARTICLES+0, // ����� ������, �� ������� ���� ������ �������
		KEY_PARTICLES_VAP,
		KEY_PARTICLES_VSL,
		KEY_PARTICLES_VCL,
		KEY_PARTICLES_ALH,
		KEY_PARTICLES_BCF,
		KEY_PARTICLES_STR,
		KEY_PARTICLES_LIN,		

		// ��� ����������
		KEY_PARTICLES_ASYMMETRY,
		KEY_PARTICLES_POINTEDFRONT,
		KEY_PARTICLES_POINTEDBACK,
		KEY_PARTICLES_ACROSOMEPERCENT,

        KEY_PARTICLES_DUMMY
};

enum KEYS_SPERM
{
        // ��� ����������
		KEY_SPERM_ASYMMETRY = KEY_BASE_SPERM, //���������� �������
		KEY_SPERM_POINTED_FRONT, // ������������� �����
		KEY_SPERM_POINTED_BACK, // ������������� �����
		KEY_SPERM_ACROSOME_PERCENT, // ������� ������� ��������
		KEY_SPERM_MITO_LENGTH, // ����� ���������������� ����� ������
		KEY_SPERM_MITO_WIDTH,  // ������
		KEY_SPERM_MITO_AREA, // �������
		KEY_SPERM_TAIL_SHIFT, // ����� ������ �� ��������� � ������� ��� �������
		KEY_SPERM_TAIL_ANGLE, // ���� ����� ������� � ������� ���� �������
		KEY_SPERM_TAIL_LENGTH, // ����� ������

        KEY_SPERM_DUMMY
};

enum KEYS_PHASE
{
        KEY_PHASE128AREA=KEY_BASE_PHASE+0, // ������� ���� 128
        KEY_PHASE129AREA, // ������� ���� 129
        KEY_PHASE130AREA, // ������� ���� 130

		KEY_PHASE_DUMMY,
};

enum KEYS_CHORD
{
        KEY_VCHORD_AVG=KEY_BASE_CHORD+0, // ������� �������� ������������ �����
        KEY_VCHORD_MIN,	// �����������
        KEY_VCHORD_MAX, // ������������

		KEY_CHORD_DUMMY,
};

enum KEYS_SHAPE
{
	KEY_CURVATURE_ENERGY = KEY_BASE_SHAPE,
	KEY_CURVATURE_MAX,
	KEY_MOMENTS_RATIO,
	KEY_BENDING_ENERGY,
	KEY_BRIGHTNESS_MOMENTS_DISP,
	KEY_SKELETON_PERIMETER_RATIO,
	KEY_POINTS_IN_ED,
	KEY_HORDES_RATIO
};

#define KEY_MEAN        (USERKEY+10)    // ������� ��������
#define KEY_DEV         (USERKEY+11)    // ���
#define KEY_VAR         (USERKEY+12)    // ����������� ��������
#define KEY_ERROR       (USERKEY+13)    // ���������� �����������
#define KEY_MIN         (USERKEY+14)    // min
#define KEY_MAX         (USERKEY+15)    // max
#define KEY_RA          (USERKEY+16)    //
#define KEY_REA         (USERKEY+17)    //
#define KEY_RN          (USERKEY+18)    //
#define KEY_REN         (USERKEY+19)    //
#define KEY_NUM         (USERKEY+20)    // ����������
#define KEY_MEANOBJ             (USERKEY+21)
#define KEY_PERCENT             (USERKEY+22)
#define KEY_SUMMA               (USERKEY+23)// ����� ��������


#define KEY_AREASUM (USERKEY+100)
#define KEY_VOLUMEPART (USERKEY+101)
#define KEY_SURFAREA (USERKEY+102)
#define KEY_UDELSURF (USERKEY+103)
#define KEY_AVERCHORD (USERKEY+104)
#define KEY_AVERDIST (USERKEY+105)
#define KEY_MODA (USERKEY+106)
#define KEY_UDEL_NUM (USERKEY+107)
#define KEY_ERR_AREAPERC (USERKEY+108)
#define KEY_NUM_CLASS (USERKEY+109)
#define KEY_STEP (USERKEY+110)
#define KEY_TOTAL_AREA (USERKEY+111)
#define KEY_AVER_DIFF_STD (USERKEY+150)
#define KEY_PERC_AVER_DIFF_STD (USERKEY+151)
#define KEY_DISP_DIFF_STD (USERKEY+152)
#define KEY_PERC_DISP_DIFF_STD (USERKEY+153)
#define KEY_AVER_DIFF_TBL (USERKEY+154)
#define KEY_PERC_AVER_DIFF_TBL (USERKEY+155)
#define KEY_DISP_DIFF_TBL (USERKEY+156)
#define KEY_PERC_DISP_DIFF_TBL (USERKEY+157)
#define KEY_SIGMA (USERKEY+158)

#define KEY_EXTERNAL_STAT (USERKEY+200)


#define KEY_CLASS       0xFFFFFFFE

//Meas params
#define MEAS_PARAMS_FIRST_KEY			0x00000
#define MEAS_PARAMS_LAST_KEY			(MEAS_PARAMS_FIRST_KEY + 0x20000)

//Meas user params
#define MEAS_USER_PARAMS_FIRST_KEY		(MEAS_PARAMS_LAST_KEY + 1)
#define MEAS_USER_PARAMS_LAST_KEY		(MEAS_USER_PARAMS_FIRST_KEY + 0x10000)

//Statistic params
#define STAT_PARAMS_FIRST_KEY			(MEAS_USER_PARAMS_LAST_KEY + 1)
#define STAT_PARAMS_LAST_KEY			(STAT_PARAMS_FIRST_KEY + 0x10000)
 
//Statistic user params
#define STAT_USER_PARAMS_FIRST_KEY		(STAT_PARAMS_LAST_KEY + 1)
#define STAT_USER_PARAMS_LAST_KEY		(STAT_USER_PARAMS_FIRST_KEY + 0x10000 - 2) // ����� � ��� ���������

//Base Paramaters
#define BASE_PARAMS_FIRST_KEY			(STAT_USER_PARAMS_LAST_KEY + 1 + 2)
#define BASE_PARAMS_LAST_KEY			(BASE_PARAMS_FIRST_KEY + 0x10000)

// Constant Parameters
#define CONST_PARAMS_FIRST_KEY		(BASE_PARAMS_LAST_KEY + 1)
#define CONST_PARAMS_LAST_KEY		(CONST_PARAMS_FIRST_KEY + 0x1000)
// Constant parameters for metal
#define KEY_PARAM_OBJECT1                CONST_PARAMS_FIRST_KEY
#define KEY_PARAM_OBJECT2                CONST_PARAMS_FIRST_KEY+1
// Constant parameters for blood (when using table)
#define KEY_X_OFFSET                CONST_PARAMS_FIRST_KEY+10
#define KEY_Y_OFFSET                CONST_PARAMS_FIRST_KEY+11

//Base parameters store in \BaseParamaters\key=value
#define BASE_PARAMS_SECTION				"BaseParameters"

#define MIN_FLOAT_VAL   1e-10
#define MAX_FLOAT_VAL   1e+10

//Square after cut by selection
#define BASE_PARAM_CUT_AREA             BASE_PARAMS_FIRST_KEY

//image size: cx & cy
#define BASE_PARAMS_IMAGE_WIDTH			( BASE_PARAMS_FIRST_KEY + 1 )
#define BASE_PARAMS_IMAGE_HEIGHT		( BASE_PARAMS_FIRST_KEY + 2 )
#define BASE_PARAMS_IMAGE_CALIBR		( BASE_PARAMS_FIRST_KEY + 3 )


//////////////////////////////////////////////
#define PARAM_STUDENT_IMG		STAT_USER_PARAMS_LAST_KEY + 2
#define PARAM_STUDENT_OB		STAT_USER_PARAMS_LAST_KEY + 1

#define PARAM_BASE		STAT_PARAMS_FIRST_KEY	// ������� ��������.
#define PARAM_MX		( PARAM_BASE + 0 )		// ������� ���������.
#define PARAM_MX_GEOM	( PARAM_BASE + 1 )		// ������� ���������.
#define PARAM_MX_GORM	( PARAM_BASE + 2 )		// ������� �����������.
#define PARAM_MIN		( PARAM_BASE + 3 )		// �������.
#define PARAM_MAX		( PARAM_BASE + 4 )		// ��������.
#define PARAM_VAR		( PARAM_BASE + 5 )		// ������ ��������.
#define PARAM_DISP		( PARAM_BASE + 6 )		// ���������.
#define PARAM_STDDEV	( PARAM_BASE + 7 )		// �����������. ����
#define PARAM_MODE		( PARAM_BASE + 8 )		// ����
#define PARAM_MEDIANE	( PARAM_BASE + 9 )		// �������
#define PARAM_ASSIMETRY	( PARAM_BASE + 10 )		// ����������
#define PARAM_EXCESS	( PARAM_BASE + 11 )		// �������
#define PARAM_COEF_VAR	( PARAM_BASE + 12 )		// ����. ���
#define PARAM_COUNT		( PARAM_BASE + 13 )		// ���������� ��������
#define PARAM_AREA		( PARAM_BASE + 14 )		// ������� ��������
#define PARAM_LENGTH	( PARAM_BASE + 15 )		// ����� ��������
#define PARAM_USEDAREA	( PARAM_BASE + 16 )		// ������������ �������
#define PARAM_SPECAREA	( PARAM_BASE + 17 )		// �������� �������
#define PARAM_SPECAREA_ERR ( PARAM_BASE + 18 )		// ������ �������� �������
#define PARAM_AREAPERC	( PARAM_BASE + 19 )		// % �������
#define PARAM_AREAPERC_ERR ( PARAM_BASE + 20 )		// ������ % �������
#define PARAM_NORMAL_AREA ( PARAM_BASE + 21 )		// ���������� �������
#define PARAM_SPECCOUNT ( PARAM_BASE + 22 )		// �������� ���-��
#define PARAM_SPECCOUNT_ERR ( PARAM_BASE + 23 )		// ������ �������� ���-��
#define PARAM_COUNTPERC ( PARAM_BASE + 24 )		// % ���-��
#define PARAM_COUNTPERC_ERR ( PARAM_BASE + 25 )		// ������ % ���-��
#define PARAM_NORMAL_COUNT ( PARAM_BASE + 26 )		// ���������� �����
#define PARAM_SPECLENGTH ( PARAM_BASE + 27 )		// �������� �����
#define PARAM_SPECLENGTH_ERR ( PARAM_BASE + 28 )	// ������ �������� �����
#define PARAM_3DPART ( PARAM_BASE + 29 )	// �������� ����
#define PARAM_MX_ERR ( PARAM_BASE + 30 )	// ������ ��������
#define PARAM_MX_PROB ( PARAM_BASE + 31 )	// ������� ����� ��������
#define PARAM_CHI_SQUARE ( PARAM_BASE + 32 )	// ��-�������
#define PARAM_CHI_SQUARE_LOG ( PARAM_BASE + 33 )	// ��-������� log
#define PARAM_IMAGE_COUNT ( PARAM_BASE + 34 )	// ���-�� �����������
#define PARAM_FULL_AREA ( PARAM_BASE + 35 )	// ����� (������ ��� ������������������) �������
#define PARAM_PERIMETR ( PARAM_BASE + 36 )	// ��������
#define PARAM_SURF_AREA ( PARAM_BASE + 37 )	// ������� �����������
#define PARAM_MDL_CHORD ( PARAM_BASE + 38 )	// ������� �����
#define PARAM_MDL_DIST ( PARAM_BASE + 39 )	// ������� ���������
#define PARAM_SURFAREAPERC  ( PARAM_BASE + 40 )	// % ������� �����������
#define PARAM_SPEC_SURF	( PARAM_BASE + 41 )	// �������� �����������
#define PARAM_SPEC_SURF_PERC	( PARAM_BASE + 42 )	// % �������� �����������

#define PARAM_STD_DEV_LOG	( PARAM_BASE + 43 )	// ��������������� �������� �����
#define PARAM_MX_ERR_LOG ( PARAM_BASE + 44 )	// log ������ �������� ���������.
#define PARAM_MX_PROB_LOG ( PARAM_BASE + 45 )	// ������������� �������� �������� ���������.
#define PARAM_MODE_LOG  ( PARAM_BASE + 46 )	// ���� log 
#define PARAM_ASSIMETRY_LOG ( PARAM_BASE + 47 )	// ���������� log 
#define PARAM_EXCESS_LOG ( PARAM_BASE + 48 ) // ������� log
#define PARAM_COEF_VAR_LOG ( PARAM_BASE + 49 )  // ����. ���. log
#define PARAM_DXLOG			( PARAM_BASE + 50 )
#define PARAM_MATHXLOG		( PARAM_BASE + 51 )

#define PARAM_MX_LOGNORM				( PARAM_BASE + 52 )
#define PARAM_DISP_LOGNORM			( PARAM_BASE + 53 )
#define PARAM_MODE_LOGNORM			( PARAM_BASE + 54 )
#define PARAM_ASSIMETRY_LOGNORM	( PARAM_BASE + 55 )
#define PARAM_EXCESS_LOGNORM		( PARAM_BASE + 56 )
#define PARAM_CHI2_CRITIC				( PARAM_BASE + 57 )
#define PARAM_WEIGHTED_AVERAGE	( PARAM_BASE + 58 )
#define PARAM_CHI2_PROB ( PARAM_BASE + 59 )	// ����������� �������� �� ��-�������
#define PARAM_CHI2_PROB_LOG ( PARAM_BASE + 60 )	// ����������� �������� �� ��-������� log

#define PARAM_FIRST_PARAM	PARAM_MX	   // ������ ��������

#define PARAM_LAST_PARAM	PARAM_CHI2_PROB_LOG	   // ��������� ��������
#define PARAM_SIZEOF_PARAM ( PARAM_LAST_PARAM - PARAM_BASE + 1 ) // ���-�� ����������

#define PARAM_LAST_PARAM_VER5	 PARAM_WEIGHTED_AVERAGE	   // ��������� ��������
#define PARAM_SIZEOF_PARAM_VER5 ( PARAM_LAST_PARAM_VER5 - PARAM_BASE + 1 ) // ���-�� ����������

#define PARAM_LAST_PARAM_VER4	PARAM_FULL_AREA	   // ��������� ��������
#define PARAM_SIZEOF_PARAM_VER4 ( PARAM_LAST_PARAM_VER4 - PARAM_BASE + 1 ) // ���-�� ����������

#define PARAM_LAST_PARAM_VER3	PARAM_CHI_SQUARE_LOG	   // ��������� ��������
#define PARAM_SIZEOF_PARAM_VER3 ( PARAM_LAST_PARAM_VER3 - PARAM_BASE + 1 ) // ���-�� ����������

#define PARAM_LAST_PARAM_VER2	PARAM_MX_PROB	   // ��������� ��������
#define PARAM_SIZEOF_PARAM_VER2 ( PARAM_LAST_PARAM_VER2 - PARAM_BASE + 1 ) // ���-�� ����������

#define PARAM_LAST_PARAM_VER1	PARAM_COUNT	   // ��������� ��������
#define PARAM_SIZEOF_PARAM_VER1 ( PARAM_LAST_PARAM_VER1 - PARAM_BASE + 1 ) // ���-�� ����������

#define PARAM_USERDEFINE_MIN_KEY STAT_USER_PARAMS_FIRST_KEY

#define MANUAL_NEXT_KEY  "ManualNextKey"
#define MEASUSER_NEXT_KEY "MeasUserNextKey"

//////////////////////////////////////////////

#endif //__Params_h__
