#include "pch.h"

CValue::CValue()
{
	m_Value = 0.0;
	m_ValueState = ValueState::NOTSET;

}

inline CValue::~CValue()
{
}
