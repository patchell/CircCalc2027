#include "pch.h"

CCoilCalculator::CCoilCalculator()
{
	m_bMuliLayer = false;	// True if multi-layer coil, false if single-layer
}

CCoilCalculator::~CCoilCalculator()
{
}

void CCoilCalculator::GetString(CString& cS, Param param)
{
	switch (param)
	{
	case Param::DIAMETER_1:
		m_Diameter_1.GetString(cS);
		break;
	case Param::RADIUS_1:
		m_Radius_1.GetString(cS);
		break;
	case Param::RADIUS_2:
		m_Radius_2.GetString(cS);
		break;
	case Param::COIL_LENGTH:
		m_CoilLength.GetString(cS);
		break;
	case Param::INDUCTANCE:
		m_Inductance.GetString(cS);
		break;
	case Param::TURNS:
		m_Turns.GetString(cS);
		break;
	case Param::WIRE_DIAMETER:
		m_WireDiameter.GetString(cS);
		break;
	case Param::TURNS_PER_INCH:
		m_TurnsPerInch.GetString(cS);
		break;
	case Param::MULTI_LAYER:
		cS.Format(_T("%d"), m_bMuliLayer ? 1 : 0);
		break;
	default:
		cS.Empty();
		break;
	}
}

void CCoilCalculator::Calculate()
{
	double Error = 0.0;
	double PercentError = 0.0;
	double Turns = 0.0;
	double L = 0.0;
	double Len = 0.0;
	int MaxIterations = 10;
	double TurnsGuess = 0.0;
	double NextLen = 0.0;
	int CoilLayers = 2;
	double TurnsPerLayer = 0.0;
	double Temp = 0.0;
	int Iteration = 0;

	if (m_bMuliLayer)
	{
		//-------------------------------------
		// We will need to guess radius2
		// we need to know the length
		// we will need to know the wire diameter
		//-------------------------------------
		do {
			TurnsPerLayer = m_TurnsPerInch.GetValue() * m_CoilLength.GetValueInInches();
			Temp = m_Radius_1.GetValueInInches() + (m_WireDiameter.GetValueInInches() * CoilLayers);
			m_Radius_2.SetValueInInches(Temp);
			Turns = CalculateMultiLayerTurns(
				m_Radius_1.GetValueInInches(),
				m_Radius_2.GetValueInInches(), 
				m_CoilLength.GetValueInInches(), 
				m_Inductance.GetValueInMicroHenrys()
			);
			if(Turns/TurnsPerLayer > CoilLayers)
			{
				CoilLayers++;
				Temp = m_Radius_1.GetValueInInches() + (m_WireDiameter.GetValueInInches() * CoilLayers);
				m_Radius_2.SetValueInInches(Temp);
				PercentError = 100.0;
			}
			else
			{
				L = CalculateInductanceMultiLayer(
					m_Radius_1.GetValueInInches(), 
					m_Radius_2.GetValueInInches(), 
					m_CoilLength.GetValueInInches(), 
					Turns
				);
				Error = m_Inductance.GetValueInMicroHenrys() - L;
				PercentError = Error / m_Inductance.GetValueInMicroHenrys();
			}
			Iteration++;
			printf(
				"Iteration=%d  Radius2=%lf  Turns=%lf  Len=%lf  L=%lf  Error=%lf  PercentError=%lf\n", 
				Iteration, 
				m_Radius_2,
				Turns, 
				m_CoilLength, 
				L, 
				Error, 
				PercentError
			);
		} while (fabs(PercentError) > 0.5 && Iteration < MaxIterations);
	}
	else
	{
		//-------------------------------------
		// Guess the Length of the coil
		// and the number of turns
		//-------------------------------------
		Len = m_Radius_1.GetValueInInches();
		do {
			Turns = CalculateSingleLayerTurns(m_Radius_1.GetValueInInches(), Len, m_Inductance.GetValueInMicroHenrys());
			Len = Turns / m_TurnsPerInch.GetValue();
			L = CalculateInductanceSingleLayer(m_Radius_1.GetValueInInches(), Len, Turns);
			Error = m_Inductance.GetValueInMicroHenrys() - L;
			PercentError = 100 * Error / m_Inductance.GetValueInMicroHenrys();
			Iteration++;
			printf(
				"Iteration=%d  Turns=%lf  Len=%lf  L=%lf  Error=%lf  PercentError=%lf\n", 
				Iteration, 
				Turns, 
				Len, 
				L, 
				Error, 
				PercentError
			);
		} while (fabs(PercentError) > 0.5 && Iteration < MaxIterations);

	}
}
double CCoilCalculator::CalculateSingleLayerTurns(double Radius, double Length, double Inductance)
{
	//-------------------------------------
	// Calculate the number of turns for a 
	// single-layer coil based on the given
	// parameters Using Wheeler's formula
	// for inductance.
	// Diameter and Length are in inches
	//-------------------------------------
	double T = 0.0;

	T = 6.0 * Radius;
	T += 9.0 * Length;
	T *= Inductance;
	T = sqrt(T);
	T /= Radius;
	
    return T;
}

double CCoilCalculator::CalculateInductanceSingleLayer(double R, double Length, double N)
{
	double L = 0.0;

	L = (R * R * N * N) / (6.0 * R + 9.0 * Length);
	return L;
}

double CCoilCalculator::CalculateMultiLayerTurns(double R1, double R2, double Length, double Inductance)
{
	//-------------------------------------
	// Calculate the number of turns for a 
	// multi-layer coil based on the given
	// parameters Using Wheeler's formula
	// for inductance.
	// Inductance is in microhenries (uH)
	// Length is in inches
	// R1 and R2 are the inner and outer
	//-------------------------------------
	double T = 0.0;

	T = 6.0 * R1;
	T += 9.0 * Length;
	T += 10.0 * (R2 - R1);
	T *= Inductance;
	T /= 0.8 * R1 * R1;
	T = sqrt(T);
	
	return T;
}

double CCoilCalculator::CalculateInductanceMultiLayer(double R1, double R2, double Length, double Turns)
{
	double L = 0.0;

	L = (0.8 * R1 * R1 * Turns * Turns) / (6.0 * R1 + 9.0 * Length + 10.0 * (R2 - R1));
	return L;
}

void CCoilCalculator::Set_WireDiameter(double d)
{
	m_WireDiameter.SetValueInInches(d);
	m_TurnsPerInch.SetValue(1.0 / m_WireDiameter.GetValueInInches());
}
