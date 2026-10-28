// EditInductor.cpp : implementation file
//

#include "pch.h"


// CEditInductor

IMPLEMENT_DYNAMIC(CEditInductor, CEditParam)

CEditInductor::CEditInductor()
{

}

CEditInductor::~CEditInductor()
{
}


BEGIN_MESSAGE_MAP(CEditInductor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditInductor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditInductor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditInductor::OnEnSetfocus)
END_MESSAGE_MAP()

void CEditInductor::ConvertUnits(CValue::ValueUnits Units)
{

}


// CEditInductor message handlers



void CEditInductor::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditInductor::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditInductor::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
