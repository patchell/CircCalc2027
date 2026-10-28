#pragma once

class CInductiveReactance : public CCalculation
{
	CInductor m_L;
	CFrequency m_F;
	CXl m_Xl;
	CResistor m_R;
	CFrequency m_Fc;
	CRiseTime m_Rt;
	CTimeConstant m_Tc;
public:
	CInductiveReactance();
	virtual ~CInductiveReactance();

	bool Calculate();	// master function to calculate the missing value
	bool CalculateR();
	bool CalculateFc();
	bool CalculateL();
	bool CalculateF();
	bool CalculateXl();
	bool CalculateRiseTime();
	bool CalculateTimeConstant();
	//--------------------------------
	static double CalculateReactance(double L, double F);
	static double CalculateInductance(double Xl, double F);
	static double CalculateFrequency(double Xl, double L);
	static double CalculateFc(double R, double L);
	static double CalculateR(double L, double Fc);
	static double CalculateRiseTime(double L, double R);
	static double CalculateTimeConstant(double L, double R);
	//--------------------------------
	double Get_L(CValue::ValueUnits VU = CValue::ValueUnits::HENRYS)  { return m_L.GetValue(VU); }	
	double Get_F(CValue::ValueUnits VU = CValue::ValueUnits::HERTZ)  { return m_F.GetValue(VU); }
	double Get_Xl(CValue::ValueUnits VU = CValue::ValueUnits::OHMS)  { return m_Xl.GetValue(VU); }
	double Get_R(CValue::ValueUnits VU = CValue::ValueUnits::OHMS)  { return m_R.GetValue(VU); }
	double Get_Fc(CValue::ValueUnits VU = CValue::ValueUnits::HERTZ)  { return m_Fc.GetValue(VU); }
	double Get_Rt(CValue::ValueUnits VU = CValue::ValueUnits::SECONDS)  { return m_Rt.GetValue(VU); }
	double Get_Tc(CValue::ValueUnits VU = CValue::ValueUnits::SECONDS)  { return m_Tc.GetValue(VU); }
	//--------- Get Value Objects ----------------------
	CInductor* Get_L_Value() { return &m_L; }
	CFrequency* Get_F_Value() { return &m_F; }
	CXl* Get_Xl_Value() { return &m_Xl; }
	CResistor* Get_R_Value() { return &m_R; }
	CFrequency* Get_Fc_Value() { return &m_Fc; }
	CRiseTime* Get_Rt_Value() { return &m_Rt; }
	CTimeConstant* Get_Tc_Value() { return &m_Tc; }
	//--------------------------------
	void Set_L(double Value,CValue::ValueUnits Units) { m_L.SetValue(Value, Units); }
	void Set_F(double F, CValue::ValueUnits Units) { m_F.SetValue(F, Units); }
	void Set_Xl(double Xl, CValue::ValueUnits Units) { m_Xl.SetValue(Xl, Units); }
	void Set_R(double R, CValue::ValueUnits Units) { m_R.SetValue(R, Units); }
	void Set_Fc(double Fc, CValue::ValueUnits Units) { m_Fc.SetValue(Fc, Units); }
	void Set_Rt(double Rt, CValue::ValueUnits Units) { m_Rt.SetValue(Rt, Units); }
	void Set_Tc(double Tc, CValue::ValueUnits Units) { m_Tc.SetValue(Tc, Units); }
	//--------------------------------
	bool Get_L_String(CString& cS, CValue::ValueUnits VU) { return m_L.GetString(cS, VU); }
	bool Get_F_String(CString& cS, CValue::ValueUnits VU) { return m_F.GetString(cS, VU); }
	bool Get_Xl_String(CString& cS, CValue::ValueUnits VU) { return m_Xl.GetString(cS, VU); }
	bool Get_R_String(CString& cS, CValue::ValueUnits VU) { return m_R.GetString(cS, VU); }
	bool Get_Fc_String(CString& cS, CValue::ValueUnits VU) { return m_Fc.GetString(cS, VU); }
	bool Get_Rt_String(CString& cS, CValue::ValueUnits VU) { return m_Rt.GetString(cS, VU); }
	bool Get_Tc_String(CString& cS, CValue::ValueUnits VU) { return m_Tc.GetString(cS, VU); }

	//--------------------------------
	void Clr_L() { m_L.Clr(); }
	void Clr_F() { m_F.Clr(); }
	void Clr_Xl() { m_Xl.Clr(); }
	void Clr_R() { m_R.Clr(); }
	void Clr_Fc() { m_Fc.Clr(); }
	void Clr_Rt() { m_Rt.Clr(); }
	void Clr_Tc() { m_Tc.Clr(); }
};

