
// Shapes7Dlg.cpp : implementation file
//

#include "pch.h"
#include "pShapes.h"
#include "framework.h"
#include "Shapes7.h"
#include "Shapes7Dlg.h"
#include "afxdialogex.h"
#include <vector>
#include <string>
#include <sstream>



using namespace comsc;
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCalculateBtn();
	//afx_msg void OnCbnSelchangeShapeCombo();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CALCULATE_BTN, &CAboutDlg::OnBnClickedCalculateBtn)
	//ON_CBN_SELCHANGE(IDC_SHAPE_COMBO1, &CAboutDlg::OnCbnSelchangeShapeCombo)
END_MESSAGE_MAP()


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_SHAPE_COMBO1, &CShapes7Dlg::OnCbnSelchangeShapeCombo1)
	ON_BN_CLICKED(IDC_CALCULATE_BTN, &CShapes7Dlg::OnBnClickedCalculateBtn)
	
	ON_STN_CLICKED(IDC_PICTURE_CONTROL, &CShapes7Dlg::OnStnClickedPictureControl)
END_MESSAGE_MAP()



BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//combo box drop down
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_SHAPE_COMBO1);
	if (pComboBox != nullptr)	{
		
			pComboBox->InsertString(0, _T("Square"));
			pComboBox->InsertString(1, _T("Cube"));
			pComboBox->InsertString(2, _T("Rectangle"));
			pComboBox->InsertString(3, _T("Box"));
			pComboBox->InsertString(4, _T("Circle"));
			pComboBox->InsertString(5, _T("Cylinder"));
			pComboBox->InsertString(6, _T("Triangle"));
			pComboBox->InsertString(7, _T("Prism"));
			pComboBox->SetCurSel(-1); // Set the first item as selected by default
		}

		return TRUE;  
	}
		
	

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapes7Dlg::OnCbnSelchangeShapeCombo1() {
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_SHAPE_COMBO1);
	if (!pComboBox) return;

	int selectedIndex = pComboBox->GetCurSel();

	CWnd* pLengthEdit = GetDlgItem(IDC_LENGTH_EDIT);
	CWnd* pWidthEdit = GetDlgItem(IDC_WIDTH_EDIT);
	CWnd* pHeightEdit = GetDlgItem(IDC_HEIGHT_EDIT);
	CWnd* pRadiusEdit = GetDlgItem(IDC_RADIUS_EDIT);

	CWnd* pLengthLabel = GetDlgItem(IDC_LENGTH_LABEL);
	CWnd* pWidthLabel = GetDlgItem(IDC_WIDTH_LABEL);
	CWnd* pHeightLabel = GetDlgItem(IDC_HEIGHT_LABEL);
	CWnd* pRadiusLabel = GetDlgItem(IDC_RADIUS_LABEL);

	if (!pLengthEdit || !pWidthEdit || !pHeightEdit || !pRadiusEdit ||
		!pLengthLabel || !pWidthLabel || !pHeightLabel || !pRadiusLabel) return;

	switch (selectedIndex) {
	case 0: // Square
		pLengthLabel->SetWindowText(_T("Side:"));
		pLengthEdit->ShowWindow(SW_SHOW);
		pWidthEdit->ShowWindow(SW_HIDE);
		pHeightEdit->ShowWindow(SW_HIDE);
		pRadiusEdit->ShowWindow(SW_HIDE);
		break;
	case 1: // Cube
		pLengthLabel->SetWindowText(_T("Side:"));
		pLengthEdit->ShowWindow(SW_SHOW);
		pWidthEdit->ShowWindow(SW_HIDE);
		pHeightEdit->ShowWindow(SW_HIDE);
		pRadiusEdit->ShowWindow(SW_HIDE);
		break;
	case 2: // Rectangle
		pLengthLabel->SetWindowText(_T("Length:"));
		pWidthLabel->SetWindowText(_T("Width:"));
		pLengthEdit->ShowWindow(SW_SHOW);
		pWidthEdit->ShowWindow(SW_SHOW);
		pHeightEdit->ShowWindow(SW_HIDE);
		pRadiusEdit->ShowWindow(SW_HIDE);
		break;
	case 3: // Box
		pLengthLabel->SetWindowText(_T("Length:"));
		pWidthLabel->SetWindowText(_T("Width:"));
		pHeightLabel->SetWindowText(_T("Height:"));
		pLengthEdit->ShowWindow(SW_SHOW);
		pWidthEdit->ShowWindow(SW_SHOW);
		pHeightEdit->ShowWindow(SW_SHOW);
		pRadiusEdit->ShowWindow(SW_HIDE);
		break;
	case 4: // Circle
		pRadiusLabel->SetWindowText(_T("Radius:"));
		pLengthEdit->ShowWindow(SW_HIDE);
		pWidthEdit->ShowWindow(SW_HIDE);
		pHeightEdit->ShowWindow(SW_HIDE);
		pRadiusEdit->ShowWindow(SW_SHOW);
		break;
	case 5: // Cylinder
		pRadiusLabel->SetWindowText(_T("Radius:"));
		pHeightLabel->SetWindowText(_T("Height:"));
		pLengthEdit->ShowWindow(SW_HIDE);
		pWidthEdit->ShowWindow(SW_HIDE);
		pHeightEdit->ShowWindow(SW_SHOW);
		pRadiusEdit->ShowWindow(SW_SHOW);
		break;
	case 6: // Triangle
		pLengthLabel->SetWindowText(_T("Side:"));
		pLengthEdit->ShowWindow(SW_SHOW);
		pWidthEdit->ShowWindow(SW_HIDE);
		pHeightEdit->ShowWindow(SW_HIDE);
		pRadiusEdit->ShowWindow(SW_HIDE);
		break;
	case 7: // Prism
		pLengthLabel->SetWindowText(_T("Side:"));
		pHeightLabel->SetWindowText(_T("Height:"));
		pLengthEdit->ShowWindow(SW_SHOW);
		pWidthEdit->ShowWindow(SW_HIDE);
		pHeightEdit->ShowWindow(SW_SHOW);
		pRadiusEdit->ShowWindow(SW_HIDE);
		break;
	}
}





