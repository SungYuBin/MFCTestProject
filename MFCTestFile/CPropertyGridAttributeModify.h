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


private:
	CMFCPropertyGridProperty* SelectedProperty;
};

