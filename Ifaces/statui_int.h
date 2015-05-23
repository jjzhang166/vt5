#pragma once

//------------------------------------------------------------------
#include "params.h"

#define STAT_VERSION "StatVersion"
#define STAT_VERSION_NUM 6L

//------------------------------------------------------------------
#define SECT_STATUI_ROOT		"\\StatUI"				// ����� �������������� ������
#define SECT_DEPENDENCE_ROOT	"\\StatDependence"		// C����� ��������� �����������
#define	SECT_STATCMP_ROOT		"\\StatCompare"			// ������ ��������� ���������

#define CALC_FOR_GROUPS "CalcForGroups"			// ��� ����� ����������� �����������
#define CALC_FOR_ALL_CLASSES "CalcForAllClasses"			// ��� ����� ������� ����������� �����
#define CALC_FOR_RELATIVE_CLASSES "CalcForRelativeClasses"			// ��� ����� ������� ����������� ������������� ���������

#define SPLITTER_TYPE	"SplitterType"		// ��� ���������
#define PANE0_DATA		"Pane0_Data"		// ������ � ���� 0
#define PANE1_DATA		"Pane1_Data"		// ������ � ���� 1
#define PANE2_DATA		"Pane2_Data"		// ������ � ���� 2
#define CLASS_FILE		"ClassFile"			// ������ � ���� 2
#define	STATTABLE_OWN	"OwnStatTable"		// Guid ������� ������, �� �������� ���� ������� ����������
//------------------------------------------------------------------
#define FORM_NAME_TABLE_AREA "TableStatArea_PropertyScript" // �������� ������ ������� �������� ����������
#define FORM_NAME_LEGEND_AREA "StatParamArea_PropertyScript" // �������� ������ ������� ����������� ����������
#define FORM_NAME_CHART_AREA "ChartArea_PropertyScript" // �������� ������ ������� ����� �������
#define FORM_NAME_AXIS_AREA "AxisArea_PropertyScript" // �������� ������ ������� ����
#define FORM_NAME_XPARAM_AREA "X_ParamsArea_PropertyScript" // �������� ������ ������� ���������� ��� ��� X
#define FORM_NAME_YPARAM_AREA "Y_ParamsArea_PropertyScript" // �������� ������ ������� ���������� ��� ��� Y

#define INDEX_TABLE_AREA "TableStatArea_ImgIndex" // ������ �������� ��� ������ ������ ������� �������� ����������
#define INDEX_LEGEND_AREA "StatParamArea_ImgIndex" // ������ �������� ��� ������ ������ ������� ����������� ����������
#define INDEX_CHART_AREA "ChartArea_ImgIndex" // ������ �������� ��� ������ ������ ������� ����� �������
#define INDEX_AXIS_AREA "AxisArea_ImgIndex" // ������ �������� ��� ������ ������ ������� ����
#define INDEX_XPARAM_AREA "X_ParamsArea_ImgIndex" // ������ �������� ��� ������ ������ ������� ���������� ��� ��� X
#define INDEX_YPARAM_AREA "Y_ParamsArea_ImgIndex" // ������ �������� ��� ������ ������ ������� ���������� ��� ��� Y

#define ENABLE_CHART_AREA		"Enable_ChartArea"     // �������� ���� ������� ����� �������. ��������: [0;1] Def: 1
#define ENABLE_STAT_PARAM_AREA	"Enable_StatParamArea" // �������� ���� ������� ����������� ����������. ��������: [0;1] Default: 1
#define ENABLE_TABLE_STAT_AREA	"Enable_TableStatArea" // �������� ���� ������� �������� ���������� . ��������: [0;1] Default: 1
#define ENABLE_AXIS_AREA		"Enable_AxisArea"	   // �������� ���� ������� ����. ��������: [0;1] Default: 1
#define ENABLE_X_PARAMS_AREA	"Enable_X_ParamsArea"  // �������� ���� ������� ���������� ��� ��� X. ��������: [0;1] Default: 1
#define ENABLE_Y_PARAMS_AREA	"Enable_Y_ParamsArea"  // �������� ���� ������� ���������� ��� ��� Y. ��������: [0;1] Default: 1

#define ENABLE_Y_PARAMS_AREA	"Enable_Y_ParamsArea"  // �������� ���� ������� ���������� ��� ��� Y. ��������: [0;1] Default: 1
#define ENABLE_Y_PARAMS_AREA	"Enable_Y_ParamsArea"  // �������� ���� ������� ���������� ��� ��� Y. ��������: [0;1] Default: 1

