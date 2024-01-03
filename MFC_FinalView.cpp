
// MFC_FinalView.cpp: CMFCFinalView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_Final.h"
#endif

#include "MFC_FinalDoc.h"
#include "MFC_FinalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"input_nameDlg.h"
#include"ScoreBoard.h"
#include"Dice.h"
#include"rules.h"


#include<time.h>
#include<cstdlib>


// CMFCFinalView

IMPLEMENT_DYNCREATE(CMFCFinalView, CFormView)

BEGIN_MESSAGE_MAP(CMFCFinalView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCFinalView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCFinalView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCFinalView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCFinalView::OnBnClickedButton4)

	ON_WM_CTLCOLOR()

	ON_STN_CLICKED(IDC_fir_aces, &CMFCFinalView::OnStnClickedfiraces)

	ON_STN_CLICKED(IDC_fir_deuces, &CMFCFinalView::OnStnClickedfirdeuces)
	ON_STN_CLICKED(IDC_fir_threes, &CMFCFinalView::OnStnClickedfirthrees)
	ON_STN_CLICKED(IDC_fir_fours, &CMFCFinalView::OnStnClickedfirfours)
	ON_STN_CLICKED(IDC_fir_fives, &CMFCFinalView::OnStnClickedfirfives)
	ON_STN_CLICKED(IDC_fir_sixes, &CMFCFinalView::OnStnClickedfirsixes)
	ON_STN_CLICKED(IDC_sec_aces, &CMFCFinalView::OnStnClickedsecaces)
	ON_STN_CLICKED(IDC_sec_deuces, &CMFCFinalView::OnStnClickedsecdeuces)
	ON_STN_CLICKED(IDC_sec_threes, &CMFCFinalView::OnStnClickedsecthrees)
	ON_STN_CLICKED(IDC_sec_fours, &CMFCFinalView::OnStnClickedsecfours)
	ON_STN_CLICKED(IDC_sec_fives, &CMFCFinalView::OnStnClickedsecfives)
	ON_STN_CLICKED(IDC_sec_sixes, &CMFCFinalView::OnStnClickedsecsixes)
	ON_STN_CLICKED(IDC_fir_choices, &CMFCFinalView::OnStnClickedfirchoices)
	ON_STN_CLICKED(IDC_fir_fofkind, &CMFCFinalView::OnStnClickedfirfofkind)
	ON_STN_CLICKED(IDC_fir_fullhouse, &CMFCFinalView::OnStnClickedfirfullhouse)
	ON_STN_CLICKED(IDC_fir_sstraight, &CMFCFinalView::OnStnClickedfirsstraight)
	ON_STN_CLICKED(IDC_fir_lstraight, &CMFCFinalView::OnStnClickedfirlstraight)
	ON_STN_CLICKED(IDC_fir_yatch, &CMFCFinalView::OnStnClickedfiryatch)
	ON_STN_CLICKED(IDC_sec_choices, &CMFCFinalView::OnStnClickedsecchoices)
	ON_STN_CLICKED(IDC_sec_fofkind, &CMFCFinalView::OnStnClickedsecfofkind)
	ON_STN_CLICKED(IDC_sec_fullhouse, &CMFCFinalView::OnStnClickedsecfullhouse)
	ON_STN_CLICKED(IDC_sec_sstraight, &CMFCFinalView::OnStnClickedsecsstraight)
	ON_STN_CLICKED(IDC_sec_lstraight, &CMFCFinalView::OnStnClickedseclstraight)
	ON_STN_CLICKED(IDC_sec_yatch, &CMFCFinalView::OnStnClickedsecyatch)
END_MESSAGE_MAP()

// CMFCFinalView 생성/소멸

