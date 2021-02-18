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


void CPropertyGridAttributeModify::OnLButtonDown(UINT nFlags, CPoint point) //��� ��� Ŭ���� �����°�
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
		Depthstring.Format(_T("�θ��ε���: %d \n"), Nodenumber);
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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


void CPropertyGridAttributeModify::OnAttributeeditDelete() //Attribute�� �����մϴ�.
{
	AfxMessageBox(L"���� ���� ��������ʽ��ϴ�.");

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CPropertyGridAttributeModify::OnAttributeeditOpen() //��ɾ ���ϴ�.
{
	if (pSelectedProperty != nullptr) //���õ� ���� NUll�� �ƴҰ��
	{
		CString Value = pSelectedProperty->GetValue();

		if (Value!="") //Ư�������� �̴ϴ�. //value �� ���� ��������ʰ�, Ư�������� �����Ұ��
		{
			ShellExecute(NULL, _T("open"), _T("iexplore"), NULL, NULL, SW_SHOW); //�ͽ��÷η��� ���ϴ�.
		}
	}

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
