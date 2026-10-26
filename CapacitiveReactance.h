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
	double Get_C(CValue::ValueUnits Units)  { return m_C.GetValue(Units); }	//convert pF to Farads
	double Get_F(CValue::ValueUnits Units)  { return m_F.GetValue(Units); }
	double Get_Xc(CValue::ValueUnits Units)  { return m_Xc.GetValue(Units); }
	double Get_R(CValue::ValueUnits Units)  { return m_R.GetValue(Units); }
	double Get_TC(CValue::ValueUnits Units)  { return m_TC.GetValue(Units); }
	double Get_RiseTime(CValue::ValueUnits Units)  { return m_RiseTime.GetValue(Units); }
	double Get_Fc(CValue::ValueUnits Units)  { return m_Fc.GetValue(Units); }
	//---------- Get Value Objects ----------------------
	CCapacitor* Get_C_Value() { return &m_C; }
	CFrequency* Get_F_Value() { return &m_F; }
	CXc* Get_Xc_Value() { return &m_Xc; }
	CResistor* Get_R_Value() { return &m_R; }
	CTimeConstant* Get_TC_Value() { return &m_TC; }
	CRiseTime* Get_RiseTime_Value() { return &m_RiseTime; }
	CFrequency* Get_Fc_Value() { return &m_Fc; }
	//--------------------------------
	void Set_C(double C, CValue::ValueUnits Units){ m_C.SetValue(C, Units); }
	void Set_Frequency(double F, CValue::ValueUnits Units){ m_F.SetValue(F, Units); }
	void Set_Reactance(double Xc, CValue::ValueUnits Units){ m_Xc.SetValue(Xc, Units); }
	void Set_Resistor(double R, CValue::ValueUnits Units){ m_R.SetValue(R, Units); }
	void Set_TimeConstant(double TC, CValue::ValueUnits Units){ m_TC.SetValue(TC, Units); }
	void Set_RiseTime(double RiseTime, CValue::ValueUnits Units){ m_RiseTime.SetValue(RiseTime, Units); }
	void SetFc(double CutoffFreq, CValue::ValueUnits Units){ m_Fc.SetValue(CutoffFreq, Units); }
	//--------------------------------
	void Clr_C(){ m_C.Clr(); }
	void Clr_F(){ m_F.Clr(); }
	void Clr_Xc(){ m_Xc.Clr(); }
	void Clr_R(){ m_R.Clr(); }
	void Clr_TC(){ m_TC.Clr(); }
	void Clr_RiseTime(){ m_RiseTime.Clr(); }
	void Clr_Fc(){ m_Fc.Clr(); }
	//--------------------------------
	char* GetCapacitanceString(CString& cS, CValue::ValueUnits Units );
	char* GetFrequencyString(CString& fS, CValue::ValueUnits Units );
	char* GetXcString(CString& xS, CValue::ValueUnits Units );
	char* GetResistorString(CString& rS, CValue::ValueUnits Units );
	char* GetTimeConstantString(CString& tcS, CValue::ValueUnits Units );
	char* GetRiseTimeString(CString& rtS, CValue::ValueUnits Units );
	char* GetCutoffFreqString(CString& cfS, CValue::ValueUnits Units );
	//----------------------------------------------------------------------
	// Debugging Functions
	//----------------------------------------------------------------------
	void PrintValues();
};
