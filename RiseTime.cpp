#include "pch.h"

CRiseTime::CRiseTime()
{
}

CRiseTime::~CRiseTime()
{
}

void CRiseTime::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
			CValue::SetValue(value);
			break;
		case ValueUnits::MICROSECONDS:
			CValue::SetValue(value * 1.0e-6);
			break;
		}
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CRiseTime::HasValidUnits(ValueUnits vuUnits)
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

double CRiseTime::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
			break;
		case ValueUnits::MICROSECONDS:
			value = CValue::GetValue() * 1.0e6;
			break;
		}
	}
	return value;
}

bool CRiseTime::GetString(CString& cS, ValueUnits vuUnits)
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
			value = GetValue(CValue::ValueUnits::SECONDS);
			if (value < 0.000001)
				csFormat.Format(_T("%0.8lf"), value);
			else if (value < 0.0001)
				csFormat.Format(_T("%0.6lf"), value);
			else if (value < 0.01)
				csFormat.Format(_T("%0.4lf"), value);
			else if (value < 1.0)
				csFormat.Format(_T("%0.3lf"), value);
			else
				csFormat.Format(_T("%0.1lf"), value);
			bItsCoolDude = true;
			break;
		case ValueUnits::MICROSECONDS:
			value = GetValue(CValue::ValueUnits::MICROSECONDS);
			if (value < 1.0)
				csFormat.Format(_T("%3.3le"), value);
			else if (value < 10.0)
				csFormat.Format(_T("%0.2lf"), value);
			else
				csFormat.Format(_T("%0.0lf"), value);
			bItsCoolDude = true;
			break;
		}
		cS.Format(csFormat, value);
	}
	else
		cS.Empty();
	return bItsCoolDude;
}

void CRiseTime::Print()
{
	printf("\tRise Time: %lf seconds\n", GetValue(ValueUnits::SECONDS));
}

