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

BEGIN_MESSAGE_MAP(CEditBW, CEditParam)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditBW::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditBW::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditBW::OnEnSetfocus)
END_MESSAGE_MAP()


void CEditBW::ConvertUnits(CValue::ValueUnits Units)
{
}


// CEditBW message handlers



void CEditBW::OnEnChange()
{
	CEditParam::OnEnChange();
}

void CEditBW::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditBW::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
