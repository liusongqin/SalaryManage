
// SalaryManageDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SalaryManage.h"
#include "SalaryManageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "AddDialog.h"
#include "DeleteEmployeeDIg.h"
#include "SearchEmployeeDig.h"
#include "SaveDig.h"
#include "ReadFileDig.h"
#include "ShowSalary.h"

string CStringToString(const CString& cstr)
{
	CT2CA pszConvertedAnsiString(cstr);
	string str(pszConvertedAnsiString);
	return str;
}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSalaryManageDlg 对话框



CSalaryManageDlg::CSalaryManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SALARYMANAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSalaryManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_LIST, _Main_ShowList);
}

BEGIN_MESSAGE_MAP(CSalaryManageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_SHOW_LIST, &CSalaryManageDlg::OnLvnItemchangedList)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CSalaryManageDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_SHOW_BUTTON, &CSalaryManageDlg::OnBnClickedShowButton)
	ON_BN_CLICKED(IDC_ADD_EMPLOYEE_BUTTON, &CSalaryManageDlg::OnBnClickedAddEmployeeButton)
	ON_BN_CLICKED(IDC_DELETE_EMPLOYEE_BUTTON, &CSalaryManageDlg::OnBnClickedDeleteEmployeeButton)
	ON_BN_CLICKED(IDC_SEARCH_EMPLOYEE_BUTTON, &CSalaryManageDlg::OnBnClickedSearchEmployeeButton)
	ON_BN_CLICKED(IDC_SAVE_FILE_BUTTON, &CSalaryManageDlg::OnBnClickedSaveFileButton)
	ON_BN_CLICKED(IDC_READ_BUTTON, &CSalaryManageDlg::OnBnClickedReadButton)
	ON_BN_CLICKED(IDC_SHOW_SALARY_BUTTON, &CSalaryManageDlg::OnBnClickedShowSalaryButton)
	ON_BN_CLICKED(IDC_SELECT_ALL_BUTTON, &CSalaryManageDlg::OnBnClickedSelectAllButton)
	ON_EN_CHANGE(IDC_EDIT_MAIN_1, &CSalaryManageDlg::OnEnChangeEditMain1)
	ON_EN_CHANGE(IDC_EDIT_MAIN_7, &CSalaryManageDlg::OnEnChangeEditMain7)
	ON_EN_CHANGE(IDC_EDIT_MAIN_8, &CSalaryManageDlg::OnEnChangeEditMain8)
	ON_BN_CLICKED(IDC_CHANGE_INF_BUTTON, &CSalaryManageDlg::OnBnClickedChangeInfButton)
	ON_BN_CLICKED(IDC_CANCEL_SELALL_BUTTON, &CSalaryManageDlg::OnBnClickedCancelSelallButton)
	ON_BN_CLICKED(IDOK, &CSalaryManageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSalaryManageDlg 消息处理程序

BOOL CSalaryManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	_manager = Management::getInstance();
	_Main_ShowList.SetExtendedStyle(LVS_EX_CHECKBOXES| LVS_EX_GRIDLINES);
	_Main_ShowList.InsertColumn(0, _T("工号"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(2, _T("年龄"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(3, _T("入职日期"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(4, _T("电话"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(5, _T("住址"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(6, _T("年工资数据"), LVCFMT_LEFT, 150, -1);
	_Main_ShowList.InsertColumn(7, _T("特殊员工职位"), LVCFMT_LEFT, 150, -1);

	
	
		return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSalaryManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSalaryManageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSalaryManageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int m_nPreSel = -1;
void CSalaryManageDlg::OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

/*	if (pNMLV->uNewState == 0x2000 && pNMLV->uOldState == 0x1000)	//复选框选中状态
	{
		if (m_nPreSel != -1 && m_nPreSel != pNMLV->iItem)
		{
			_Main_ShowList.SetCheck(m_nPreSel, FALSE);	//设置上次选中状态复选框为未选中状态
		}

		m_nPreSel = pNMLV->iItem;
	}*/
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	if (pNMItemActivate->iItem != -1 && pNMItemActivate->uNewState & LVIS_SELECTED)
	{
		CString strData = _Main_ShowList.GetItemText(pNMItemActivate->iItem, 1); // 获取选中行的数据
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_SHOW_LIST); // 获取CEdit控件的指针
		pEdit->SetWindowText(strData); // 显示选中行的数据
	}
	
		
	*pResult = 0;
}


void CSalaryManageDlg::OnBnClickedAddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedAddEmployeeButton();
	

}

static int SearchIndex = 0;
void CSalaryManageDlg::OnBnClickedShowButton()
{

	// TODO: 在此添加控件通知处理程序代码
	/*_Main_ShowList.DeleteAllItems();
	int last_row=0;
	for (int i = 0; i < _manager->getEeVector().size(); i++)
	{
	
		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;
		CString add_tag;
	

		add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
		add_name = _manager->getEeVector()[i].GetName().c_str();
		add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
		add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
		add_phone = _manager->getEeVector()[i].GetPhone().c_str();
		add_address = _manager->getEeVector()[i].GetAddress().c_str();
		add_monthlySalary = to_string(_manager->getEeVector()[i].GetYearlySalary()).c_str();
		add_tag= _manager->getEeVector()[i].GetTag().c_str();

		last_row = _Main_ShowList.GetItemCount();
		_Main_ShowList.InsertItem(last_row, add_id);
		_Main_ShowList.SetItemText(last_row, 1, add_name);
		_Main_ShowList.SetItemText(last_row, 2, add_age);
		_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
		_Main_ShowList.SetItemText(last_row, 4, add_phone);
		_Main_ShowList.SetItemText(last_row, 5, add_address);
		_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
		_Main_ShowList.SetItemText(last_row, 7, add_tag);

	}
	UpdateData();*/
	
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = nItemCount - 1; i > -1; i--)
	{
		if (_Main_ShowList.GetCheck(i))
		{
			// 处理复选框被选中的情况
			SearchIndex = i;
			CString add_id;
			CString add_name;
			CString add_age;
			CString add_hireDate;
			CString add_phone;
			CString add_address;
			CString add_monthlySalary;
			CString add_tag;


			add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
			add_name = _manager->getEeVector()[i].GetName().c_str();
			add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
			add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
			add_phone = _manager->getEeVector()[i].GetPhone().c_str();
			add_address = _manager->getEeVector()[i].GetAddress().c_str();
			add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
			add_tag = _manager->getEeVector()[i].GetTag().c_str();

			CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_1); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_id);
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_2); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_name);
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_3); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_age);
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_4); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_hireDate);
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_5); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_phone);
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_6); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_address);
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_8); // 获取Edit Control控件的指针
			pEdit->SetWindowText(add_tag);

		}
	}
	Management* to_get_a_employee = Management::getInstance();
		
		_Main_ShowList.EnsureVisible(SearchIndex, FALSE);
		//_Main_ShowList.SetItemState(nTargetRow, LVIS_SELECTED, LVIS_SELECTED);
		_Main_ShowList.SetCheck(SearchIndex, TRUE);

}


