// EditFrequency.cpp : implementation file
//

#include "pch.h"


// CEditFrequency

IMPLEMENT_DYNAMIC(CEditFrequency, CEditParam)

CEditFrequency::CEditFrequency()
{

}

CEditFrequency::~CEditFrequency()
{
}


BEGIN_MESSAGE_MAP(CEditFrequency, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditFrequency::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditFrequency::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditFrequency::OnEnSetfocus)
END_MESSAGE_MAP()


void CEditFrequency::ConvertUnits(CValue::ValueUnits Units)
{
}

// CEditFrequency message handlers

void CEditFrequency::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditFrequency::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditFrequency::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
