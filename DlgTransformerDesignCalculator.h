#pragma once


// CDlgTransformerDesignCalculator dialog

class CDlgTransformerDesignCalculator : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTransformerDesignCalculator)

public:
	CDlgTransformerDesignCalculator(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgTransformerDesignCalculator();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TRANSFORMER_DESIGN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
