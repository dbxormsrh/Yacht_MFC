// gamestart.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Final.h"
#include "gamestart.h"
#include "afxdialogex.h"


// gamestart 대화 상자

IMPLEMENT_DYNAMIC(gamestart, CDialogEx)

gamestart::gamestart(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	YorN = false;
}

gamestart::~gamestart()
{
}

void gamestart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(gamestart, CDialogEx)
	ON_BN_CLICKED(IDOK, &gamestart::OnBnClickedOk)
END_MESSAGE_MAP()


// gamestart 메시지 처리기


void gamestart::OnBnClickedOk()
{
	YorN = true;
	CDialogEx::OnOK();
}

bool gamestart::return_YorN() {
	return YorN;
}