#include "stdafx.h"
#include "CPropertyGridAttributeModify.h"


CPropertyGridAttributeModify::CPropertyGridAttributeModify()
{
}


CPropertyGridAttributeModify::~CPropertyGridAttributeModify()
{
}
BEGIN_MESSAGE_MAP(CPropertyGridAttributeModify, CMFCPropertyGridCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CPropertyGridAttributeModify::OnLButtonDown(UINT nFlags, CPoint point) //��� ��� Ŭ���� �����°�
{
	CMFCPropertyGridProperty::ClickArea clickArea;
	CMFCPropertyGridProperty *pProp = HitTest(point, &clickArea);
	if (pProp != nullptr)
	{
		SetSelectedProPerty(pProp);
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