// EditTurns.cpp : implementation file
//

#include "pch.h"


// CEditTurns

IMPLEMENT_DYNAMIC(CEditTurns, CEditParam)

CEditTurns::CEditTurns()
{

}

CEditTurns::~CEditTurns()
{
}


BEGIN_MESSAGE_MAP(CEditTurns, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditTurns::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditTurns::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditTurns::OnEnSetfocus)
END_MESSAGE_MAP()



void CEditTurns::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

// CEditTurns message handlers



void CEditTurns::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditTurns::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();		
}

void CEditTurns::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
