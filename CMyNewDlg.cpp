// CMyNewDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CMyNewDlg.h"
#include "afxdialogex.h"
#include "sciencemode.h"
#include "iostream"
// CMyNewDlg 对话框

IMPLEMENT_DYNAMIC(CMyNewDlg, CDialogEx)

CMyNewDlg::CMyNewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_str(_T(""))
{

}

CMyNewDlg::~CMyNewDlg()
{
}

void CMyNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_edit);
	DDX_Text(pDX, IDC_EDIT2, m_str);
}


BEGIN_MESSAGE_MAP(CMyNewDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyNewDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CMyNewDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

void stimulate2(CString m_str)
{
    int length = m_str.GetLength();
    stimulator stim;
    int a[100] = {1,1,1};
    for (int i = 0; i < length; i++)
    {
        unsigned char getin;
        getin = m_str[i];
        //cin >> getin;
        int TenAscii = getin;
        //cout << TenAscii << '\n';
        int c[8] = {};
        stimulator stim;
        //十进制转二进制
        for (int j = 7; j >= 0; j--)
        {
            c[j] = TenAscii % 2;
            TenAscii = (TenAscii - c[j]) / 2;
            a[j + i * 8 + 3] = c[j];
            printf("%d",c[j]);
        }
    }
    
    //发送
    //&&&&&&&&&&&&&///

    clock_t start;
    start = clock();
    unsigned int i = 0;
    while (1)
    {
        if (i >= length*8 + 3 )
        //if (i > m_str.GetLength() - 1)
        {
           
            break;
        }
        else if ((clock() - start) == 500)
        {
            start = clock();
            if (a[i] == 1)
            {
                start = clock();
                stim.Open_serial();//
                stim.Setup_serial();

                stim.Send_Single_Pulse(0, 10, 70);
                stim.Close_serial();
            }
            ++i;
        }
        
    }
}
// CMyNewDlg 消息处理程序


void CMyNewDlg::OnBnClickedOk()
{
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	stimulate2(str);
	
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}




void CMyNewDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
