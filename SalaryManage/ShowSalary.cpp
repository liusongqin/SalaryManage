// ShowSalary.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "ShowSalary.h"
#include "Management.h"
#include "ChangeDig.h"


// ShowSalary 对话框

IMPLEMENT_DYNAMIC(ShowSalary, CDialogEx)

ShowSalary::ShowSalary(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOW_DIALOG, pParent)
{

}

ShowSalary::~ShowSalary()
{
}

void ShowSalary::DoDataExchange(CDataExchange* pDX)
{
	
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, _ShowSalaryList);
	_ShowSalaryList.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES);
	if (index == 0)
	{

		_ShowSalaryList.InsertColumn(0, _T("月份"), LVCFMT_LEFT, 90, -1);
		_ShowSalaryList.InsertColumn(1, _T("基本工资"), LVCFMT_LEFT, 90, -1);
		_ShowSalaryList.InsertColumn(2, _T("岗位工资"), LVCFMT_LEFT, 90, -1);
		_ShowSalaryList.InsertColumn(3, _T("工龄工资"), LVCFMT_LEFT, 120, -1);
		_ShowSalaryList.InsertColumn(4, _T("津贴"), LVCFMT_LEFT, 90, -1);
		_ShowSalaryList.InsertColumn(5, _T("岗贴"), LVCFMT_LEFT, 90, -1);
		_ShowSalaryList.InsertColumn(6, _T("补贴"), LVCFMT_LEFT, 150, -1);
		_ShowSalaryList.InsertColumn(7, _T("房贴"), LVCFMT_LEFT, 150, -1);
		_ShowSalaryList.InsertColumn(8, _T("交通补贴"), LVCFMT_LEFT, 150, -1);
		_ShowSalaryList.InsertColumn(9, _T("个人所得税"), LVCFMT_LEFT, 150, -1);
		_ShowSalaryList.InsertColumn(10, _T("实发数"), LVCFMT_LEFT, 150, -1);
		index++;
		_ShowSalaryList.DeleteAllItems();
		int last_row = 0;
		int i = 0;
		int the_all_total = 0;
		Management* to_get_a_employee = Management::getInstance();
		for (i = 0; i <12; i++)
		{
			CString add_month;
			CString add_baseSalary;
			CString add_positionSalary;
			CString add_senioritySalary;
			CString add_allowance;
			CString add_StatusAllowance;
			CString add_subsidy;
			CString add_houseSubsidy;
			CString add_trafficAllowance;
			CString add_tax;
			CString add_total;
			to_get_a_employee->getEeVector()[0].GetCMonthlySalary()[i].SetMonth(i+1);
			 add_month = to_string(to_get_a_employee->getEeVector()[0].GetCMonthlySalary()[i].GetMonth()).c_str();
			 add_baseSalary= to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetBaseSalary()).c_str();
			 add_positionSalary = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetPositionSalary()).c_str();
			 add_senioritySalary = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetSenioritySalary()).c_str();
			 add_allowance = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetAllowance()).c_str();
			 add_StatusAllowance = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetStatusAllowance()).c_str();
			 add_subsidy = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetSubsidy()).c_str();
			 add_houseSubsidy = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetHouseSubsidy()).c_str();
			 add_trafficAllowance = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTrafficAllowance()).c_str();
			 add_tax = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTax()).c_str();
			 add_total = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTotal()).c_str();

			last_row = _ShowSalaryList.GetItemCount();
			_ShowSalaryList.InsertItem(last_row, add_month);
			_ShowSalaryList.SetItemText(last_row, 1, add_baseSalary);
			_ShowSalaryList.SetItemText(last_row, 2, add_positionSalary);
			_ShowSalaryList.SetItemText(last_row, 3, add_senioritySalary);
			_ShowSalaryList.SetItemText(last_row, 4, add_allowance);
			_ShowSalaryList.SetItemText(last_row, 5, add_StatusAllowance);
			_ShowSalaryList.SetItemText(last_row, 6, add_subsidy);
			_ShowSalaryList.SetItemText(last_row, 7, add_houseSubsidy);
			_ShowSalaryList.SetItemText(last_row, 8, add_trafficAllowance);
			_ShowSalaryList.SetItemText(last_row, 9, add_tax);
			_ShowSalaryList.SetItemText(last_row, 10, add_total);

		}
	}

}


