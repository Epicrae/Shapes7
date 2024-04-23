
// Shapes7Dlg.h : header file
//

#pragma once


// CShapes7Dlg dialog
class CShapes7Dlg : public CDialogEx
{
// Construction
public:
	CShapes7Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPES7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeShapeCombo1();
	afx_msg void OnEnChangeEdit1();
	void OnBnClickedCalculateBtn();
	//afx_msg void OnEnChangeResultsDisplay();
	//afx_msg void OnEnChangeEdit6();
	//afx_msg void OnCbnSelchangeTestCombo();
	afx_msg void OnStnClickedPictureControl();
};
