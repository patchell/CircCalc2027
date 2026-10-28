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

bool CFrequency::GetString(CString& cS, ValueUnits vuUnits)
{
	bool bItsCoolDude = false;
	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HERTZ:
			cS.Format(_T("%0.0lf"), GetValue(vuUnits));
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

void CFrequency::Print()
{
	printf("\tFrequency: %lf Hertz\n", GetValue(ValueUnits::HERTZ));
}
