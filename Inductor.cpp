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
			CValue::SetState(ValueState::SET);
			CValue::SetValue(value, vuUnits);
			break;
		case ValueUnits::MICRO_HENRYS:
			CValue::SetState(ValueState::SET);
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
	case ValueUnits::MICRO_HENRYS:
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
		case ValueUnits::MICRO_HENRYS:
			value = CValue::GetValue() * 1e6;
			break;
		}
	}
	return value;
}

char* CInductor::GetString(CString& cS, ValueUnits vuUnits)
{
	char* pS = nullptr;

	if (IsSet * () && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::HENRYS:
			cS.Format(_T("%0.6lf"), GetValue(vuUnits));
			break;
		case ValueUnits::MICRO_HENRYS:
			cS.Format(_T("%0.0lf"), GetValue(vuUnits));
			break;
		}
		pS = CT2A(cS);
	}
	else
	{
		cS.Empty();
	}
	return pS;
}
