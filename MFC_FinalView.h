
// MFC_FinalView.h: CMFCFinalView 클래스의 인터페이스
//

#pragma once
#include<string>
#include"ScoreBoard.h"
#include"Dice.h"
using namespace std;

class CMFCFinalView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMFCFinalView() noexcept;
	DECLARE_DYNCREATE(CMFCFinalView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_FINAL_FORM };
#endif

// 특성입니다.
public:

	int turn = 0;
	CMFCFinalDoc* GetDocument() const;
	CStatic* fir_scoreboard;
	CStatic* sec_scoreboard;
	ScoreBoard fp, sp;
	int dice[5];
	int flag = 0;
	int dice_id[5];
	int score = 0;
// 작업입니다.
public:
	void show_dice(int d,int id);
	void set_turn();
	void fir_reset_option();
	void sec_reset_option();
	void rect_inva(int ID);

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCFinalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	void set_guide(CString text);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CStatic sb_guide;
	CStatic static_turn;
	afx_msg void OnStnClickedfiraces();
	afx_msg void OnStnClickedfirdeuces();
	afx_msg void OnStnClickedfirthrees();
	afx_msg void OnStnClickedfirfours();
	afx_msg void OnStnClickedfirfives();
	afx_msg void OnStnClickedfirsixes();
	afx_msg void OnStnClickedsecaces();
	afx_msg void OnStnClickedsecdeuces();
	afx_msg void OnStnClickedsecthrees();
	afx_msg void OnStnClickedsecfours();
	afx_msg void OnStnClickedsecfives();
	afx_msg void OnStnClickedsecsixes();
	afx_msg void OnStnClickedfirchoices();
	afx_msg void OnStnClickedfirfofkind();
	afx_msg void OnStnClickedfirfullhouse();
	afx_msg void OnStnClickedfirsstraight();
	afx_msg void OnStnClickedfirlstraight();
	afx_msg void OnStnClickedfiryatch();
	afx_msg void OnStnClickedsecchoices();
	afx_msg void OnStnClickedsecfofkind();
	afx_msg void OnStnClickedsecfullhouse();
	afx_msg void OnStnClickedsecsstraight();
	afx_msg void OnStnClickedseclstraight();
	afx_msg void OnStnClickedsecyatch();
};

#ifndef _DEBUG  // MFC_FinalView.cpp의 디버그 버전
inline CMFCFinalDoc* CMFCFinalView::GetDocument() const
   { return reinterpret_cast<CMFCFinalDoc*>(m_pDocument); }
#endif

