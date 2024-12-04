
// AutoProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AutoProject.h"
#include "AutoProjectDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include <afxdisp.h>
#include <comdef.h>
#include <vector>

using namespace std;

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


// CAutoProjectDlg 대화 상자


IMPLEMENT_DYNAMIC(CAutoProjectDlg, CDialogEx);

CAutoProjectDlg::CAutoProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTOPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}

CAutoProjectDlg::~CAutoProjectDlg()
{
	// 이 대화 상자에 대한 자동화 프록시가 있을 경우 이 대화 상자에 대한
	//  후방 포인터를 null로 설정하여
	//  대화 상자가 삭제되었음을 알 수 있게 합니다.
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}

void CAutoProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAutoProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_EXCEL, &CAutoProjectDlg::OnBnClickedButtonCloseExcel)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAutoProjectDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_EXCEL, &CAutoProjectDlg::OnBnClickedButtonOpenExcel)
	ON_BN_CLICKED(IDC_BUTTON_MAKE_EXCEL2, &CAutoProjectDlg::OnBnClickedButtonMakeExcel2)
	ON_BN_CLICKED(IDC_BUTTON_TEMP, &CAutoProjectDlg::OnBnClickedButtonTemp)
END_MESSAGE_MAP()


// CAutoProjectDlg 메시지 처리기

BOOL CAutoProjectDlg::OnInitDialog()
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

void CAutoProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoProjectDlg::OnPaint()
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
HCURSOR CAutoProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 컨트롤러에서 해당 개체 중 하나를 계속 사용하고 있을 경우
//  사용자가 UI를 닫을 때 자동화 서버를 종료하면 안 됩니다.  이들
//  메시지 처리기는 프록시가 아직 사용 중인 경우 UI는 숨기지만,
//  UI가 표시되지 않아도 대화 상자는
//  남겨 둡니다.

