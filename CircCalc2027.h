
// CircCalc2027.h : main header file for the CircCalc2027 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif


// CCircCalcApp:
// See CircCalc2027.cpp for the implementation of this class
//

class CCircCalcApp : public CWinAppEx
{
	FILE* pConsol;
	inline static double m_Pi = 4.0 * atan(1.0);
public:
	BOOL  m_bHiColorIcons;

public:
	CCircCalcApp() noexcept;
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//--------------------------------
	bool HasConsol() const { return pConsol != NULL; }
	double RadiansToFrequency(double w);
	double FrequencyToRadians(double F);
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCircCalcApp theApp;
extern double Radians(double F);
extern double Frequency(double w);
