// EditCapacitiveReactance.cpp : implementation file
//

#include "pch.h"


// CEditCapacitiveReactance

IMPLEMENT_DYNAMIC(CEditCapacitiveReactance, CEditParam)

CEditCapacitiveReactance::CEditCapacitiveReactance()
{

}

CEditCapacitiveReactance::~CEditCapacitiveReactance()
{
}


BEGIN_MESSAGE_MAP(CEditCapacitiveReactance, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditCapacitiveReactance::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditCapacitiveReactance::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditCapacitiveReactance::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditCapacitiveReactance message handlers


void CEditCapacitiveReactance::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditCapacitiveReactance::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditCapacitiveReactance::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditCapacitiveReactance::UpdateValue()
{}

void CEditCapacitiveReactance::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditCapacitiveReactance::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditCapacitiveReactance::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
