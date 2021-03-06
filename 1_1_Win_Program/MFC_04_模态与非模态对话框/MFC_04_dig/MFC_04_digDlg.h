
// MFC_04_digDlg.h: 头文件
//

#pragma once
#include "CLogin.h"
#include "CShowMsgDlg.h"


// CMFC04digDlg 对话框
class CMFC04digDlg : public CDialogEx
{
// 构造
public:
	CMFC04digDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_04_DIG_DIALOG };
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

	//模态对话框
	CLogin m_dlg;

	//非模态对话框
	CShowMsgDlg m_ShowMsgDlg;
	BOOL m_bCreated;
public:
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonNonmod();
};
