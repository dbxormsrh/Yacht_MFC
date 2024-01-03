// input_nameDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Final.h"
#include "input_nameDlg.h"
#include "afxdialogex.h"


// input_nameDlg 대화 상자

IMPLEMENT_DYNAMIC(input_nameDlg, CDialogEx)

input_nameDlg::input_nameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

input_nameDlg::~input_nameDlg()
{
}

void input_nameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, input_name);
}


BEGIN_MESSAGE_MAP(input_nameDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &input_nameDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// input_nameDlg 메시지 처리기


void input_nameDlg::OnBnClickedOk()
{
	input_name.GetWindowTextW(name);
	CDialogEx::OnOK();
}


CString input_nameDlg::return_name() {
	return name;
}