#include "pch.h"

CTurnsPerInch::CTurnsPerInch()
{}

CTurnsPerInch::~CTurnsPerInch()
{}

void CTurnsPerInch::SetValue(double value, ValueUnits vuUnits)
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

bool CTurnsPerInch::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
	case ValueUnits::TURNS_PER_INCH:
		bUnitsAreValid = true;
		break;
	}
	return bUnitsAreValid;
}

double CTurnsPerInch::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::TURNS_PER_INCH:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

char* CTurnsPerInch::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	char* pS = NULL;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::TURNS_PER_INCH:
			csFormat = _T("%0.1f");
			cS.Format(csFormat, value);
			pS = CT2A(cS);
			break;
		}
	}
	return pS;
}
