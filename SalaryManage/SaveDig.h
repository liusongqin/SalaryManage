#pragma once
#include "afxdialogex.h"


// SaveDig 对话框

class SaveDig : public CDialogEx
{
	DECLARE_DYNAMIC(SaveDig)

public:
	SaveDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SaveDig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAVE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString filename;
	CEdit m_edit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeSaveEdit();
	afx_msg void OnBnClickedSavePathButton();
};