BOOL CAutoProjectDlg::CanExit()
{
	// 프록시 개체가 계속 남아 있으면 자동화 컨트롤러에서는
	//  이 응용 프로그램을 계속 사용합니다.  대화 상자는 남겨 두지만
	//  해당 UI는 숨깁니다.
	if (m_pAutoProxy != nullptr)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CAutoProjectDlg::OnBnClickedButtonOpenExcel()
{
	COleVariant covTrue((short)TRUE);								// 매개변수(파라미터) 설정
	COleVariant covFalse((short)FALSE);								// 매개변수(파라미터) 설정
	COleVariant covOpetional((long)DISP_E_PARAMNOTFOUND, VT_ERROR); // 매개변수(파라미터) 설정

	if (!excelApp.CreateDispatch(_T("Excel.Application")))
	{
		AfxMessageBox(_T("Fail to Open Excel"));
	}
	else
	{
		excelApp.put_Visible(TRUE);									// 엑셀 켜기
		workbooks = excelApp.get_Workbooks();
		workbook = workbooks.Add(covOpetional);

		worksheets = workbook.get_Sheets();
		worksheet = worksheets.get_Item(COleVariant((short)TRUE));
	}
}

void CAutoProjectDlg::OnBnClickedButtonCloseExcel()
{
	COleVariant covTrue((short)TRUE);
	COleVariant covFalse((short)FALSE);
	COleVariant covOpetional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	if (excelApp.get_UserControl())
	{
		worksheet.ReleaseDispatch();
		worksheets.ReleaseDispatch();
		workbook.ReleaseDispatch();
		workbooks.ReleaseDispatch();
	}
	excelApp.Quit();
	excelApp.ReleaseDispatch();
}


void CAutoProjectDlg::OnBnClickedButtonAdd()
{
	try
	{
		COleVariant covTrue((short)TRUE);
		COleVariant covFalse((short)FALSE);
		COleVariant covOpetional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
		COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

		// Excel 시작
		excelApp.CreateDispatch(_T("Excel.Application"), nullptr);
		excelApp.put_Visible(TRUE); // 개발 중 보기 설정

		// 저장 경로
		CString filePath = _T("D:\\123\\Results.xlsx");

		// 워크북 열기 또는 새로 생성
		if (PathFileExists(filePath))
		{
			// 기존 파일 열기
			workbooks = excelApp.get_Workbooks();
			workbook = workbooks.Open(
				filePath,				// 1. 파일 경로 (필수)
				VOptional,				// 2. UpdateLinks
				VOptional,				// 3. ReadOnly
				VOptional,				// 4. Format
				VOptional,				// 5. Password
				VOptional, 				// 6. WriteResPassword
				VOptional, 				// 7. IgnoreReadOnlyRecommended
				VOptional, 				// 8. Origin - Excel 기본값 필요
				VOptional,				// 9. Delimiter
				VOptional, 				// 10. Editable
				VOptional, 				// 11. Notify
				VOptional, 				// 12. Converter
				VOptional, 				// 13. AddToMru
				VOptional, 				// 14. Local
				VOptional);				// 15. CorruptLoad
		}
		else
		{
			// 새 워크북 생성
			workbooks = excelApp.get_Workbooks();
			workbook = workbooks.Add(COleVariant((long)1));
		}

		// 첫 번째 워크시트 가져오기
		worksheets = workbook.get_Worksheets();
		worksheet = worksheets.get_Item(COleVariant((short)1));

		// 마지막 사용된 행 찾기
		CRange usedRange = worksheet.get_UsedRange();
		CRange rows = usedRange.get_Rows();
		long lastRow = rows.get_Count();

		// 새 데이터 추가 시작 행
		long startRow = lastRow + 1;

		// 예제 데이터 작성
		CString data[3][3] = {
			{_T("Name"), _T("Age"), _T("Score")},
			{_T("Alice"), _T("25"), _T("85")},
			{_T("Bob"), _T("30"), _T("90")}
		};

		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				CString cell;
				cell.Format(_T("%c%d"), 'A' + col, startRow + row);

				range = worksheet.get_Range(COleVariant(cell), COleVariant(cell));
				range.put_Value2(COleVariant(data[row][col]));
			}
		}

		// 엑셀 저장
		workbook.SaveAs(
			COleVariant(filePath),          // 저장 경로 (필수)
			VOptional,						// 파일 형식
			VOptional,						// 암호 없음
			VOptional,						// 쓰기 암호 없음
			VOptional,						// 읽기 전용 권장 안 함
			VOptional,						// 백업 생성 안 함
			1,						        // AccessMode: xlNoChange
			VOptional,						// 충돌 해결: xlLocalSessionChanges
			VOptional,						// MRU 추가 안 함
			VOptional,						// 텍스트 코드 페이지
			VOptional,						// 텍스트 시각적 레이아웃
			VOptional,						// 로컬 설정 사용
			VOptional);						// WorkIdentity

		// 워크북 닫기
		workbook.Close(
			VOptional,						// 변경사항 저장 안 함
			VOptional,						// 파일 경로 없음
			VOptional);						// 라우트 옵션 없음

		if (excelApp.get_UserControl())		//엑셀이 동작하고 있을 때
		{
			worksheet.ReleaseDispatch();	// 해제
			worksheets.ReleaseDispatch();	// 해제
			workbook.ReleaseDispatch();		// 해제
			workbooks.ReleaseDispatch();	// 해제
		}
		// Excel 종료
		excelApp.Quit();
		excelApp.ReleaseDispatch();

		AfxMessageBox(_T("엑셀 파일에 데이터가 추가되었습니다."));
	}
	catch (COleException* e)
	{
		e->ReportError();
		e->Delete();
	}
}




