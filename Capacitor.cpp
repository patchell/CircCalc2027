#include "pch.h"

CCapacitor::CCapacitor()
{
}

CCapacitor::~CCapacitor()
{
}

void CCapacitor::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::FARADS:
			CValue::SetState(ValueState::SET);
			CValue::SetValue(value);
			break;
		case ValueUnits::PICO_FARADS:
			CValue::SetState(ValueState::SET);
			CValue::SetValue(value * 1.0e-12);
			break;
		}
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CCapacitor::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
		case ValueUnits::FARADS:
		case ValueUnits::PICO_FARADS:
			bUnitsAreValid = true;
			break;
	}
	return bUnitsAreValid;
}

double CCapacitor::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	switch (vuUnits)
	{
	case ValueUnits::FARADS:
		value = CValue::GetValue();
		break;
	case ValueUnits::PICO_FARADS:
		value = CValue::GetValue() * 1e12;
		break;
	}
	return value;
}

char* CCapacitor::GetString(CString& cS, ValueUnits vuUnits)
{
	char* pS = nullptr;

	if(IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::FARADS:
			cS.Format(_T("%0.0lf"), GetValue());
			break;
		case ValueUnits::PICO_FARADS:
			cS.Format(_T("%0.0lf"), GetValue() * 1e12);
			break;
		}
		pS = CT2A(cS);
	}
	else
	{
		cS.Empty();
	}
	return pS;
}
/*
void CCapacitor::SetValueInFarads(double value)
{
	CValue::SetValue(value);
}

double CCapacitor::GetValueInFarads() const
{
    return CValue::GetValue();
}

double CCapacitor::GetValueInPicoFarads() const
{
	return CValue::GetValue() * 1e12;
}

char* CCapacitor::GetString(CString& cS) const
{
	if(IsSet())
		cS.Format(_T("%12.0lf"), GetValueInPicoFarads());
	else
		cS.Empty();
	return CT2A(cS);
}*/
