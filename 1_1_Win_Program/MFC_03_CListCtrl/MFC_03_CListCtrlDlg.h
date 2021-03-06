
// MFC_03_CListCtrlDlg.h: 头文件
//

#pragma once


// CMFC03CListCtrlDlg 对话框
class CMFC03CListCtrlDlg : public CDialogEx
{
// 构造
public:
	CMFC03CListCtrlDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_03_CLISTCTRL_DIALOG };
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


	int m_istat;
	CString m_szSite;
	CString m_szProduct;
	CString m_szValue;
	UINT m_iValue;

public:
	static DWORD m_SortColum;
	static BOOL m_bAs;
	static int CALLBACK MyListCompar(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	CListCtrl m_listCtrl;
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