BEGIN_MESSAGE_MAP(ShowSalary, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &ShowSalary::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_CHANGE_SALARY_BUTTON, &ShowSalary::OnBnClickedChangeSalaryButton)
	ON_BN_CLICKED(IDOK, &ShowSalary::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ShowSalary::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_SEARCH_RESULT_LIST, &ShowSalary::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// ShowSalary 消息处理程序


void ShowSalary::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (pNMLV->uChanged & LVIF_STATE)
	{
		// 判断当前列表项的复选框是否被选中
		BOOL bChecked = _ShowSalaryList.GetCheck(pNMLV->iItem);

		// 如果当前列表项的复选框被选中，则取消其他列表项的选择状态
		if (bChecked)
		{
			for (int i = 0; i < _ShowSalaryList.GetItemCount(); i++)
			{
				if (i != pNMLV->iItem)
				{
					_ShowSalaryList.SetCheck(i, FALSE);
				}
			}
		}
	}
	*pResult = 0;
}


void ShowSalary::OnBnClickedChangeSalaryButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = -1;
	int nItemCount = _ShowSalaryList.GetItemCount();
	for (int i = nItemCount - 1; i > -1; i--)
	{
		if (_ShowSalaryList.GetCheck(i))
		{
			CString a;
			a = to_string(i).c_str();
			ChangeDig ToChangeDig;
			ToChangeDig._month_id = i;
			ToChangeDig._change_employee_id = _employee_id;

			Management* to_get_a_employee = Management::getInstance();
			ToChangeDig._baseSalary_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetBaseSalary();
			ToChangeDig._positionSalary_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetPositionSalary();
			ToChangeDig._senioritySalary_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetSenioritySalary();
			ToChangeDig._allowance_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetAllowance();
			ToChangeDig._StatusAllowance_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetStatusAllowance();
			ToChangeDig._subsidy_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetSubsidy();
			ToChangeDig._houseSubsidy_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetHouseSubsidy();
			ToChangeDig._trafficAllowance_edit = to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTrafficAllowance();

			ToChangeDig.DoModal();

			_ShowSalaryList.DeleteAllItems();
			int last_row = 0;
			int i = 0;
			int the_all_total = 0;

			for (i = 0; i < 12; i++)
			{
				CString add_month;
				CString add_baseSalary;
				CString add_positionSalary;
				CString add_senioritySalary;
				CString add_allowance;
				CString add_StatusAllowance;
				CString add_subsidy;
				CString add_houseSubsidy;
				CString add_trafficAllowance;
				CString add_tax;
				CString add_total;
				to_get_a_employee->getEeVector()[0].GetCMonthlySalary()[i].SetMonth(i + 1);
				add_month = to_string(to_get_a_employee->getEeVector()[0].GetCMonthlySalary()[i].GetMonth()).c_str();
				add_baseSalary = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetBaseSalary()).c_str();
				add_positionSalary = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetPositionSalary()).c_str();
				add_senioritySalary = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetSenioritySalary()).c_str();
				add_allowance = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetAllowance()).c_str();
				add_StatusAllowance = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetStatusAllowance()).c_str();
				add_subsidy = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetSubsidy()).c_str();
				add_houseSubsidy = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetHouseSubsidy()).c_str();
				add_trafficAllowance = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTrafficAllowance()).c_str();
				add_tax = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTax()).c_str();
				add_total = to_string(to_get_a_employee->getEeVector()[_employee_id].GetCMonthlySalary()[i].GetTotal()).c_str();

				last_row = _ShowSalaryList.GetItemCount();
				_ShowSalaryList.InsertItem(last_row, add_month);
				_ShowSalaryList.SetItemText(last_row, 1, add_baseSalary);
				_ShowSalaryList.SetItemText(last_row, 2, add_positionSalary);
				_ShowSalaryList.SetItemText(last_row, 3, add_senioritySalary);
				_ShowSalaryList.SetItemText(last_row, 4, add_allowance);
				_ShowSalaryList.SetItemText(last_row, 5, add_StatusAllowance);
				_ShowSalaryList.SetItemText(last_row, 6, add_subsidy);
				_ShowSalaryList.SetItemText(last_row, 7, add_houseSubsidy);
				_ShowSalaryList.SetItemText(last_row, 8, add_trafficAllowance);
				_ShowSalaryList.SetItemText(last_row, 9, add_tax);
				_ShowSalaryList.SetItemText(last_row, 10, add_total);

			}
			to_get_a_employee->getEeVector()[_employee_id].SetMonthlySalary(to_get_a_employee->getEeVector()[_employee_id].GetYearlySalary());
			UpdateData();

			return;
		}
		else {
			//AfxMessageBox(_T("请选定一个对象"));
		}

	}
}


void ShowSalary::OnBnClickedOk()
	{
		// TODO: 在此添加控件通知处理程序代码
		CDialogEx::OnOK();
	}


void ShowSalary::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
