
// MyMacroDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMyMacroDlg ��ȭ ����
class CMyMacroDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMyMacroDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITCONTROLMACRO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CEdit mHwndEdit;
	CEdit mHconEdit;
	CEdit mHEdit;
	CEdit mHBtn;
};
