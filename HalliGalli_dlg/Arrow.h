#pragma once


// CArrow ��ȭ �����Դϴ�.
#include "Arrow_piece.h"
#include "afxcmn.h"

class CArrow : public CDialogEx
{
	DECLARE_DYNAMIC(CArrow)

public:
	CArrow(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CArrow();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ARROW };
#endif
private:
	CArray<Arrow_piece*> m_arrow_arr;
	int m_arrowcnt;
	int m_position = 0;
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl m_ProCtrl;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