void CShapes7Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAboutDlg::OnBnClickedCalculateBtn()// DO NOT NEED 
{
	
}


// Inside CShapes7Dlg class in Shapes7Dlg.cpp



void CShapes7Dlg::OnBnClickedCalculateBtn()
{
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_SHAPE_COMBO1);
	int selectedIndex = pCombo->GetCurSel();

	CString strLength, strWidth, strHeight, strRadius;

	GetDlgItemText(IDC_LENGTH_EDIT, strLength);
	GetDlgItemText(IDC_WIDTH_EDIT, strWidth);
	GetDlgItemText(IDC_HEIGHT_EDIT, strHeight);
	GetDlgItemText(IDC_RADIUS_EDIT, strRadius);

	CEdit* results_Edit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_RESULTS_DISPLAY));
	ostringstream out;

	double length = _ttof(strLength);
	double width = _ttof(strWidth);
	double height = _ttof(strHeight);
	double radius = _ttof(strRadius);

	switch (selectedIndex) {
	case 0: { // Square
		vector<string> dimensions{ "", to_string(length) };
		SQUARE square(dimensions);
		square.output(out);
		break;
	}
	case 1: { // Cube
		vector<string> dimensions{ "", to_string(length) };
		CUBE cube(dimensions);
		cube.output(out);
		break;
	}
	case 2: { // Rectangle
		vector<string> dimensions{ "", to_string(length), to_string(width) };
		RECTANGLE rectangle(dimensions);
		rectangle.output(out);
		break;
	}
	case 3: { // Box
		vector<string> dimensions{ "", to_string(length), to_string(width), to_string(height) };
		BOX box(dimensions);
		box.output(out);
		break;
	}
	case 4: { // Circle
		vector<string> dimensions{ "", to_string(radius) };
		CIRCLE circle(dimensions);
		circle.output(out);
		break;
	}
	case 5: { // Cylinder
		vector<string> dimensions{ "", to_string(radius), to_string(height) };
		CYLINDER cylinder(dimensions);
		cylinder.output(out);
		break;
	}
	case 6: { // Triangle
		vector<string> dimensions{ "", to_string(length) };
		TRIANGLE triangle(dimensions);
		triangle.output(out);
		break;
	}
	case 7: { // Prism
		vector<string> dimensions{ "", to_string(length), to_string(height) };
		PRISM prism(dimensions);
		prism.output(out);
		break;
	}
	}

	if (results_Edit) {
		results_Edit->SetWindowText(CString(out.str().c_str()));
	}
	else {
		MessageBox(_T("Error accessing the results display."), _T("Error"), MB_ICONERROR);
	}
}


//
//void CAboutDlg::OnCbnSelchangeShapeCombo()
//{
//	
//}




void CShapes7Dlg::OnStnClickedPictureControl()
{
	// TODO: Add your control notification handler code here
}
