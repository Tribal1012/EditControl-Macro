
// EditControlMacro.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMyMacroApp:
// �� Ŭ������ ������ ���ؼ��� EditControlMacro.cpp�� �����Ͻʽÿ�.
//

class CMyMacroApp : public CWinApp
{
public:
	CMyMacroApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMyMacroApp theApp;