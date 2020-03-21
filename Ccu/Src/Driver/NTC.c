#include "ntc.h"

/*******************************************************************************
 文件说明：定义所有的NTC的“阻值-温度”表格
 定义并初始化NTC对象
*******************************************************************************/

////科帝特,KDT-P01,10K,B=3950K
//const static unsigned short NTC_3950_14BTAB[] =
//{
//	/*-50*/	16156 ,	16139 ,	16121 ,	16102 ,	16082 ,	16060 ,	16037 ,	16012 ,	15986 ,	15959 ,
//			15930 ,	15899 ,	15866 ,	15832 ,	15795 ,	15757 ,	15717 ,	15674 ,	15629 ,	15582 ,
//			15532 ,	15479 ,	15425 ,	15367 ,	15307 ,	15243 ,	15177 ,	15108 ,	15036 ,	14960 ,
//			14881 ,	14799 ,	14714 ,	14625 ,	14533 ,	14437 ,	14337 ,	14234 ,	14128 ,	14017 ,
//			13903 ,	13786 ,	13664 ,	13539 ,	13411 ,	13279 ,	13143 ,	13004 ,	12861 ,	12715 ,
//			12566 ,	12413 ,	12258 ,	12099 ,	11938 ,	11774 ,	11608 ,	11439 ,	11267 ,	11094 ,
//			10920 ,	10742 ,	10564 ,	10384 ,	10203 ,	10021 ,	9839 ,	9655 ,	9472 ,	9288 ,
//			9104 ,	8920 ,	8737 ,	8554 ,	8373 ,	8192 ,	8012 ,	7833 ,	7655 ,	7480 ,
//			7306 ,	7133 ,	6963 ,	6794 ,	6628 ,	6465 ,	6304 ,	6144 ,	5988 ,	5834 ,
//			5683 ,	5535 ,	5389 ,	5246 ,	5106 ,	4969 ,	4834 ,	4703 ,	4575 ,	4449 ,
//			4326 ,	4206 ,	4089 ,	3974 ,	3863 ,	3754 ,	3648 ,	3545 ,	3444 ,	3346 ,
//			3251 ,	3158 ,	3068 ,	2980 ,	2895 ,	2812 ,	2731 ,	2653 ,	2576 ,	2503 ,
//			2431 ,	2361 ,	2293 ,	2227 ,	2163 ,	2101 ,	2041 ,	1983 ,	1926 ,	1871 ,
//			1818 ,	1766 ,	1716 ,	1667 ,	1620 ,	1574 ,	1530 ,	1487 ,	1446 ,	1405 ,
//			1365 ,	1328 ,	1290 ,	1254 ,	1221 ,	1187 ,	1154 ,	1122 ,	1092 ,	1062 ,
//			1033 ,	1004 ,	978 ,	951 ,	926 ,	901 ,	876 ,	854 ,	831 ,	808 ,
//			788 ,	767 ,	747 ,	728 ,	708 ,	690 ,	672 ,	654 ,	638 ,	623 ,
//	/*120*/	606 ,	591 ,	575 ,	562 ,	546 ,	534 
//};
//
////赛斯通,SK103FJ1000ST,10K,B=3435K
//const static unsigned short NTC_3435_14BTAB[] =
//{
//	/*-50*/	15910 ,	15883 ,	15854 ,	15824 ,	15793 ,	15760 ,	15726 ,	15690 ,	15652 ,	15613 ,
//			15572 ,	15529 ,	15484 ,	15437 ,	15388 ,	15337 ,	15285 ,	15230 ,	15173 ,	15113 ,
//			15051 ,	14988 ,	14920 ,	14852 ,	14780 ,	14706 ,	14630 ,	14551 ,	14469 ,	14385 ,
//			14297 ,	14208 ,	14115 ,	14020 ,	13922 ,	13822 ,	13718 ,	13612 ,	13504 ,	13392 ,
//			13278 ,	13161 ,	13042 ,	12920 ,	12796 ,	12670 ,	12541 ,	12409 ,	12276 ,	12140 ,
//			12002 ,	11862 ,	11720 ,	11577 ,	11432 ,	11285 ,	11136 ,	10987 ,	10836 ,	10684 ,
//			10530 ,	10376 ,	10221 ,	10066 ,	9910 ,	9753 ,	9596 ,	9440 ,	9282 ,	9126 ,
//			8969 ,	8812 ,	8656 ,	8500 ,	8346 ,	8192 ,	8038 ,	7886 ,	7734 ,	7584 ,
//			7435 ,	7288 ,	7142 ,	6997 ,	6854 ,	6712 ,	6572 ,	6434 ,	6298 ,	6163 ,
//			6030 ,	5900 ,	5771 ,	5644 ,	5519 ,	5397 ,	5276 ,	5157 ,	5041 ,	4926 ,
//			4813 ,	4703 ,	4594 ,	4488 ,	4384 ,	4282 ,	4182 ,	4084 ,	3989 ,	3894 ,
//			3802 ,	3712 ,	3625 ,	3539 ,	3454 ,	3372 ,	3291 ,	3213 ,	3137 ,	3061 ,
//			2988 ,	2917 ,	2847 ,	2779 ,	2712 ,	2647 ,	2584 ,	2523 ,	2463 ,	2403 ,
//			2346 ,	2290 ,	2235 ,	2183 ,	2129 ,	2080 ,	2030 ,	1982 ,	1935 ,	1890 ,
//			1845 ,	1801 ,	1759 ,	1717 ,	1678 ,	1638 ,	1601 ,	1563 ,	1527 ,	1492 ,
//			1457 ,	1424 ,	1391 ,	1359 ,	1328 ,	1298 ,	1268 ,	1239 ,	1211 ,	1184 ,
//			1158 ,	1132 ,	1106 ,	1082 ,	1058 ,	1035 ,	1012 ,	990 ,	968 ,	947 ,
//	/*120*/	926 
//
//};
//
//const static unsigned long NTC_103KT1608T_RESTAB[] =
//{
//	/*-40*/	192010  ,	181838  ,	172236  ,	163182  ,	154653  ,	146625  ,	139208  ,	132090  ,	125397  ,	119000  ,
//			112995  ,	107441  ,	101982  ,	97008   ,	92202   ,	87692   ,	83457   ,	79427   ,	75596   ,	71997   ,
//			68538   ,	65324   ,	62235   ,	59331   ,	56570   ,	53971   ,	51475   ,	49123   ,	46905   ,	44774   ,
//			42763   ,	40847   ,	39036   ,	37309   ,	35673   ,	34123   ,	32642   ,	31225   ,	29890   ,	28612   ,
//			27396   ,	26238   ,	25134   ,	24089   ,	23090   ,	22136   ,	21224   ,	20361   ,	19535   ,	18747   ,
//			17991   ,	17273   ,	16587   ,	15935   ,	15310   ,	14710   ,	14139   ,	13596   ,	13071   ,	12575   ,
//			12097   ,	11639   ,	11202   ,	10783   ,	10384   ,	10001   ,	9632    ,	9281    ,	8942    ,	8619    ,
//			8309    ,	8013    ,	7729    ,	7455    ,	7193    ,	6940    ,	6699    ,	6467    ,	6245    ,	6030    ,
//			5824    ,	5628    ,	5438    ,	5256    ,	5080    ,	4913    ,	4750    ,	4594    ,	4445    ,	4300    ,
//			4160    ,	4027    ,	3897    ,	3773    ,	3654    ,	3539    ,	3428    ,	3321    ,	3218    ,	3118    ,
//			3022    ,	2930    ,	2841    ,	2755    ,	2672    ,	2592    ,	2514    ,	2440    ,	2368    ,	2298    ,
//			2231    ,	2166    ,	2103    ,	2043    ,	1984    ,	1927    ,	1873    ,	1820    ,	1769    ,	1719    ,
//			1671    ,	1625    ,	1580    ,	1537    ,	1494    ,	1454    ,	1414    ,	1376    ,	1339    ,	1304    ,
//			1269    ,	1235    ,	1203    ,	1171    ,	1141    ,	1111    ,	1083    ,	1055    ,	1028    ,	1002    ,
//			976     ,	952     ,	928     ,	905     ,	882     ,	860     ,	839     ,	818     ,	798     ,	779     ,
//			761     ,	742     ,	724     ,	707     ,	690     ,	674     ,	658     ,	643     ,	628     ,	614     ,
//	/*120*/	599     ,
//};

