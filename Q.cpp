#include "pch.h"

CQ::CQ()
{
}

CQ::~CQ()
{
}

void CQ::SetValue(double value, ValueUnits vuUnits)
{
	if (IsSet() && HasValidUnits(vuUnits))
	{
		CValue::SetState(ValueState::SET);
		CValue::SetValue(value);
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CQ::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
	case ValueUnits::NONE:
		bUnitsAreValid = true;
		break;
	}
	return bUnitsAreValid;
}

double CQ::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::NONE:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

char* CQ::GetString(CString& cS, ValueUnits vuUnits)
{
	char* pS = nullptr;
	double value = 0.0;
	CString csFormat;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::NONE:
			value = CValue::GetValue();
			if (modf(value, NULL) == 0.0)
			{
				csFormat = _T("%0.0lf");
			}
			else
			{
				csFormat = _T("%0.2lf");
			}
			cS.Format(csFormat, value);
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
