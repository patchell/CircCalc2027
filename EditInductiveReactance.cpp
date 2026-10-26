// EditInductiveReactance.cpp : implementation file
//

#include "pch.h"


// CEditInductiveReactance

IMPLEMENT_DYNAMIC(CEditInductiveReactance, CEditParam)

CEditInductiveReactance::CEditInductiveReactance()
{

}

CEditInductiveReactance::~CEditInductiveReactance()
{
}


BEGIN_MESSAGE_MAP(CEditInductiveReactance, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditInductiveReactance::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditInductiveReactance::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditInductiveReactance::OnEnSetfocus)
END_MESSAGE_MAP()

void CEditInductiveReactance::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{


}

void CEditInductiveReactance::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditInductiveReactance::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditInductiveReactance::UpdateValue()
{}


// CEditInductiveReactance message handlers



void CEditInductiveReactance::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditInductiveReactance::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditInductiveReactance::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
