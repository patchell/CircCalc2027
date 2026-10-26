#pragma once


// CDlgResonantLRC dialog

class CDlgResonantLRC : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgResonantLRC)
	CEditCapacitor m_Edit_Capacitor;			// Capacitor value
	CEditFrequency m_Edit_CenterFrequency;		// Center Frequency value
	CEditInductor m_Edit_Inductor;				// Inductor value
	CEditFrequency m_Edit_BandWidth;			// Bandwidth value
	CEditQFactor m_Edit_Q;					// Q factor value
	CEditResistor m_Edit_Resistor;				// Resistor value

public:
	CDlgResonantLRC(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgResonantLRC();
	void UpdateControls();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RESONANT_RLC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonClrInd();
    afx_msg void OnBnClickedButtonClrCap();
    afx_msg void OnBnClickedButtonResonanceClrResistance();
    afx_msg void OnBnClickedButtonResonanceClrQ();
    afx_msg void OnBnClickedButtonResonanceClrBw();
    afx_msg void OnBnClickedButtonClrFreq();
    afx_msg void OnBnClickedButtonResonantFreq();
	virtual BOOL OnInitDialog();
};
