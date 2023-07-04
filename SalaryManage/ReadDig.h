#pragma once
#include "afxdialogex.h"


// ReadDig 对话框

class ReadDig : public CDialogEx
{
	DECLARE_DYNAMIC(ReadDig)

public:
	ReadDig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ReadDig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
