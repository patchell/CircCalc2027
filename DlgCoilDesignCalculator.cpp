// DlgCoilDesignCalculator.cpp : implementation file
//

#include "pch.h"


// CDlgCoilDesignCalculator dialog

IMPLEMENT_DYNAMIC(CDlgCoilDesignCalculator, CDialogEx)

CDlgCoilDesignCalculator::CDlgCoilDesignCalculator(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COIL_DESIGN_CALCULATOR, pParent)
{

}

CDlgCoilDesignCalculator::~CDlgCoilDesignCalculator()
{
}

void CDlgCoilDesignCalculator::UpdateControls()
{
	m_Edit_Diameter1.UpdateValue();;
	m_Edit_Radius_1.UpdateValue();;
	m_Edit_Radius_2.UpdateValue();;
	m_Edit_CoilLength.UpdateValue();;
	m_Edit_Inductance.UpdateValue();;
	m_Edit_Turns.UpdateValue();;
	m_Edit_TurnsPerInch.UpdateValue();;
	m_Edit_WireDiameter.UpdateValue();;

	HideRadius2Controls(!m_CoilCalculator.Get_MultiLayer());
}

void CDlgCoilDesignCalculator::HideRadius2Controls(bool bHide)
{
	if (bHide)
	{
		m_Edit_Radius_2.ShowWindow(SW_HIDE);
		m_Static_Radius2_Text.ShowWindow(SW_HIDE);
		m_Button_Radius2Clr.ShowWindow(SW_HIDE);
	}
	else
	{
		m_Edit_Radius_2.ShowWindow(SW_SHOW);
		m_Static_Radius2_Text.ShowWindow(SW_SHOW);
		m_Button_Radius2Clr.ShowWindow(SW_SHOW);
	}
}

void CDlgCoilDesignCalculator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COIL_RADIUS_1, m_Edit_Radius_1);
	DDX_Control(pDX, IDC_EDIT_COIL_RADIUS_2, m_Edit_Radius_2);
	DDX_Control(pDX, IDC_EDIT_COILCALC_WIRE_DIAMETER, m_Edit_WireDiameter);
	DDX_Control(pDX, IDC_EDIT_COILCALC_INDUCTANCE, m_Edit_Inductance);
	DDX_Control(pDX, IDC_EDIT_COILCALC_LENGTH, m_Edit_CoilLength);
	DDX_Control(pDX, IDC_EDIT_COILCALC_TURNS, m_Edit_Turns);
	DDX_Control(pDX, IDC_EDIT_COILCALC_TURNS_PER_INCH, m_Edit_TurnsPerInch);
	DDX_Control(pDX, IDC_COMBO_WIRE_SIZE, m_Combo_WireDiameter);
	DDX_Control(pDX, IDC_CHECK_COILCALC_MULTILAYER, m_Check_MultiLayerCoil);
	DDX_Control(pDX, IDC_EDIT_DIAMETER_1, m_Edit_Diameter1);
	DDX_Control(pDX, IDC_STATIC_COIL_RADIUS_2, m_Static_Radius2_Text);
	DDX_Control(pDX, IDC_BUTTON_COIL_RADIUS_2_CLR, m_Button_Radius2Clr);
}


BEGIN_MESSAGE_MAP(CDlgCoilDesignCalculator, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_COIL_RADIUS_2_CLR, &CDlgCoilDesignCalculator::OnClickedButtonCoilRadius2Clr)
	ON_BN_CLICKED(IDC_BUTTON_COILCALC_COILLENGTH_CLR, &CDlgCoilDesignCalculator::OnClickedButtonCoilcalcCoillengthClr)
	ON_BN_CLICKED(IDC_BUTTON_COILCALC_INDUCTANCE_CLR, &CDlgCoilDesignCalculator::OnClickedButtonCoilcalcInductanceClr)
	ON_BN_CLICKED(IDC_BUTTON_COILCALC_RADIUS_1_CLR, &CDlgCoilDesignCalculator::OnClickedButtonCoilcalcRadius1Clr)
	ON_BN_CLICKED(IDC_BUTTON_COILCALC_TURNS_CLR, &CDlgCoilDesignCalculator::OnClickedButtonCoilcalcTurnsClr)
	ON_BN_CLICKED(IDC_BUTTON_COILCALC_TURNS_PER_INCH_CLR, &CDlgCoilDesignCalculator::OnClickedButtonCoilcalcTurnsPerInchClr)
	ON_BN_CLICKED(IDC_BUTTON_DIAMETER_CLR, &CDlgCoilDesignCalculator::OnClickedButtonDiameterClr)
	ON_BN_CLICKED(IDC_CHECK_COILCALC_MULTILAYER, &CDlgCoilDesignCalculator::OnClickedCheckCoilcalcMultilayer)
	//---------------------------------------------
	ON_CBN_SELCHANGE(IDC_COMBO_WIRE_SIZE, &CDlgCoilDesignCalculator::OnSelchangeComboWireSize)
