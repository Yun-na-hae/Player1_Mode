
// HalliGalli_dlg.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHalliGalli_dlgApp:
// �� Ŭ������ ������ ���ؼ��� HalliGalli_dlg.cpp�� �����Ͻʽÿ�.
//

class CHalliGalli_dlgApp : public CWinApp
{
public:
	CHalliGalli_dlgApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHalliGalli_dlgApp theApp;