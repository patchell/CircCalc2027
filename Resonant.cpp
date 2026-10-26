#include "pch.h"

CResonant::CResonant()
{
}

CResonant::~CResonant()
{
}
//----------------------
bool CResonant::Calculate()
{
	bool bLoop = true;
	bool bChangeMade = false;
	int nChanges = 0;
	int nLastChanges = 0;

	while(bLoop)
	{
		if(CalculateC())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateL())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateF())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateXc())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateXl())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateR())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateQ())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateBW())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(nChanges == nLastChanges)
		{
			bLoop = false;
		}
		nLastChanges = nChanges;
	}
	return bChangeMade;
}

//----------------------
bool CResonant::CalculateC()
{
	bool bChangeMade = false;
	if(m_C.IsNotSet())
	{
		if(m_F.IsSet() && m_L.IsSet())
		{
			m_C.SetValue(ResonantCapacitance(Get_F(), Get_L()), CValue::ValueUnits::FARADS);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateL()
{
	bool bChangeMade = false;
	if(m_L.IsNotSet())
	{
		if(m_F.IsSet() && m_C.IsSet())
		{
			m_L.SetValue(ResonantInductance(Get_F(), Get_C()), CValue::ValueUnits::HENRYS);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateXc()
{
	bool bChangeMade = false;
	if(m_Xc.IsNotSet())
	{
		if(m_F.IsSet() && m_C.IsSet())
		{
			m_Xc.SetValue(ResonantCapacitiveReactance(Get_F(), Get_C()), CValue::ValueUnits::OHMS);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateF()
{
	bool bChangeMade = false;
	if(m_F.IsNotSet())
	{
		if(m_C.IsSet() && m_L.IsSet())
		{
			m_F.SetValue(ResonantFrequency(Get_C(), Get_L()), CValue::ValueUnits::HERTZ);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateXl()
{
	bool bChangeMade = false;
	if(m_Xl.IsNotSet())
	{
		if(m_F.IsSet() && m_L.IsSet())
		{
			m_Xl.SetValue(ResonantInductiveReactance(Get_F(), Get_L()), CValue::ValueUnits::OHMS);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateR()
{
	bool bChangeMade = false;
	if(m_R.IsNotSet())
	{
		if(m_Q.IsSet() && m_L.IsSet() && m_C.IsSet())
		{
			m_R.SetValue(DampingResistance(Get_Q(), Get_L(), Get_C()), CValue::ValueUnits::OHMS);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateQ()
{
	bool bChangeMade = false;

	if (m_Q.IsNotSet())
	{
		if (m_R.IsSet() && m_L.IsSet() && m_C.IsSet())
		{
			m_Q.SetValue(ResonantQualityFactor(Get_R(), Get_L(), Get_C()), CValue::ValueUnits::NONE);
			bChangeMade = true;
		}
		else if(m_F.IsSet() && m_BW.IsSet())
		{
			m_Q.SetValue(Get_F() / Get_BW(), CValue::ValueUnits::NONE);
			bChangeMade = true;
		}
		else if(m_C.IsSet() && m_L.IsSet() && m_BW.IsSet())
		{
			double R = 1.0 / (Get_BW() * Get_C());
			m_Q.SetValue(ResonantQualityFactor(R, Get_L(), Get_C()), CValue::ValueUnits::NONE);
			bChangeMade = true;
		}
		else if(m_C.IsSet() && m_L.IsSet() && m_R.IsSet())
		{
			m_Q.SetValue(ResonantQualityFactor(Get_R(), Get_L(), Get_C()), CValue::ValueUnits::NONE);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CResonant::CalculateBW()
{
	bool bChangeMade = false;
	if(m_BW.IsNotSet())
	{
		if(m_R.IsSet() && m_L.IsSet())
		{
			m_BW.SetValue(ResonantBandwidth(Get_R(), Get_L(), Get_C()), CValue::ValueUnits::HERTZ);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

//----------------------

double CResonant::ResonantFrequency(double C, double L)
{
	//----------------------
	// F = 1 / (2 * pi * sqrt(L * C))
	//----------------------
	double F = 0.0;
	F = Frequency(1.0 / (sqrt(L * C)));
	return F;
}

double CResonant::ResonantCapacitance(double F, double L)
{
	//----------------------
	// C = 1 / (4 * pi^2 * F^2 * L)
	//----------------------
	double w = Radians(F);
	double C = 1.0 / (w * w * L);
	return C;
}

double CResonant::ResonantInductance(double F, double C)
{
	//----------------------
	// L = 1 / (4 * pi^2 * F^2 * C)
	//----------------------
	double w = Radians(F);
	double L = 1.0 / (w * w * C);
	return L;
}

double CResonant::ResonantCapacitiveReactance(double F, double C)
{
	//----------------------
	// Xc = 1 / (2 * pi * F * C)
	//----------------------
	double w = Radians(F);
	double Xc = 1.0 / (w * C);
	return Xc;
}

double CResonant::ResonantInductiveReactance(double F, double L)
{
	//----------------------
	// Xl = 2 * pi * F * L
	//----------------------
	double w = Radians(F);
	double Xl = w * L;
	return Xl;
}

double CResonant::DampingResistance(double Q, double L, double C)
{
	//----------------------
	// R = Q / sqrt(C / L)
	//----------------------
	double R = Q / sqrt(C / L);
	return R;
}

double CResonant::ResonantQualityFactor(double R, double L, double C)
{
	//----------------------
	// Q = R * sqrt(C / L)
	//----------------------
	double Q = R * sqrt(C / L);
	return Q;
}

double CResonant::ResonantBandwidth(double R, double L, double C)
{
	//----------------------
	// BW = 1/(RC) = R / L
	//----------------------
	double BW = 1.0 / (R * C);
	BW = Frequency(BW);
	return BW;
}
