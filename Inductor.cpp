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
	bool bItsCoolDude = false;
	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HENRYS:
			cS.Format(_T("%0.6lf"), GetValue(vuUnits));
			bItsCoolDude = true;
			break;
		case ValueUnits::MICROHENRYS:
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
