#pragma once

class CPlot : public CStatic
{
	CPen BlackPen;
	int MaxY;
	int nData;
	int bsize;
	int tail;
	int head;
	short * Data;
// Construction
public:
	CPlot();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlot)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawXAxis(CDC *dc);
	void Erase(void);
	int MaxX;
	double m_Scale_Offset;
	double m_Scale_Gain;
	void SetScale(int MaxY,int MinY);
	int ScaleY(int nPy);
	void InitPlot(int buffersize=0);
	void AddPoint(int x, short y);
	virtual ~CPlot();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPlot)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