//热敏电阻JAS103J410JA的“阻值-温度”对应表
const static unsigned long NTC_JAS103J410JA_RESTAB[] =
{
	/*-40*/ 342803, 323156, 304557, 286966, 270346, 254654, 239851, 225895, 212745, 200361,
	/*-30*/ 188703, 177734, 167415, 157711, 148588, 140011, 131951, 124375, 117256, 110567,
	/*-20*/ 104281, 98375,  92824,  87608,  82706,  78097,  73765,  69692,  65862,  62260,
	/*-10*/ 58872,  55684,  52684,  49860,  47201,  44698,  42339,  40118,  38024,  36050,
	/*  0*/ 34190,  32435,  30779,  29217,  27742,  26350,  25035,  23792,  22618,  21509,
	/* 10*/ 20460,  19467,  18529,  17640,  16799,  16003,  15249,  14535,  13857,  13216,
	/* 20*/ 12607,  12030,  11482,  10962,  10469,  10000,  9555,   9132,   8730,   8348,
	/* 30*/ 7985,   7640,   7311,   6998,   6700,   6417,   6147,   5890,   5645,   5411,
	/* 40*/ 5189,   4976,   4774,   4581,   4397,   4221,   4053,   3892,   3739,   3593,
	/* 50*/ 3453,   3319,   3191,   3069,   2952,   2840,   2733,   2631,   2533,   2439,
	/* 60*/ 2349,   2263,   2180,   2101,   2025,   1953,   1883,   1816,   1752,   1690,
	/* 70*/ 1631,   1575,   1520,   1468,   1418,   1370,   1323,   1279,   1236,   1195,
	/* 80*/ 1155,   1117,   1081,   1046,   1012,   979,    948,    918,    889,    861,
	/* 90*/ 834,    808,    783,    759,    735,    713,    691,    671,    650,    631,
	/*100*/ 612,    594,    577,    560,    544,    528,    513,    499,    484,    471,
	/*110*/ 458,    445,    433,    421,    409,    398,    387,    377,    367,    357,
	/*120*/ 348,    338,    330,    321,    313,    305,
};

Ntc g_Ntc[] =
{
	{NTC_JAS103J410JA, NTC_JAS103J410JA_RESTAB, sizeof(NTC_JAS103J410JA_RESTAB) / 4, -40}
};

Ntc* Ntc_Create(NTC_TYPE type)
{
	for (int i = 0; i < sizeof(g_Ntc) / sizeof(Ntc); i++)
	{
		if (g_Ntc[i].type == (unsigned char)type) return &g_Ntc[i];
	}
	return 0;
}