void CSalaryManageDlg::OnBnClickedAddEmployeeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	Employee newEmployee;
	// 弹出IDD_ADD_DIALOG对话框
	//DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ADD_DIALOG), 131, AddDialogProc);
	AddDialog ToAddDialog;
	ToAddDialog.DoModal();
	Management* to_get_a_employee = Management::getInstance();
	for (auto it:to_get_a_employee->getEeVector())
	{
		if (ToAddDialog._id_edit == it.GetId())
		{
			AfxMessageBox(_T("有重复的工号"));
			return;

		}
	}
	newEmployee.SetId(ToAddDialog._id_edit);
	newEmployee.SetName(CStringToString(ToAddDialog._name_edit));
	newEmployee.SetAge(ToAddDialog._age_edit);
	newEmployee.SetHireDate(CStringToString(ToAddDialog._hireDate_edit));
	newEmployee.SetPhone(CStringToString(ToAddDialog._phone_edit));
	newEmployee.SetAddress(CStringToString(ToAddDialog._address_edit));
	newEmployee.SetMonthlySalary(ToAddDialog._monthlySalary_edit);
	newEmployee.SetTag(CStringToString(ToAddDialog._tag_edit));

	_manager->AddEmployee(newEmployee);
	_Main_ShowList.DeleteAllItems();
	int last_row = 0;
	int i = 0;
	for (i = 0; i < _manager->getEeVector().size(); i++)
	{

		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;
		CString add_tag;


		add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
		add_name = _manager->getEeVector()[i].GetName().c_str();
		add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
		add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
		add_phone = _manager->getEeVector()[i].GetPhone().c_str();
		add_address = _manager->getEeVector()[i].GetAddress().c_str();
		add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
		add_tag = _manager->getEeVector()[i].GetTag().c_str();

		last_row = _Main_ShowList.GetItemCount();
		_Main_ShowList.InsertItem(last_row, add_id);
		_Main_ShowList.SetItemText(last_row, 1, add_name);
		_Main_ShowList.SetItemText(last_row, 2, add_age);
		_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
		_Main_ShowList.SetItemText(last_row, 4, add_phone);
		_Main_ShowList.SetItemText(last_row, 5, add_address);
		_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
		_Main_ShowList.SetItemText(last_row, 7, add_tag);

	}
	UpdateData();
}


