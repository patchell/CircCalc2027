#pragma once


// CDlgVoltageDivider dialog

class CDlgVoltageDivider : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgVoltageDivider)

public:
	CDlgVoltageDivider(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgVoltageDivider();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_VOLTAGE_DIVICER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
