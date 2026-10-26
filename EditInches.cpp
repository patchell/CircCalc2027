// EditInches.cpp : implementation file
//

#include "pch.h"


// CEditInches

IMPLEMENT_DYNAMIC(CEditInches, CEditParam)

CEditInches::CEditInches()
{

}

void CEditInches::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{}

void CEditInches::ConvertUnits(CValue::ValueUnits Units)
{}

void CEditInches::UpdateText()
{}

void CEditInches::UpdateValue()
{}

CEditInches::~CEditInches()
{
}


BEGIN_MESSAGE_MAP(CEditInches, CEditParam)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditInches::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditInches::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditInches::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditInches message handlers



void CEditInches::OnEnChange()
{
}

void CEditInches::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditInches::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
