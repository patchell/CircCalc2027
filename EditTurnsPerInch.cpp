// EditTurnsPerInch.cpp : implementation file
//

#include "pch.h"


// CEditTurnsPerInch

IMPLEMENT_DYNAMIC(CEditTurnsPerInch, CEditParam)

CEditTurnsPerInch::CEditTurnsPerInch()
{

}

CEditTurnsPerInch::~CEditTurnsPerInch()
{
}


BEGIN_MESSAGE_MAP(CEditTurnsPerInch, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditTurnsPerInch::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditTurnsPerInch::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditTurnsPerInch::OnEnSetfocus)
END_MESSAGE_MAP()

void CEditTurnsPerInch::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditTurnsPerInch::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditTurnsPerInch::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditTurnsPerInch::UpdateValue()
{}


// CEditTurnsPerInch message handlers

void CEditTurnsPerInch::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditTurnsPerInch::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditTurnsPerInch::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
