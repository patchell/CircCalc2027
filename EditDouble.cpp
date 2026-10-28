// EditDouble.cpp : implementation file
//

#include "pch.h"
#include "CircCalc2027.h"
#include "EditDouble.h"


// CEditDouble

IMPLEMENT_DYNAMIC(CEditDouble, CEdit)

CEditDouble::CEditDouble()
{

}

CEditDouble::~CEditDouble()
{
}

void CEditDouble::ConvertUnits(CValue::ValueUnits Units)
{
}

BEGIN_MESSAGE_MAP(CEditDouble, CEdit)
    ON_CONTROL_REFLECT(EN_CHANGE, &CEditDouble::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditDouble::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditDouble::OnEnSetfocus)
END_MESSAGE_MAP()



// CEditDouble message handlers



void CEditDouble::OnEnChange()
{
//	UpdateValue();
}

void CEditDouble::OnEnKillfocus()
{
//	GetValuePtr()->SetState(CValue::ValueState::SET);
}

void CEditDouble::OnEnSetfocus()
{
//	GetValuePtr()->SetState(CValue::ValueState::UPDATE);
}
