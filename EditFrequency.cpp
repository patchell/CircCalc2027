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



// CEditFrequency message handlers



void CEditFrequency::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{}

void CEditFrequency::ConvertUnits(CValue::ValueUnits Units)
{}

void CEditFrequency::UpdateText()
{}

void CEditFrequency::UpdateValue()
{}

void CEditFrequency::OnEnChange()
{
}

void CEditFrequency::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditFrequency::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
