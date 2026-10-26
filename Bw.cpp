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

char* CBw::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	char* pS = NULL;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::HERTZ:
			if (modf(value, NULL) == 0.0)
			{
				csFormat = "%0.0f";
			}
			else
			{
				csFormat = "%0.3f";
			}
			cS.Format(csFormat, value);
			pS = CT2A(cS);
			break;
		}
	}
	return pS;
}
