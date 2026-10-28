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



void CEditCapacitiveReactance::ConvertUnits(CValue::ValueUnits Units)
{
}


// CEditCapacitiveReactance message handlers

void CEditCapacitiveReactance::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditCapacitiveReactance::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditCapacitiveReactance::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
