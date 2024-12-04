
// AutoProjectDlg.h: 헤더 파일
//

#pragma once

class CAutoProjectDlgAutoProxy;


// CAutoProjectDlg 대화 상자
class CAutoProjectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAutoProjectDlg);
	friend class CAutoProjectDlgAutoProxy;

// 생성입니다.
public:
	CAutoProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	virtual ~CAutoProjectDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOPROJECT_DIALOG };
#endif
private:
	CApplication	excelApp;
	CWorkbook		workbook;
	CWorkbooks		workbooks;
	CWorksheet		worksheet;
	CWorksheets		worksheets;
	CRange			range;
	CRanges			ranges;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	CAutoProjectDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCloseExcel();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonOpenExcel();
	afx_msg void OnBnClickedButtonMakeExcel2();
	afx_msg void OnBnClickedButtonTemp();
};
