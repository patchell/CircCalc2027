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
		CValue::SetValue(value);
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
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
			value = CValue::GetValue() * 1.0e6;
			break;
		case ValueUnits::MICROSECONDS:
			value = CValue::GetValue() ;
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
			csFormat =_T("%0.3lf");
			cS.Format(csFormat, value);
			bItsCoolDude = true;
			break;
		case ValueUnits::MICROSECONDS:
			value = GetValue(CValue::ValueUnits::MICROSECONDS) * 1.0e6;
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

void CRiseTime::Print()
{
	printf("\tRise Time: %lf seconds\n", GetValue(ValueUnits::SECONDS));
}

