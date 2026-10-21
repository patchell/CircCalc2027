#pragma once

class CCoilCalculator
{
	CInches m_Diameter_1;	// inches
	CInches m_Radius_1;	// inches
	CInches m_Radius_2;	// inches
	CInches m_CoilLength;	//inches
	CInductor m_Inductance;	// microhenrys
	CInches m_WireDiameter;	// inches
	CValue m_TurnsPerInch;		// inches per turn
	CValue m_Turns;		// Total number of turns in the coil
	bool m_bMuliLayer;	// True if multi-layer coil, false if single-layer
public:
	enum class Param {
		DIAMETER_1,
		RADIUS_1,
		RADIUS_2,
		COIL_LENGTH,
		INDUCTANCE,
		TURNS,
		WIRE_DIAMETER,
		TURNS_PER_INCH,
		MULTI_LAYER
	};

public:
	CCoilCalculator();
	virtual ~CCoilCalculator();
	void GetString(CString& cS, Param param);
	void Calculate();
	static double CalculateSingleLayerTurns(double Radius, double Length, double Inductance);
	static double CalculateInductanceSingleLayer(double Radius, double Length, double Turns);
	static double CalculateMultiLayerTurns(double R1, double R2, double Length, double Inductance);
	static double CalculateInductanceMultiLayer(double R1, double R2, double Length, double Turns);
	//-------- Clear Methods -----------------
	void Clr_Diameter_1() { m_Diameter_1.Clr(); }
	void Clr_Radius_1() { m_Radius_1.Clr(); }
	void Clr_Radius_2() { m_Radius_2.Clr(); }
	void Clr_CoilLength() { m_CoilLength.Clr(); }
	void Clr_Inductance() { m_Inductance.Clr(); }
	void Clr_Turns() { m_Turns.Clr(); }
	void Clr_WireDiameter() { m_WireDiameter.Clr(); }
	void Clr_TurnsPerInch() { m_TurnsPerInch.Clr(); }
	void Clr_MultiLayer() { m_bMuliLayer = false; }
	void Clr_All()
	{
		Clr_Diameter_1();
		Clr_Radius_1();
		Clr_Radius_2();
		Clr_CoilLength();
		Clr_Inductance();
		Clr_Turns();
		Clr_WireDiameter();
		Clr_TurnsPerInch();
		Clr_MultiLayer();
	}
	//-------- Get Methods -----------------
	double Get_Diameter_1() const { return m_Diameter_1.GetValueInInches(); }
	double Get_Radius_1() const { return m_Radius_1.GetValueInInches(); }
	double Get_Radius_2() const { return m_Radius_2.GetValueInInches(); }
	double Get_CoilLength()const { return m_CoilLength.GetValueInInches(); }
	double Get_InductanceInMicroHenries() const { return m_Inductance.GetValueInMicroHenrys(); }
	double Get_Turns() const { return m_Turns.GetValue(); }
	double Get_WireDiameter() const { return m_WireDiameter.GetValueInInches(); }
	double Get_TurnPerInch() const { return m_TurnsPerInch.GetValue(); }
	bool Get_MultiLayer() const { return m_bMuliLayer; }
	//-------- Set Methods -----------------
	void Set_Diameter_1(double d) { m_Diameter_1.SetValueInInches(d); }
	void Set_Radius_1(double r) { m_Radius_1.SetValueInInches(r); }
	void Set_Radius_2(double r) { m_Radius_2.SetValueInInches(r); }
	void Set_CoilLength(double l) { m_CoilLength.SetValueInInches(l); }
	void Set_InductanceInMicroHenries(double L_uH) { m_Inductance.SetValueInMicroHenrys(L_uH); }
	void Set_Turns(double t) { m_Turns.SetValue(t); }
	void Set_WireDiameter(double d);
	void Set_TurnPerInch(double p) { m_TurnsPerInch.SetValue(p); }
	void Set_MultiLayer(bool b) { m_bMuliLayer = b; }
};

