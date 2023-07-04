// ReadFileDig.cpp: 实现文件
//

#include "pch.h"
#include "SalaryManage.h"
#include "afxdialogex.h"
#include "ReadFileDig.h"
#include<fstream>
#include"Employee.h"
#include<string>
#include <iostream>
#include <vector>
#include "Management.h"
using namespace std;

/*istream& operator>>(istream& is, Employee& ob)
{
	is >> ob.set() >> ob.GetName() >> ob.GetAge() >> ob.GetHireDate() >> ob.GetPhone()
		>> ob.GetAddress() >> ob.GetMonthlySalary() << endl;
	return is;
}*/

// ReadFileDig 对话框

IMPLEMENT_DYNAMIC(ReadFileDig, CDialogEx)

ReadFileDig::ReadFileDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_READ_DIALOG, pParent)
	, filename(_T("D:/study/fstreamTest/example.txt"))
{

}

ReadFileDig::~ReadFileDig()
{
}

void ReadFileDig::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_READ_FILE_EDIT, m_edit);
}


BEGIN_MESSAGE_MAP(ReadFileDig, CDialogEx)
	ON_BN_CLICKED(IDOK, &ReadFileDig::OnBnClickedOk)
    ON_EN_CHANGE(IDC_READ_FILE_EDIT, &ReadFileDig::OnEnChangeReadFileEdit)
    ON_BN_CLICKED(IDC_READ_PATH, &ReadFileDig::OnBnClickedReadPath)
END_MESSAGE_MAP()


// ReadFileDig 消息处理程序


void ReadFileDig::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData();
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }
    Management* to_get_a_employee = Management::getInstance();
    vector<Employee>& EmployeeRef = to_get_a_employee->getEeVector();
    EmployeeRef.clear(); // 清空原有学生数据
    string Name_id;
    string Name_name;
    string Name_age;
    string Name_hireDate;
    string Name_phone;
    string Name_address;
    string Name_monthlySalary;
    string Name_tag;
    file >> Name_id
        >> Name_name
        >> Name_age 
        >> Name_hireDate 
        >> Name_phone 
        >> Name_address 
        >> Name_monthlySalary
        >> Name_tag;
    while (file.good()) {
        int m_id;
        string m_name;
        int m_age;
        string m_hireDate;
        string m_phone;
        string m_address;
        double m_monthlySalary;
        string m_tag;
        file >> m_id 
            >> m_name 
            >> m_age 
            >> m_hireDate
            >> m_phone
            >> m_address
            >> m_monthlySalary
            >> m_tag;
        if (m_name.empty()) 
        { // 如果已读到文件末尾，则退出循环
            break;
        }
        Employee epEmployee(m_id, m_name, m_age, m_hireDate, m_phone, m_address, m_monthlySalary, m_tag);
        EmployeeRef.push_back(epEmployee);
    }
    file.close();

}


void ReadFileDig::OnEnChangeReadFileEdit()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
    UpdateData();
}


void ReadFileDig::OnBnClickedReadPath()
{
    // TODO: 在此添加控件通知处理程序代码
    // 声明一个CFileDialog对象
    CFileDialog dlg(TRUE);

    // 设置文件选择对话框的标题和初始目录
    dlg.m_ofn.lpstrTitle = _T("打开文件");
    dlg.m_ofn.lpstrInitialDir = _T("C:\\");


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