#define DEPENDENCE_TYPE "DependenceType" // ��� �����������. ��������: [0(�����);1(������); 2(����������)] Default: 0
#define MARKER_TYPE "MarkerType" // ��� �������. ��������: [0(��������������);1(����������); 2(�������)] Default: 2
#define MARKER_SIZE_2 "MarkerSize"  // ������ �������. Default: 2
#define MODEL_TYPE "ModelType"  // �����������. Def:0 ��������: 
												//	0:   y= a + b * x
												//	1:   y = 1 \ ( a + b * x )
												//	2:   y = a + b \ x
												//	3:   y = x \ ( a + b * x )
												//	4:   y = a * exp( b * x )
												//	5:   y = a * 10 ^ (b * x )
												//	6:   y = 1 \ ( a + b * e ^  (- x )  )
												//	7:   y = a * x  ^  b
												//	8:   y = a  +  b * lg( x )
												//	9:   y = a  +  b * ln( x )
												//	10: y = a * exp( b \ x )
												//	11: y = a + b * x ^ 2
												//	12: y = a + b * x ^ 3

#define MARKER_COLOR "MarkerColor"  // ���� �������. Default: 2
#define SHOW_MODEL "ShowModel"  // ���������� �� ������
#define ENABLE_CONNECTING_LINES "EnableConnectingLines"
#define CONN_LINES_CLR "ConnectingLineColor"

//------------------------------------------------------------------
#define SECT_STATUI_STAT_PARAM_ROOT sMainStatParamsSection	// ��������� ���������
#define NORMAL_AREA "NormalArea"
#define MX_PROPABILITY "Probability"


#define PARAM_NAME sUserName // ��������
#define FORMAT_STRING sFormat // ����������� ������� �����������. ������: %0.3f
#define DESIGNATION sGraphics // ���������� �����������
#define MODULE_OF_DESIGN "Units" // ������� ���������
#define PARAM_VISIBILITY "Visible"
//#define SHOW_ON_GRAPH "ShowOnGraph" // ����������� ���������� �� �������.
#define CALC_FROM "CalcFrom" //������ �������. ��������: [0(�� ��������);1(�� ������������)].
#define EXPRESSION_STRING sExprString // ������ � ��������� �������� � ���� �������
#define CALC_METHOD "CalcMethod" // �� ������ ������ �������. ��������(����� ������): [-1(�� �������); 0..n].
#define PARAM_GREEK_SYMB sGreekSymbol
#define PARAM_CLASSIFIER sClassifier
#define PARAM_TABLE_ORDER "TableOrder"
#define PARAM_LEGEND_ORDER "LegendOrder"

//------------------------------------------------------------------
#define SECT_STATUI_STAT_LEGEND "\\StatUI\\Legend"			// ��������� �������
#define SECT_STATCMP_STAT_LEGEND "\\StatCompare\\Legend"	// ��������� ������� ��� ��������� 

#define SECT_STATUI_LEGEND_TITLE_FONT_ROOT "\\StatUI\\Legend\\TitleFont" // ��������� ������ ���������

#define TEXT_COLOR "TextColor" // ���� ��� ����������� ��������. Default: ( 0, 0, 0 )
#define SAMPLING_COLOR "SamplingColor" // ���� ������� ��� ���������. Default: ( 0, 0, 0 )
#define SAMPLING_NAME "SamplingName" // �������� ������� ��� ���������. 

#define FISHER_PROBABILITY "FisherProbability"
#define SECT_STATUI_STAT_LEGEND_USERDATA "\\StatUI\\Legend\\UserValues"	// �������������� ������
#define ENTRY_NAME "EntryName" // �������� ������
#define ENTRY_VALUE "EntryValue" // �������� ������
#define ENTRY_ORDER "EntryOrder" // �������� ������

#define SECT_STATUI_STAT_TABLE_USERDATA "\\StatUI\\StatTable\\UserValues"	// �������������� ������

//---
#define SECT_STATUI_STAT_LEGEND_FONT "\\StatUI\\Legend\\Font\\"	// ��������� ������
//------------------------------------------------------------------
#define SECT_STATUI_STAT_TABLE "\\StatUI\\StatTable\\"	// ��������� ������� ����������
#define SECT_STATUI_TABLE_TITLE_FONT_ROOT "\\StatUI\\StatTable\\TitleFont" // ��������� ������ ���������

