
// InputAndSpy.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSpyApp:
// �� Ŭ������ ������ ���ؼ��� InputAndSpy.cpp�� �����Ͻʽÿ�.
//

class CSpyApp : public CWinApp
{
public:
	CSpyApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSpyApp theApp;