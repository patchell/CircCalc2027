// DlgCapacitiveReactance.cpp : implementation file
//

#include "pch.h"


// CDlgCapacitiveReactance dialog

IMPLEMENT_DYNAMIC(CDlgCapacitiveReactance, CDialogEx)

CDlgCapacitiveReactance::CDlgCapacitiveReactance(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CAPACITIVE_REACTANCE, pParent)
{

}

CDlgCapacitiveReactance::~CDlgCapacitiveReactance()
{
}

void CDlgCapacitiveReactance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_XC_CAP, m_Edit_Capacitor);
	DDX_Control(pDX, IDC_EDIT_XC_RESISTOR, m_Edit_Resistor);
	DDX_Control(pDX, IDC_EDIT_XC_RISETIME, m_Edit_RiseTime);
	DDX_Control(pDX, IDC_EDIT_XC_CUTTOFF_FREQUENCY, m_Edit_CutOffFrequency);
	DDX_Control(pDX, IDC_EDIT_XC_FREQ, m_Edit_Frequency);
	DDX_Control(pDX, IDC_EDIT_XC_TIMECONSTANT, m_Edit_TimeConstant);
	DDX_Control(pDX, IDC_EDIT_XC, m_Edit_CapacitiveReactance);
}


BEGIN_MESSAGE_MAP(CDlgCapacitiveReactance, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_XC_CLR_FREQ, &CDlgCapacitiveReactance::OnClickedButtonXcClrFreq)
	ON_BN_CLICKED(IDC_BUTTON_XC_CUTOFF_CLR, &CDlgCapacitiveReactance::OnClickedButtonXcCutoffClr)
	ON_BN_CLICKED(IDC_BUTTON_XC_R_CLR, &CDlgCapacitiveReactance::OnClickedButtonXcRClr)
	ON_BN_CLICKED(IDC_BUTTON_XC_CLR_CAP, &CDlgCapacitiveReactance::OnClickedButtonXcClrCap)
	ON_BN_CLICKED(IDC_BUTTON_XC_CLR, &CDlgCapacitiveReactance::OnClickedButtonXcClr)
	ON_BN_CLICKED(IDC_BUTTON_XC_RISETIME_CLR, &CDlgCapacitiveReactance::OnClickedButtonXcRisetimeClr)
	ON_BN_CLICKED(IDC_BUTTON_XC_TIMECONSTANT_CLR, &CDlgCapacitiveReactance::OnClickedButtonXcTimeconstantClr)
	ON_BN_CLICKED(IDC_BUTTON_CALC_XC, &CDlgCapacitiveReactance::OnClickedButtonCalcXc)
END_MESSAGE_MAP()


// CDlgCapacitiveReactance message handlers

bool CDlgCapacitiveReactance::CalculateXc()
{
	bool Flag = false;

	Flag = m_CapacitiveReactance.Calculate();
	if (Flag)
	{
		UpdateXcEditBoxes();
	}
	return Flag;
}

void CDlgCapacitiveReactance::UpdateXcEditBoxes()
{
	m_CapacitiveReactance.PrintValues();	// Debugging

	m_Edit_Capacitor.UpdateValue();
	m_Edit_Frequency.UpdateValue();
	m_Edit_CapacitiveReactance.UpdateValue();
	m_Edit_Resistor.UpdateValue();
	m_Edit_TimeConstant.UpdateValue();
	m_Edit_RiseTime.UpdateValue();
	m_Edit_CutOffFrequency.UpdateValue();
}

void CDlgCapacitiveReactance::OnClickedButtonXcClrFreq()
{
	m_Edit_Frequency.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_F();
}

void CDlgCapacitiveReactance::OnClickedButtonXcCutoffClr()
{
	m_Edit_CutOffFrequency.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_Fc();
}

void CDlgCapacitiveReactance::OnClickedButtonXcRClr()
{
	m_Edit_Resistor.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_R();
}

void CDlgCapacitiveReactance::OnClickedButtonXcClrCap()
{
	m_Edit_Capacitor.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_C();
}

void CDlgCapacitiveReactance::OnClickedButtonXcClr()
{
	m_Edit_CapacitiveReactance.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_Xc();
}

void CDlgCapacitiveReactance::OnClickedButtonXcRisetimeClr()
{
	m_Edit_RiseTime.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_RiseTime();
}

void CDlgCapacitiveReactance::OnClickedButtonXcTimeconstantClr()
{
	m_Edit_TimeConstant.SetWindowTextW(L"");
	m_CapacitiveReactance.Clr_TC();
}


void CDlgCapacitiveReactance::OnClickedButtonCalcXc()
{
	if (CalculateXc() == false)
	{
		MessageBox(L"Xc:Too Many Blank Parameters", L"ERROR", MB_ICONHAND);
	}
}

BOOL CDlgCapacitiveReactance::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	m_Edit_CapacitiveReactance.SetName("Xc");
	m_Edit_CapacitiveReactance.SetValue(m_CapacitiveReactance.Get_Xc_Value(), CValue::ValueUnits::PICO_FARADS);

	m_Edit_Capacitor.SetName("C");
	m_Edit_Capacitor.SetValue(m_CapacitiveReactance.Get_C_Value(), CValue::ValueUnits::PICO_FARADS);

	m_Edit_CutOffFrequency.SetName("Fc");
	m_Edit_CutOffFrequency.SetValue(m_CapacitiveReactance.Get_Fc_Value(), CValue::ValueUnits::HERTZ);

	m_Edit_Frequency.SetName("F");
	m_Edit_Frequency.SetValue(m_CapacitiveReactance.Get_F_Value(), CValue::ValueUnits::HERTZ);

	m_Edit_RiseTime.SetName("RiseTime");
	m_Edit_RiseTime.SetValue(m_CapacitiveReactance.Get_RiseTime_Value(), CValue::ValueUnits::SECONDS);

	m_Edit_Resistor.SetName("R");
	m_Edit_Resistor.SetValue(m_CapacitiveReactance.Get_R_Value(), CValue::ValueUnits::OHMS);

	m_Edit_TimeConstant.SetName("TC");
	m_Edit_TimeConstant.SetValue(m_CapacitiveReactance.Get_TC_Value(), CValue::ValueUnits::SECONDS);

	return TRUE;  // return TRUE unless you set the focus to a control
}
