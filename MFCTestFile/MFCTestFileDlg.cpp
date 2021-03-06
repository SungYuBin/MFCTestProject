﻿
// MFCTestFileDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCTestFile.h"
#include "MFCTestFileDlg.h"
#include "afxdialogex.h"

#include <windows.h>
#include <stdlib.h>//atoi와 itoa함수를 위한 헤더이다
#include "resource.h"
#include <sstream>
#include"MultiData.h"
#include"myGridProperty.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTestFileDlg 대화 상자



CMFCTestFileDlg::CMFCTestFileDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTESTFILE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pFeature = new R_FeatureRecord();
}

void CMFCTestFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NODENAME, propertyName);
	DDX_Control(pDX, IDC_MFCPROPERTYGRIDTEST, m_propertyList);
}

BEGIN_MESSAGE_MAP(CMFCTestFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCTestFileDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, &CMFCTestFileDlg::OnBnClickedButtonCancle)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, &CMFCTestFileDlg::OnBnClickedButtonRefresh)
END_MESSAGE_MAP()


// CMFCTestFileDlg 메시지 처리기

BOOL CMFCTestFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ProgertyListInit();
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCTestFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCTestFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCTestFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTestFileDlg::OnBnClickedButtonAdd()
{
	CString name = _T("");
	GetDlgItemText(IDC_EDIT_NODENAME, name);

	if (name.IsEmpty() != true)
	{
		int parentIndex = 0;
		CMFCPropertyGridProperty* pGroupInfo = new CMFCPropertyGridProperty(name);
		//myGridProperty* pGroupInfo = new myGridProperty(name);

		ATTR* attr = new ATTR();
		F_ATTR* attrParent = NULL;
		 
		if (m_pFeature->m_attr.begin() != m_pFeature->m_attr.end())
		{
			attrParent = *m_pFeature->m_attr.begin();
		}
		else
		{
			attrParent = new F_ATTR();
			m_pFeature->m_attr.push_back(attrParent);
		}
		auto selectedListNode = m_propertyList.GetSelectedProPerty(); //선택한값이 있는경우
		if (selectedListNode != nullptr)
		{
			selectedListNode->AddSubItem(pGroupInfo);
			SetSelectedPropertyNum(m_propertyList.GetSelectedPropertyNum());
			parentIndex = GetSelectedPropertyNum();

			selectedListNode->Expand(FALSE);
			selectedListNode->Expand(TRUE);

		}
		else //비어있는게 아니라면
		{
			m_propertyList.AddProperty(pGroupInfo);
		}

		attr->m_atix = NodeNum;
		attr->m_paix = parentIndex;
		attr->m_atin = 1;
		attr->m_atvl = L"";
		attr->m_atname = name;
		attrParent->m_arr.push_back(attr);
														//type,CMFCPropertyGridProperty,R_FeatureRecord,ATTR
		MultiData *multiData = InsertPropertyMultiData(111, pGroupInfo, (DWORD_PTR)m_pFeature, (DWORD_PTR)attr);
		pGroupInfo->SetData((DWORD_PTR)multiData);

		NodeNum++;
	}
	else
	{
		AfxMessageBox(L"빈 문자열은 진행할수없습니다.");
		return;
	}
}

void CMFCTestFileDlg::OnBnClickedButtonCancle() //선택한 값을 삭제합니다.
{
	auto selectedListNode = m_propertyList.GetSelectedProPerty();
	if (selectedListNode)
	{
		auto Data = (MultiData*)selectedListNode->GetData();
		delete Data;

		m_propertyList.DeleteProperty(selectedListNode);
		
	}
	




	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//예외처리 추가


}

//기능::모든내용을 삭제하고 다시 원래 구조대로 다시 표출합니다.
void CMFCTestFileDlg::OnBnClickedButtonRefresh() 
{
	std::vector<CMFCPropertyGridProperty*> pAttrItemList;

	while (m_propertyList.GetPropertyCount() > 0)
	{
		m_propertyList.RemoveAll();
		m_propertyList.ExpandAll();
	}

	for (auto itorParent = m_pFeature->m_attr.begin(); itorParent != m_pFeature->m_attr.end(); itorParent++)
	{
		F_ATTR* attrParent = *itorParent;

		for (auto itor = attrParent->m_arr.begin(); itor != attrParent->m_arr.end(); itor++)
		{
			ATTR* attr = *itor;
			CMFCPropertyGridProperty* pGroupInfo = new CMFCPropertyGridProperty(attr->m_atname);

			MultiData *multiData = InsertPropertyMultiData(111, pGroupInfo, (DWORD_PTR)m_pFeature, (DWORD_PTR)attr);

			pGroupInfo->SetData((DWORD_PTR)multiData); //데이터 구조를 셋팅해줍니다.

			pAttrItemList.push_back(pGroupInfo);
	
			//기본구조는 이렇게 이루어집니다.
			if (attr->m_paix!= 0) 
			{
				if (pAttrItemList[attr->m_paix - 1]->IsGroup()) {pAttrItemList[attr->m_paix - 1]->AddSubItem(pGroupInfo);}
				else { pAttrItemList[attr->m_paix]->AddSubItem(pGroupInfo);}
			}
			else
			{
				m_propertyList.AddProperty(pGroupInfo);
			}

		}
		m_propertyList.ExpandAll();
	}

}


bool CMFCTestFileDlg::ProgertyListInit() //기본셋팅입니다.
{
	return false;
}


unsigned CMFCTestFileDlg::GetATIX(unsigned natc, unsigned parentIndex)
{
	unsigned index = 1;
	for (auto itorParent = m_pFeature->m_attr.begin(); itorParent != m_pFeature->m_attr.end(); itorParent++)
	{
		F_ATTR* attrParent = *itorParent;

		for (auto itor = attrParent->m_arr.begin(); itor != attrParent->m_arr.end(); itor++)
		{
			ATTR* attr = *itor;

			if (attr->m_paix == parentIndex)
			{
				index = attr->m_atix + 1;
			}
		}
	}
	return index;
}

MultiData* CMFCTestFileDlg::InsertPropertyMultiData(int multidataType, CMFCPropertyGridProperty* pGP, DWORD_PTR pointer_1, DWORD_PTR pointer_2, DWORD_PTR pointer_3, DWORD_PTR pointer_4)
{
	MultiData* multiData = new MultiData();

	multiData->type = multidataType;
	multiData->data.push_back((DWORD_PTR)nullptr); //cell
	multiData->data.push_back((DWORD_PTR)pointer_1);
	multiData->data.push_back((DWORD_PTR)pointer_2);
	multiData->data.push_back((DWORD_PTR)pointer_3);
	multiData->data.push_back((DWORD_PTR)pointer_4);


	
	return multiData;

}

void CMFCTestFileDlg::SetSelectedPropertyNum(int selected)
{
	SelectedPropertyNum = selected;
}

int CMFCTestFileDlg::GetSelectedPropertyNum()
{
	return SelectedPropertyNum;
}


CMFCTestFileDlg::~CMFCTestFileDlg()
{
	delete m_pFeature;
	
	
}






void CMFCTestFileDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	

	CDialogEx::PostNcDestroy();
}


BOOL CMFCTestFileDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	int count = m_propertyList.GetPropertyCount();
	for (int i = 0; i < count; i++)
	{
		auto property = m_propertyList.GetProperty(i);
		auto data = (MultiData*)property->GetData();
		delete data;

	}
	return CDialogEx::DestroyWindow();
}


