#include "pch.h"

CFrequency::CFrequency()
{
}

CFrequency::~CFrequency()
{
}

void CFrequency::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		CValue::SetState(ValueState::SET);
		CValue::SetValue(value);
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CFrequency::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
		case ValueUnits::HERTZ:
			bUnitsAreValid = true;
			break;
	}
	return bUnitsAreValid;
}

double CFrequency::GetValue(ValueUnits vuUnits)
{
	return CValue::GetValue();
}

char* CFrequency::GetString(CString& cS, ValueUnits vuUnits)
{
	char* pS = nullptr;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HERTZ:
			cS.Format(_T("%0.0lf"), GetValue());
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
