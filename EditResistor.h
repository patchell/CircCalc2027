#pragma once


// CEditResistor

class CEditResistor : public CEditParam
{
	DECLARE_DYNAMIC(CEditResistor)

public:
	CEditResistor();
	virtual ~CEditResistor();
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


