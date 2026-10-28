// EditSeconds.cpp : implementation file
//

#include "pch.h"


// CEditSeconds

IMPLEMENT_DYNAMIC(CEditSeconds, CEditParam)

CEditSeconds::CEditSeconds()
{

}

CEditSeconds::~CEditSeconds()
{
}


BEGIN_MESSAGE_MAP(CEditSeconds, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditSeconds::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditSeconds::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditSeconds::OnEnSetfocus)
END_MESSAGE_MAP()


void CEditSeconds::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

// CEditSeconds message handlers



void CEditSeconds::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditSeconds::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();	
}

void CEditSeconds::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