END_MESSAGE_MAP()


// CDlgCoilDesignCalculator message handlers

void CDlgCoilDesignCalculator::OnClickedButtonCoilRadius2Clr()
{
	m_CoilCalculator.Clr_Radius_2();
	UpdateControls();
}

void CDlgCoilDesignCalculator::OnClickedButtonCoilcalcCoillengthClr()
{
	m_CoilCalculator.Clr_CoilLength();
	UpdateControls();
}

void CDlgCoilDesignCalculator::OnClickedButtonCoilcalcInductanceClr()
{
	m_CoilCalculator.Clr_Inductance();
	UpdateControls();
}

void CDlgCoilDesignCalculator::OnClickedButtonCoilcalcRadius1Clr()
{
	m_CoilCalculator.Clr_Radius_1();
	UpdateControls();
}

void CDlgCoilDesignCalculator::OnClickedButtonCoilcalcTurnsClr()
{
	m_CoilCalculator.Clr_Turns();
	UpdateControls();
}

void CDlgCoilDesignCalculator::OnClickedButtonCoilcalcTurnsPerInchClr()
{
	m_CoilCalculator.Clr_TurnsPerInch();
	UpdateControls();
}

void CDlgCoilDesignCalculator::OnClickedButtonDiameterClr()
{
	m_CoilCalculator.Clr_Diameter_1();
	UpdateControls();
}


void CDlgCoilDesignCalculator::OnClickedCheckCoilcalcMultilayer()
{
	if (m_Check_MultiLayerCoil.GetCheck() == BST_CHECKED)
	{
		m_CoilCalculator.Set_MultiLayer(true);
	}
	else
	{
		m_CoilCalculator.Set_MultiLayer(false);
	}
	HideRadius2Controls(!m_CoilCalculator.Get_MultiLayer());
}

BOOL CDlgCoilDesignCalculator::OnInitDialog()
{
	CString cS;

	CDialogEx::OnInitDialog();

	
	//-----------------------------------------------
	// Initialize the Wire Size Combo Box
	//-----------------------------------------------
	for (int i = 0; i < 11; ++i)
	{
		cS.Format(L"#%d AWG", i * 2 + 14);
		m_Combo_WireDiameter.InsertString(i, cS);
	}
	m_Combo_WireDiameter.SetCurSel(4);
	m_CoilCalculator.Set_WireDiameter(WireDiameter[4]);
	//-----------------------------------------------
	// Initialize Edit Box Values
	//-----------------------------------------------
	m_Edit_Diameter1.SetName("Diameter1");
	m_Edit_Diameter1.SetValue(m_CoilCalculator.Get_Diameter_1_Value(), CValue::ValueUnits::INCHES);
	
	m_Edit_Radius_1.SetName("Radius1");
	m_Edit_Radius_1.SetValue(m_CoilCalculator.Get_Radius_1_Value(), CValue::ValueUnits::INCHES);

	m_Edit_Radius_2.SetName("Radius2");
	m_Edit_Radius_2.SetValue(m_CoilCalculator.Get_Radius_2_Value(), CValue::ValueUnits::INCHES);
		
	m_Edit_CoilLength.SetName("CoilLength");
	m_Edit_CoilLength.SetValue(m_CoilCalculator.Get_CoilLength_Value(), CValue::ValueUnits::INCHES);
		
	m_Edit_Inductance.SetName("Inductance");
	m_Edit_Inductance.SetValue(m_CoilCalculator.Get_Inductance_Value(), CValue::ValueUnits::MICROHENRYS);

	m_Edit_Turns.SetName("Turns");
	m_Edit_Turns.SetValue(m_CoilCalculator.Get_Turns_Value(), CValue::ValueUnits::TURNS);

	m_Edit_TurnsPerInch.SetName("TurnsPerInch");
	m_Edit_TurnsPerInch.SetValue(m_CoilCalculator.Get_TurnPerInch_Value(), CValue::ValueUnits::TURNS_PER_INCH);

	m_Edit_WireDiameter.SetName("WireDiameter");
	m_Edit_WireDiameter.SetValue(m_CoilCalculator.Get_WireDiameter_Value(), CValue::ValueUnits::INCHES);

	UpdateControls();
	return TRUE;
}

void CDlgCoilDesignCalculator::OnSelchangeComboWireSize()
{
	int Selection = m_Combo_WireDiameter.GetCurSel();
	if (Selection >= 0 && Selection < 11)
	{
		m_CoilCalculator.Set_WireDiameter(WireDiameter[Selection]);
//		m_Edit_WireDiameter.SetValue(WireDiameter[Selection]);
	}
}

