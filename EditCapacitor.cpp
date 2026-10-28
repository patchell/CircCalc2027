// EditCapacitor.cpp : implementation file
//

#include "pch.h"


// CEditCapacitor

IMPLEMENT_DYNAMIC(CEditCapacitor, CEditParam)


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


void CEditCapacitor::ConvertUnits(CValue::ValueUnits Units)
{
}

// CEditCapacitor message handlers

void CEditCapacitor::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditCapacitor::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditCapacitor::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
