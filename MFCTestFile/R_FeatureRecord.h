
#include<list>
#include"F_ATTR.h"
class R_FeatureRecord
{
public:
	R_FeatureRecord(void);
	~R_FeatureRecord(void);

public:
	//F_FRID m_frid;
	//F_FOID m_foid;
	std::list<F_ATTR*> m_attr;
	//std::list<F_INAS*> m_inas;
	//std::list<F_SPAS*> m_spas;
	//std::list<F_FASC*> m_fasc;
	////F_THAS *m_thas;
	//std::list<F_MASK*> m_mask;
	//SGeometry *m_geometry;
	//std::map<unsigned, SGeometry*> m_geometryOfPart;
	//S101_ConditionalSymbol *m_cs;
	//// for get to feature instruction
	//std::vector<SENC_Attribute*> m_attrList;

	int m_scaleMin;
	int m_scaleMax;
	int m_bShownAllScale;

	int m_displayPriority;
	int m_viewingGroup;
	//__int64 m_overGroup;
	int m_displayCategory;
	int m_radarOver;
	bool m_hasText;

//	std::list<R_PointRecord*> m_pointList;
//	std::list<R_CurveRecord*> m_curveList;
//	std::list<R_CurveRecord*> m_maskCurveList;
//
//public:
//	BOOL ReadRecord(DRDirectoryInfo *dir, BYTE*& buf);
//	BOOL Save(CFile *file);
//	void Draw(CDC *pDC, Scaler *scaler, double offset = 0);
//	void Draw(HDC &hDC, Scaler *scaler, double offset = 0);
//	/*
//	* Drawing Instruction Type
//	* 1 : Point Instruction
//	* 2 : Curve Instruction
//	* 3 : Surface Instruction
//	* 4 : Text Instruction
//	*/
//	void Draw(HDC &hDC, Scaler *scaler, int type, int priority, double offset = 0);
//
//	void CreateCS(S101Cell *cell, CString csName, bool bSENC);
//
//	MBR GetMBR();
//int GetRCID();
};
