#include "pch.h"

CResistor::CResistor()
{
}

CResistor::~CResistor()
{
}

void CResistor::SetValue(double value, ValueUnits vuUnits)
{
	if (HasValidUnit	s(vuUnits))
	{
		CValue::SetState(ValueState::SET);
		CValue::SetValue(value);
	}
	else
	{
		CValue::SetState(ValueState::NOTSET);
	}
}

bool CResistor::HasValidUnits(ValueUnits vuUnits)
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

double CResistor::GetValue(ValueUnits vuUnits)
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

char* CResistor::GetString(CString& cS, ValueUnits vuUnits)
{
	char* pS = nullptr;
	double value = 0.0;
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
			cS.Format(csFormat, GetValue());
			break;
		}
		pS = CT2A(cS);
	}
	else
	{
		cS.Empty();
	}
	return nullptr;
}

