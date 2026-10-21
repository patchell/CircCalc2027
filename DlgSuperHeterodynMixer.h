#pragma once


// CDlgSuperHeterodynMixer dialog

class CDlgSuperHeterodynMixer : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSuperHeterodynMixer)

public:
	CDlgSuperHeterodynMixer(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgSuperHeterodynMixer();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SUPER_HETERODYNE_MIXER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonTankCalc();
    CEditParam m_Edit_C1_Max;
    CEditParam m_Edit_C1_Min;
//    CEditParam m_Edit_C2_Max;
//    CEdit m_Edit_C2_Max;
    CEditParam m_Edit_C2_Max;
    CEditParam m_Edit_C2_Min;
    CEditParam m_Edit_Tank_HighFrequency;
    CEditParam m_Edit_IF_Frequency;
    CEditParam m_Edit_AntennaInductor;
    CEditParam m_Edit_LocalOscilatorInductor;
    CEditParam m_Edit_AntennaPadCapacitor;
    CEditParam m_Edit_LocalOscillatorPad;
    CEditParam m_Edit_MaxError;
    CEditParam m_Edit_RangeLowFreq;
    CPlot m_Static_ErrorPlot;
};