#define INCORRECT_COLOR "IncorrectColor" // ���� ��� ����������� ������������ ��������. Default: ( 255, 0, 0 )
#define HIGHLIGHT_COLOR "HighlightColor" // ���� ��� ��������� ��������. Default:(127,127,127)
//--
#define SECT_STATUI_STAT_TABLE_COLOR "\\StatUI\\StatTable\\Colors\\"	// ��������� ������ ������� ����������
//--
#define SECT_STATUI_STAT_TABLE_WIDTH "\\StatUI\\StatTable\\Width\\"	// ��������� ������ �������� ������� ����������

#define COLUMN_COLOR_ID "Column" // ���� ������� ����� [X]. Default: ( 0, 0, 0)
//--
#define SECT_STATUI_STAT_TABLE_FONT "\\StatUI\\StatTable\\Font\\"	// ��������� ������ �������
#define SECT_STATUI_STAT_TABLE_HEADER_FONT "\\StatUI\\StatTable\\HeaderFont\\"	// ��������� ������ �������
//--
#define FONT_NAME "Name" // �������� ������. Default: Arial
#define FONT_SIZE "Size" // ������ � ������������ �������: Default: 10
#define FONT_BOLD "Bold" // ��������. Default: 0
#define FONT_ITALIC "Italic" // ���������. Default: 0
#define FONT_UNDERLINE "Underline" // ������������. Default: 0
#define FONT_STRIKEOUT "StrikeOut" // �������������. Default: 0
//------------------------------------------------------------------
#define CALC_FULL_STAT_CLASSES "CalcFullStatClasses" // �� ����� ������� ������� ����� ����������. Default: -1 ( �� ���� )
//------------------------------------------------------------------
#define SECT_STATUI_CHART_ROOT "\\StatUI\\ChartParams" // ��������� �������
#define SECT_DEPENDENCE_CHART_ROOT "\\StatDependence\\ChartParams" // ��������� ��� ����������� �������
#define SECT_STATCMP_CHART_ROOT "\\StatCompare\\ChartParams" // ��������� ��� ��������� �������

#define CHART_TYPE "ChartType" // ��� �������. ��������: [0(���������);1(���������
#define CHART_VIEW_TYPE "ChartViewType" //��� �������. ��������: [0(���������);1(��������)] Default: 0
#define CHART_COLOR "ChartColor" // ���� ����������� ��������� �������. Default: (255,0,0)
#define SHOW_GRAY_SCALE "ShowGrayScale" // ��� ��������� ��������. ��������: [0(������);1(�����)] Default: 1
#define GRAY_SCALE_LEVEL "GrayScaleLevel" // ������� ������ ������. ��������: [0..255] Default: 128
#define CHART_TITLE "Title" // ���������
#define CLASSES_NAME "XParamName" // �������� ��������� �� ��� X d ������ �� ������
#define SHOW_LEGEND "ShowLegend" // ���������� �������. ��������: [0(�������);1(�������)] Default: 0
#define SHOW_CURVE "ShowCurve" // ����������� ������ ������ �������������. ��������: [0;1] Default: 0
#define UNIFORM_DISTRIBUTION "UniformDistribution" // ����� �������������. ��������: [0(����������);1(�������������)] Default: 0
#define CURVE_COLOR "CurveColor" // ���� ������ �������������. Default: ( 0, 0, 0 )
#define COLOR_HATCH "ColorHatch"

#define SHOW_USERCURVE "ShowUserCurve" // ����������� ������ ������ ������������� ������������. Default: 0
#define USERCURVE_COLOR "UserCurveColor" // ���� ������ ������������� ������������. Default: ( 0, 0, 255 )
#define USERCURVE_MX "UserCurveMX" // ���. �������� ����������������� ������ �������������. Default: 0
#define USERCURVE_DX "UserCurveDX" // ��������� ����������������� ������ �������������. Default: 1
#define VISIBLE_CLASSES "VisibleClass" // ��������� ����������������� ������ �������������. Default: 1

