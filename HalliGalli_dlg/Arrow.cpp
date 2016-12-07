// Arrow.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "Arrow.h"
#include "afxdialogex.h"
#include "Arrow_piece.h"
#include "afxtempl.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>


// CArrow 대화 상자입니다.

IMPLEMENT_DYNAMIC(CArrow, CDialogEx)

CArrow::CArrow(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ARROW, pParent)
{

}

CArrow::~CArrow()
{
	for (int i = 0; i < m_arrow_arr.GetCount(); i++)
		delete m_arrow_arr.GetAt(i);
}

void CArrow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProCtrl);
}


BEGIN_MESSAGE_MAP(CArrow, CDialogEx)
	ON_WM_PAINT()
	//	ON_WM_KEYDOWN()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CArrow::OnNMCustomdrawProgress1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CArrow 메시지 처리기입니다.


BOOL CArrow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	srand((unsigned int)time(NULL));
	m_arrowcnt = rand() % 4 + 5; //화살표 개수를 5개~8개까지 랜덤으로 생성하기 위함
	for (int i = 0; i < m_arrowcnt; i++) {
		Arrow_piece* ap = new Arrow_piece(rand() % 4);
		m_arrow_arr.Add(ap);//화살표들을 배열에 추가
	}


	m_ProCtrl.SetRange(0, 100);
	m_ProCtrl.SetPos(100);
	m_ProCtrl.SetStep(-2);
	SetTimer(1000, 40, NULL);//50밀리세컨드마다 온타임 함수 실행

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CArrow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	int x = 0;

	if (m_arrowcnt == 5)
		x = 210;
	else if (m_arrowcnt == 6)
		x = 155;
	else if (m_arrowcnt == 7)
		x = 115;
	else if (m_arrowcnt == 8)
		x = 70;


	bool is_fail = false;

	for (int i = 0; i < m_arrow_arr.GetCount(); i++)
	{
		Arrow_piece* ap = m_arrow_arr.GetAt(i);
		ap->LoadArrowImage();
		ap->GetImage().TransparentBlt(dc.m_hDC, x + i * 100, 200, 100, 100, RGB(0, 0, 0));

		if (ap->GetArrowStatus() == 2)//틀렸을 경우
			is_fail = true;
	}

	if (is_fail)
	{
		KillTimer(1000);
		AfxMessageBox(_T("FAIL"));
		OnCancel();

	}

	if (m_position == m_arrow_arr.GetCount())
	{
		KillTimer(1000);
		AfxMessageBox(_T("SUCCESS"));
		OnOK();
	}

}

//0왼 1오 2위 3아래

BOOL CArrow::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	if (pMsg->message == WM_KEYDOWN) {
		Arrow_piece* ap = m_arrow_arr.GetAt(m_position);

		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE) {
			return TRUE;
		}


		if (ap->GetDirection() == 0) {
			if (pMsg->wParam == VK_LEFT) {
				ap->SetCorrectStatus();
				PlaySound(_T("./res/correct.wav"), NULL, SND_ASYNC );
			}
			else {
				ap->SetWrongStatus();
				PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			}
		}

		if (ap->GetDirection() == 1) {
			if (pMsg->wParam == VK_RIGHT) {
				ap->SetCorrectStatus();
				PlaySound(_T("./res/correct.wav"), NULL, SND_ASYNC);
			}
			else {
				ap->SetWrongStatus();
				PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			}
		}

		if (ap->GetDirection() == 2) {
			if (pMsg->wParam == VK_UP) {
				ap->SetCorrectStatus();
				PlaySound(_T("./res/correct.wav"), NULL, SND_ASYNC);
			}
			else {
				ap->SetWrongStatus();
				PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			}
		}


		if (ap->GetDirection() == 3) {
			if (pMsg->wParam == VK_DOWN) {
				ap->SetCorrectStatus();
				PlaySound(_T("./res/correct.wav"), NULL, SND_ASYNC);
			}
			else {
				ap->SetWrongStatus();
				PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			}
		}
		m_position++;
		InvalidateRect(NULL, FALSE);//온페인트 호츌
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}




void CArrow::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CArrow::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 1000) {
		m_ProCtrl.StepIt();//셋팅한 -만큼 줄어듦
		if (m_ProCtrl.GetPos() == 0) {
			KillTimer(1000);
			PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			MessageBox(_T("시간초과 실패지롱"));
			OnCancel();
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}
