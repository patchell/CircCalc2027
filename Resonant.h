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
	void Set_C_InFarads(double C) { m_C.SetValue(C, CValue::ValueUnits::FARADS); }
	void Set_C_InPicoFarads(double PicoFarads) { m_C.SetValue(PicoFarads, CValue::ValueUnits::PICO_FARADS); }
	void Set_L_InHenrys(double L) { m_L.SetValue(L, CValue::ValueUnits::HENRYS); }
	void Set_L_InMicroHenrys(double uH) { m_L.SetValue(uH, CValue::ValueUnits::MICROHENRYS); }
	void Set_F(double F) { m_F.SetValue(F, CValue::ValueUnits::HERTZ); }
	void Set_Xc(double Xc) { m_Xc.SetValue(Xc, CValue::ValueUnits::OHMS); }
	void Set_Xl(double Xl) { m_Xl.SetValue(Xl, CValue::ValueUnits::OHMS); }
	void Set_R(double R) { m_R.SetValue(R, CValue::ValueUnits::OHMS); }
	void Set_Q(double Q) { m_Q.SetValue(Q, CValue::ValueUnits::NONE); }
	void Set_BW(double BW) { m_BW.SetValue(BW, CValue::ValueUnits::HERTZ); }
	//--------------------------------
	double Get_BW()  { return m_BW.GetValue(CValue::ValueUnits::HERTZ); }
	double Get_F()  { return m_F.GetValue(CValue::ValueUnits::HERTZ); }
	double Get_C()  { return m_C.GetValue(CValue::ValueUnits::FARADS); }
	double Get_L()  { return m_L.GetValue(CValue::ValueUnits::HENRYS); }
	double Get_Xc()  { return m_Xc.GetValue(CValue::ValueUnits::OHMS); }
	double Get_Xl()  { return m_Xl.GetValue(CValue::ValueUnits::OHMS); }
	double Get_R()  { return m_R.GetValue(CValue::ValueUnits::OHMS); }
	double Get_Q()  { return m_Q.GetValue(CValue::ValueUnits::NONE); }
	//----------- Get Value Objects ----------------------
	CFrequency* Get_F_Value() { return &m_F; }
	CCapacitor* Get_C_Value() { return &m_C; }
	CInductor* Get_L_Value() { return &m_L; }
	CXc* Get_Xc_Value() { return &m_Xc; }
	CXl* Get_Xl_Value() { return &m_Xl; }
	CResistor* Get_R_Value() { return &m_R; }
	CQ* Get_Q_Value() { return &m_Q; }
	CBw* Get_BW_Value() { return &m_BW; }
	//--------------------------------
	char* Get_C_String(CString& cS, CValue::ValueUnits VU) { return m_C.GetString(cS, VU); }
	char* Get_L_String(CString& cS, CValue::ValueUnits VU) { return m_L.GetString(cS, VU); }
	char* Get_F_String(CString& cS, CValue::ValueUnits VU) { return m_F.GetString(cS, VU); }
	char* Get_Xc_String(CString& cS, CValue::ValueUnits VU) { return m_Xc.GetString(cS, VU); }
	char* Get_Xl_String(CString& cS, CValue::ValueUnits VU) { return m_Xl.GetString(cS, VU); }
	char* Get_R_String(CString& cS, CValue::ValueUnits VU) { return m_R.GetString(cS, VU); }
	char* Get_Q_String(CString& cS, CValue::ValueUnits VU) { return m_Q.GetString(cS, VU); }
	char* Get_BW_String(CString& cS, CValue::ValueUnits VU) { return m_BW.GetString(cS, VU); }
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

