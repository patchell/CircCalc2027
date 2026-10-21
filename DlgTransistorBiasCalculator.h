#pragma once


// CDlgTransistorBiasCalculator dialog

class CDlgTransistorBiasCalculator : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTransistorBiasCalculator)

public:
	CDlgTransistorBiasCalculator(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgTransistorBiasCalculator();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TRANSISTOR_BIAS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
