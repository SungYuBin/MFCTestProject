#pragma once
#include <afxpropertygridctrl.h>
class myGridProperty :
	public CMFCPropertyGridProperty
{
public:
	myGridProperty(const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr = NULL, DWORD_PTR dwData = 0,
		LPCTSTR lpszEditMask = NULL, LPCTSTR lpszEditTemplate = NULL, LPCTSTR lpszValidChars = NULL);

	myGridProperty();
	virtual ~myGridProperty();

	virtual BOOL HasButton() const;
	CButton *openButton;
	
	void OnCreate(LPCREATESTRUCT lpCreateStruct);
	bool isButtonVisible;

};

