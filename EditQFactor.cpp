// EditQFactor.cpp : implementation file
//

#include "pch.h"

// CEditQFactor

IMPLEMENT_DYNAMIC(CEditQFactor, CEdit)

CEditQFactor::CEditQFactor()
{

}

CEditQFactor::~CEditQFactor()
{
}

void CEditQFactor::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{}

void CEditQFactor::ConvertUnits(CValue::ValueUnits Units)
{}

void CEditQFactor::UpdateText()
{}

void CEditQFactor::UpdateValue()
{}


BEGIN_MESSAGE_MAP(CEditQFactor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditQFactor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditQFactor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditQFactor::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditQFactor message handlers



void CEditQFactor::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditQFactor::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditQFactor::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