void CAutoProjectDlg::OnBnClickedButtonMakeExcel2()
{
	COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	CString strResultsPath = _T("D:\\fff");
	CString strFolderPath = strResultsPath + _T("\\");
	CreateDirectory(strResultsPath, NULL);
	CreateDirectory(strFolderPath, NULL);
	strFolderPath += _T("Result\\");
	CreateDirectory(strFolderPath, NULL);
	CString strFilePath = strFolderPath + _T("213.xlsx");

	try {
		// Excel Application 시작
		if (!excelApp.CreateDispatch(_T("Excel.Application"))) {
			AfxMessageBox(_T("Excel을 실행할 수 없습니다."));
			return;
		}

		// Excel 앱 비활성화
		excelApp.put_Visible(FALSE); // TRUE로 설정하면 Excel 창을 볼 수 있음
		workbooks.AttachDispatch(excelApp.get_Workbooks());

		// 워크북 추가
		workbook.AttachDispatch(workbooks.Add(COleVariant((long)1)));
		worksheets.AttachDispatch(workbook.get_Worksheets());
		worksheet.AttachDispatch(worksheets.get_Item(COleVariant((short)TRUE))); // 첫 번째 시트 선택

		// 셀에 데이터 삽입
		range.AttachDispatch(worksheet.get_Range(COleVariant(_T("A1")), COleVariant(_T("C1"))));
		range.put_Value2(COleVariant(_T("Header1\tHeader2\tHeader3")));

		range.AttachDispatch(worksheet.get_Range(COleVariant(_T("A2")), COleVariant(_T("C2"))));
		range.put_Value2(COleVariant(_T("Data1\tData2")));

		// 파일 저장
		workbook.SaveAs(
			COleVariant(strFilePath),          // 저장 경로 (필수)
			VOptional,						// 파일 형식
			VOptional,						// 암호 없음
			VOptional,						// 쓰기 암호 없음
			VOptional,						// 읽기 전용 권장 안 함
			VOptional,						// 백업 생성 안 함
			1,						        // AccessMode: xlNoChange
			VOptional,						// 충돌 해결: xlLocalSessionChanges
			VOptional,						// MRU 추가 안 함
			VOptional,						// 텍스트 코드 페이지
			VOptional,						// 텍스트 시각적 레이아웃
			VOptional,						// 로컬 설정 사용
			VOptional);						// WorkIdentity

		// 종료
		workbook.Close(VOptional, VOptional, VOptional);
		if (excelApp.get_UserControl())		//엑셀이 동작하고 있을 때
		{
			worksheet.ReleaseDispatch();	// 해제
			worksheets.ReleaseDispatch();	// 해제
			workbook.ReleaseDispatch();		// 해제
			workbooks.ReleaseDispatch();	// 해제
		}
		excelApp.Quit();
	}
	catch (CException* e) {
		TCHAR szError[1024];
		e->GetErrorMessage(szError, 1024);
		AfxMessageBox(szError);
		e->Delete();
	}
}


void CAutoProjectDlg::OnBnClickedButtonTemp()
{
#if 1
	try
	{
		// Excel Application 초기화
		COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR); // 설정값

		CApplication excelApp;
		excelApp.CreateDispatch(_T("Excel.Application"));
		excelApp.put_Visible(FALSE);

		CWorkbooks workbooks = excelApp.get_Workbooks();
		CWorkbook workbook;
		CString strFilePath = _T("D:\\Result\\123.xlsx");

		// 기존 파일 확인 후 열기 또는 새로 생성
		if (PathFileExists(strFilePath))
		{
			workbook = workbooks.Open(strFilePath, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional, VOptional);
		
		}
		else
		{
			workbook = workbooks.Add(COleVariant((long)1));
		}

		CWorksheets worksheets = workbook.get_Worksheets();
		CWorksheet worksheet = worksheets.get_Item(COleVariant((short)1));

		// 데이터 초기화
		int rowIndex = 1;
		int colIndex = 1;

		// 마지막 사용된 행 찾기
		CRange usedRange = worksheet.get_UsedRange();
		CRange rows = usedRange.get_Rows();

		long lastRow = rows.get_Count();
		rowIndex = lastRow + 1;

		// 헤더 작성
		CString cellAddress;
		cellAddress.Format(_T("A%d"), rowIndex); // A열의 시작 행
		CRange range = worksheet.get_Range(COleVariant(cellAddress), COleVariant(cellAddress));
		range.put_Value2(COleVariant(_T("Frame Index"))); // 고정된 첫 번째 열

		colIndex = 2; // B열부터 시작
		std::vector<CString> vstrItemNames = { _T("Good"), _T("Crease"), _T("Etc") };

		// 동적으로 헤더 작성
		for (const auto& itemName : vstrItemNames)
		{
			cellAddress.Format(_T("%c%d"), 'A' + colIndex - 1, rowIndex); // B, C, ...
			range = worksheet.get_Range(COleVariant(cellAddress), COleVariant(cellAddress));
			range.put_Value2(COleVariant(itemName + _T("(NG)")));
			colIndex++;

			cellAddress.Format(_T("%c%d"), 'A' + colIndex - 1, rowIndex); // B, C, ...
			range = worksheet.get_Range(COleVariant(cellAddress), COleVariant(cellAddress));
			range.put_Value2(COleVariant(itemName + _T("(Value)")));
			colIndex++;
		}

		rowIndex++; // 데이터 시작 행

		// 데이터 작성
		for (int i = 0; i < 10; ++i) // 예시로 10개의 데이터를 작성
		{
			colIndex = 1; // 각 행의 첫 번째 열부터 시작

			// Frame Index 작성
			cellAddress.Format(_T("A%d"), rowIndex); // A열
			range = worksheet.get_Range(COleVariant(cellAddress), COleVariant(cellAddress));
			range.put_Value2(COleVariant((long)i));

			// 검사 항목 데이터 작성
			for (int j = 0; j < (int)vstrItemNames.size(); ++j)
			{
				BOOL bNG = (i + j) % 2; // 예시로 NG 값 생성
				double dValue = (double)(i * j) + 0.1234; // 예시 값

				// NG 데이터
				cellAddress.Format(_T("%c%d"), 'A' + colIndex, rowIndex); // NG 열
				range = worksheet.get_Range(COleVariant(cellAddress), COleVariant(cellAddress));
				range.put_Value2(COleVariant((VARIANT_BOOL)bNG));
				colIndex++;

				// Value 데이터
				cellAddress.Format(_T("%c%d"), 'A' + colIndex, rowIndex); // Value 열
				range = worksheet.get_Range(COleVariant(cellAddress), COleVariant(cellAddress));
				range.put_Value2(COleVariant((long)dValue));
				colIndex++;
			}

			rowIndex++; // 다음 행으로 이동
		}

		// 파일 저장
		workbook.SaveAs(
			COleVariant(strFilePath),       // 저장 경로 (필수)
			VOptional,						// 파일 형식
			VOptional,						// 암호 없음
			VOptional,						// 쓰기 암호 없음
			VOptional,						// 읽기 전용 권장 안 함
			VOptional,						// 백업 생성 안 함
			1,						        // AccessMode: xlNoChange
			VOptional,						// 충돌 해결: xlLocalSessionChanges
			VOptional,						// MRU 추가 안 함
			VOptional,						// 텍스트 코드 페이지
			VOptional,						// 텍스트 시각적 레이아웃
			VOptional,						// 로컬 설정 사용
			VOptional);						// WorkIdentity

		workbook.Close(
			VOptional,						// 변경사항 저장 안 함
			VOptional,						// 파일 경로 없음
			VOptional);						// 라우트 옵션 없음
		if (excelApp.get_UserControl())		//엑셀이 동작하고 있을 때
		{
			worksheet.ReleaseDispatch();	// 해제
			worksheets.ReleaseDispatch();	// 해제
			workbook.ReleaseDispatch();		// 해제
			workbooks.ReleaseDispatch();	// 해제
		}
		// Excel 종료

		excelApp.Quit();
		excelApp.ReleaseDispatch();
	}
	catch (CException* e)
	{
		e->ReportError();
		e->Delete();
	}
