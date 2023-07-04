// SearchEmployeeDig.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "SearchEmployeeDig.h"
#include "SalaryManageDlg.h"
#include "ShowSalary.h"
#include "ChangeDig.h"


// SearchEmployeeDig 对话框

IMPLEMENT_DYNAMIC(SearchEmployeeDig, CDialogEx)

SearchEmployeeDig::SearchEmployeeDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCH_EMPLOYEE_DIALOG, pParent)
	, _id_edit(0)
{
	/*_Search_Emp_List.InsertColumn(0, _T("工号"), LVCFMT_LEFT, 90, -1);
	_Search_Emp_List.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 90, -1);
	_Search_Emp_List.InsertColumn(2, _T("年龄"), LVCFMT_LEFT, 90, -1);
	_Search_Emp_List.InsertColumn(3, _T("入职日期"), LVCFMT_LEFT, 120, -1);
	_Search_Emp_List.InsertColumn(4, _T("电话"), LVCFMT_LEFT, 90, -1);
	_Search_Emp_List.InsertColumn(5, _T("住址"), LVCFMT_LEFT, 90, -1);
	_Search_Emp_List.InsertColumn(6, _T("月工资数据集"), LVCFMT_LEFT, 150, -1);
	*/
}

SearchEmployeeDig::~SearchEmployeeDig()
{
}

void SearchEmployeeDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH_RESULT_LIST, _Search_Emp_List);
	DDX_Text(pDX, IDC_SEARCH_EMPLOYEE_EDIT, _id_edit);
	if (index==0)
	{ 
		_Search_Emp_List.DeleteAllItems();
		_Search_Emp_List.InsertColumn(0, _T("工号"), LVCFMT_LEFT, 90, -1);
		_Search_Emp_List.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 90, -1);
		_Search_Emp_List.InsertColumn(2, _T("年龄"), LVCFMT_LEFT, 90, -1);
		_Search_Emp_List.InsertColumn(3, _T("入职日期"), LVCFMT_LEFT, 120, -1);
		_Search_Emp_List.InsertColumn(4, _T("电话"), LVCFMT_LEFT, 90, -1);
		_Search_Emp_List.InsertColumn(5, _T("住址"), LVCFMT_LEFT, 90, -1);
		_Search_Emp_List.InsertColumn(6, _T("年工资数据"), LVCFMT_LEFT, 150, -1);
		index++;

	}
	
}


BEGIN_MESSAGE_MAP(SearchEmployeeDig, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_SEARCH_RESULT_LIST, &SearchEmployeeDig::OnLvnItemchangedSearchResultList)
	ON_EN_CHANGE(IDC_SEARCH_EMPLOYEE_EDIT, &SearchEmployeeDig::OnEnChangeSearchEmployeeEdit)
	ON_BN_CLICKED(IDC_SEARCH_EMPLOYEE_BUTTON, &SearchEmployeeDig::OnBnClickedSearchEmployeeButton)
	ON_BN_CLICKED(IDC_TO_CHANGE_BUTTON, &SearchEmployeeDig::OnBnClickedToChangeButton)
	ON_BN_CLICKED(IDOK, &SearchEmployeeDig::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SearchEmployeeDig::OnBnClickedCancel)
END_MESSAGE_MAP()


// SearchEmployeeDig 消息处理程序


void SearchEmployeeDig::OnLvnItemchangedSearchResultList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	*pResult = 0;
}


void SearchEmployeeDig::OnEnChangeSearchEmployeeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	UpdateData();
}


void SearchEmployeeDig::OnBnClickedSearchEmployeeButton()
{
	
	// TODO: 在此添加控件通知处理程序代码
	Management* to_get_a_employee = Management::getInstance();
	if (to_get_a_employee->SearchEmployeeId(_id_edit))
	{
		
		//int last_row;
		//to_get_a_employee->SeaGetEmployee(_id_edit)
		
		_Search_Emp_List.DeleteAllItems();
		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;


		add_id = to_string(to_get_a_employee->SeaGetEmployee(_id_edit).GetId()).c_str();
		add_name = to_get_a_employee->SeaGetEmployee(_id_edit).GetName().c_str();
		add_age = to_string(to_get_a_employee->SeaGetEmployee(_id_edit).GetAge()).c_str();
		add_hireDate = to_get_a_employee->SeaGetEmployee(_id_edit).GetHireDate().c_str();
		add_phone = to_get_a_employee->SeaGetEmployee(_id_edit).GetPhone().c_str();
		add_address = to_get_a_employee->SeaGetEmployee(_id_edit).GetAddress().c_str();
		add_monthlySalary = to_string(to_get_a_employee->SeaGetEmployee(_id_edit).GetYearlySalary()).c_str();

		//last_row = _Search_Emp_List.GetItemCount();
		_Search_Emp_List.InsertItem(0, add_id);
		_Search_Emp_List.SetItemText(0, 1, add_name);
		_Search_Emp_List.SetItemText(0, 2, add_age);
		_Search_Emp_List.SetItemText(0, 3, add_hireDate);
		_Search_Emp_List.SetItemText(0, 4, add_phone);
		_Search_Emp_List.SetItemText(0, 5, add_address);
		_Search_Emp_List.SetItemText(0, 6, add_monthlySalary);
		UpdateData();
	
	}
	else
	{
		AfxMessageBox(_T("没有找到指定目标"));
		return;
	}
}


void SearchEmployeeDig::OnBnClickedToChangeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = -1;
	if ((index = _Search_Emp_List.GetNextItem(index, LVNI_SELECTED)) != -1)
	{
		CString a;
		a = to_string(index).c_str();
		ShowSalary ToShowSalary2;
		ToShowSalary2._employee_id = index;
		ToShowSalary2.DoModal();
		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;

		_Search_Emp_List.DeleteAllItems();

		Management* to_get_a_employee = Management::getInstance();
		add_id = to_string(to_get_a_employee->SeaGetEmployee(_id_edit).GetId()).c_str();
		add_name = to_get_a_employee->SeaGetEmployee(_id_edit).GetName().c_str();
		add_age = to_string(to_get_a_employee->SeaGetEmployee(_id_edit).GetAge()).c_str();
		add_hireDate = to_get_a_employee->SeaGetEmployee(_id_edit).GetHireDate().c_str();
		add_phone = to_get_a_employee->SeaGetEmployee(_id_edit).GetPhone().c_str();
		add_address = to_get_a_employee->SeaGetEmployee(_id_edit).GetAddress().c_str();
		add_monthlySalary = to_string(to_get_a_employee->SeaGetEmployee(_id_edit).GetYearlySalary()).c_str();

		//last_row = _Search_Emp_List.GetItemCount();
		_Search_Emp_List.InsertItem(0, add_id);
		_Search_Emp_List.SetItemText(0, 1, add_name);
		_Search_Emp_List.SetItemText(0, 2, add_age);
		_Search_Emp_List.SetItemText(0, 3, add_hireDate);
		_Search_Emp_List.SetItemText(0, 4, add_phone);
		_Search_Emp_List.SetItemText(0, 5, add_address);
		_Search_Emp_List.SetItemText(0, 6, add_monthlySalary);
		OnBnClickedSearchEmployeeButton();
		UpdateData();
	}
	else
	{
		AfxMessageBox(_T("请选定一个对象"));
	}

	
}


void SearchEmployeeDig::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
	OnBnClickedSearchEmployeeButton();


}


void SearchEmployeeDig::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
