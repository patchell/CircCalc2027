#pragma once


// CEditTurnsPerInch

class CEditTurnsPerInch : public CEditParam
{
	DECLARE_DYNAMIC(CEditTurnsPerInch)

public:
	CEditTurnsPerInch();
	virtual ~CEditTurnsPerInch();
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


