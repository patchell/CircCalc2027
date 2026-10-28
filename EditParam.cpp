#include "pch.h"

IMPLEMENT_DYNAMIC(CEditParam, CEdit)

CEditParam::CEditParam()
{
	m_pcvValue = 0;
	m_pName = 0;
	m_ValueUnits = CValue::ValueUnits::NONE;
//	printf("CEditParam::CEditParam()\n");
}

CEditParam::~CEditParam()
{
	if (m_pName) delete[] m_pName;
}

BEGIN_MESSAGE_MAP(CEditParam, CEdit)
	ON_CONTROL_REFLECT(EN_CHANGE, &CEditParam::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditParam::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditParam::OnEnSetfocus)
END_MESSAGE_MAP()


void CEditParam::SetName(const char* pName)
{
	int l = strlen(pName) + 1;

	m_pName = new char[l];
	strcpy_s(m_pName, l, pName);
}

void CEditParam::SetValue(CValue* pcvValue, CValue::ValueUnits Units)
{
	if (!pcvValue->HasValidUnits(Units))
	{
		AfxMessageBox(L"Invalid Units for Capacitive Reactance", MB_ICONHAND);
	}
	else
	{
		SetValuePtr(pcvValue);
		SetValueUnits(Units);
	}
}

void CEditParam::UpdateText()
{
	CString cS;

	if (GetValuePtr()->GetString(cS, GetValueUnits()))
	{
		SetWindowTextW(cS);
	}
}

void CEditParam::UpdateValue()
{
	CString cS;

	GetWindowTextW(cS);
	GetValuePtr()->SetValue(_ttof(cS), GetValueUnits());
}

void CEditParam::OnEnChange()
{
	UpdateValue();
}

void CEditParam::OnEnKillfocus()
{
	GetValuePtr()->SetState(CValue::ValueState::SET);
}

void CEditParam::OnEnSetfocus()
{
	GetValuePtr()->SetState(CValue::ValueState::UPDATE);
}