void CSalaryManageDlg::OnBnClickedDeleteEmployeeButton()
{
	// TODO: 在此添加控件通知处理程序代码

	/*int index = -1;
	if ((index = _Main_ShowList.GetNextItem(index, LVNI_SELECTED)) != -1)
	{
		CString a;
		a = to_string(index).c_str();
		DeleteEmployeeDIg ToDeleteEmployeeDIg;
		ToDeleteEmployeeDIg._delete_employee_id = index;
		ToDeleteEmployeeDIg.DoModal();
		//重新加载list
		OnBnClickedShowButton();
		// 找到一个选定项，返回其索引
		return;
	}
	else {
		AfxMessageBox(_T("请选定一个对象"));
	}
*/
	DeleteEmployeeDIg ToDeleteEmployeeDIg;
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = nItemCount-1; i > -1; i--)
	{
		if (_Main_ShowList.GetCheck(i))
		{
			CString a;
			a = to_string(i).c_str();
			
			ToDeleteEmployeeDIg._delete_employee_id = i;
			
			//重新加载list
			Management* to_delete_a_employee = Management::getInstance();
			to_delete_a_employee->getEeVector().erase
			(
				to_delete_a_employee->getEeVector().begin() + ToDeleteEmployeeDIg._delete_employee_id
			);
			
			// 找到一个选定项，返回其索引
		}
	}
	_Main_ShowList.DeleteAllItems();
	int last_row = 0;
	for (int i = 0; i < _manager->getEeVector().size(); i++)
	{

		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;
		CString add_tag;


		add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
		add_name = _manager->getEeVector()[i].GetName().c_str();
		add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
		add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
		add_phone = _manager->getEeVector()[i].GetPhone().c_str();
		add_address = _manager->getEeVector()[i].GetAddress().c_str();
		add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
		add_tag = _manager->getEeVector()[i].GetTag().c_str();

		last_row = _Main_ShowList.GetItemCount();
		_Main_ShowList.InsertItem(last_row, add_id);
		_Main_ShowList.SetItemText(last_row, 1, add_name);
		_Main_ShowList.SetItemText(last_row, 2, add_age);
		_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
		_Main_ShowList.SetItemText(last_row, 4, add_phone);
		_Main_ShowList.SetItemText(last_row, 5, add_address);
		_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
		_Main_ShowList.SetItemText(last_row, 7, add_tag);

	}
	UpdateData();
}


