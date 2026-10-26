// EditInductor.cpp : implementation file
//

#include "pch.h"


// CEditInductor

IMPLEMENT_DYNAMIC(CEditInductor, CEditParam)

CEditInductor::CEditInductor()
{

}

CEditInductor::~CEditInductor()
{
}


BEGIN_MESSAGE_MAP(CEditInductor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditInductor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditInductor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditInductor::OnEnSetfocus)
END_MESSAGE_MAP()

void CEditInductor::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditInductor::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditInductor::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditInductor::UpdateValue()
{}


// CEditInductor message handlers



void CEditInductor::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditInductor::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditInductor::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
