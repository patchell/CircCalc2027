// EditTurnsPerInch.cpp : implementation file
//

#include "pch.h"


// CEditTurnsPerInch

IMPLEMENT_DYNAMIC(CEditTurnsPerInch, CEditParam)

CEditTurnsPerInch::CEditTurnsPerInch()
{

}

CEditTurnsPerInch::~CEditTurnsPerInch()
{
}


BEGIN_MESSAGE_MAP(CEditTurnsPerInch, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditTurnsPerInch::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditTurnsPerInch::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditTurnsPerInch::OnEnSetfocus)
END_MESSAGE_MAP()

void CEditTurnsPerInch::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

// CEditTurnsPerInch message handlers

void CEditTurnsPerInch::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditTurnsPerInch::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditTurnsPerInch::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
