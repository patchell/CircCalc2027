#pragma once


// CDlgSuperHeterodynMixer dialog

class CDlgSuperHeterodynMixer : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSuperHeterodynMixer)
	CEditCapacitor m_Edit_C1_Max;
	CEditCapacitor m_Edit_C1_Min;
	//    CEditParam m_Edit_C2_Max;
	//    CEdit m_Edit_C2_Max;
	CEditCapacitor m_Edit_C2_Max;
	CEditCapacitor m_Edit_C2_Min;
	CEditFrequency m_Edit_Tank_HighFrequency;
	CEditFrequency m_Edit_IF_Frequency;
	CEditInductor m_Edit_AntennaInductor;
	CEditInductor m_Edit_LocalOscilatorInductor;
	CEditCapacitor m_Edit_AntennaPadCapacitor;
	CEditCapacitor	 m_Edit_LocalOscillatorPad;
	CEditDouble m_Edit_MaxError;
	CEditFrequency m_Edit_RangeLowFreq;

	CPlot m_Static_ErrorPlot;

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
  };
