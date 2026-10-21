#pragma once


// CDlgCapacitiveReactance dialog

class CDlgCapacitiveReactance : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCapacitiveReactance)

	CCapacitiveReactance m_CapacitiveReactance;
	CEditParam m_Edit_Capacitor;
	CEditParam m_Edit_Resistor;
	CEditParam m_Edit_RiseTime;
	CEditParam m_Edit_CutOffFrequency;
	CEditParam m_Edit_Frequency;
	CEditParam m_Edit_TimeConstant;
	CEditParam m_Edit_CapacitiveReactance;
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
	afx_msg LRESULT OnXc(WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL OnInitDialog();
};
