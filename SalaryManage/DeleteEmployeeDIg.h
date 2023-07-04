#pragma once
#include "afxdialogex.h"


// DeleteEmployeeDIg 对话框

class DeleteEmployeeDIg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteEmployeeDIg)

public:
	DeleteEmployeeDIg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DeleteEmployeeDIg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_EMPLOYEE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int _delete_employee_id;
	afx_msg void OnEnChangeDeleteEmployeeEdit();
	afx_msg void OnBnClickedOk();
};
