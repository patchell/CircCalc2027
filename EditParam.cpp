#include "pch.h"

CEditParam::CEditParam()
{
	m_WM_MSG = 0;
	m_fValue = 0.0;
	m_pName = 0;

}

CEditParam::~CEditParam()
{
	if (m_pName) delete[] m_pName;
}

/*double CEditParam::GetValue()
{
	wchar_t* s = new wchar_t[256];
	GetWindowTextW(s, 256);
	m_fValue = _wtof(s);
	delete[] s;	
	return m_fValue;
}*/

/*void CEditParam::SetValue(double fValue)
{
	m_fValue = fValue;
	wchar_t* s = new wchar_t[256];
	swprintf_s(s, 256, L"%lf", m_fValue);
	SetWindowTextW(s);
	delete[] s;
}*/


BEGIN_MESSAGE_MAP(CEditParam, CEdit)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CEditParam::OnEnKillfocus)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CEditParam::OnEnSetfocus)
END_MESSAGE_MAP()

void CEditParam::OnEnKillfocus()
{
	printf("Lost Focus %s\n", m_pName);
	UINT nID = GetDlgCtrlID();
	GetParent()->PostMessageW(m_WM_MSG, nID, nID);
}

void CEditParam::SetName(const char* pName)
{
	int l = strlen(pName) + 1;

	m_pName = new char[l];
	strcpy_s(m_pName, l, pName);
}

void CEditParam::OnEnSetfocus()
{
	printf("Got Focus %s\n", m_pName);
}
