#include "pch.h"

CInches::CInches():CValue()
{
}

CInches::~CInches()
{
}

void CInches::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::INCHES:
			CValue::SetValue(value);
			break;
		}
	}
	else
	{
		SetState(ValueState::NOTSET);
	}
}

bool CInches::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;
	switch (vuUnits)
	{
	case ValueUnits::INCHES:
		bUnitsAreValid = true;
		break;
	}
	return bUnitsAreValid;
}

double CInches::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::INCHES:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

bool CInches::GetString(CString& cS, ValueUnits vuUnits)
{
	bool bItsCoolDude = false;
	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::INCHES:
			cS.Format(_T("%0.3lf"), GetValue(vuUnits));
			bItsCoolDude = true;
			break;
		}
	}
	else
	{
		cS.Empty();
	}
	return bItsCoolDude;
}
