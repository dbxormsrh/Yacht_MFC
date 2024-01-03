#pragma once


// input_nameDlg 대화 상자

class input_nameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(input_nameDlg)

public:
	input_nameDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~input_nameDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CString name;
	DECLARE_MESSAGE_MAP()
public:
	CEdit input_name;
	CString return_name();
	afx_msg void OnBnClickedOk();
};
