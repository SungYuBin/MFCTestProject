#include "stdafx.h"
#include "CPropertyGridAttributeModify.h"
#include "MultiData.h"
#include "F_ATTR.h"

CPropertyGridAttributeModify::CPropertyGridAttributeModify()
{
}


CPropertyGridAttributeModify::~CPropertyGridAttributeModify()
{
}
BEGIN_MESSAGE_MAP(CPropertyGridAttributeModify, CMFCPropertyGridCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CPropertyGridAttributeModify::OnLButtonDown(UINT nFlags, CPoint point) //노드 요소 클릭후 들어오는곳
{
	CMFCPropertyGridProperty::ClickArea clickArea;
	CMFCPropertyGridProperty *pProp = HitTest(point, &clickArea);
	if (pProp != nullptr)
	{
		SetSelectedProPerty(pProp);
		int Nodenumber = 0;
		MultiData *multiData = (MultiData *)pProp->GetData();
		ATTR *attr = (ATTR *)multiData->data[2];
		Nodenumber = attr->m_atix;

	} 
	else 
	{
		SetSelectedProPerty(nullptr);
	


	}
	CMFCPropertyGridCtrl::OnLButtonDown(nFlags, point);
}

void CPropertyGridAttributeModify::SetSelectedProPerty(CMFCPropertyGridProperty* selected)
{
	SelectedProperty = selected;
}

CMFCPropertyGridProperty* CPropertyGridAttributeModify::GetSelectedProPerty()
{
	return SelectedProperty;
}

void CPropertyGridAttributeModify::SetSelectedPropertyNum(int Num)
{
	SelectedPropertyNum = Num;
}

int CPropertyGridAttributeModify::GetSelectedPropertyNum()
{
	return SelectedPropertyNum;
}



