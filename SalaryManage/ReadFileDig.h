#pragma once
#include "afxdialogex.h"


// ReadFileDig 对话框

class ReadFileDig : public CDialogEx
{
	DECLARE_DYNAMIC(ReadFileDig)

public:
	ReadFileDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ReadFileDig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_READ_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString filename;
	CEdit m_edit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeReadFileEdit();
	afx_msg void OnBnClickedReadPath();
};
