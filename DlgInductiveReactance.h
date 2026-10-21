#pragma once


// CDlgInductiveReactance dialog

class CDlgInductiveReactance : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInductiveReactance)
	CInductiveReactance m_InductiveReactance;
	// Dialog controls
	CEditParam m_Edit_Reactance;
	CEditParam m_Edit_Frequency;
	CEditParam m_Edit_CutOffFrequency;
	CEditParam m_Edit_Inductance;
	CEditParam m_Edit_Resistance;
	CEditParam m_Edit_TimeConstant;
	CEditParam m_Edit_RiseTime;

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
//    afx_msg void OnCheckCoilcalcMultilayer();
    afx_msg void OnClickedButtonXlRiseTimeClr();
    afx_msg void OnClickedButtonXlTimeConstantClr();
    afx_msg void OnClickedButtonCalcXl();
	afx_msg void OnClickedButtonInductiveReactanceResistanceClr();
	afx_msg void OnClickedButtonInductiveReactanceCutoffClr();
	afx_msg LRESULT OnXl(WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL OnInitDialog();
};
