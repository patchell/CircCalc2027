#include "pch.h"

CTurns::CTurns()
{}

CTurns::~CTurns()
{}

void CTurns::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		CValue::SetValue(value);
		SetState(ValueState::SET);
	}
	else
	{
		SetState(ValueState::NOTSET);
	}
}

bool CTurns::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
	case ValueUnits::TURNS:
		bUnitsAreValid = true;
		break;
	}
	return bUnitsAreValid;
}

double CTurns::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::TURNS:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

char* CTurns::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	char* pS = NULL;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::TURNS:
			csFormat = _T("%0.1f");
			cS.Format(csFormat, value);
			pS = CT2A(cS);
			break;
		}
	}
	return pS;
}
