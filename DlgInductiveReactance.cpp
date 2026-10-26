// DlgInductiveReactance.cpp : implementation file
//

#include "pch.h"


// CDlgInductiveReactance dialog

IMPLEMENT_DYNAMIC(CDlgInductiveReactance, CDialogEx)

CDlgInductiveReactance::CDlgInductiveReactance(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INDUCTIVE_REACTANCE, pParent)
{

}

CDlgInductiveReactance::~CDlgInductiveReactance()
{
}

void CDlgInductiveReactance::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_XL, m_Edit_Reactance);
    DDX_Control(pDX, IDC_EDIT_XL_F, m_Edit_Frequency);
    DDX_Control(pDX, IDC_EDIT_XL_FC, m_Edit_CutOffFrequency);
    DDX_Control(pDX, IDC_EDIT_XL_L, m_Edit_Inductance);
    DDX_Control(pDX, IDC_EDIT_XL_R, m_Edit_Resistance);
    DDX_Control(pDX, IDC_EDIT_XL_TIME_CONSTANT, m_Edit_TimeConstant);
    DDX_Control(pDX, IDC_EDIT_XL_RISE_TIME, m_Edit_RiseTime);
}

bool CDlgInductiveReactance::CalculateXl()
{
	bool Flag = false;

	Flag = m_InductiveReactance.Calculate();
	if (Flag)
	{
		UpdateXlEditBoxes();
	}
	return Flag;
}

void CDlgInductiveReactance::UpdateXlEditBoxes()
{

	m_Edit_CutOffFrequency.UpdateValue();
	m_Edit_Frequency.UpdateValue();
	m_Edit_Inductance.UpdateValue();
	m_Edit_Resistance.UpdateValue();
	m_Edit_RiseTime.UpdateValue();
	m_Edit_TimeConstant.UpdateValue();
	m_Edit_Reactance.UpdateValue();
}


BEGIN_MESSAGE_MAP(CDlgInductiveReactance, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_XL_CLR, &CDlgInductiveReactance::OnClickedButtonXlClr)
	ON_BN_CLICKED(IDC_BUTTON_XL_CLR_FREQ, &CDlgInductiveReactance::OnClickedButtonXlClrFreq)
	ON_BN_CLICKED(IDC_BUTTON_XL_CLR_IND, &CDlgInductiveReactance::OnClickedButtonXlClrInd)
	ON_BN_CLICKED(IDC_BUTTON_XL_RISE_TIME_CLR, &CDlgInductiveReactance::OnClickedButtonXlRiseTimeClr)
	ON_BN_CLICKED(IDC_BUTTON_XL_TIME_CONSTANT_CLR, &CDlgInductiveReactance::OnClickedButtonXlTimeConstantClr)
	//---------------------------------------------------------------------------------------------------------
	ON_BN_CLICKED(IDC_BUTTON_CALC_XL, &CDlgInductiveReactance::OnClickedButtonCalcXl)
	//---------------------------------------------------------------------------------------------------------
	ON_BN_CLICKED(IDC_BUTTON_INDUCTIVE_REACTANCE_RESISTANCE_CLR, &CDlgInductiveReactance::OnClickedButtonInductiveReactanceResistanceClr)
	ON_BN_CLICKED(IDC_BUTTON_inductive_reactance_cutoff_clr, &CDlgInductiveReactance::OnClickedButtonInductiveReactanceCutoffClr)
END_MESSAGE_MAP()


// CDlgInductiveReactance message handlers

void CDlgInductiveReactance::OnClickedButtonXlClr()
{
	m_InductiveReactance.Clr_Xl();
	m_Edit_Reactance.SetWindowTextW(L"");
}

void CDlgInductiveReactance::OnClickedButtonXlClrFreq()
{
	m_InductiveReactance.Clr_F();
	m_Edit_Frequency.SetWindowTextW(L"");
}

void CDlgInductiveReactance::OnClickedButtonXlClrInd()
{
	m_InductiveReactance.Clr_L();
	m_Edit_Inductance.SetWindowTextW(L"");
}


void CDlgInductiveReactance::OnClickedButtonInductiveReactanceResistanceClr()
{
	m_InductiveReactance.Clr_R();
	m_Edit_Resistance.SetWindowTextW(L"");
}

void CDlgInductiveReactance::OnClickedButtonInductiveReactanceCutoffClr()
{
	m_InductiveReactance.Clr_Fc();
	m_Edit_CutOffFrequency.SetWindowTextW(L"");
}

void CDlgInductiveReactance::OnClickedButtonXlRiseTimeClr()
{
	m_InductiveReactance.Clr_Rt();
	m_Edit_RiseTime.SetWindowTextW(L"");
}

void CDlgInductiveReactance::OnClickedButtonXlTimeConstantClr()
{
	m_InductiveReactance.Clr_Tc();
	m_Edit_TimeConstant.SetWindowTextW(L"");
}


void CDlgInductiveReactance::OnClickedButtonCalcXl()
{
	CalculateXl();
}

BOOL CDlgInductiveReactance::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Edit_CutOffFrequency.SetName("Cutoff Frequency");
	m_Edit_CutOffFrequency.SetValue(m_InductiveReactance.Get_Fc_Value(), CValue::ValueUnits::HERTZ);

	m_Edit_Frequency.SetName("Frequency");
	m_Edit_Frequency.SetValue(m_InductiveReactance.Get_F_Value(), CValue::ValueUnits::HERTZ);

	m_Edit_Inductance.SetName("Inductance");
	m_Edit_Inductance.SetValue(m_InductiveReactance.Get_L_Value(), CValue::ValueUnits::MICROHENRYS);

	m_Edit_Resistance.SetName("Resistance");
	m_Edit_Resistance.SetValue(m_InductiveReactance.Get_R_Value(), CValue::ValueUnits::OHMS);

	m_Edit_RiseTime.SetName("Rise Time");
	m_Edit_RiseTime.SetValue(m_InductiveReactance.Get_Rt_Value(), CValue::ValueUnits::SECONDS);

	m_Edit_TimeConstant.SetName("Time Constant");
	m_Edit_TimeConstant.SetValue(m_InductiveReactance.Get_Tc_Value(), CValue::ValueUnits::SECONDS);

	return TRUE;  }
