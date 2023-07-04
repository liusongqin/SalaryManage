#pragma once
#include "afxdialogex.h"


// SearchEmployeeDig 对话框

class SearchEmployeeDig : public CDialogEx
{
	DECLARE_DYNAMIC(SearchEmployeeDig)

public:
	SearchEmployeeDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SearchEmployeeDig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH_EMPLOYEE_DIALOG };
#endif

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl _Search_Emp_List;
	int _id_edit;
	int index = 0;
	int index2 = 0;
	
	afx_msg void OnLvnItemchangedSearchResultList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeSearchEmployeeEdit();
	afx_msg void OnBnClickedSearchEmployeeButton();
	afx_msg void OnBnClickedToChangeButton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
