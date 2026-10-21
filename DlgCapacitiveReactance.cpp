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
	ON_MESSAGE(WM_XC, &CDlgCapacitiveReactance::OnXc)
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
	CString s;

	m_CapacitiveReactance.GetCapacitanceString(s);
	m_Edit_Capacitor.SetWindowTextW(s);

	m_CapacitiveReactance.GetFrequencyString(s);
	m_Edit_Frequency.SetWindowTextW(s);

	m_CapacitiveReactance.GetXcString(s);
	m_Edit_CapacitiveReactance.SetWindowTextW(s);

	m_CapacitiveReactance.GetResistorString(s);
	m_Edit_Resistor.SetWindowTextW(s);

	m_CapacitiveReactance.GetTimeConstantString(s);
	m_Edit_TimeConstant.SetWindowTextW(s);

	m_CapacitiveReactance.GetRiseTimeString(s);
	m_Edit_RiseTime.SetWindowTextW(s);

	m_CapacitiveReactance.GetCutoffFreqString(s);
	m_Edit_CutOffFrequency.SetWindowTextW(s);
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

LRESULT CDlgCapacitiveReactance::OnXc(WPARAM wParam, LPARAM lParam)
{
	//------------------------------------------------
	// This message is sent from the Capacitive
	// Reactance class.
	// parameters:
	// wParam = N.A.
	// lParam = Edit Control ID
	//------------------------------------------------
	CString s;

	switch (lParam)
	{
	case IDC_EDIT_XC_CAP:
		m_CapacitiveReactance.Set_C_InPicoFarads(m_Edit_Capacitor.GetValue());
		break;
	case IDC_EDIT_XC_FREQ:
		m_CapacitiveReactance.Set_Frequency(m_Edit_Frequency.GetValue());
		break;
	case IDC_EDIT_XC:
		m_CapacitiveReactance.Set_Reactance(m_Edit_CapacitiveReactance.GetValue());
		break;
	case IDC_EDIT_XC_RESISTOR:
		m_CapacitiveReactance.Set_Resistor(m_Edit_Resistor.GetValue());
		break;
	case IDC_EDIT_XC_RISETIME:
		m_CapacitiveReactance.Set_RiseTime(m_Edit_RiseTime.GetValue());
		break;
	case IDC_EDIT_XC_TIMECONSTANT:
		m_CapacitiveReactance.Set_TimeConstant(m_Edit_TimeConstant.GetValue());
		break;
	case IDC_EDIT_XC_CUTTOFF_FREQUENCY:
		m_CapacitiveReactance.SetFc(m_Edit_CutOffFrequency.GetValue());
		break;
	}
	return LRESULT();
}

BOOL CDlgCapacitiveReactance::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	m_Edit_CapacitiveReactance.SetWMMessage(WM_XC);
	m_Edit_CapacitiveReactance.SetName("Xc");

	m_Edit_Capacitor.SetWMMessage(WM_XC);
	m_Edit_Capacitor.SetName("C");

	m_Edit_CutOffFrequency.SetWMMessage(WM_XC);
	m_Edit_CutOffFrequency.SetName("Fc");

	m_Edit_Frequency.SetWMMessage(WM_XC);
	m_Edit_Frequency.SetName("F");

	m_Edit_RiseTime.SetWMMessage(WM_XC);
	m_Edit_RiseTime.SetName("RiseTime");

	m_Edit_Resistor.SetWMMessage(WM_XC);
	m_Edit_Resistor.SetName("R");

	m_Edit_TimeConstant.SetWMMessage(WM_XC);
	m_Edit_TimeConstant.SetName("TC");


	return TRUE;  // return TRUE unless you set the focus to a control
}
