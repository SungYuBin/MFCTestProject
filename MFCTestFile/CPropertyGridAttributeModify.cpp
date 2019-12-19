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


void CPropertyGridAttributeModify::OnLButtonDown(UINT nFlags, CPoint point) //노드 요소 클릭후 들어오는곳
{
	CMFCPropertyGridProperty::ClickArea clickArea;
	CMFCPropertyGridProperty *pProp = HitTest(point, &clickArea);
	if (pProp != nullptr)
	{
		SetSelectedProPerty(pProp);

		auto count = this->GetPropertyCount();

		for (int i = 0; i < count; i++)
		{
			auto property = this->GetProperty(i);
			if (property == pProp)
			{
				CString Depthstring;
				Depthstring.Format(_T("index값:%d ::::\n"), i);
				OutputDebugString(Depthstring);


			}
		}
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

void CPropertyGridAttributeModify::SetSelectedPropertyNum(CMFCPropertyGridProperty* selected)
{
	SelectedPropertyNum = 0;
}

int CPropertyGridAttributeModify::GetSelectedPropertyNum()
{
	return SelectedPropertyNum;
}



