#pragma once


// CMyNewDlg2 对话框

class CMyNewDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewDlg2)

public:
	CMyNewDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyNewDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};