CMFCFinalView::CMFCFinalView() noexcept
	: CFormView(IDD_MFC_FINAL_FORM)
{	
	srand((unsigned)time(0));
	fir_scoreboard = new CStatic[16];
	sec_scoreboard = new CStatic[16];
	dice_id[0] = 1037;
	int x = 1042;
	for (int i = 1; i < 5; i++) {
		dice_id[i] = x + i;
	}
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCFinalView::~CMFCFinalView()
{

}

void CMFCFinalView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//첫 번째 플레이어 점수판의 스테틱 컨트롤들
	DDX_Control(pDX, IDC_fir_name, fir_scoreboard[0]);
	DDX_Control(pDX, IDC_fir_aces, fir_scoreboard[1]);
	DDX_Control(pDX, IDC_fir_deuces, fir_scoreboard[2]);
	DDX_Control(pDX, IDC_fir_threes, fir_scoreboard[3]);
	DDX_Control(pDX, IDC_fir_fours, fir_scoreboard[4]);
	DDX_Control(pDX, IDC_fir_fives, fir_scoreboard[5]);
	DDX_Control(pDX, IDC_fir_sixes, fir_scoreboard[6]);
	DDX_Control(pDX, IDC_fir_subtotal, fir_scoreboard[7]);
	DDX_Control(pDX, IDC_fir_bonus, fir_scoreboard[8]);
	DDX_Control(pDX, IDC_fir_choices, fir_scoreboard[9]);
	DDX_Control(pDX, IDC_fir_fofkind, fir_scoreboard[10]);
	DDX_Control(pDX, IDC_fir_fullhouse, fir_scoreboard[11]);
	DDX_Control(pDX, IDC_fir_sstraight, fir_scoreboard[12]);
	DDX_Control(pDX, IDC_fir_lstraight, fir_scoreboard[13]);
	DDX_Control(pDX, IDC_fir_yatch, fir_scoreboard[14]);
	DDX_Control(pDX, IDC_fir_total, fir_scoreboard[15]);
	//두 번째 플레이어 점수판의 스테틱 컨트롤들
	DDX_Control(pDX, IDC_sec_name, sec_scoreboard[0]);
	DDX_Control(pDX, IDC_sec_aces, sec_scoreboard[1]);
	DDX_Control(pDX, IDC_sec_deuces, sec_scoreboard[2]);
	DDX_Control(pDX, IDC_sec_threes, sec_scoreboard[3]);
	DDX_Control(pDX, IDC_sec_fours, sec_scoreboard[4]);
	DDX_Control(pDX, IDC_sec_fives, sec_scoreboard[5]);
	DDX_Control(pDX, IDC_sec_sixes, sec_scoreboard[6]);
	DDX_Control(pDX, IDC_sec_subtotal, sec_scoreboard[7]);
	DDX_Control(pDX, IDC_sec_bonus, sec_scoreboard[8]);
	DDX_Control(pDX, IDC_sec_choices, sec_scoreboard[9]);
	DDX_Control(pDX, IDC_sec_fofkind, sec_scoreboard[10]);
	DDX_Control(pDX, IDC_sec_fullhouse, sec_scoreboard[11]);
	DDX_Control(pDX, IDC_sec_sstraight, sec_scoreboard[12]);
	DDX_Control(pDX, IDC_sec_lstraight, sec_scoreboard[13]);
	DDX_Control(pDX, IDC_sec_yatch, sec_scoreboard[14]);
	DDX_Control(pDX, IDC_sec_total, sec_scoreboard[15]);
	//

	DDX_Control(pDX, IDC_guide, sb_guide);
	DDX_Control(pDX, IDC_turn, static_turn);
}

BOOL CMFCFinalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMFCFinalView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}


// CMFCFinalView 인쇄

BOOL CMFCFinalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCFinalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCFinalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCFinalView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMFCFinalView 진단

