// EditResistor.cpp : implementation file
//

#include "pch.h"


// CEditResistor

IMPLEMENT_DYNAMIC(CEditResistor, CEditParam)

CEditResistor::CEditResistor()
{

}

CEditResistor::~CEditResistor()
{
}


BEGIN_MESSAGE_MAP(CEditResistor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditResistor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditResistor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditResistor::OnEnSetfocus)
END_MESSAGE_MAP()



void CEditResistor::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditResistor::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditResistor::UpdateText()
{
	// TODO: Add your implementation code here
}

void CEditResistor::UpdateValue()
{}


// CEditResistor message handlers



void CEditResistor::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditResistor::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditResistor::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
