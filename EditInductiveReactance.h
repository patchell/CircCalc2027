#pragma once


// CEditInductiveReactance

class CEditInductiveReactance : public CEditParam
{
	DECLARE_DYNAMIC(CEditInductiveReactance)

public:
	CEditInductiveReactance();
	virtual ~CEditInductiveReactance();
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


