// DlgResonantLRC.cpp : implementation file
//

#include "pch.h"


// CDlgResonantLRC dialog

IMPLEMENT_DYNAMIC(CDlgResonantLRC, CDialogEx)

CDlgResonantLRC::CDlgResonantLRC(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_RESONANT_RLC, pParent)
{

}

CDlgResonantLRC::~CDlgResonantLRC()
{
}

void CDlgResonantLRC::UpdateControls()
{
	m_Edit_Capacitor.UpdateText();
	m_Edit_CenterFrequency.UpdateText();
	m_Edit_Inductor.UpdateText();
	m_Edit_BandWidth.UpdateText();
	m_Edit_Q.UpdateText();
	m_Edit_Resistor.UpdateText();
}

void CDlgResonantLRC::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_RES_CAP, m_Edit_Capacitor);
    DDX_Control(pDX, IDC_EDIT_RES_FREQ, m_Edit_CenterFrequency);
    DDX_Control(pDX, IDC_EDIT_RES_IND, m_Edit_Inductor);
    DDX_Control(pDX, IDC_EDIT_RESONANCE_BW, m_Edit_BandWidth);
    DDX_Control(pDX, IDC_EDIT_RESONANCE_Q, m_Edit_Q);
    DDX_Control(pDX, IDC_EDIT_RESONANCE_RESOSTANCE, m_Edit_Resistor);
}


BEGIN_MESSAGE_MAP(CDlgResonantLRC, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_CLR_IND, &CDlgResonantLRC::OnBnClickedButtonClrInd)
	ON_BN_CLICKED(IDC_BUTTON_CLR_CAP, &CDlgResonantLRC::OnBnClickedButtonClrCap)
	ON_BN_CLICKED(IDC_BUTTON_RESONANCE_CLR_RESISTANCE, &CDlgResonantLRC::OnBnClickedButtonResonanceClrResistance)
	ON_BN_CLICKED(IDC_BUTTON_RESONANCE_CLR_Q, &CDlgResonantLRC::OnBnClickedButtonResonanceClrQ)
	ON_BN_CLICKED(IDC_BUTTON_RESONANCE_CLR_BW, &CDlgResonantLRC::OnBnClickedButtonResonanceClrBw)
	ON_BN_CLICKED(IDC_BUTTON_CLR_FREQ, &CDlgResonantLRC::OnBnClickedButtonClrFreq)
	ON_BN_CLICKED(IDC_BUTTON_RESONANT_FREQ, &CDlgResonantLRC::OnBnClickedButtonResonantFreq)
END_MESSAGE_MAP()


// CDlgResonantLRC message handlers

void CDlgResonantLRC::OnBnClickedButtonClrInd()
{
    // TODO: Add your control notification handler code here
}

void CDlgResonantLRC::OnBnClickedButtonClrCap()
{
	// TODO: Add your control notification handler code here
}

void CDlgResonantLRC::OnBnClickedButtonResonanceClrResistance()
{
	// TODO: Add your control notification handler code here
}

void CDlgResonantLRC::OnBnClickedButtonResonanceClrQ()
{
	// TODO: Add your control notification handler code here
}

void CDlgResonantLRC::OnBnClickedButtonResonanceClrBw()
{
	// TODO: Add your control notification handler code here
}

void CDlgResonantLRC::OnBnClickedButtonClrFreq()
{
	// TODO: Add your control notification handler code here
}

void CDlgResonantLRC::OnBnClickedButtonResonantFreq()
{
	// TODO: Add your control notification handler code here
}

BOOL CDlgResonantLRC::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
}
