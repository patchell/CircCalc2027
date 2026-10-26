#pragma once
#include <Windows.h>


// CDlgInductiveReactance dialog

class CDlgInductiveReactance : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInductiveReactance)
	CInductiveReactance m_InductiveReactance;
	// Dialog controls
	CEditInductiveReactance m_Edit_Reactance;	// Inductive Reactance (Xl) in Ohms
	CEditFrequency m_Edit_Frequency;			// Applied Frequency (F) in Hertz
	CEditFrequency m_Edit_CutOffFrequency;		// Cutoff Frequency (Fc) in Hertz
	CEditInductor m_Edit_Inductance;			// Inductance (L) in Henrys
	CEditResistor m_Edit_Resistance;			// Resistance (R) in Ohms
	CEditSeconds m_Edit_TimeConstant;			// Time Constant (τ) in Seconds
	CEditSeconds m_Edit_RiseTime;				// Rise Time (Tr) in Seconds

public:
	CDlgInductiveReactance(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgInductiveReactance();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INDUCTIVE_REACTANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	bool CalculateXl();
	void UpdateXlEditBoxes();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnClickedButtonXlClr();
    afx_msg void OnClickedButtonXlClrFreq();
    afx_msg void OnClickedButtonXlClrInd();
    afx_msg void OnClickedButtonXlRiseTimeClr();
    afx_msg void OnClickedButtonXlTimeConstantClr();
    afx_msg void OnClickedButtonCalcXl();
	afx_msg void OnClickedButtonInductiveReactanceResistanceClr();
	afx_msg void OnClickedButtonInductiveReactanceCutoffClr();
public:
	virtual BOOL OnInitDialog();
};