#ifdef _DEBUG
void CMFCFinalView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCFinalView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCFinalDoc* CMFCFinalView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCFinalDoc)));
	return (CMFCFinalDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCFinalView 메시지 처리기




void CMFCFinalView::OnBnClickedButton1()
{	
	int xxxx = 2;
	rect_inva(1020);
	CString str;
	str.Format(_T("%d"), xxxx);
	AfxMessageBox(str);
	fir_scoreboard[15].SetWindowTextW(str);
	xxxx = xxxx * 2;
}

void CMFCFinalView::OnBnClickedButton2()
{
	
}

//https://argc.tistory.com/312 스태틱 텍스트 배경 투명으로 만들어주는 코드
HBRUSH CMFCFinalView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	CRect rect;
	UINT nID = pWnd->GetDlgCtrlID();

	if (nCtlColor == CTLCOLOR_STATIC) {
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	return hbr;
}

void CMFCFinalView::OnBnClickedButton3()
{		
	int* sub_dice;
	if (flag < 3) {
		Dice d;
		sub_dice = d.RollDice();
		for (int i = 0; i < 5; i++) {
			dice[i] = sub_dice[i];
			show_dice(dice[i], dice_id[i]);
		}
		flag++;
	}

	if(flag==3) {
		set_guide(_T("점수입력을 원하는 항목을 선택해주세요!"));
		flag = 0;
		(GetDlgItem(IDC_BUTTON3))->ShowWindow(false);
	}
}


void CMFCFinalView::OnBnClickedButton4()
{
	fp.get_name();
	sp.get_name();
	turn = 1;

	
	fir_scoreboard[0].SetWindowTextW(fp.return_name());
	sec_scoreboard[0].SetWindowTextW(sp.return_name());

	set_turn();
	(GetDlgItem(IDC_BUTTON4))->ShowWindow(false);
	set_guide(_T("주사위를 굴려서 주세요!"));
	(GetDlgItem(IDC_BUTTON3))->ShowWindow(true);
}

void CMFCFinalView::rect_inva(int ID) {
	CRect rect;
	GetDlgItem(ID)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	InvalidateRect(rect);
}

void CMFCFinalView::set_guide(CString text) {
	rect_inva(1036);
	sb_guide.SetWindowTextW(text);
}

void CMFCFinalView::show_dice(int d, int id) {
	CString str;
	str.Format(_T("dice_%d.bmp"), d);

	CImage image;
	image.Load(str);
	CStatic* p_static = (CStatic*)GetDlgItem(id);
	p_static->SetBitmap(image);
}

void CMFCFinalView::set_turn() {
	if (turn <= 24) {
		rect_inva(1042);
		CString str;
		str.Format(_T("%d"), turn);
		static_turn.SetWindowTextW(str);
	}
	else {
		if (fp.total() < sp.total())
			AfxMessageBox(_T("2P님의 승리입니다! 축하드립니다!"));
		else if (fp.total() > sp.total())
			AfxMessageBox(_T("1P님의 승리입니다! 축하드립니다!"));
		else {
			AfxMessageBox(_T("Draw!"));
		}
		AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}
}


void CMFCFinalView::fir_reset_option() {
	CString str;
	for (int i = 0; i < 5; i++) {
		dice[i] = 0;
	}
	flag = 0;
	turn++;
	set_turn();
	str.Format(_T("%d"), fp.re_subtotal());
	rect_inva(1033);
	fir_scoreboard[7].SetWindowTextW(str);
	if (fp.subtotal())
		fir_scoreboard[8].SetWindowTextW(_T("+35"));
	
	str.Format(_T("%d"), fp.total());
	rect_inva(1020);
	fir_scoreboard[15].SetWindowTextW(str);
	set_guide(_T("주사위를 굴려주세요!"));
	(GetDlgItem(IDC_BUTTON3))->ShowWindow(true);
}
void CMFCFinalView::sec_reset_option() {
	CString str;
	for (int i = 0; i < 5; i++) {
		dice[i] = 0;
	}
	flag = 0;
	turn++;
	set_turn();
	str.Format(_T("%d"), fp.re_subtotal());
	rect_inva(IDC_sec_subtotal);
	sec_scoreboard[7].SetWindowTextW(str);
	if (fp.subtotal())
		sec_scoreboard[8].SetWindowTextW(_T("+35"));

	str.Format(_T("%d"), fp.total());
	rect_inva(IDC_sec_total);
	sec_scoreboard[15].SetWindowTextW(str);
	set_guide(_T("주사위를 굴려주세요!"));
	(GetDlgItem(IDC_BUTTON3))->ShowWindow(true);
}

void CMFCFinalView::OnStnClickedfiraces()
{		
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(1, dice, fp.ab, score)) {
			fp.inputScore(1, score);
			str.Format(_T("%d"), fp.board[0]);
			fir_scoreboard[1].SetWindowTextW(str);
			
		}
		else {
			fp.inputScore(1, 0);
			str.Format(_T("%d"), fp.board[0]);
			fir_scoreboard[1].SetWindowTextW(str);
		}
	}
	fir_reset_option();
}


void CMFCFinalView::OnStnClickedfirdeuces()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(2, dice, fp.ab, score)) {
			fp.inputScore(2, score);
			str.Format(_T("%d"), fp.board[1]);
			fir_scoreboard[2].SetWindowTextW(str);

		}
		else {
			fp.inputScore(2, 0);
			str.Format(_T("%d"), fp.board[1]);
			fir_scoreboard[2].SetWindowTextW(str);
		}
	}			
	fir_reset_option();
}


