#pragma once


// CArrow 대화 상자입니다.
#include "Arrow_piece.h"
#include "afxcmn.h"

class CArrow : public CDialogEx
{
	DECLARE_DYNAMIC(CArrow)

public:
	CArrow(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CArrow();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ARROW };
#endif
private:
	CArray<Arrow_piece*> m_arrow_arr;
	int m_arrowcnt;
	int m_position = 0;
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl m_ProCtrl;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