void CSalaryManageDlg::OnBnClickedSearchEmployeeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	SearchEmployeeDig ToSearchEmployeeDig;
	ToSearchEmployeeDig.DoModal();
	_Main_ShowList.DeleteAllItems();
	int last_row = 0;
	int i = 0;
	for (i = 0; i < _manager->getEeVector().size(); i++)
	{

		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;
		CString add_tag;


		add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
		add_name = _manager->getEeVector()[i].GetName().c_str();
		add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
		add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
		add_phone = _manager->getEeVector()[i].GetPhone().c_str();
		add_address = _manager->getEeVector()[i].GetAddress().c_str();
		add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
		add_tag = _manager->getEeVector()[i].GetTag().c_str();

		last_row = _Main_ShowList.GetItemCount();
		_Main_ShowList.InsertItem(last_row, add_id);
		_Main_ShowList.SetItemText(last_row, 1, add_name);
		_Main_ShowList.SetItemText(last_row, 2, add_age);
		_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
		_Main_ShowList.SetItemText(last_row, 4, add_phone);
		_Main_ShowList.SetItemText(last_row, 5, add_address);
		_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
		_Main_ShowList.SetItemText(last_row, 7, add_tag);

	}
	Management* to_get_a_employee = Management::getInstance();
	if (to_get_a_employee->SearchEmployeeId(ToSearchEmployeeDig._id_edit))
	{
		int nTargetRow = to_get_a_employee->SeaGetEmployeeRow(ToSearchEmployeeDig._id_edit);
		_Main_ShowList.EnsureVisible(nTargetRow, FALSE);
		//_Main_ShowList.SetItemState(nTargetRow, LVIS_SELECTED, LVIS_SELECTED);
		_Main_ShowList.SetCheck(nTargetRow, TRUE);
	}
	UpdateData();
	
}


void CSalaryManageDlg::OnBnClickedSaveFileButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//_manager->getEeVector()

	SaveDig ToSaveDig;
	ToSaveDig.DoModal();
	/*CString GPntTmpFName;
	CString GPntFName;
	//
	LPCTSTR lpszFilters;//它指明可供选择的文件类型和相应的扩展名
	lpszFilters = _T("点(*.pnt)|*.pnt||"); //文件类型说明和扩展名间用 | 分隔，同种类型文件的扩展名间可以用; 分割，每种文件类型间用 | 分隔，末尾用 || 指明
	CFileDialog dlg(false, _T("pnt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilters);//为FALSE则显示保存对话文件对话框,指定默认的文件扩展名， ,文件风格
	int nPos = GPntTmpFName.ReverseFind(_T('\\'));//返回此CString对象中与要求的字符匹配的最后一个字符的索引；如果没有找到需要的字符则返回-1
	CString folderAdd = GPntTmpFName.Left(nPos);// 返回字符串nPos前的字符串
	dlg.m_ofn.lpstrInitialDir = folderAdd;
	if (dlg.DoModal() == IDOK) {
		GPntFName = dlg.GetPathName();

	}
	*/
}


