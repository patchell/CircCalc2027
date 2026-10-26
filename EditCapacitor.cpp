// EditCapacitor.cpp : implementation file
//

#include "pch.h"


// CEditCapacitor

IMPLEMENT_DYNAMIC(CEditCapacitor, CEditParam)

void CEditCapacitor::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{}

void CEditCapacitor::ConvertUnits(CValue::ValueUnits Units)
{}

void CEditCapacitor::UpdateText()
{}

void CEditCapacitor::UpdateValue()
{}

CEditCapacitor::CEditCapacitor()
{

}

CEditCapacitor::~CEditCapacitor()
{
}


BEGIN_MESSAGE_MAP(CEditCapacitor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditCapacitor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditCapacitor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditCapacitor::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditCapacitor message handlers



void CEditCapacitor::OnEnChange()
{
    // TODO:  If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CEdit::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO:  Add your control notification handler code here
}

void CEditCapacitor::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditCapacitor::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
