#include "stdafx.h"
#include "CPropertyGridAttributeModify.h"
#include "MultiData.h"
#include "F_ATTR.h"
#include "resource.h"


CPropertyGridAttributeModify::CPropertyGridAttributeModify()
{
}


CPropertyGridAttributeModify::~CPropertyGridAttributeModify()
{
}
BEGIN_MESSAGE_MAP(CPropertyGridAttributeModify, CMFCPropertyGridCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_ATTRIBUTEEDIT_DELETE, &CPropertyGridAttributeModify::OnAttributeeditDelete)
	ON_COMMAND(ID_ATTRIBUTEEDIT_OPEN, &CPropertyGridAttributeModify::OnAttributeeditOpen)
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
		SetSelectedPropertyNum(Nodenumber);


		CString Depthstring;
		Depthstring.Format(_T("부모인덱스: %d \n"), Nodenumber);
		OutputDebugString(Depthstring);
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

void CPropertyGridAttributeModify::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCPropertyGridProperty::ClickArea clickArea;
	CMFCPropertyGridProperty *pProp = HitTest(point, &clickArea);
	if (pProp != nullptr)
	{
		ATTR* attr = (ATTR*)pProp->GetData();
		//if (attr->m_paix == 0)
		{
			//if (pHit->IsAllowEdit())
			//{
			CPoint point;
			::GetCursorPos(&point);
			CMenu menu;
			VERIFY(menu.LoadMenu(IDR_MENU_EDIT_PANE));      //IDR_MENU1 is the new context menu
			CMenu* popup = menu.GetSubMenu(0);
			popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
			//}
		pSelectedProperty = pProp;
		}
	}

	CMFCPropertyGridCtrl::OnRButtonDown(nFlags, point);
}


void CPropertyGridAttributeModify::OnAttributeeditDelete() //Attribute를 삭제합니다.
{
	AfxMessageBox(L"여긴 지금 사용하지않습니다.");

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPropertyGridAttributeModify::OnAttributeeditOpen() //명령어를 엽니다.
{
	if (pSelectedProperty != nullptr) //선택된 값이 NUll이 아닐경우
	{
		CString Value = pSelectedProperty->GetValue();

		if (Value!="") //특정조건을 겁니다. //value 의 값은 비어있지않고, 특정조건을 만족할경우
		{
			ShellExecute(NULL, _T("open"), _T("iexplore"), NULL, NULL, SW_SHOW); //익스플로러를 엽니다.
		}
	}

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
