// EditInches.cpp : implementation file
//

#include "pch.h"


// CEditInches

IMPLEMENT_DYNAMIC(CEditInches, CEditParam)

CEditInches::CEditInches()
{

}

CEditInches::~CEditInches()
{
}

void CEditInches::ConvertUnits(CValue::ValueUnits Units)
{
}

BEGIN_MESSAGE_MAP(CEditInches, CEditParam)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditInches::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditInches::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditInches::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditInches message handlers



void CEditInches::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditInches::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditInches::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
