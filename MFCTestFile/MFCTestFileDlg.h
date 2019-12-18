
// MFCTestFileDlg.h: 헤더 파일
//

#pragma once
#include"CPropertyGridAttributeModify.h"

// CMFCTestFileDlg 대화 상자
class CMFCTestFileDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCTestFileDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

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
	//CMFCPropertyGridCtrl m_propertyList;
	CPropertyGridAttributeModify m_propertyList;
	
	bool ProgertyListInit();


//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//afx_msg void OnStnClickedMfcpropertygridtest();
};
