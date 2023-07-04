// DeleteEmployeeDIg.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "DeleteEmployeeDIg.h"
#include "Management.h"


// DeleteEmployeeDIg 对话框

IMPLEMENT_DYNAMIC(DeleteEmployeeDIg, CDialogEx)

DeleteEmployeeDIg::DeleteEmployeeDIg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_EMPLOYEE_DIALOG, pParent)
	, _delete_employee_id(-1)
{

}

DeleteEmployeeDIg::~DeleteEmployeeDIg()
{
}

void DeleteEmployeeDIg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteEmployeeDIg, CDialogEx)
	//ON_EN_CHANGE(IDC_DELETE_EMPLOYEE_EDIT, &DeleteEmployeeDIg::OnEnChangeDeleteEmployeeEdit)
	ON_BN_CLICKED(IDOK, &DeleteEmployeeDIg::OnBnClickedOk)
END_MESSAGE_MAP()


// DeleteEmployeeDIg 消息处理程序


void DeleteEmployeeDIg::OnEnChangeDeleteEmployeeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void DeleteEmployeeDIg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	/*Management* to_delete_a_employee = Management::getInstance();
	to_delete_a_employee->getEeVector().erase
	(
		to_delete_a_employee->getEeVector().begin() + _delete_employee_id
	);*/
}
