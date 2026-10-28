#include "pch.h"


CTimeConstant::CTimeConstant()
{
}

CTimeConstant::~CTimeConstant()
{
}

void CTimeConstant::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		CValue::SetValue(value);
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CTimeConstant::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
		case ValueUnits::SECONDS:
		case ValueUnits::MICROSECONDS:
			bUnitsAreValid = true;
			break;
	}
	return bUnitsAreValid;
}

double CTimeConstant::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
		case ValueUnits::MICROSECONDS:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

bool CTimeConstant::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	double dbIntPart = 0.0;
	bool bItsCoolDude = false;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
			value = GetValue(vuUnits);
			bItsCoolDude = true;
			break;
		case ValueUnits::MICROSECONDS:
			value = GetValue(vuUnits) * 1e6;
			bItsCoolDude = true;
			break;
		}
		if (modf(value, &dbIntPart) == 0.0)
			csFormat.Format(_T("%0.0lf"), value);
		else
			csFormat.Format(_T("%0.3lf"), value);
		cS.Format(csFormat, value);
	}
	else
	{
		cS.Empty();
	}
	return bItsCoolDude;
}

void CTimeConstant::Print()
{
	printf("\tTime Constant: %lf Seconds\n", GetValue(ValueUnits::SECONDS));
}
