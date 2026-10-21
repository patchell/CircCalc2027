#pragma once

class CCapacitiveReactance : public CCalculation
{
	CCapacitor m_C;		// value in pico farads of the capacitor
	CFrequency m_F;		// frequency in Hz
	CXc m_Xc;	// Reactance in ohms
	CResistor m_R;		// Series Resistor in ohms
	CTimeConstant m_TC;	// Time constant in seconds
	CRiseTime m_RiseTime;	// rise time in seconds
	CFrequency m_Fc;	// cutoff frequency in Hz
	//--------------------------------
public:
	CCapacitiveReactance();
	virtual ~CCapacitiveReactance();
	bool Calculate();
	bool CalculateC();
	bool CalculateF();
	bool CalculateXc();
	bool CalculateR();
	bool CalculateTC();
	bool CalculateRt();
	bool CalculateFc();
	//--------------------------------
	static double CalculateReactance(double C, double F);
	static double CalculateCapacitance(double Xc, double F);
	static double CalculateFrequency(double Xc, double C);
	static double CalculateResistor(double Fc, double C);
	static double CalculateTimeConstant(double R, double C);
	static double CalculateRiseTime(double TC);
	static double CalculateFc(double TC);
	//--------------------------------
	double Get_C_InFarads() const { return m_C.GetValue(); }	//convert pF to Farads
	double Get_C_InPicoFarads() const { return m_C.GetValueInPicoFarads(); }
	double Get_F() const { return m_F.GetValue(); }
	double Get_Xc() const { return m_Xc.GetValue(); }
	double Get_R() const { return m_R.GetValue(); }
	double Get_TC() const { return m_TC.GetValue(); }
	double Get_RiseTime() const { return m_RiseTime.GetValue(); }
	double Get_Fc() const { return m_Fc.GetValue(); }
	//--------------------------------
	void Set_C_InFarads(double C){ m_C.SetValueInFarads(C); }
	void Set_C_InPicoFarads(double PicoFarads) { m_C.SetValueInPicoFarads(PicoFarads); }
	void Set_Frequency(double F){ m_F.SetValue(F); }
	void Set_Reactance(double Xc){ m_Xc.SetValue(Xc); }
	void Set_Resistor(double R){ m_R.SetValue(R); }
	void Set_TimeConstant(double TC){ m_TC.SetValue(TC); }
	void Set_RiseTime(double RiseTime){ m_RiseTime.SetValue(RiseTime); }
	void SetFc(double CutoffFreq){ m_Fc.SetValue(CutoffFreq); }
	//--------------------------------
	void Clr_C(){ m_C.Clr(); }
	void Clr_F(){ m_F.Clr(); }
	void Clr_Xc(){ m_Xc.Clr(); }
	void Clr_R(){ m_R.Clr(); }
	void Clr_TC(){ m_TC.Clr(); }
	void Clr_RiseTime(){ m_RiseTime.Clr(); }
	void Clr_Fc(){ m_Fc.Clr(); }
	//--------------------------------
	char* GetCapacitanceString(CString& cS );
	char* GetFrequencyString(CString& fS );
	char* GetXcString(CString& xS );
	char* GetResistorString(CString& rS );
	char* GetTimeConstantString(CString& tcS );
	char* GetRiseTimeString(CString& rtS );
	char* GetCutoffFreqString(CString& cfS );
};