void CSalaryManageDlg::OnBnClickedReadButton()
{
	// TODO: 在此添加控件通知处理程序代码
	ReadFileDig ToReadFileDig;
	ToReadFileDig.DoModal();
	/*CString GPntTmpFName;
	CString GPntFName;
	LPCTSTR lpszFilters;//它指明可供选择的文件类型和相应的扩展名
	lpszFilters = _T("点(*.pnt)|*.pnt||"); //文件类型说明和扩展名间用 | 分隔，同种类型文件的扩展名间可以用; 分割，每种文件类型间用 | 分隔，末尾用 || 指明
	CFileDialog dlg(false, _T("pnt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilters);//为FALSE则显示保存对话文件对话框,指定默认的文件扩展名， ,文件风格
	int nPos = GPntTmpFName.ReverseFind(_T('\\'));//返回此CString对象中与要求的字符匹配的最后一个字符的索引；如果没有找到需要的字符则返回-1
	CString folderAdd = GPntTmpFName.Left(nPos);// 返回字符串nPos前的字符串
	dlg.m_ofn.lpstrInitialDir = folderAdd;
	if (dlg.DoModal() == IDOK) {
		GPntFName = dlg.GetPathName();

	}*/
	_Main_ShowList.DeleteAllItems();
	int last_row = 0;
	for (int i = 0; i < _manager->getEeVector().size(); i++)
	{

		CString add_id;
		CString add_name;
		CString add_age;
		CString add_hireDate;
		CString add_phone;
		CString add_address;
		CString add_monthlySalary;
		CString add_tag;


		add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
		add_name = _manager->getEeVector()[i].GetName().c_str();
		add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
		add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
		add_phone = _manager->getEeVector()[i].GetPhone().c_str();
		add_address = _manager->getEeVector()[i].GetAddress().c_str();
		add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
		add_tag = _manager->getEeVector()[i].GetTag().c_str();

		last_row = _Main_ShowList.GetItemCount();
		_Main_ShowList.InsertItem(last_row, add_id);
		_Main_ShowList.SetItemText(last_row, 1, add_name);
		_Main_ShowList.SetItemText(last_row, 2, add_age);
		_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
		_Main_ShowList.SetItemText(last_row, 4, add_phone);
		_Main_ShowList.SetItemText(last_row, 5, add_address);
		_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
		_Main_ShowList.SetItemText(last_row, 7, add_tag);

	}
	UpdateData();
}


void CSalaryManageDlg::OnBnClickedShowSalaryButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = -1;
	/*if ((index = _Main_ShowList.GetNextItem(index, LVNI_SELECTED)) != -1)
	{*/
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = nItemCount - 1; i > -1; i--)
	{
		if (_Main_ShowList.GetCheck(i))
		{
			CString a;
			a = to_string(i).c_str();
			ShowSalary ToShowSalary;
			ToShowSalary._employee_id = i;
			ToShowSalary.DoModal();
			_Main_ShowList.DeleteAllItems();
			int last_row = 0;
			int i = 0;
			for (i = 0; i < _manager->getEeVector().size(); i++)
			{

				CString add_id;
				CString add_name;
				CString add_age;
				CString add_hireDate;
				CString add_phone;
				CString add_address;
				CString add_monthlySalary;
				CString add_tag;


				add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
				add_name = _manager->getEeVector()[i].GetName().c_str();
				add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
				add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
				add_phone = _manager->getEeVector()[i].GetPhone().c_str();
				add_address = _manager->getEeVector()[i].GetAddress().c_str();
				add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
				add_tag = _manager->getEeVector()[i].GetTag().c_str();

				last_row = _Main_ShowList.GetItemCount();
				_Main_ShowList.InsertItem(last_row, add_id);
				_Main_ShowList.SetItemText(last_row, 1, add_name);
				_Main_ShowList.SetItemText(last_row, 2, add_age);
				_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
				_Main_ShowList.SetItemText(last_row, 4, add_phone);
				_Main_ShowList.SetItemText(last_row, 5, add_address);
				_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
				_Main_ShowList.SetItemText(last_row, 7, add_tag);

			}
			UpdateData();


		}
		else
		{
			//AfxMessageBox(_T("请选定一个对象"));
		}
	}
	
}


void CSalaryManageDlg::OnBnClickedSelectAllButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = 0; i < nItemCount; i++)
	{
		_Main_ShowList.SetCheck(i, TRUE);
	}
}


void CSalaryManageDlg::OnEnChangeEditMain1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	/*
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = 0; i < nItemCount; i++)
	{
		if (_Main_ShowList.GetCheck(i))
		{
			Management* to_get_a_employee = Management::getInstance();
			CString strData;
			strData = to_string(_manager->getEeVector()[i].GetId()).c_str(); // 获取选中行的数据
			CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_1); // 获取CEdit控件的指针
			pEdit->SetWindowText(strData); // 实时更新CEdit控件中的数据

			// 处理复选框被选中的情况
		}
	}
	*/
	
		


}


