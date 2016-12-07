// Arrow.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "Arrow.h"
#include "afxdialogex.h"
#include "Arrow_piece.h"
#include "afxtempl.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>


// CArrow ��ȭ �����Դϴ�.

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


// CArrow �޽��� ó�����Դϴ�.


BOOL CArrow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	srand((unsigned int)time(NULL));
	m_arrowcnt = rand() % 4 + 5; //ȭ��ǥ ������ 5��~8������ �������� �����ϱ� ����
	for (int i = 0; i < m_arrowcnt; i++) {
		Arrow_piece* ap = new Arrow_piece(rand() % 4);
		m_arrow_arr.Add(ap);//ȭ��ǥ���� �迭�� �߰�
	}


	m_ProCtrl.SetRange(0, 100);
	m_ProCtrl.SetPos(100);
	m_ProCtrl.SetStep(-2);
	SetTimer(1000, 40, NULL);//50�и������帶�� ��Ÿ�� �Լ� ����

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}



void CArrow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
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

		if (ap->GetArrowStatus() == 2)//Ʋ���� ���
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

//0�� 1�� 2�� 3�Ʒ�

BOOL CArrow::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
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
		InvalidateRect(NULL, FALSE);//������Ʈ ȣ��
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}




void CArrow::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CArrow::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 1000) {
		m_ProCtrl.StepIt();//������ -��ŭ �پ��
		if (m_ProCtrl.GetPos() == 0) {
			KillTimer(1000);
			PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			MessageBox(_T("�ð��ʰ� ��������"));
			OnCancel();
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}
