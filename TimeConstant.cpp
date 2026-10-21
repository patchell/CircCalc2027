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
		CValue::SetState(ValueState::SET);
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
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

char* CTimeConstant::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	char* pS = nullptr;
	CString csFormat;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
			value = GetValue();
			break;
		}
		if (modf(value, NULL) == 0.0)
			cS.Format(_T("%0.0lf"), value);
		else
			csFormat.Format(_T("%0.3lf"), value);
		cS.Format(csFormat, value);
		pS = CT2A(cS);
	}
	else
	{
		cS.Empty();
	}
	return pS;
}
