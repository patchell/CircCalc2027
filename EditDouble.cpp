// EditDouble.cpp : implementation file
//

#include "pch.h"
#include "CircCalc2027.h"
#include "EditDouble.h"


// CEditDouble

IMPLEMENT_DYNAMIC(CEditDouble, CEdit)

CEditDouble::CEditDouble()
{

}

CEditDouble::~CEditDouble()
{
}

void CEditDouble::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{}

void CEditDouble::ConvertUnits(CValue::ValueUnits Units)
{}

void CEditDouble::UpdateText()
{}

void CEditDouble::UpdateValue()
{}


BEGIN_MESSAGE_MAP(CEditDouble, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditDouble::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditDouble::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditDouble::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditDouble message handlers



void CEditDouble::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditDouble::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditDouble::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
