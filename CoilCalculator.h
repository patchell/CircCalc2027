#pragma once

class CCoilCalculator: public CCalculation
{
	CInches m_Diameter_1;			// inches
	CInches m_Radius_1;				// inches
	CInches m_Radius_2;				// inches
	CInches m_CoilLength;			// inches
	CInductor m_Inductance;			// microhenrys
	CInches m_WireDiameter;			// inches
	CTurnsPerInch m_TurnsPerInch;	// inches per turn
	CTurns m_Turns;					// Total number of turns in the coil
	bool m_bMuliLayer;				// True if multi-layer coil, false if single-layer
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
	double Get_Diameter_1()  { return m_Diameter_1.GetValue(CValue::ValueUnits::INCHES); }
	double Get_Radius_1()  { return m_Radius_1.GetValue(CValue::ValueUnits::INCHES); }
	double Get_Radius_2()  { return m_Radius_2.GetValue(CValue::ValueUnits::INCHES); }
	double Get_CoilLength()  { return m_CoilLength.GetValue(CValue::ValueUnits::INCHES); }
	double Get_InductanceInMicroHenries()  { return m_Inductance.GetValue(CValue::ValueUnits::MICROHENRYS); }
	double Get_Turns()  { return m_Turns.GetValue(CValue::ValueUnits::TURNS); }
	double Get_WireDiameter()  { return m_WireDiameter.GetValue(CValue::ValueUnits::INCHES); }
	double Get_TurnPerInch()  { return m_TurnsPerInch.GetValue(CValue::ValueUnits::TURNS_PER_INCH); }
	bool Get_MultiLayer() const { return m_bMuliLayer; }
	//-------- Set Methods -----------------
	void Set_Diameter_1(double d) { m_Diameter_1.SetValue(d, CValue::ValueUnits::INCHES); }
	void Set_Radius_1(double r) { m_Radius_1.SetValue(r, CValue::ValueUnits::INCHES); }
	void Set_Radius_2(double r) { m_Radius_2.SetValue(r, CValue::ValueUnits::INCHES); }
	void Set_CoilLength(double l) { m_CoilLength.SetValue(l, CValue::ValueUnits::INCHES); }
	void Set_InductanceInMicroHenries(double L_uH) { m_Inductance.SetValue(L_uH, CValue::ValueUnits::MICROHENRYS); }
	void Set_Turns(double t) { m_Turns.SetValue(t, CValue::ValueUnits::TURNS); }
	void Set_WireDiameter(double d);
	void Set_TurnPerInch(double p) { m_TurnsPerInch.SetValue(p, CValue::ValueUnits::TURNS_PER_INCH); }
	void Set_MultiLayer(bool b) { m_bMuliLayer = b; }
};

