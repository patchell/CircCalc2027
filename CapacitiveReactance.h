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
	double Get_C_InFarads()  { return m_C.GetValue(CValue::ValueUnits::FARADS); }	//convert pF to Farads
	double Get_C_InPicoFarads()  { return m_C.GetValue(CValue::ValueUnits::PICO_FARADS); }
	double Get_F()  { return m_F.GetValue(CValue::ValueUnits::HERTZ); }
	double Get_Xc()  { return m_Xc.GetValue(CValue::ValueUnits::OHMS); }
	double Get_R()  { return m_R.GetValue(CValue::ValueUnits::OHMS); }
	double Get_TC()  { return m_TC.GetValue(CValue::ValueUnits::SECONDS); }
	double Get_RiseTime()  { return m_RiseTime.GetValue(CValue::ValueUnits::SECONDS); }
	double Get_Fc()  { return m_Fc.GetValue(CValue::ValueUnits::HERTZ); }
	//--------------------------------
	void Set_C_InFarads(double C){ m_C.SetValue(C, CValue::ValueUnits::FARADS); }
	void Set_C_InPicoFarads(double PicoFarads) { m_C.SetValue(PicoFarads, CValue::ValueUnits::PICO_FARADS); }
	void Set_Frequency(double F){ m_F.SetValue(F, CValue::ValueUnits::HERTZ); }
	void Set_Reactance(double Xc){ m_Xc.SetValue(Xc, CValue::ValueUnits::OHMS); }
	void Set_Resistor(double R){ m_R.SetValue(R, CValue::ValueUnits::OHMS); }
	void Set_TimeConstant(double TC){ m_TC.SetValue(TC, CValue::ValueUnits::SECONDS); }
	void Set_RiseTime(double RiseTime){ m_RiseTime.SetValue(RiseTime, CValue::ValueUnits::SECONDS); }
	void SetFc(double CutoffFreq){ m_Fc.SetValue(CutoffFreq, CValue::ValueUnits::HERTZ); }
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
