// CMyNewDlg2.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CMyNewDlg2.h"
#include "afxdialogex.h"
#include "sciencemode.h"



// CMyNewDlg2 对话框

IMPLEMENT_DYNAMIC(CMyNewDlg2, CDialogEx)

CMyNewDlg2::CMyNewDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CMyNewDlg2::~CMyNewDlg2()
{
}

void CMyNewDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyNewDlg2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyNewDlg2::OnBnClickedOk)
    ON_EN_CHANGE(IDC_EDIT1, &CMyNewDlg2::OnEnChangeEdit1)
END_MESSAGE_MAP()



CString stimulate(CString m_str)
{
    CString temp = m_str;
    int length = temp.GetLength();
    stimulator stim;
    /*float end1 = 155;
    unsigned char getin;
    getin = m_str[0];
    //cin >> getin;
    int TenAscii = getin;
    //cout << TenAscii << '\n';
    int c[8] = {};*/
    //十进制转二进制
    /*for (int j = 7; j >= 0; j--)
    {
        c[j] = TenAscii % 2;
        TenAscii = (TenAscii - c[j]) / 2;
        temp+=char( '0' + c[j]);
        //cout << c[j] << '\n';
    }*/
    //发送
    int* pa = new int[length];
    for (int i = 0; i < length; i++)
    {
        pa[i] = temp[i]-'0';
        printf("%d", pa[i]);
    }
    //&&&&&&&&&&&&&///

    DWORD dwTimerId;
    dwTimerId = SetTimer(NULL, 1, 2000, NULL);
    MSG msg;
    unsigned int i = 0;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (i >= length)
        {
            KillTimer(NULL, dwTimerId);
            dwTimerId = SetTimer(NULL, 1, 2000, NULL);
            break;
        }
        else if (msg.message == WM_TIMER)
        {
            if (pa[i] == 1)
            {
                stim.Open_serial();//
                stim.Setup_serial();

                stim.Send_Single_Pulse(0, 3, 70);
                stim.Close_serial();
            }
        }
        ++i;
    }
    return temp;
}


// CMyNewDlg2 消息处理程序
void CMyNewDlg2::OnBnClickedOk()
{
    CString str;
    CString temp;
    GetDlgItemText(IDC_EDIT1, str);
    temp=stimulate(str);
    SetDlgItemText(IDC_EDIT1, temp);
        // TODO: 在此添加控件通知处理程序代码
    //CDialogEx::OnOK();
}


void CMyNewDlg2::OnEnChangeEdit1()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}
