#pragma once

// 参数化建模 模块 数据结构定义
#include <vector>
#include <QtCore/qstring.h>
using namespace std;

typedef vector<int> VINT;
typedef vector<VINT> VVINT;
typedef vector<float> VFLOAT;

// 整型平面点
typedef struct PixelPos
{
	int nXY[2];
}PixelPos;
typedef vector<PixelPos> VPIXELPOS;

typedef struct SimpleShape
{
	int nCen[2];			// 中心点
	int nWH[2];				// 宽高 XY范围
	int unitType;
	int unitIdx;
	VPIXELPOS vCorner;
}SimpleShape;
typedef vector<SimpleShape> VSHAPE;



// 空间三维点
typedef struct Ver3D
{
	int nIdx;
	float fXYZ[3];			//空间位置 Y为空间高度
}Ver3D;
typedef vector<Ver3D> V3DPT;
typedef vector<V3DPT> VV3DPT;

typedef struct GeoShape
{
	int nShapeType;				// 形状类型 方 圆 多边形
	int nThickNess;				// 墙和板的厚度
	int nShapeRange[4];			// 外框的左下右上 从小到大
	int nCen[2];				// 中心点 圆心点
	int nNumOrRadius;			// 圆半径 或者 多边形点数量
	QString nShapeName;				// 构建名称
	VINT vPolyPt;				// 多边形闭合顶点集 逆时针排列 首尾点重合
}GeoShape;

typedef struct MatInfo
{
	int MatType;				// 材质类型
	int nMatPicType;			// 材质贴图类型
	VFLOAT vMatPara;			// 材质属性
}MatInfo;

// 基本构件单元
typedef struct BasicUnit
{
	int nUnitIdx;				// 基本构件单元Idx
	int nUnitType;				// 基本单元类型 线柱梁板墙门窗
	GeoShape oShape;			// 外形轮廓描述
	MatInfo  oMaterial;			// 组成材质描述
}BasicUnit;
typedef vector<BasicUnit> VUNITTABLE;

// 基本拓扑单元
typedef struct TopoUnit
{
	int nTopoIdx;				// 构件序号
	int nUnitType;				// 中心构件单元类型 线柱梁板墙门窗
	int nCenUnitIdx;			// 中心构件单元Id
	int nAdjUnitIdx[12];		// 前后左右方向 按上下表示梁墙 每方向最多两个 邻接单元Id 无邻接-1
	int nEdgeType;				// 边界类型 前后上下左右 按向限角度划分 45度 右上为1 正下为6
	int nStatusFlag;			// 标志0 1 2 正常 删除 其他
	int nUnitAngle;				// 0 90度 两种
	int nCenPos[4];				// 基本构件单元的中心线下点 和上点高度  Y值表示高度
}TopoUnit;
typedef vector<TopoUnit> VTOPOTABLE;
typedef vector<TopoUnit> VLAYERTOPO;
typedef vector<VLAYERTOPO> VBUILDTOPO;

// 拓扑单元对应的实际空间数据
typedef struct UnitData
{
	Ver3D oData[8];
}UnitData;
typedef vector<UnitData> VUNITDATA;

// 设计系统模板库的存储方式 IO操作库

// 构建系统模板库的 构件表格和对应的拓扑表格

// 设计单类视图的基本模板关联移动 编辑 功能

// 设计多个视图的基本模板关联移动 编辑 功能

// 属性之间的合规性检查

// 系统路径信息
typedef struct SysPath
{
	string sExePath;			// 可执行文件完整路径 含.exe
	string sExeDir;				// 可执行文件所在目录完整路径
	string sProcLibDir;			// 算法库路径
	string sTmpDir;				// 临时数据路径
	string sModelLibDir;		// 模型路径
	string sBoomLibDir;			// 弹文件路径
	string sParaLibDir;			// 弹及材料参数路径
}SysPath;