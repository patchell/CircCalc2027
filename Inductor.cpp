#include "pch.h"

CInductor::CInductor()
{
}

CInductor::~CInductor()
{
}

void CInductor::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HENRYS:
			CValue::SetValue(value);
			break;
		case ValueUnits::MICROHENRYS:
			CValue::SetValue(value * 1.0e-6);
			break;
		}
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CInductor::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
	case ValueUnits::HENRYS:
	case ValueUnits::MICROHENRYS:
		bUnitsAreValid = true;
		break;
	}
	return bUnitsAreValid;
}

double CInductor::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HENRYS:
			value = CValue::GetValue();
			break;
		case ValueUnits::MICROHENRYS:
			value = CValue::GetValue() * 1e6;
			break;
		}
	}
	return value;
}

bool CInductor::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;

	bool bItsCoolDude = false;
	if (IsSet() && HasValidUnits(vuUnits))
	{
		value = GetValue(vuUnits);
		switch (vuUnits)
		{
		case ValueUnits::HENRYS:
			if (value > 100.0)
			{
				cS.Format(_T("%0.0lf"), value);
			}
			else
			{
				cS.Format(_T("%2.3le"), value);
			}
			cS.Format(_T("%0.6lf"), value);
			bItsCoolDude = true;
			break;
		case ValueUnits::MICROHENRYS:
			if (value > 100.0)
			{
				cS.Format(_T("%0.0lf"), value);
			}
			else if (value < 100.0 && value > 10.0)
			{
				cS.Format(_T("%0.1lf"), value);
			}
			else if (value < 10.0 && value > 1.0)
			{
				cS.Format(_T("%0.2lf"), value);
			}
			else
			{
				cS.Format(_T("%2.3le"), value);
			}
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
