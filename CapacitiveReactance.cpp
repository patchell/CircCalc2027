#include "pch.h"

CCapacitiveReactance::CCapacitiveReactance()
{
	//----------------------

}

CCapacitiveReactance::~CCapacitiveReactance()
{
}

bool CCapacitiveReactance::Calculate()
{
	bool bChangeMade = false;
	int nChanges = 0;
	int nLastChanges = 0;
	bool bLoop = true;

	while(bLoop)
	{
		if(CalculateC())
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
		if(CalculateR())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateTC())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateRt())
		{
			bChangeMade = true;
			nChanges++;
		}
		if(CalculateFc())
		{
			bChangeMade = true;
			nChanges++;
		}
		
		if(nChanges == 0)
			bLoop = false;
		else
			nChanges = 0;
	}

	return bChangeMade;
}

bool CCapacitiveReactance::CalculateC()
{
	bool bChangeMade = false;
	if(m_C.IsNotSet())
	{
		if(m_Xc.IsSet() && m_F.IsSet())
		{
			m_C.SetValue(CalculateCapacitance(Get_Xc(CValue::ValueUnits::OHMS), Get_F(CValue::ValueUnits::HERTZ	)), CValue::ValueUnits::FARADS);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CCapacitiveReactance::CalculateF()
{
	bool bChangeMade = false;

	if(m_F.IsNotSet())
	{
		if(m_Xc.IsSet() && m_C.IsSet())
		{
			m_F.SetValue(CalculateFrequency(Get_Xc(CValue::ValueUnits::OHMS), Get_C(CValue::ValueUnits::FARADS)), CValue::ValueUnits::HERTZ);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CCapacitiveReactance::CalculateXc()
{
	bool bChangeMade = false;

	if(m_Xc.IsNotSet())
	{
		if(m_C.IsSet())
			printf("\t\tC is set\n");
		else
			printf("\t\tC is NOT set\n");
		if (m_F.IsSet())
			printf("\t\tF is set\n");
		else
			printf("\t\tF is NOT set\n");
		if(m_C.IsSet() && m_F.IsSet())
		{
			m_Xc.SetValue(CalculateReactance(Get_C(CValue::ValueUnits::FARADS), Get_F(CValue::ValueUnits::HERTZ)), CValue::ValueUnits::OHMS);
			m_Xc.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CCapacitiveReactance::CalculateR()
{
	bool bChangeMade = false;

	if(m_R.IsNotSet())
	{
		if(m_Fc.IsSet() && m_C.IsSet())
		{
			m_R.SetValue(CalculateResistor(Get_Fc(CValue::ValueUnits::HERTZ), Get_C(CValue::ValueUnits::FARADS)), CValue::ValueUnits::OHMS);
			m_R.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CCapacitiveReactance::CalculateTC()
{
	bool bChangeMade = false;

	if(m_TC.IsNotSet())
	{
		if(m_R.IsSet() && m_C.IsSet())
		{
			m_TC.SetValue(CalculateTimeConstant(Get_R(CValue::ValueUnits::OHMS), Get_C(CValue::ValueUnits::FARADS)), CValue::ValueUnits::SECONDS);
			m_TC.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
	}
	return bChangeMade;
}

bool CCapacitiveReactance::CalculateRt()
{
	//----------------------
	// Rise time = 2.2 * Time constant
	//----------------------
	bool bChangeMade = false;

	if(m_RiseTime.IsNotSet())
	{
		if(m_TC.IsSet())
		{
			m_RiseTime.SetValue(CalculateRiseTime(Get_TC(CValue::ValueUnits::SECONDS)), CValue::ValueUnits::SECONDS);
			m_RiseTime.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
		else if (m_TC.IsNotSet())
		{
			if(m_R.IsSet() && m_C.IsSet())
			{
				m_TC.SetValue(CalculateTimeConstant(Get_R(CValue::ValueUnits::OHMS), Get_C(CValue::ValueUnits::FARADS)), CValue::ValueUnits::SECONDS);
				m_TC.SetState(CValue::ValueState::SET);
				m_RiseTime.SetValue(CalculateRiseTime(Get_TC(CValue::ValueUnits::SECONDS)), CValue::ValueUnits::SECONDS);
				m_RiseTime.SetState(CValue::ValueState::SET);
				bChangeMade = true;
			}
		}
	}
	return bChangeMade;
}

bool CCapacitiveReactance::CalculateFc()
{
	bool bChangeMade = false;

	if(m_Fc.IsNotSet())
	{
		if(m_TC.IsSet())
		{
			m_Fc.SetValue(CalculateFc(Get_TC(CValue::ValueUnits::SECONDS)), CValue::ValueUnits::HERTZ);
			m_Fc.SetState(CValue::ValueState::SET);
			bChangeMade = true;
		}
		else if (m_TC.IsNotSet())
		{
			if(m_R.IsSet() && m_C.IsSet())
			{
				m_TC.SetValue(CalculateTimeConstant(Get_R(CValue::ValueUnits::OHMS), Get_C(CValue::ValueUnits::FARADS)), CValue::ValueUnits::SECONDS);
				m_TC.SetState(CValue::ValueState::SET);
				m_Fc.SetValue(CalculateFc(Get_TC(CValue::ValueUnits::SECONDS)), CValue::ValueUnits::HERTZ);
				m_Fc.SetState(CValue::ValueState::SET);
				bChangeMade = true;
			}
		}
	}
	return bChangeMade;
}

//------------------------------------------------------------

double CCapacitiveReactance::CalculateReactance(double C, double F)
{
	//----------------------
	// Xc = 1 / (2 * pi * F * C)
	// where F is in Hz
	// C is in farads
	//----------------------
	double Xc = 1.0 / (C * Radians(F));
	return Xc;
}

double CCapacitiveReactance::CalculateCapacitance(double Xc, double F)
{
	//----------------------
	// C = 1 / (2 * pi * F * Xc)
	// Returns capacitance in farads
	//----------------------
	double C = 1.0 / (Radians(F) * Xc);
	return C;	
}
double CCapacitiveReactance::CalculateFrequency(double Xc, double C)
{
	//----------------------
	// F = 1 / (2 * pi * C * Xc)
	//----------------------
	double F = Frequency(1.0 / (C * Xc));
	return F;
}

double CCapacitiveReactance::CalculateResistor(double Fc, double C)
{
	double R = 1.0 / (Radians(Fc) * C);
	return R;
}

double CCapacitiveReactance::CalculateTimeConstant(double R, double C)
{
	double TC = R * C;
	return TC;
}

double CCapacitiveReactance::CalculateRiseTime(double TC)
{
	double RiseTime = 2.2 * TC;
	return RiseTime;
}

double CCapacitiveReactance::CalculateFc(double TC)
{
	double Fc = Frequency(1.0 / TC);
	return Fc;
}

//------------------------------------------------

char* CCapacitiveReactance::GetCapacitanceString(CString& cS, CValue::ValueUnits Units )
{
	m_C.GetString(cS,Units);
	return CT2A(cS);
}

char* CCapacitiveReactance::GetFrequencyString(CString& fS, CValue::ValueUnits Units )
{
	m_F.GetString(fS,Units);
	return CT2A(fS);
}

char* CCapacitiveReactance::GetXcString(CString& xS, CValue::ValueUnits Units )
{
	m_Xc.GetString(xS,Units);
	return CT2A(xS);
}

char* CCapacitiveReactance::GetResistorString(CString& rS, CValue::ValueUnits Units )
{
	m_R.GetString(rS,Units);
	return CT2A(rS);
}

char* CCapacitiveReactance::GetTimeConstantString(CString& tcS, CValue::ValueUnits Units )
{
	m_TC.GetString(tcS,Units);
	return CT2A(tcS);
}

char* CCapacitiveReactance::GetRiseTimeString(CString& rtS, CValue::ValueUnits Units )
{
	m_RiseTime.GetString(rtS,Units);
	return CT2A(rtS);
}

char* CCapacitiveReactance::GetCutoffFreqString(CString& cfS, CValue::ValueUnits Units )
{
	m_Fc.GetString(cfS,Units);
	return CT2A(cfS);
}

//------------------------------------------------

void CCapacitiveReactance::PrintValues()
{
	m_C.Print();
	m_F.Print();
	m_Xc.Print();
	m_R.Print();
	m_TC.Print();
	m_RiseTime.Print();
	m_Fc.Print();
}




