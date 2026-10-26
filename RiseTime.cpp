#include "pch.h"

CRiseTime::CRiseTime()
{
}

CRiseTime::~CRiseTime()
{
}

void CRiseTime::SetValue(double value, ValueUnits vuUnits)
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

bool CRiseTime::HasValidUnits(ValueUnits vuUnits)
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

double CRiseTime::GetValue(ValueUnits vuUnits)
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

char* CRiseTime::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	char* pS = nullptr;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::SECONDS:
			value = CValue::GetValue();
			if (modf(value, NULL) == 0.0)
			{
				csFormat = _T("%0.0lf");
			}
			else
			{
				csFormat =_T("%0.3lf");
			}
			cS.Format(csFormat, value);
			break;
		}
	}
	else
		cS.Empty();
	pS = CT2A(cS);
	return pS;
}

void CRiseTime::Print()
{
	printf("Rise Time: %lf seconds\n", GetValue(ValueUnits::SECONDS));
}