#define DISTRIBUTION_SCRIPT "DistributionScript" // �������� ������� ����������� ��� ������� ����� �� �������
#define HALF_HOT_ZONE "HalfHotZone" // �������� ������ �������� ���� ����� � ������ ������ ��� ������������ �����. Default: 1
#define CHART_PARAM_HEIGHT "ChartParamHeight" // ������ �������������� ����������. Default: 10
#define MIN_CLASS_INDEX "MinClassIndex" // ������ ������ � �������� ��������. Default: 0
#define CLASS_STEP "ClassStep" // ��� ������ �������. Default: 1
#define CLASS_COL_TITLE "ClassColTitle" // ���������
#define ALL_WORD "AllWordName" // ���������
#define SHOW_SINGLE_COLORED_BAR "ShowSingleColoredBar" // ��������� ��� ������� ������ �����. ��������: [0,1] Default: 0
#define BAR_SINGLE_COLOR "BarSingleColor" // ������� ������ ������. ��������: [0..255] Default: 128

#define SHOW_BEGIN_END "ShowBeginEnd" // ������, �����. ��������: [0;1] Default: 1
#define SHOW_STEP "ShowStep" // ���. ��������: [0;1] Default: 1
#define SHOW_CLASS_COUNT "ShowClassCount" // ���-�� �������. ��������: [0;1] Default: 1
#define SHOW_CHECK_MODEL "ShowCheckModel" // ���������� �������� ��������. ��������: [0;1] Default: 1
#define CHECK_MODEL_TYPE "CheckModelType" // ��� �������� ��������. ��������: [0(��-�������);1(�����)] Default: 0
#define USER_SIGNATURE "Signature" // ������� ������������

#define BAR_WIDTH "BarWidth" // ������ �������� �����������. 
#define BAR_WIDTH_SPACE "BarWidthSpace" //������ ����� ��������� �� ������ �������

#define SECT_STATUI_CHART_TITLE_FONT_ROOT "\\StatUI\\ChartParams\\TitleFont" // ��������� ������ ��������� �������
#define SECT_STATUI_CHART_LEGEND_FONT_ROOT "\\StatUI\\ChartParams\\LegendFont"  // ��������� ������ ������� �������
#define SECT_STATUI_CHART_AXIS_FONT_ROOT "\\StatUI\\ChartParams\\AxisFont"  // ��������� ������ �������� �������
#define SECT_STATUI_CHART_SIGNATURE_FONT_ROOT "\\StatUI\\ChartParams\\SignatureFont" // ��������� ������ ��������� �������
#define SECT_STATUI_CHART_HINT_FONT_ROOT "\\StatUI\\ChartParams\\HintFont" // ��������� ������ ������� (����)  �� �������
#define SECT_STATUI_CHART_PARAM_FONT_ROOT "\\StatUI\\ChartParams\\ParamNameFont" // ��������� ������ ���������� �������

#define SECT_DEPENDENCE_CHART_TITLE_FONT_ROOT "\\StatDependence\\ChartParams\\TitleFont" // ��������� ������ ��������� �������  ��� �����������
#define SECT_DEPENDENCE_CHART_LEGEND_FONT_ROOT "\\StatDependence\\ChartParams\\LegendFont"  // ��������� ������ ������� �������  ��� �����������
#define SECT_DEPENDENCE_CHART_AXIS_FONT_ROOT "\\StatDependence\\ChartParams\\AxisFont"  // ��������� ������ �������� �������  ��� �����������
#define SECT_DEPENDENCE_CHART_PARAM_FONT_ROOT "\\StatDependence\\ChartParams\\ParamNameFont" // ��������� ������ ���������� �������  ��� �����������

//--
#define SECT_STATUI_CHART_AXIS_ROOT "\\StatUI\\ChartParams\\Axis" // ��������� ���� �������
#define SECT_DEPENDENCE_CHART_AXIS_ROOT "\\StatDependence\\ChartParams\\Axis" // ��������� ���� ��� ����������� �������

#define X_USE_LOGA_SCALE "X_UseLogaScale" // ������������ ��������������� ����� ��� X. ��������: [0;1] Default: 1
#define Y_USE_LOGA_SCALE "Y_UseLogaScale" // ������������ ��������������� ����� ��� y. ��������: [0;1] Default: 1

#define X_AXIS_TYPE "X_AxisType" // ����� ��� ��������. ��������: [0(�����);1(��������)]
#define X_PARAM_KEY "X_ParamKey" // ��� ���������.

#define X_USE_CUSTOM_FORMAT "X_UseCustomFormat" 
#define Y_USE_CUSTOM_FORMAT "Y_UseCustomFormat" 

#define X_CUSTOM_FORMAT "X_CustomFormat" 
#define Y_CUSTOM_FORMAT "Y_CustomFormat" 

