// EditSeconds.cpp : implementation file
//

#include "pch.h"


// CEditSeconds

IMPLEMENT_DYNAMIC(CEditSeconds, CEditParam)

CEditSeconds::CEditSeconds()
{

}

CEditSeconds::~CEditSeconds()
{
}


BEGIN_MESSAGE_MAP(CEditSeconds, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditSeconds::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditSeconds::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditSeconds::OnEnSetfocus)
END_MESSAGE_MAP()



void CEditSeconds::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditSeconds::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditSeconds::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditSeconds::UpdateValue()
{}


// CEditSeconds message handlers



void CEditSeconds::OnEnChange()
{
}

void CEditSeconds::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditSeconds::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
