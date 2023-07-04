
// SalaryManageDlg.h: 头文件
//

#pragma once
#include "Management.h"


// CSalaryManageDlg 对话框
class CSalaryManageDlg : public CDialogEx
{
// 构造
public:
	CSalaryManageDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SALARYMANAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl _Main_ShowList;
	//CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_SHOW_LIST);
	CEdit EditMain1;
	CEdit m_editCtrl;
	afx_msg void OnBnClickedAddButton();
	Management* _manager;
	afx_msg void OnBnClickedShowButton();
	afx_msg void OnBnClickedAddEmployeeButton();
	afx_msg void OnBnClickedDeleteEmployeeButton();
	afx_msg void OnBnClickedSearchEmployeeButton();
	afx_msg void OnBnClickedSaveFileButton();
	afx_msg void OnBnClickedReadButton();
	afx_msg void OnBnClickedShowSalaryButton();

	afx_msg void OnBnClickedSelectAllButton();
	afx_msg void OnEnChangeEditMain1();
	afx_msg void OnEnChangeEditMain7();
	afx_msg void OnEnChangeEditMain8();
	afx_msg void OnBnClickedChangeInfButton();
	afx_msg void OnBnClickedCancelSelallButton();
	afx_msg void OnBnClickedOk();
};
