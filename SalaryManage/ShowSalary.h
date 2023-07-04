#pragma once
#include "afxdialogex.h"


// ShowSalary 对话框

class ShowSalary : public CDialogEx
{
	DECLARE_DYNAMIC(ShowSalary)

public:
	ShowSalary(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ShowSalary();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl _ShowSalaryList;
	int index = 0;
	int _employee_id;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedChangeSalaryButton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

};
