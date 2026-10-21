#include "pch.h"

CXl::CXl()
{
}

CXl::~CXl()
{
}

void CXl::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnits(vuUnits))
	{
		CValue::SetValue(value);
		SetState(ValueState::SET);
	}
}

bool CXl::HasValidUnits(ValueUnits vuUnits)
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

double CXl::GetValue(ValueUnits vuUnits)
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

char* CXl::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	char* pS = NULL;

	if (HasValidUnits(vuUnits) && IsSet())
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			if (modf(value, NULL) == 0.0)
				csFormat = _T("%0.0lf");
			else
				csFormat = _T("%0.3lf");
			cS.Format(csFormat, value);
			pS = CT2A(cS);
			break;
		}
	}
	else
		cS.Empty();
	return pS;
}
