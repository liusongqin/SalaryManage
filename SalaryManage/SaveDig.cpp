// SaveDig.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "SaveDig.h"
#include <string>
#include<fstream>
#include "Management.h"
#include<iomanip>

using namespace std;
/*std::string CStringToString(const CString& cstr)
{
	CT2CA pszConvertedAnsiString(cstr);
	std::string str(pszConvertedAnsiString);
	return str;
}*/

ostream& operator << (ostream& os, Employee & ob)
{
	os << setw(16) << ob.GetId() 
		<< setw(16) << ob.GetName() 
		<< setw(16) << ob.GetAge() 
		<< setw(16) << ob.GetHireDate() 
		<< setw(16) << ob.GetPhone()
		<< setw(16) << ob.GetAddress() 
		<< setw(16) << ob.GetDirtyYearlySalary()
		<<setw(16)<<ob.GetTag()
		//<< setw(16) << ob.GetCMonthlySalary().
		<< endl;
	return os;
}


// SaveDig 对话框

IMPLEMENT_DYNAMIC(SaveDig, CDialogEx)

SaveDig::SaveDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAVE_DIALOG, pParent)
	, filename(_T("D:/study/fstreamTest/example.txt"))
{

}

SaveDig::~SaveDig()
{
}

void SaveDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SAVE_EDIT, m_edit);
}


BEGIN_MESSAGE_MAP(SaveDig, CDialogEx)
	ON_BN_CLICKED(IDOK, &SaveDig::OnBnClickedOk)
	ON_EN_CHANGE(IDC_SAVE_EDIT, &SaveDig::OnEnChangeSaveEdit)
	ON_BN_CLICKED(IDC_SAVE_PATH_BUTTON, &SaveDig::OnBnClickedSavePathButton)
END_MESSAGE_MAP()


// SaveDig 消息处理程序


void SaveDig::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CT2CA pszConvertedAnsiString(filename);
	string str(pszConvertedAnsiString);
	string StrFileName = str;
	ofstream outFile(StrFileName);
	Management* to_get_a_employee = Management::getInstance();
	outFile 
		<< setw(16) << "工号" 
		<< setw(16) << "姓名" 
		<< setw(16) << "年龄" 
		<< setw(16) << "入职日期" 
		<< setw(16) << "电话" 
		<< setw(16) << "住址" 
		<< setw(16) << "年工资数据" 
		<< setw(16) << "特殊员工职位"<<endl;
	for (int i = 0; i < to_get_a_employee->getEeVector().size(); i++) {
		outFile << to_get_a_employee->getEeVector()[i] << endl;
	}
	outFile.close();


}


void SaveDig::OnEnChangeSaveEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void SaveDig::OnBnClickedSavePathButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(FALSE);

	// 设置文件选择对话框的标题和初始目录
	dlg.m_ofn.lpstrTitle = _T("保存文件");
	dlg.m_ofn.lpstrInitialDir = _T("C:\\");

	dlg.m_ofn.lpstrFilter = _T("文本文件|*.txt|所有文件|*.*||");
	dlg.m_ofn.lpstrDefExt = _T("txt");
//	dlg.m_ofn.lpstrFile = _T("");
//	dlg.m_ofn.lpstrFile = _T("newfile.txt");
	// 显示文件选择对话框
	if (dlg.DoModal() == IDOK)
	{
		// 获取用户选择的文件路径
		CString filePath = dlg.GetPathName();

		filename = filePath;
		m_edit.SetWindowTextW(filename);

		// TODO: 在这里可以对文件路径进行相应的操作
	}

}
