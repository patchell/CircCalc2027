#include "pch.h"

IMPLEMENT_DYNAMIC(CEditParam, CEdit)

CEditParam::CEditParam()
{
	m_pcvValue = 0;
	m_pName = 0;
	m_ValueUnits = CValue::ValueUnits::NONE;

}

CEditParam::~CEditParam()
{
	if (m_pName) delete[] m_pName;
}

BEGIN_MESSAGE_MAP(CEditParam, CEdit)
END_MESSAGE_MAP()


void CEditParam::SetName(const char* pName)
{
	int l = strlen(pName) + 1;

	m_pName = new char[l];
	strcpy_s(m_pName, l, pName);
}