#define X_BEGIN "X_Begin" // ������ �������� �� ���
#define X_END "X_End" // ����� �������� �� ���

#define Y_BEGIN "Y_Begin" // ������ �������� �� ���
#define Y_END "Y_End" // ����� �������� �� ���

#define X_USE_VALUE_RANGE "X_UseValueRange" // ������������ �������� ��������. ��������: [0;1] Default: 0
#define Y_USE_VALUE_RANGE "Y_UseValueRange" // ������������ �������� ��������. ��������: [0;1] Default: 0

#define X_SHOW_AXIS_VALUES "X_ShowAxisValues" // ���������� ��������. ��������: [0;1]
#define Y_SHOW_AXIS_VALUES "Y_ShowAxisValues" // ���������� ��������. ��������: [0;1]

#define X_SHOW_AXIS_LABELS "X_ShowAxisLabels" // ���������� ������. ��������: [0;1]
#define Y_SHOW_AXIS_LABELS "Y_ShowAxisLabels" // ���������� ������. ��������: [0;1]

#define X_TEXT_OFFSET "X_TextOffset"
#define Y_TEXT_OFFSET "Y_TextOffset"


#define X_SCALE_FACTOR "X_ScaleFactor" // ��� ������� �� ��� X.
#define X_SCALE_FACTOR_VALUES "X_ScaleFactorValues" // ��� �������� �� ��� X.
#define X_SCALE_FACTOR_GRID "X_ScaleFactorGrid" // ��� ����� �� ��� X.

#define X_LOGARITHMIC_SCALE "X_LogarithmicScale" // ��������������� �����. ��������: [0;1]
#define X_GRID "X_Grid" // ����� �� ���. ��������: [0(�� ���� �������);1(0,5 ���� �������)]
#define Y_PARAM_KEY "Y_ParamKey" // ��� ���������.

#define Y_SCALE_FACTOR "Y_ScaleFactor" // ��� ������� �� ��� Y.
#define Y_SCALE_FACTOR_VALUES "Y_ScaleFactorValues" // ��� �������� �� ��� Y.
#define Y_SCALE_FACTOR_GRID "Y_ScaleFactorGrid" // ��� ����� �� ��� Y.

#define Y_GRID "Y_Grid" // ����� �� ���. 
#define GRID_COLOR "GridColor" // ���� �����. Default: 0

#define CONVERT_TO_CALIBR "ConvertToCalibr"

#define DRAW_END_CHART_GRID_LINE_X "DrawEndChartGridLineX"
#define DRAW_END_CHART_GRID_LINE_Y "DrawEndChartGridLineY"
#define TABLE_ALIGN "TableAlign"

#define USE_CUSTOM_INTERVALS "UseCustomIntervals"
#define SECT_CUSTOM_INTERVALS "\\CustomIntervals"
#define ERROR_NUMBER "ErrorNumber"
#define ERROR_STRING "ErrorString"

#define SECT_DEPENDENCE_RESULT_ROOT "\\StatDependence\\Result"
#define RESUL_MODEL			"ModelIndex"
#define RESUL_CORREL		"Correlation"
#define RESUL_COEF_A		"Coef_A"
#define RESUL_COEF_B		"Coef_B"
#define RESULT_ALL_COUNT	"AllCount"		// ���������� �������� � ������� ������
#define RESULT_CURR_COUNT	"CurrCount"		// �������� ���������� ��������, ������������ � �����������

//------------------------------------------------------------------
#define SECT_STATUI_VIRTUAL_CLASSES_DIVISION_ROOT "\\StatUI\\VirtualClassesDivision" // ��������� ���������� �� ����������� ������
#define DIVISION_CLASS_COUNT "ClassCount" //���-�� ������� �� ������� ����� ������������ �������: Default: 0
#define DIVISION_TYPE "DivisionType:" // ��� �������. ��������: [0(����.);1(�������)] Default: 0
#define DIVISION_VALUE "DivisionValue" // �������� �������. 

//------------------------------------------------------------------
#define PROPBAG_PANES  "Views"
//------------------------------------------------------------------
#define VIRTUAL_STAT_CLASSIFIER  "VirtualClasses.ini"
#define VIRTUAL_MAIN_CLASS  "VirtualMainClass"
#define VIRTUAL_CLASS_COUNT  "VirtualClassCount"
//------------------------------------------------------------------