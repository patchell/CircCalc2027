#include "pch.h"

CXc::CXc()
{
}

CXc::~CXc()
{
}

void CXc::SetValue(double value, ValueUnits vuUnits)
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

bool CXc::HasValidUnits(ValueUnits vuUnits)
{
	bool bUnitsAreValid = false;

	switch (vuUnits)
	{
		case ValueUnits::OHMS:
			bUnitsAreValid = true;
			break;
	}
	return bUnitsAreValid	;
}

double CXc::GetValue(ValueUnits vuUnits)
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

char* CXc::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	char* pS = nullptr;
	CString csFormat;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			value = CValue::GetValue();
			if (modf(value, NULL) == 0.0)
			{
				csFormat = _T("%0.0lf");
			}
			else
			{
				csFormat = _T("%0.3lf");
			}
			cS.Format(csFormat, value);
			pS = CT2A(cS);
			break;
		}
	}
	else
	{
		cS.Empty();
	}
	return pS;
}
