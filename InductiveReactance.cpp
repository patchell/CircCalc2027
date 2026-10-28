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
	int nLoopCount = 0;

	while(bLoop)
	{
		if(CalculateXl())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateXl() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateL())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateL() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateF())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateF() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateR())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateR() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateFc())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateFc() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateRiseTime())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateRiseTime() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateTimeConstant())
		{
			printf("\t%d: CInductiveReactance::Calculate() - CalculateTimeConstant() returned true\n", nLoopCount);
			bChangeMade = true;
			nChanges++;
		}
		if(nChanges == 0)
			bLoop = false;
		nChanges = 0;
		if (nLoopCount++ > 10)
		{
			bLoop = false;
			AfxMessageBox(_T("Internal ERROR:CInductiveReactance::Calculate() - Loop count exceeded 10 iterations."));
		}
	}
	
	return bChangeMade;
}

//------------------------------------------------------------

bool CInductiveReactance::CalculateR()
{
	bool bChangeMade = false;

	if (m_R.IsNotSet())
	{
		if (m_Fc.IsSet() && m_L.IsSet())
		{
			m_R.SetValue(CalculateR(Get_L(CValue::ValueUnits::HENRYS), Get_Fc(CValue::ValueUnits::HERTZ)), CValue::ValueUnits::OHMS);
			m_R.SetState(CValue::ValueState::SET);
			bChangeMade = true;
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
			m_Fc.SetValue(CalculateFc(Get_R(CValue::ValueUnits::OHMS), Get_L(CValue::ValueUnits::HENRYS)), CValue::ValueUnits::HERTZ);
			m_Fc.SetState(CValue::ValueState::SET);
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
			m_L.SetValue(CalculateInductance(Get_Xl(CValue::ValueUnits::OHMS), Get_F(CValue::ValueUnits::HERTZ)), CValue::ValueUnits::HENRYS);
			m_L.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
		else if(m_R.IsSet() && m_Fc.IsSet())
		{
			m_L.SetValue(CalculateInductance(Get_R(CValue::ValueUnits::OHMS), Get_Fc(CValue::ValueUnits::HERTZ)), CValue::ValueUnits::HENRYS);
			m_L.SetState(CValue::ValueState::SET);
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
			m_F.SetValue(CalculateFrequency(Get_Xl(CValue::ValueUnits::OHMS), Get_L(CValue::ValueUnits::HENRYS)), CValue::ValueUnits::HERTZ);
			m_F.SetState(CValue::ValueState::SET);
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
			m_Xl.SetValue(CalculateReactance(Get_L(CValue::ValueUnits::HENRYS), Get_F(CValue::ValueUnits::HERTZ)), CValue::ValueUnits::OHMS);
			m_Xl.SetState(CValue::ValueState::SET);
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
		if (m_Tc.IsSet())
		{
			m_Rt.SetValue(2.2 * m_Tc.GetValue(CValue::ValueUnits::SECONDS), CValue::ValueUnits::SECONDS);
			m_Rt.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
		else if (m_Tc.IsNotSet())
		{
			if (m_R.IsSet() && m_L.IsSet())
			{
				m_Tc.SetValue(CalculateTimeConstant(Get_L(CValue::ValueUnits::HENRYS), Get_R(CValue::ValueUnits::OHMS)), CValue::ValueUnits::SECONDS);
				m_Tc.SetState(CValue::ValueState::SET);
				m_Rt.SetValue(CalculateRiseTime(Get_L(CValue::ValueUnits::HENRYS), Get_R(CValue::ValueUnits::OHMS)), CValue::ValueUnits::SECONDS);
				m_Rt.SetState(CValue::ValueState::SET);
				bChangeMade = true;
			}
		}
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
			m_Tc.SetValue(CalculateTimeConstant(Get_L(CValue::ValueUnits::HENRYS), Get_R(CValue::ValueUnits::OHMS)), CValue::ValueUnits::SECONDS);
			m_Tc.SetState(CValue::ValueState::SET);
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

