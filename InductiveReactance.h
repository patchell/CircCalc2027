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
	double Get_L() const { return m_L.GetValue(); }	
	double Get_F() const { return m_F.GetValue(); }
	double Get_Xl() const { return m_Xl.GetValue(); }
	double Get_R() const { return m_R.GetValue(); }
	double Get_Fc() const { return m_Fc.GetValue(); }
	double Get_Rt() const { return m_Rt.GetValue(); }
	double Get_Tc	() const { return m_Tc.GetValue(); }
	//--------------------------------
	void Set_L_InMicroHenrys(double uH) { m_L.SetValueInMicroHenrys(uH); }
	void Set_L_InHenrys(double H) { m_L.SetValueInHenrys(H); }
	void Set_L(CString& cS) { m_L.SetValue(cS); }
	void Set_F(double F) { m_F.SetValue(F); }
	void Set_Xl(double Xl) { m_Xl.SetValue(Xl); }
	void Set_R(double R) { m_R.SetValue(R); }
	void Set_Fc(double Fc) { m_Fc.SetValue(Fc); }
	void Set_Rt(double Rt) { m_Rt.SetValue(Rt); }
	void Set_Tc(double Tc) { m_Tc.SetValue(Tc); }
	//--------------------------------
	char* Get_L_String(CString& cS) { return m_L.GetString(cS); }
	char* Get_F_String(CString& cS) { return m_F.GetString(cS); }
	char* Get_Xl_String(CString& cS) { return m_Xl.GetString(cS); }
	char* Get_R_String(CString& cS) { return m_R.GetString(cS); }
	char* Get_Fc_String(CString& cS) { return m_Fc.GetString(cS); }
	char* Get_Rt_String(CString& cS) { return m_Rt.GetString(cS); }
	char* Get_Tc_String(CString& cS) { return m_Tc.GetString(cS); }

	//--------------------------------
	void Clr_L() { m_L.Clr(); }
	void Clr_F() { m_F.Clr(); }
	void Clr_Xl() { m_Xl.Clr(); }
	void Clr_R() { m_R.Clr(); }
	void Clr_Fc() { m_Fc.Clr(); }
	void Clr_Rt() { m_Rt.Clr(); }
	void Clr_Tc() { m_Tc.Clr(); }
};

