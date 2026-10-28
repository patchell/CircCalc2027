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

void CEditInductiveReactance::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}


// CEditInductiveReactance message handlers



void CEditInductiveReactance::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditInductiveReactance::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditInductiveReactance::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
