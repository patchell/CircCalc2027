// EditBW.cpp : implementation file
//

#include "pch.h"


// CEditBW

IMPLEMENT_DYNAMIC(CEditBW, CEditParam)

CEditBW::CEditBW()
{

}

CEditBW::~CEditBW()
{
}

void CEditBW::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditBW::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

void CEditBW::UpdateText()
{
	// TODO: Add your implementation code here
}


BEGIN_MESSAGE_MAP(CEditBW, CEditParam)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditBW::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditBW::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditBW::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditBW message handlers



void CEditBW::OnEnChange()
{
}

void CEditBW::OnEnKillfocus()
{
	// TODO: Add your control notification handler code here
}

void CEditBW::OnEnSetfocus()
{
	// TODO: Add your control notification handler code here
}
