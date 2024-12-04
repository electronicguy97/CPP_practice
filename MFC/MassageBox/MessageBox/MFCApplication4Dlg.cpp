
// MFCApplication4Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

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


// CMFCApplication4Dlg 대화 상자



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	, m_strResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_RESULT, &CMFCApplication4Dlg::OnEnChangeEditResult)
	ON_BN_CLICKED(IDC_BUTTON_OC, &CMFCApplication4Dlg::OnBnClickedButtonOc)
	ON_BN_CLICKED(IDC_BUTTON_YN, &CMFCApplication4Dlg::OnClickedButtonYn)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMFCApplication4Dlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CMFCApplication4Dlg::OnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_RC, &CMFCApplication4Dlg::OnClickedButtonRc)
	ON_BN_CLICKED(IDC_BUTTON_YNC, &CMFCApplication4Dlg::OnClickedButtonYnc)
	ON_BN_CLICKED(IDC_BUTTON_ARI, &CMFCApplication4Dlg::OnClickedButtonAri)
	ON_BN_CLICKED(IDC_BUTTON_MFC, &CMFCApplication4Dlg::OnClickedButtonMfc)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 메시지 처리기

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication4Dlg::OnPaint()
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
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication4Dlg::OnEnChangeEditResult()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication4Dlg::OnBnClickedButtonOc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;
	iResults = AfxMessageBox(_T("OK/CANCLE 버튼을 누르셨습니다."), MB_OKCANCEL | MB_ICONSTOP);
	if (iResults == IDOK)
	{
		m_strResult = _T("OK 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_strResult = _T("CANCLE 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
}




void CMFCApplication4Dlg::OnClickedButtonYn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;
	iResults = AfxMessageBox(_T("YES/NO 버튼을 누르셨습니다."), MB_YESNO | MB_ICONEXCLAMATION);
	if (iResults == IDYES)
	{
		m_strResult = _T("YES 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_strResult = _T("NO 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
}


void CMFCApplication4Dlg::OnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CMFCApplication4Dlg::OnClickedButtonOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;
	iResults = AfxMessageBox(_T("OK 버튼을 누르셨습니다."), MB_OK | MB_ICONSTOP);
	if (iResults == IDOK)
	{
		m_strResult = _T("OK 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
}


void CMFCApplication4Dlg::OnClickedButtonRc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;
	iResults = AfxMessageBox(_T("RETRY/CANCLE 버튼을 누르셨습니다."), MB_RETRYCANCEL | MB_ICONQUESTION);
	if (iResults == IDRETRY)
	{
		m_strResult = _T("RETRY 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_strResult = _T("CANCLE 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
}


void CMFCApplication4Dlg::OnClickedButtonYnc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;
	iResults = AfxMessageBox(_T("YES/NO/CANCLE 버튼을 누르셨습니다."), MB_YESNOCANCEL | MB_ICONSTOP);
	if (iResults == IDYES)
	{
		m_strResult = _T("YES 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_strResult = _T("NO 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_strResult = _T("CANCEL 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
}


void CMFCApplication4Dlg::OnClickedButtonAri()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;
	iResults = AfxMessageBox(_T("ABORT/RETRY/IGNORE 버튼을 누르셨습니다."), MB_ABORTRETRYIGNORE | MB_ICONINFORMATION);
	if (iResults == IDABORT)
	{
		m_strResult = _T("ABORT 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDRETRY)
	{
		m_strResult = _T("RETRY 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
	if (iResults == IDIGNORE)
	{
		m_strResult = _T("IGNORE 버튼을 누르셨습니다.");
		UpdateData(FALSE);
	}
}


void CMFCApplication4Dlg::OnClickedButtonMfc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("Microsoft Foundation Class입니다"));
}
