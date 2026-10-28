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

bool CXl::GetString(CString& cS, ValueUnits vuUnits)
{
	double value = 0.0;
	CString csFormat;
	double dbIntPart = 0.0;
	bool bItsCoolDude = false;

	if (HasValidUnits(vuUnits) && IsSet())
	{
		value = CValue::GetValue();
		switch (vuUnits)
		{
		case ValueUnits::OHMS:
			if (value < 1.0)
			{
				csFormat = _T("%3.3le");
			}
			else if (value < 10.0)
			{
				csFormat = _T("%0.2lf");
			}
			else
			{
				csFormat = _T("%0.0lf");
			}
			cS.Format(csFormat, value);
			bItsCoolDude = true;
		}
	}
	else
		cS.Empty();
	return bItsCoolDude;
}