void CMFCFinalView::OnStnClickedfirthrees()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(3, dice, fp.ab, score)) {
			fp.inputScore(3, score);
			str.Format(_T("%d"), fp.board[2]);
			fir_scoreboard[3].SetWindowTextW(str);

		}
		else {
			fp.inputScore(3, 0);
			str.Format(_T("%d"), fp.board[2]);
			fir_scoreboard[3].SetWindowTextW(str);
		}
	}
	fir_reset_option();
}


void CMFCFinalView::OnStnClickedfirfours()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(4, dice, fp.ab, score)) {
			fp.inputScore(4, score);
			str.Format(_T("%d"), fp.board[3]);
			fir_scoreboard[4].SetWindowTextW(str);
		}
		else {
			fp.inputScore(4, 0);
			str.Format(_T("%d"), fp.board[3]);
			fir_scoreboard[4].SetWindowTextW(str);
		}
	}
	fir_reset_option();
}


void CMFCFinalView::OnStnClickedfirfives()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(5, dice, fp.ab, score)) {
			fp.inputScore(5, score);
			str.Format(_T("%d"), fp.board[4]);
			fir_scoreboard[5].SetWindowTextW(str);
			
		}
		else {
			fp.inputScore(5, 0);
			str.Format(_T("%d"), fp.board[4]);
			fir_scoreboard[5].SetWindowTextW(str);
		}
	}
	fir_reset_option();
}


void CMFCFinalView::OnStnClickedfirsixes()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(6, dice, fp.ab, score)) {
			fp.inputScore(6, score);
			str.Format(_T("%d"), fp.board[5]);
			fir_scoreboard[6].SetWindowTextW(str);
			
		}
		else {
			fp.inputScore(6, 0);
			str.Format(_T("%d"), fp.board[5]);
			fir_scoreboard[6].SetWindowTextW(str);
		}
	}
	fir_reset_option();
}


void CMFCFinalView::OnStnClickedsecaces()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(1, dice, sp.ab, score)) {
			sp.inputScore(1, score);
			str.Format(_T("%d"), sp.board[0]);
			sec_scoreboard[1].SetWindowTextW(str);
			
		}
		else {
			sp.inputScore(1, 0);
			str.Format(_T("%d"), sp.board[0]);
			sec_scoreboard[1].SetWindowTextW(str);
		}
	}
	sec_reset_option();

}


void CMFCFinalView::OnStnClickedsecdeuces()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(2, dice, sp.ab, score)) {
			sp.inputScore(2, score);
			str.Format(_T("%d"), sp.board[1]);
			sec_scoreboard[2].SetWindowTextW(str);
		
		}
		else {
			sp.inputScore(2, 0);
			str.Format(_T("%d"), sp.board[1]);
			sec_scoreboard[2].SetWindowTextW(str);
		}
	}
	sec_reset_option();
}


void CMFCFinalView::OnStnClickedsecthrees()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(3, dice, sp.ab, score)) {
			sp.inputScore(3, score);
			str.Format(_T("%d"), sp.board[2]);
			sec_scoreboard[3].SetWindowTextW(str);

		}
		else {
			sp.inputScore(3, 0);
			str.Format(_T("%d"), sp.board[2]);
			sec_scoreboard[3].SetWindowTextW(str);
		}
	}			
	sec_reset_option();
}