#else
	try {

	CString strResultsPath = _T("D:\\fff");
	CString strFolderPath = strResultsPath + _T("\\");
	CreateDirectory(strResultsPath, NULL);
	CreateDirectory(strFolderPath, NULL);
	strFolderPath += _T("Result\\");
	CreateDirectory(strFolderPath, NULL);
	CString strFilePath = strFolderPath + _T("313.xlsx");

	// 데이터 초기화
	int rowIndex = 1;
	int colIndex = 1;

	COleVariant VOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR); // 설정값
	COleVariant cellValue(_T("Frame Index"));

	// Excel Application 시작
	CApplication excelApp;
	excelApp.CreateDispatch(_T("Excel.Application"));
	excelApp.put_Visible(FALSE);

	// Workbook 생성
	//if (PathFileExists(strFolderPath))
	//{
	//	// 기존 파일 열기
	//	workbooks = excelApp.get_Workbooks();
	//	workbook = workbooks.Open(
	//		strFolderPath,				// 1. 파일 경로 (필수)
	//		VOptional,				// 2. UpdateLinks
	//		VOptional,				// 3. ReadOnly
	//		VOptional,				// 4. Format
	//		VOptional,				// 5. Password
	//		VOptional, 				// 6. WriteResPassword
	//		VOptional, 				// 7. IgnoreReadOnlyRecommended
	//		VOptional, 				// 8. Origin - Excel 기본값 필요
	//		VOptional,				// 9. Delimiter
	//		VOptional, 				// 10. Editable
	//		VOptional, 				// 11. Notify
	//		VOptional, 				// 12. Converter
	//		VOptional, 				// 13. AddToMru
	//		VOptional, 				// 14. Local
	//		VOptional);				// 15. CorruptLoad
	//}
	//else
	//{
	//	// 새 워크북 생성
	//	workbooks = excelApp.get_Workbooks();
	//	workbook = workbooks.Add(COleVariant((long)1));
	//}
	workbooks = excelApp.get_Workbooks();
	workbook = workbooks.Add(COleVariant((long)1));
	CWorksheets worksheets = workbook.get_Worksheets();
	CWorksheet worksheet = worksheets.get_Item(COleVariant((short)1)); // 첫 번째 워크시트 -> 엑셀에서는 각 Vision 마다 시트로 관리 가능

	// 마지막 사용된 행 찾기
	CRange usedRange = worksheet.get_UsedRange();
	CRange rows = usedRange.get_Rows();

	long lastRow = rows.get_Count();
	long startRow = 0;

	if (lastRow == 1) startRow = 0;
	else long startRow = lastRow;

	COleVariant row((long)rowIndex + startRow), col((long)colIndex);

	// 항목 이름 저장
	vector<CString> vstrItemNames;
	vector<int> viItemPriorities;

	// 데이터 반복 구조를 기반으로 헤더 작성

	range = worksheet.get_Range(row, COleVariant((long)colIndex++)); // 고정된 열
	range.put_Value2(cellValue);


	// 헤더 작성: 항목별 이름 동적 처리
	for (int i = 0; i < 1; i++)
	{
		int nItems = 3;
		for (int j = 0; j < nItems; j++)
		{
			CString strTemp;
			strTemp.Format(j);
			CString strItemName = _T("Class") + strTemp;

			vstrItemNames.push_back(strItemName);
			
			range = worksheet.get_Range(row, COleVariant((long)colIndex++)); // 고정된 열
			range.put_Value2(COleVariant(strItemName + _T("(NG)")));

			range = worksheet.get_Range(row, COleVariant((long)colIndex++)); // 고정된 열
			range.put_Value2(COleVariant(strItemName + _T("(Value)")));
		}
	}

	rowIndex++; // 데이터 작성 시작 위치

	// 데이터 작성
	for (int i = 0; i < 1; i++)
	{
		int nFrames = 5;

		for (int j = 0; j < nFrames; j++)
		{
			int iFrameIndex = j;
			range = worksheet.get_Range(row, COleVariant((short)1)); // 고정된 열
			range.put_Value2(COleVariant(COleVariant((long)iFrameIndex)));

			colIndex = 2; // 검사 항목 열 시작

			int nPatternNumFirst = 1;
			for (int k = 0; k < nPatternNumFirst; k++)
			{
				int nPatternNumSecond = 1;
				for (int l = 0; l < nPatternNumSecond; l++)
				{

					// 검사 항목별 NG 및 Value 값 작성
					for (int m = 0; m < 1; m++)
					{
						BOOL bNG = TRUE;
						double dValue = 3.5;

						range = worksheet.get_Range(row, COleVariant((long)colIndex++)); // 고정된 열
						range.put_Value2(COleVariant((long)bNG));

						range = worksheet.get_Range(row, COleVariant((long)colIndex++)); // 고정된 열
						range.put_Value2(COleVariant((long)bNG));
					}
				}
			}
			rowIndex++;
		}
	}
	// 엑셀 파일 저장 및 종료
	workbook.SaveAs(
		COleVariant(strFilePath),       // 저장 경로 (필수)
		VOptional,						// 파일 형식
		VOptional,						// 암호 없음
		VOptional,						// 쓰기 암호 없음
		VOptional,						// 읽기 전용 권장 안 함
		VOptional,						// 백업 생성 안 함
		1,						        // AccessMode: xlNoChange
		VOptional,						// 충돌 해결: xlLocalSessionChanges
		VOptional,						// MRU 추가 안 함
		VOptional,						// 텍스트 코드 페이지
		VOptional,						// 텍스트 시각적 레이아웃
		VOptional,						// 로컬 설정 사용
		VOptional);						// WorkIdentity

	workbook.Close(
		VOptional,						// 변경사항 저장 안 함
		VOptional,						// 파일 경로 없음
		VOptional);						// 라우트 옵션 없음

	if (excelApp.get_UserControl())		//엑셀이 동작하고 있을 때
	{
		worksheet.ReleaseDispatch();	// 해제
		worksheets.ReleaseDispatch();	// 해제
		workbook.ReleaseDispatch();		// 해제
		workbooks.ReleaseDispatch();	// 해제
	}
	// Excel 종료

	excelApp.Quit();
	excelApp.ReleaseDispatch();
	}
	catch (CException* e)
	{
		e->ReportError();
		e->Delete();
	}
#endif
	return;
}
