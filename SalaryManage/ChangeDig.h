#pragma once
#include "afxdialogex.h"


// ChangeDig 对话框

class ChangeDig : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeDig)

public:
	ChangeDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangeDig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int _month_id;
	int _change_employee_id;
	double _baseSalary_edit;
	double _positionSalary_edit;
	double _senioritySalary_edit;
	double _allowance_edit;
	double _StatusAllowance_edit;
	double _subsidy_edit;
	double _houseSubsidy_edit;
	double _trafficAllowance_edit;
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnBnClickedOk();
};
