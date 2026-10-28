#include "pch.h"

CBw::CBw()
{}

CBw::~CBw()
{}

void CBw::SetValue(double value, ValueUnits vuUnits)
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

bool CBw::HasValidUnits(ValueUnits vuUnits)
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

double CBw::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HERTZ:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

bool CBw::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	double dbIntPart = 0.0;
	bool bItsCoolDude = false;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::HERTZ:
			if (modf(value, &dbIntPart) == 0.0)
			{
				csFormat = "%0.0f";
			}
			else
			{
				csFormat = "%0.3f";
			}
			cS.Format(csFormat, value);
			bItsCoolDude = true;
			break;
		}
	}
	return bItsCoolDude;
}
