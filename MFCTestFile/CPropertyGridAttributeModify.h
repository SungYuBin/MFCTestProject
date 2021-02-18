#pragma once
#include <afxpropertygridctrl.h>
class CPropertyGridAttributeModify :public CMFCPropertyGridCtrl
{
public:

	CPropertyGridAttributeModify();
	virtual ~CPropertyGridAttributeModify();


	CPropertyGridAttributeModify(const CPropertyGridAttributeModify& obj)
	{
		*this = obj;
	}

	void operator=(const CPropertyGridAttributeModify& obj) {}

	

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void SetSelectedProPerty(CMFCPropertyGridProperty* selected);
	CMFCPropertyGridProperty* GetSelectedProPerty();
	void CPropertyGridAttributeModify::SetSelectedPropertyNum(int Num);
	int GetSelectedPropertyNum();
	CMFCPropertyGridProperty *pSelectedProperty;

private:
	CMFCPropertyGridProperty* SelectedProperty;
	int SelectedPropertyNum;

public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAttributeeditDelete();
	afx_msg void OnAttributeeditOpen();



};

