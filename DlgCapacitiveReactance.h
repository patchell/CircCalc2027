#pragma once


// CDlgCapacitiveReactance dialog

class CDlgCapacitiveReactance : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCapacitiveReactance)

	CCapacitiveReactance m_CapacitiveReactance;
	CEditCapacitor m_Edit_Capacitor;	// edit box for capacitor value in pico farads
	CEditResistor m_Edit_Resistor;		// edit box for series resistor value in ohms
	CEditSeconds m_Edit_RiseTime;		// edit box for rise time in seconds
	CEditFrequency m_Edit_CutOffFrequency;	// edit box for cut-off frequency in hertz
	CEditFrequency m_Edit_Frequency;	// edit box for frequency in hertz
	CEditSeconds m_Edit_TimeConstant;	// edit box for time constant in seconds
	CEditCapacitiveReactance m_Edit_CapacitiveReactance;	// edit box for capacitive reactance in ohms
public:
	CDlgCapacitiveReactance(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgCapacitiveReactance();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CAPACITIVE_REACTANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	bool CalculateXc();
	void UpdateXcEditBoxes();
	afx_msg void OnClickedButtonXcClrFreq();
	afx_msg void OnClickedButtonXcCutoffClr();
	afx_msg void OnClickedButtonXcRClr();
	afx_msg void OnClickedButtonXcClrCap();
	afx_msg void OnClickedButtonXcClr();
	afx_msg void OnClickedButtonXcRisetimeClr();
	afx_msg void OnClickedButtonXcTimeconstantClr();
	afx_msg void OnClickedButtonCalcXc();
public:
	virtual BOOL OnInitDialog();
};
