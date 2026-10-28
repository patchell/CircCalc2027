#include "pch.h"

CXl::CXl()
{
}

CXl::~CXl()
{
}

void CXl::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		CValue::SetValue(value);
		SetState(ValueState::SET);
	}
}

bool CXl::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
	case ValueUnits::OHMS:
			bUnitsAreValid = true;
			break;
	}
	return bUnitsAreValid;
}

double CXl::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

bool CXl::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	double dbIntPart = 0.0;
	bool bItsCoolDude = false;

	if (HasValidUnits(vuUnits) && IsSet())
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			if (modf(value, &dbIntPart) == 0.0)
				csFormat = _T("%0.0lf");
			else
				csFormat = _T("%0.3lf");
			cS.Format(csFormat, value);
			bItsCoolDude = true;
			break;
		}
	}
	else
		cS.Empty();
	return bItsCoolDude;
}
