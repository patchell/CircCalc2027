// DlgSuperHeterodynMixer.cpp : implementation file
//

#include "pch.h"


// CDlgSuperHeterodynMixer dialog

IMPLEMENT_DYNAMIC(CDlgSuperHeterodynMixer, CDialogEx)

CDlgSuperHeterodynMixer::CDlgSuperHeterodynMixer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SUPER_HETERODYNE_MIXER, pParent)
{

}

CDlgSuperHeterodynMixer::~CDlgSuperHeterodynMixer()
{
}

void CDlgSuperHeterodynMixer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TANK_C1_MAX, m_Edit_C1_Max);
	DDX_Control(pDX, IDC_EDIT_TANK_C1_MIN, m_Edit_C1_Min);
	//  DDX_Control(pDX, IDC_EDIT_TANK_C2_MAX, m_Edit_C2_Max);
	//  DDX_Control(pDX, IDC_EDIT_TANK_C2_MIN, m_Edit_C2_Max);
	DDX_Control(pDX, IDC_EDIT_TANK_C2_MAX, m_Edit_C2_Max);
	DDX_Control(pDX, IDC_EDIT_TANK_C2_MIN, m_Edit_C2_Min);
	DDX_Control(pDX, IDC_EDIT_TANK_HF, m_Edit_Tank_HighFrequency);
	DDX_Control(pDX, IDC_EDIT_TANK_IF, m_Edit_IF_Frequency);
	DDX_Control(pDX, IDC_EDIT_TANK_L_ANT, m_Edit_AntennaInductor);
	DDX_Control(pDX, IDC_EDIT_TANK_L_OSC, m_Edit_LocalOscilatorInductor);
	DDX_Control(pDX, IDC_EDIT_TANK_PAD_ANT, m_Edit_AntennaPadCapacitor);
	DDX_Control(pDX, IDC_EDIT_TANK_PAD_OSC, m_Edit_LocalOscillatorPad);
	DDX_Control(pDX, IDC_EDIT_TRACKING_MAX_ERROR, m_Edit_MaxError);
	DDX_Control(pDX, IDC_EDIT_TANK_LF, m_Edit_RangeLowFreq);
	DDX_Control(pDX, IDC_STATIC_TRACKING, m_Static_ErrorPlot);
}


BEGIN_MESSAGE_MAP(CDlgSuperHeterodynMixer, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_TANK_CALC, &CDlgSuperHeterodynMixer::OnBnClickedButtonTankCalc)
END_MESSAGE_MAP()


// CDlgSuperHeterodynMixer message handlers

void CDlgSuperHeterodynMixer::OnBnClickedButtonTankCalc()
{
    // TODO: Add your control notification handler code here
}
