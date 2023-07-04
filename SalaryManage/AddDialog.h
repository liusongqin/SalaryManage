#pragma once
#include "afxdialogex.h"


// AddDialog 对话框

class AddDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AddDialog)

public:
	AddDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	long long _id_edit;
	CString _name_edit;
	CString _hireDate_edit;
	int _age_edit;
	CString _phone_edit;
	CString _address_edit;
	double _monthlySalary_edit;
	CString _tag_edit;
	afx_msg void OnEnChangeTagEdit();
};
