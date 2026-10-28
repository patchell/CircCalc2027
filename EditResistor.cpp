// EditResistor.cpp : implementation file
//

#include "pch.h"


// CEditResistor

IMPLEMENT_DYNAMIC(CEditResistor, CEditParam)

CEditResistor::CEditResistor()
{

}

CEditResistor::~CEditResistor()
{
}


BEGIN_MESSAGE_MAP(CEditResistor, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditResistor::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditResistor::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditResistor::OnEnSetfocus)
END_MESSAGE_MAP()


void CEditResistor::ConvertUnits(CValue::ValueUnits Units)
{
	// TODO: Add your implementation code here
}

// CEditResistor message handlers



void CEditResistor::OnEnChange()
{

	CEditParam::OnEnChange();

}

void CEditResistor::OnEnKillfocus()
{
	CEditParam::OnEnKillfocus();
}

void CEditResistor::OnEnSetfocus()
{
	CEditParam::OnEnSetfocus();
}