void CMFCFinalView::OnStnClickedsecfours()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(4, dice, sp.ab, score)) {
			sp.inputScore(4, score);
			str.Format(_T("%d"), sp.board[3]);
			sec_scoreboard[4].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(4, 0);
			str.Format(_T("%d"), sp.board[3]);
			sec_scoreboard[4].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecfives()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(5, dice, sp.ab, score)) {
			sp.inputScore(5, score);
			str.Format(_T("%d"), sp.board[4]);
			sec_scoreboard[5].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(5, 0);
			str.Format(_T("%d"), sp.board[4]);
			sec_scoreboard[5].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecsixes()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(6, dice, sp.ab, score)) {
			sp.inputScore(6, score);
			str.Format(_T("%d"), sp.board[5]);
			sec_scoreboard[6].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(6, 0);
			str.Format(_T("%d"), sp.board[5]);
			sec_scoreboard[6].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedfirchoices()
{
	int score = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(7, dice, fp.ab, score)) {
			fp.inputScore(7, score);
			str.Format(_T("%d"), fp.board[6]);
			fir_scoreboard[9].SetWindowTextW(str);
			fir_reset_option();
		}
		else {
			fp.inputScore(7, 0);
			str.Format(_T("%d"), fp.board[6]);
			fir_scoreboard[9].SetWindowTextW(str);
			fir_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedfirfofkind()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(8, dice, fp.ab, score)) {
			fp.inputScore(8, score);
			str.Format(_T("%d"), fp.board[7]);
			fir_scoreboard[10].SetWindowTextW(str);
			fir_reset_option();
		}
		else {
			fp.inputScore(8, 0);
			str.Format(_T("%d"), fp.board[7]);
			fir_scoreboard[10].SetWindowTextW(str);
			fir_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedfirfullhouse()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(9, dice, fp.ab, score)) {
			fp.inputScore(9, score);
			str.Format(_T("%d"), fp.board[8]);
			fir_scoreboard[11].SetWindowTextW(str);
			fir_reset_option();
		}
		else {
			fp.inputScore(9, 0);
			str.Format(_T("%d"), fp.board[8]);
			fir_scoreboard[11].SetWindowTextW(str);
			fir_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedfirsstraight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(10, dice, fp.ab, score)) {
			fp.inputScore(10, score);
			str.Format(_T("%d"), fp.board[9]);
			fir_scoreboard[12].SetWindowTextW(str);
			fir_reset_option();
		}
		else {
			fp.inputScore(10, 0);
			str.Format(_T("%d"), fp.board[9]);
			fir_scoreboard[12].SetWindowTextW(str);
			fir_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedfirlstraight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(11, dice, fp.ab, score)) {
			fp.inputScore(11, score);
			str.Format(_T("%d"), fp.board[10]);
			fir_scoreboard[13].SetWindowTextW(str);
			fir_reset_option();
		}
		else {
			fp.inputScore(11, 0);
			str.Format(_T("%d"), fp.board[10]);
			fir_scoreboard[13].SetWindowTextW(str);
			fir_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedfiryatch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (turn % 2 == 1) {
		CString str;
		if (rules::judge(12, dice, fp.ab, score)) {
			fp.inputScore(12, score);
			str.Format(_T("%d"), fp.board[11]);
			fir_scoreboard[14].SetWindowTextW(str);
			fir_reset_option();
		}
		else {
			fp.inputScore(12, 0);
			str.Format(_T("%d"), fp.board[11]);
			fir_scoreboard[14].SetWindowTextW(str);
			fir_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecchoices()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(7, dice, sp.ab, score)) {
			sp.inputScore(7, score);
			str.Format(_T("%d"), sp.board[6]);
			sec_scoreboard[9].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(7, 0);
			str.Format(_T("%d"), sp.board[6]);
			sec_scoreboard[9].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecfofkind()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(8, dice, sp.ab, score)) {
			sp.inputScore(8, score);
			str.Format(_T("%d"), sp.board[7]);
			sec_scoreboard[10].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(8, 0);
			str.Format(_T("%d"), sp.board[7]);
			sec_scoreboard[10].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecfullhouse()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(9, dice, sp.ab, score)) {
			sp.inputScore(9, score);
			str.Format(_T("%d"), sp.board[8]);
			sec_scoreboard[11].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(9, 0);
			str.Format(_T("%d"), sp.board[8]);
			sec_scoreboard[11].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecsstraight()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(10, dice, sp.ab, score)) {
			sp.inputScore(10, score);
			str.Format(_T("%d"), sp.board[9]);
			sec_scoreboard[12].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(10, 0);
			str.Format(_T("%d"), sp.board[9]);
			sec_scoreboard[12].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedseclstraight()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(11, dice, sp.ab, score)) {
			sp.inputScore(11, score);
			str.Format(_T("%d"), sp.board[10]);
			sec_scoreboard[13].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(11, 0);
			str.Format(_T("%d"), sp.board[10]);
			sec_scoreboard[13].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}


void CMFCFinalView::OnStnClickedsecyatch()
{
	if (turn % 2 == 0) {
		CString str;
		if (rules::judge(12, dice, sp.ab, score)) {
			sp.inputScore(12, score);
			str.Format(_T("%d"), sp.board[11]);
			sec_scoreboard[14].SetWindowTextW(str);
			sec_reset_option();
		}
		else {
			sp.inputScore(12, 0);
			str.Format(_T("%d"), sp.board[11]);
			sec_scoreboard[14].SetWindowTextW(str);
			sec_reset_option();
		}
	}
}

