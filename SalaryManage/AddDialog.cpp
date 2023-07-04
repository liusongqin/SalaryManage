// AddDialog.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "AddDialog.h"


// AddDialog 对话框

IMPLEMENT_DYNAMIC(AddDialog, CDialogEx)

AddDialog::AddDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_DIALOG, pParent)
	, _id_edit(0)
	, _name_edit(_T("0"))
	, _hireDate_edit(_T("0"))
	, _age_edit(0)
	, _phone_edit(_T("0"))
	, _address_edit(_T("0"))
	, _monthlySalary_edit(0)
	, _tag_edit(_T("0"))
{

}

AddDialog::~AddDialog()
{
}

void AddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _id_edit);
	DDX_Text(pDX, IDC_EDIT2, _name_edit);
	DDX_Text(pDX, IDC_EDIT4, _hireDate_edit);
	DDX_Text(pDX, IDC_EDIT3, _age_edit);
	DDX_Text(pDX, IDC_EDIT5, _phone_edit);
	DDX_Text(pDX, IDC_EDIT6, _address_edit);
//	DDX_Text(pDX, IDC_EDIT7, _monthlySalary_edit);
	DDX_Text(pDX, IDC_TAG_EDIT, _tag_edit);
}


BEGIN_MESSAGE_MAP(AddDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &AddDialog::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &AddDialog::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &AddDialog::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &AddDialog::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &AddDialog::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &AddDialog::OnEnChangeEdit6)
//	ON_EN_CHANGE(IDC_EDIT7, &AddDialog::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_TAG_EDIT, &AddDialog::OnEnChangeTagEdit)
END_MESSAGE_MAP()


// AddDialog 消息处理程序


void AddDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddDialog::OnEnChangeTagEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
