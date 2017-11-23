
// InputAndSpyDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CInputAndSpyDlg ��ȭ ����
class CInputAndSpyDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CInputAndSpyDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUTANDSPY_DIALOG };
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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CEdit mEdit;
	CEdit mOutEdit;
};
