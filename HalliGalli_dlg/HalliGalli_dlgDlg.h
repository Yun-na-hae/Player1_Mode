
// HalliGalli_dlgDlg.h : 헤더 파일
//

#pragma once
#include "Main.h"
#include "afxwin.h"

// CHalliGalli_dlgDlg 대화 상자
class CHalliGalli_dlgDlg : public CDialogEx
{
// 생성입니다.
public:
	CHalliGalli_dlgDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HALLIGALLI_DLG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

public:
	Main m_gamedata;
	bool bell_ring;
	bool success;
	bool time;
	CString str_num;

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBellring();
	afx_msg void OnBnClickedButtonPress();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CStatic m_p2_re;
	CStatic m_all_re;
	CStatic m_p1_re;
};
