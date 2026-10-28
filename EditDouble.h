#pragma once
#include "Value.h"


// CEditDouble

class CEditDouble : public CEdit
{
	DECLARE_DYNAMIC(CEditDouble)

public:
	CEditDouble();
	virtual ~CEditDouble();
	//-----------------------------------
	// Pure Virtual Functions
	//-----------------------------------
	virtual void ConvertUnits(CValue::ValueUnits Units);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChange();
	afx_msg void OnEnKillfocus();
	afx_msg void OnEnSetfocus();
};


