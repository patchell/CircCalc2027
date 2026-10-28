#include "pch.h"

CResistor::CResistor()
{
}

CResistor::~CResistor()
{
}

void CResistor::SetValue(double value, ValueUnits vuUnits)
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

bool CResistor::HasValidUnits(ValueUnits vuUnits)
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

double CResistor::GetValue(ValueUnits vuUnits)
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

bool CResistor::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	double dbIntPart;
	bool bItsCoolDude = false;

	CString csFormat;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			value = CValue::GetValue();
			if (modf(value, &dbIntPart) == 0.0)
			{
				csFormat = _T("%0.0lf");
			}
			else
			{
				csFormat = _T("%0.3lf");
			}
			cS.Format(csFormat, GetValue(vuUnits));
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

void CResistor::Print()
{
	printf("\tResistor: %lf Ohms\n", GetValue(ValueUnits::OHMS));
}

