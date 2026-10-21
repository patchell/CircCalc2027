#pragma once


// CDlgResonantLRC dialog

class CDlgResonantLRC : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgResonantLRC)

public:
	CDlgResonantLRC(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgResonantLRC();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RESONANT_RLC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    CEditParam m_Edit_Capacitor;
    CEditParam m_Edit_CenterFrequency;
    CEditParam m_Edit_Inductor;
    CEditParam m_Edit_BandWidth;
    CEditParam m_Edit_Q;
    CEditParam m_Edit_Resistor;
    afx_msg void OnBnClickedButtonClrInd();
    afx_msg void OnBnClickedButtonClrCap();
    afx_msg void OnBnClickedButtonResonanceClrResistance();
    afx_msg void OnBnClickedButtonResonanceClrQ();
    afx_msg void OnBnClickedButtonResonanceClrBw();
    afx_msg void OnBnClickedButtonClrFreq();
    afx_msg void OnBnClickedButtonResonantFreq();
};
