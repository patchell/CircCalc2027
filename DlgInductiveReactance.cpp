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
	CString cS;

	m_InductiveReactance.Get_Fc_String(cS);
	m_Edit_CutOffFrequency.SetWindowTextW(cS);

	m_InductiveReactance.Get_F_String(cS);
	m_Edit_Frequency.SetWindowTextW(cS);

	m_InductiveReactance.Get_L_String(cS);
	m_Edit_Inductance.SetWindowTextW(cS);

	m_InductiveReactance.Get_R_String(cS);
	m_Edit_Resistance.SetWindowTextW(cS);

	m_InductiveReactance.Get_Rt_String(cS);
	m_Edit_RiseTime.SetWindowTextW(cS);

	m_InductiveReactance.Get_Tc_String(cS);
	m_Edit_TimeConstant.SetWindowTextW(cS);

	m_InductiveReactance.Get_Xl_String(cS);
	m_Edit_Reactance.SetWindowTextW(cS);
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
	ON_MESSAGE(WM_XL, &CDlgInductiveReactance::OnXl)
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

LRESULT CDlgInductiveReactance::OnXl(WPARAM wParam, LPARAM lParam)
{
	CString m_s;

	switch (lParam)
	{
	case IDC_EDIT_XL_FC:
		m_InductiveReactance.Set_Fc(m_Edit_CutOffFrequency.GetValue());
		break;
	case IDC_EDIT_XL_F:
		m_InductiveReactance.Set_F(m_Edit_Frequency.GetValue());
		break;
	case IDC_EDIT_XL_L:
		m_InductiveReactance.Set_L_InMicroHenrys(m_Edit_Inductance.GetValue());
		break;
	case IDC_EDIT_XL_R:
		m_InductiveReactance.Set_R(m_Edit_Resistance.GetValue());
		break;
	case IDC_EDIT_XL_RISE_TIME:
		m_InductiveReactance.Set_Rt(m_Edit_RiseTime.GetValue());
		break;
	case IDC_EDIT_XL_TIME_CONSTANT:
		m_InductiveReactance.Set_Tc(m_Edit_TimeConstant.GetValue());
		break;
	case IDC_EDIT_XL:
		m_InductiveReactance.Set_Xl(m_Edit_Inductance.GetValue());
		break;
	}
	return LRESULT();
}

BOOL CDlgInductiveReactance::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Edit_CutOffFrequency.SetName("Cutoff Frequency");
	m_Edit_CutOffFrequency.SetWMMessage(WM_XL);

	m_Edit_Frequency.SetName("Frequency");
	m_Edit_Frequency.SetWMMessage(WM_XL);

	m_Edit_Inductance.SetName("Inductance");
	m_Edit_Inductance.SetWMMessage(WM_XL);

	m_Edit_Resistance.SetName("Resistance");
	m_Edit_Resistance.SetWMMessage(WM_XL);

	m_Edit_RiseTime.SetName("Rise Time");
	m_Edit_RiseTime.SetWMMessage(WM_XL);

	m_Edit_TimeConstant.SetName("Time Constant");
	m_Edit_TimeConstant.SetWMMessage(WM_XL);

	return TRUE;  }
