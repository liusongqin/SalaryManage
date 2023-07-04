// ChangeDig.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "ChangeDig.h"
#include "Management.h"


// ChangeDig 对话框

IMPLEMENT_DYNAMIC(ChangeDig, CDialogEx)

ChangeDig::ChangeDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGE_DIALOG, pParent)

	, _baseSalary_edit(0)
	, _positionSalary_edit(0)
	, _senioritySalary_edit(0)
	, _allowance_edit(0)
	, _StatusAllowance_edit(0)
	, _subsidy_edit(0)
	, _houseSubsidy_edit(0)
	, _trafficAllowance_edit(0)

{
	Management* to_get_a_employee = Management::getInstance();
	_baseSalary_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetBaseSalary();
	_positionSalary_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetPositionSalary();
	_senioritySalary_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetSenioritySalary();
	_allowance_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetAllowance();
	_StatusAllowance_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetStatusAllowance();
	_subsidy_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetSubsidy();
	_houseSubsidy_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetHouseSubsidy();
	_trafficAllowance_edit = to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].GetTrafficAllowance();

	
}

ChangeDig::~ChangeDig()
{
}

void ChangeDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, _baseSalary_edit);
	DDX_Text(pDX, IDC_EDIT2, _positionSalary_edit);
	DDX_Text(pDX, IDC_EDIT4, _senioritySalary_edit);
	DDX_Text(pDX, IDC_EDIT3, _allowance_edit);
	DDX_Text(pDX, IDC_EDIT5, _StatusAllowance_edit);
	DDX_Text(pDX, IDC_EDIT6, _subsidy_edit);
	DDX_Text(pDX, IDC_EDIT7, _houseSubsidy_edit);
	DDX_Text(pDX, IDC_EDIT8, _trafficAllowance_edit);
}


BEGIN_MESSAGE_MAP(ChangeDig, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &ChangeDig::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &ChangeDig::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &ChangeDig::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &ChangeDig::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &ChangeDig::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &ChangeDig::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &ChangeDig::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &ChangeDig::OnEnChangeEdit8)
	ON_BN_CLICKED(IDOK, &ChangeDig::OnBnClickedOk)
END_MESSAGE_MAP()


// ChangeDig 消息处理程序


void ChangeDig::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChangeDig::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	Management* to_get_a_employee = Management::getInstance();
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetBaseSalary(_baseSalary_edit);
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetPositionSalary(_positionSalary_edit);
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetSenioritySalary(_senioritySalary_edit);
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetAllowance(_allowance_edit);
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetStatusAllowance(_StatusAllowance_edit);
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetSubsidy(_subsidy_edit);
	 to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetHouseSubsidy(_houseSubsidy_edit);
	to_get_a_employee->getEeVector()[_change_employee_id].GetCMonthlySalary()[_month_id].SetTrafficAllowance(_trafficAllowance_edit);


	UpdateData();


}
