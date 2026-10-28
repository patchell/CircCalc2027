#pragma once


// CEditSeconds

class CEditSeconds : public CEditParam
{
	DECLARE_DYNAMIC(CEditSeconds)

public:
	CEditSeconds();
	virtual ~CEditSeconds();
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


