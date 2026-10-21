#include "pch.h"

CInductiveReactance::CInductiveReactance()
{

}

CInductiveReactance::~CInductiveReactance()
{
}


bool CInductiveReactance::Calculate()
{
	bool bLoop = true;
	bool bChangeMade = false;
	int nChanges = 0;
	int nLastChanges = 0;

	while(bLoop)
	{
		if(CalculateXl())
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
		if(CalculateR())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateFc())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateRiseTime())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateTimeConstant())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(nChanges == nLastChanges)
			bLoop = false;
		nLastChanges = nChanges;
		nChanges = 0;
	}
	
	return bChangeMade;
}

//------------------------------------------------------------

bool CInductiveReactance::CalculateR()
{
	bool bChangeMade = false;

	if (m_R.IsNotSet())
	{
		if (m_L.IsSet())
		{
			if (m_Fc.IsSet() && m_L.IsSet())
			{
				m_R.SetValue(CalculateR(Get_L(), Get_Fc()));
				bChangeMade = true;
			}
		}
	}
	return bChangeMade;
}

bool CInductiveReactance::CalculateFc()
{
	bool bChangeMade = false;

	if(m_Fc.IsNotSet())
	{
		if (m_R.IsSet() && m_L.IsSet())
		{
			m_Fc.SetValue(CalculateFc(Get_R(), Get_L()));
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CInductiveReactance::CalculateL()
{
	bool bChangeMade = false;

	if(m_L.IsNotSet())
	{
		if(m_Xl.IsSet() && m_F.IsSet())
		{
			m_L.SetValueInHenrys(CalculateInductance(Get_Xl(), Get_F()));
			bChangeMade = true;
		}
		else if(m_R.IsSet() && m_Fc.IsSet())
		{
			m_L.SetValueInHenrys(Get_R() / (Radians( Get_Fc())));
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CInductiveReactance::CalculateF()
{
	bool bChangeMade = false;
	if (m_F.IsNotSet())
	{
		if(m_Xl.IsSet() && m_L.IsSet())
		{
			m_F.SetValue(CalculateFrequency(Get_Xl(), Get_L()));
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CInductiveReactance::CalculateXl()
{
	bool bChangeMade = false;

	if (m_Xl.IsNotSet())
	{

		if (m_F.IsSet() && m_L.IsSet())
		{
			m_Xl.SetValue(CalculateReactance(Get_L(), Get_F()));
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CInductiveReactance::CalculateRiseTime()
{
	bool bChangeMade = false;

	if (m_Rt.IsNotSet())
	{
		if (m_R.IsSet() && m_L.IsSet())
		{
			m_Rt.SetValue(CalculateRiseTime(Get_L(), Get_R()));
			bChangeMade = true;
		}
		m_Rt.SetValue(CalculateRiseTime(Get_L(), Get_R()));
		bChangeMade = true;
	}
    return bChangeMade;
}

bool CInductiveReactance::CalculateTimeConstant()
{
	bool bChangeMade = false;

	if (m_Tc.IsNotSet())
	{
		if (m_R.IsSet() && m_L.IsSet())
		{
			m_Tc.SetValue(CalculateTimeConstant(Get_L(), Get_R()));
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

double CInductiveReactance::CalculateReactance(double L, double F)
{
	//----------------------
	// Xl = 2 * pi * F * L
	//----------------------
	double Xl = 0.0;
	Xl = Radians(F) * L;
	
    return Xl;
}

double CInductiveReactance::CalculateInductance(double Xl, double F)
{
	//----------------------
	// L = Xl / (2 * pi * F)
	//----------------------
	double L;
	L = Xl / (Radians(F));
	return L;
}

double CInductiveReactance::CalculateFrequency(double Xl, double L)
{
	//----------------------
	// F = Xl / (2 * pi * L)
	//----------------------
	double F;

	F = Frequency(Xl / L);
	return F;
}

double CInductiveReactance::CalculateFc(double R, double L)
{
	double Fc;

	Fc = Frequency(R / L);
	return Fc;
}

double CInductiveReactance::CalculateR(double L, double Fc)
{
	double R;

	R = Radians(Fc) * L;
	return R;
}

double CInductiveReactance::CalculateRiseTime(double L, double R)
{
	double RiseTime = 0.0;

	RiseTime = 2.2 * (L / R);
	return RiseTime;
}

double CInductiveReactance::CalculateTimeConstant(double L, double R)
{
	double TimeConstant = 0.0;

	TimeConstant = L / R;
	return TimeConstant;
}

