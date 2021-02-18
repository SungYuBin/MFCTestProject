
// MFCTestFileDlg.h: 헤더 파일
//


#pragma once
#include"CPropertyGridAttributeModify.h"
#include "F_ATTR.h"
#include <vector>
#include"MultiData.h"
#include "R_FeatureRecord.h"

// CMFCTestFileDlg 대화 상자
class CMFCTestFileDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCTestFileDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CMFCTestFileDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTESTFILE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonCancle();
	afx_msg void OnBnClickedButtonRefresh();
	CEdit propertyName;

	CPropertyGridAttributeModify m_propertyList;

	int SelectedPropertyNum; //선택된 노드의 값
	int NodeNum = 1;//자기 자신의 노드값입니다.


	R_FeatureRecord* m_pFeature=nullptr;

	//std::vector<CMFCPropertyGridProperty*> pAttrItemList; //모든내역을 저장할 Attribute입니다.
	bool ProgertyListInit();
	unsigned CMFCTestFileDlg::GetATIX(unsigned natc, unsigned parentIndex);
	std::vector<F_ATTR*> proInforamtion;
	MultiData* InsertPropertyMultiData(int multidataType, CMFCPropertyGridProperty* pGP, DWORD_PTR pointer_1, DWORD_PTR pointer_2 = NULL, DWORD_PTR pointer_3 = NULL, DWORD_PTR pointer_4 = NULL);
	
	int CMFCTestFileDlg::GetSelectedPropertyNum();
	void CMFCTestFileDlg::SetSelectedPropertyNum(int selected);
	virtual void PostNcDestroy();
	virtual BOOL DestroyWindow();
	afx_msg void OnStnClickedMfcpropertygridtest();
};
