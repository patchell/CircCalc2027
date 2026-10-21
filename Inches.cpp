#include "pch.h"

CInches::CInches():CValue()
{
}

CInches::~CInches()
{
}

void CInches::SetValue(double value, ValueUnits vuUnits)
{}

bool CInches::HasValidUnits(ValueUnits vuUnits)
{
	return false;
}

double CInches::GetValue(ValueUnits vuUnits)
{
	double value = 0.0;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::INCHES:
			value = CValue::GetValue();
			break;
		}
	}
	return value;
}

char* CInches::GetString(CString& cS, ValueUnits vuUnits)
{
	char* pS = nullptr;

	if (IsSet() && HasValidUnits(vuUnits))
	{
		switch (vuUnits)
		{
		case ValueUnits::INCHES:
			cS.Format(_T("%0.3lf"), GetValue());
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
