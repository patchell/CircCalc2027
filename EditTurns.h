#pragma once


// CEditTurns

class CEditTurns : public CEditParam
{
	DECLARE_DYNAMIC(CEditTurns)

public:
	CEditTurns();
	virtual ~CEditTurns();
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


