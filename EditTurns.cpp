// EditTurns.cpp : implementation file
//

#include "pch.h"


// CEditTurns

IMPLEMENT_DYNAMIC(CEditTurns, CEditParam)

CEditTurns::CEditTurns()
{

}

CEditTurns::~CEditTurns()
{
}


BEGIN_MESSAGE_MAP(CEditTurns, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditTurns::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditTurns::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditTurns::OnEnSetfocus)
END_MESSAGE_MAP()



void CEditTurns::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditTurns::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditTurns::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditTurns::UpdateValue()
{}


// CEditTurns message handlers



void CEditTurns::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditTurns::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditTurns::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
