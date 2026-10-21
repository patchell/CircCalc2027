#pragma once

class CResonant : public CCalculation
{
	CCapacitor m_C;
	CInductor m_L;
	CFrequency m_F;
	CXc m_Xc;
	CXl m_Xl;
	CResistor m_R;
	CQ m_Q;
	CBw m_BW;
public:
	CResonant();
	~CResonant();
	//--------------------------------
	bool Calculate();
	//--------------------------------
	bool CalculateC();
	bool CalculateL();
	bool CalculateF();
	bool CalculateXc();
	bool CalculateXl();
	bool CalculateR();
	bool CalculateQ();
	bool CalculateBW();
	//--------------------------------
	static double ResonantFrequency(double C, double L);
	static double ResonantCapacitance(double F, double L);
	static double ResonantInductance(double F, double C);
	static double ResonantCapacitiveReactance(double F, double C);
	static double ResonantInductiveReactance(double F, double L);
	static double DampingResistance(double Q, double L, double C);
	static double ResonantQualityFactor(double R, double L, double C);
	static double ResonantBandwidth(double R, double L, double C);
	//--------------------------------
	void Set_C_InFarads(double C) { m_C.SetValueInFarads(C); }
	void Set_C_InPicoFarads(double PicoFarads) { m_C.SetValueInPicoFarads(PicoFarads); }
	void Set_L_InHenrys(double L) { m_L.SetValueInHenrys(L); }
	void Set_L_InMicroHenrys(double uH) { m_L.SetValueInMicroHenrys(uH); }
	void Set_F(double F) { m_F.SetValue(F); }
	void Set_Xc(double Xc) { m_Xc.SetValue(Xc); }
	void Set_Xl(double Xl) { m_Xl.SetValue(Xl); }
	void Set_R(double R) { m_R.SetValue(R); }
	void Set_Q(double Q) { m_Q.SetValue(Q); }
	void Set_BW(double BW) { m_BW.SetValue(BW); }
	//--------------------------------
	double Get_BW() const { return m_BW.GetValue(); }
	double Get_F() const { return m_F.GetValue(); }
	double Get_C() const { return m_C.GetValue(); }
	double Get_L() const { return m_L.GetValue(); }
	double Get_Xc() const { return m_Xc.GetValue(); }
	double Get_Xl() const { return m_Xl.GetValue(); }
	double Get_R() const { return m_R.GetValue(); }
	double Get_Q() const { return m_Q.GetValue(); }
	//--------------------------------
	char* Get_C_String(CString& cS) { return m_C.GetString(cS); }
	char* Get_L_String(CString& cS) { return m_L.GetString(cS); }
	char* Get_F_String(CString& cS) { return m_F.GetString(cS); }
	char* Get_Xc_String(CString& cS) { return m_Xc.GetString(cS); }
	char* Get_Xl_String(CString& cS) { return m_Xl.GetString(cS); }
	char* Get_R_String(CString& cS) { return m_R.GetString(cS); }
	char* Get_Q_String(CString& cS) { return m_Q.GetString(cS); }
	char* Get_BW_String(CString& cS) { return m_BW.GetString(cS); }
	//--------------------------------
	void Clr_C() { m_C.Clr(); }
	void Clr_L() { m_L.Clr(); }
	void Clr_F() { m_F.Clr(); }
	void Clr_Xc() { m_Xc.Clr(); }
	void Clr_Xl() { m_Xl.Clr(); }
	void Clr_R() { m_R.Clr(); }
	void Clr_Q() { m_Q.Clr(); }
	void Clr_BW() { m_BW.Clr(); }
	//--------------------------------
};

