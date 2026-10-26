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
	double Get_L_InHenrys()  { return m_L.GetValue(CValue::ValueUnits::HENRYS); }	
	double Get_L_InMicroHenrys() { return m_L.GetValue(CValue::ValueUnits::MICROHENRYS); }
	double Get_F()  { return m_F.GetValue(CValue::ValueUnits::HERTZ); }
	double Get_Xl()  { return m_Xl.GetValue(CValue::ValueUnits::OHMS); }
	double Get_R()  { return m_R.GetValue(CValue::ValueUnits::OHMS); }
	double Get_Fc()  { return m_Fc.GetValue(CValue::ValueUnits::HERTZ); }
	double Get_Rt()  { return m_Rt.GetValue(CValue::ValueUnits::SECONDS); }
	double Get_Tc()  { return m_Tc.GetValue(CValue::ValueUnits::SECONDS); }
	//--------- Get Value Objects ----------------------
	CInductor* Get_L_Value() { return &m_L; }
	CFrequency* Get_F_Value() { return &m_F; }
	CXl* Get_Xl_Value() { return &m_Xl; }
	CResistor* Get_R_Value() { return &m_R; }
	CFrequency* Get_Fc_Value() { return &m_Fc; }
	CRiseTime* Get_Rt_Value() { return &m_Rt; }
	CTimeConstant* Get_Tc_Value() { return &m_Tc; }
	//--------------------------------
	void Set_L_InMicroHenrys(double uH) { m_L.SetValue(uH, CValue::ValueUnits::MICROHENRYS); }
	void Set_L_InHenrys(double H) { m_L.SetValue(H, CValue::ValueUnits::HENRYS); }
	void Set_F(double F) { m_F.SetValue(F, CValue::ValueUnits::HERTZ); }
	void Set_Xl(double Xl) { m_Xl.SetValue(Xl, CValue::ValueUnits::OHMS); }
	void Set_R(double R) { m_R.SetValue(R, CValue::ValueUnits::OHMS); }
	void Set_Fc(double Fc) { m_Fc.SetValue(Fc, CValue::ValueUnits::HERTZ); }
	void Set_Rt(double Rt) { m_Rt.SetValue(Rt, CValue::ValueUnits::SECONDS); }
	void Set_Tc(double Tc) { m_Tc.SetValue(Tc, CValue::ValueUnits::SECONDS); }
	//--------------------------------
	char* Get_L_String(CString& cS, CValue::ValueUnits VU) { return m_L.GetString(cS, VU); }
	char* Get_F_String(CString& cS, CValue::ValueUnits VU) { return m_F.GetString(cS, VU); }
	char* Get_Xl_String(CString& cS, CValue::ValueUnits VU) { return m_Xl.GetString(cS, VU); }
	char* Get_R_String(CString& cS, CValue::ValueUnits VU) { return m_R.GetString(cS, VU); }
	char* Get_Fc_String(CString& cS, CValue::ValueUnits VU) { return m_Fc.GetString(cS, VU); }
	char* Get_Rt_String(CString& cS, CValue::ValueUnits VU) { return m_Rt.GetString(cS, VU); }
	char* Get_Tc_String(CString& cS, CValue::ValueUnits VU) { return m_Tc.GetString(cS, VU); }

	//--------------------------------
	void Clr_L() { m_L.Clr(); }
	void Clr_F() { m_F.Clr(); }
	void Clr_Xl() { m_Xl.Clr(); }
	void Clr_R() { m_R.Clr(); }
	void Clr_Fc() { m_Fc.Clr(); }
	void Clr_Rt() { m_Rt.Clr(); }
	void Clr_Tc() { m_Tc.Clr(); }
};

