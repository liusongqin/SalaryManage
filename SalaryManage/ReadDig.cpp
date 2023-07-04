// ReadDig.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "ReadDig.h"


// ReadDig 对话框

IMPLEMENT_DYNAMIC(ReadDig, CDialogEx)

ReadDig::ReadDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_READ_DIALOG, pParent)
{

}

ReadDig::~ReadDig()
{
}

void ReadDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReadDig, CDialogEx)
END_MESSAGE_MAP()


// ReadDig 消息处理程序
