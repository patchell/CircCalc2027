// EditQFactor.cpp : implementation file
//

#include "pch.h"

// CEditQFactor

IMPLEMENT_DYNAMIC(CEditQFactor, CEditParam)

CEditQFactor::CEditQFactor()
{

}

CEditQFactor::~CEditQFactor()
{
}

void CEditQFactor::ConvertUnits(CValue::ValueUnits Units)
{}


BEGIN_MESSAGE_MAP(CEditQFactor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditQFactor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditQFactor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditQFactor::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditQFactor message handlers


void CEditQFactor::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditQFactor::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditQFactor::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
