#pragma once


// CEditQFactor

class CEditQFactor : public CEditParam
{
	DECLARE_DYNAMIC(CEditQFactor)

public:
	CEditQFactor();
	virtual ~CEditQFactor();
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