void CSalaryManageDlg::OnEnChangeEditMain7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSalaryManageDlg::OnEnChangeEditMain8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSalaryManageDlg::OnBnClickedChangeInfButton()
{
	
	// TODO: 在此添加控件通知处理程序代码
	Management* to_get_a_employee = Management::getInstance();
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = nItemCount - 1; i > -1; i--)
	{
		if (_Main_ShowList.GetCheck(i))
		{
			// 处理复选框被选中的情况
			CString add_id;
			CString add_name;
			CString add_age;
			CString add_hireDate;
			CString add_phone;
			CString add_address;
			CString add_monthlySalary;
			CString add_tag;

			
			/*add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
			add_name = _manager->getEeVector()[i].GetName().c_str();
			add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
			add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
			add_phone = _manager->getEeVector()[i].GetPhone().c_str();
			add_address = _manager->getEeVector()[i].GetAddress().c_str();
			add_monthlySalary = to_string(_manager->getEeVector()[i].GetYearlySalary()).c_str();
			add_tag = _manager->getEeVector()[i].GetAddress().c_str();*/

			CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_1); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_id);
			_manager->getEeVector()[i].SetId(_ttoi64(add_id));
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_2); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_name);
			_manager->getEeVector()[i].SetName(CStringToString(add_name));
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_3); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_age);
			_manager->getEeVector()[i].SetAge(_ttoi(add_age));
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_4); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_hireDate);
			_manager->getEeVector()[i].SetHireDate(CStringToString(add_hireDate));
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_5); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_phone);
			_manager->getEeVector()[i].SetPhone(CStringToString(add_phone));
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_6); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_address);
			_manager->getEeVector()[i].SetAddress(CStringToString(add_address));
			pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN_8); // 获取Edit Control控件的指针
			pEdit->GetWindowText(add_tag);
			_manager->getEeVector()[i].SetTag(CStringToString(add_tag));
			
			_Main_ShowList.DeleteAllItems();
			int last_row = 0;
			for (int i = 0; i < _manager->getEeVector().size(); i++)
			{

				CString add_id;
				CString add_name;
				CString add_age;
				CString add_hireDate;
				CString add_phone;
				CString add_address;
				CString add_monthlySalary;
				CString add_tag;


				add_id = to_string(_manager->getEeVector()[i].GetId()).c_str();
				add_name = _manager->getEeVector()[i].GetName().c_str();
				add_age = to_string(_manager->getEeVector()[i].GetAge()).c_str();
				add_hireDate = _manager->getEeVector()[i].GetHireDate().c_str();
				add_phone = _manager->getEeVector()[i].GetPhone().c_str();
				add_address = _manager->getEeVector()[i].GetAddress().c_str();
				add_monthlySalary = to_string(_manager->getEeVector()[i].GetDirtyYearlySalary()).c_str();
				add_tag = _manager->getEeVector()[i].GetTag().c_str();

				last_row = _Main_ShowList.GetItemCount();
				_Main_ShowList.InsertItem(last_row, add_id);
				_Main_ShowList.SetItemText(last_row, 1, add_name);
				_Main_ShowList.SetItemText(last_row, 2, add_age);
				_Main_ShowList.SetItemText(last_row, 3, add_hireDate);
				_Main_ShowList.SetItemText(last_row, 4, add_phone);
				_Main_ShowList.SetItemText(last_row, 5, add_address);
				_Main_ShowList.SetItemText(last_row, 6, add_monthlySalary);
				_Main_ShowList.SetItemText(last_row, 7, add_tag);

			}
			UpdateData();
			_Main_ShowList.EnsureVisible(SearchIndex, FALSE);
			//_Main_ShowList.SetItemState(nTargetRow, LVIS_SELECTED, LVIS_SELECTED);
			_Main_ShowList.SetCheck(SearchIndex, TRUE);
			return;

		}
	}

	
}


void CSalaryManageDlg::OnBnClickedCancelSelallButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int nItemCount = _Main_ShowList.GetItemCount();
	for (int i = 0; i < nItemCount; i++)
	{
		_Main_ShowList.SetCheck(i, FALSE);
	}	
}


void CSalaryManageDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedChangeInfButton();
	//CDialogEx::OnOK();
}
