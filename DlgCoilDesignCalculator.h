#pragma once
#include <Windows.h>
#include <afx.h>
#include <afxdialogex.h>
#include <afxwin.h>
#include "CoilCalculator.h"
#include "EditInches.h"
#include "EditInductor.h"
#include "EditTurns.h"
#include "EditTurnsPerInch.h"


// CDlgCoilDesignCalculator dialog

class CDlgCoilDesignCalculator : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCoilDesignCalculator)
	inline static double WireDiameter[] = {
		.0682,
		.0545,
		.0437,
		.0351,
		.0281,
		.0227,
		.0182,
		.0147,
		.0119,
		.0098,
		.0078
	};

	CCoilCalculator m_CoilCalculator;

	CButton m_Check_MultiLayerCoil;		// Multi-layer coil emable checkbox

	CEditInches m_Edit_Diameter1;
	CEditInches m_Edit_Radius_1;
	CEditInches m_Edit_Radius_2;
	CEditInches m_Edit_WireDiameter;
	CEditInductor m_Edit_Inductance;
	CEditInches m_Edit_CoilLength;
	CEditTurns m_Edit_Turns;
	CEditTurnsPerInch m_Edit_TurnsPerInch;

	CComboBox m_Combo_WireDiameter;

public:
	CDlgCoilDesignCalculator(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgCoilDesignCalculator();
	void UpdateControls();
	void HideRadius2Controls(bool bHide);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COIL_DESIGN_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
     afx_msg void OnClickedButtonCoilRadius2Clr();
    afx_msg void OnClickedButtonCoilcalcCoillengthClr();
    afx_msg void OnClickedButtonCoilcalcInductanceClr();
    afx_msg void OnClickedButtonCoilcalcRadius1Clr();
    afx_msg void OnClickedButtonCoilcalcTurnsClr();
    afx_msg void OnClickedButtonCoilcalcTurnsPerInchClr();
    afx_msg void OnClickedButtonDiameterClr();
    afx_msg void OnClickedCheckCoilcalcMultilayer();
     virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboWireSize();
	CStatic m_Static_Radius2_Text;
	CButton m_Button_Radius2Clr;
};
