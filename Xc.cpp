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
		printf("\t\t->CXc::SetValue: value = %lf, vuUnits = %d\n", value, static_cast<int>(vuUnits));
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

bool CXc::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	double intpart = 0.0;
	CString csFormat;
	bool bItsCoolDude = false;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			value = CValue::GetValue();
			if (modf(value, &intpart) == 0.0)
			{
				csFormat = _T("%0.0lf");
			}
			else
			{
				csFormat = _T("%0.0lf");
			}
			cS.Format(csFormat, value);
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

void CXc::Print()
{
	printf("\tCapacitive Reactance: %lf Ohms\n", GetValue(ValueUnits::OHMS));
}
