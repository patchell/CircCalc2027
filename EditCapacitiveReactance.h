#pragma once


// CEditCapacitiveReactance

class CEditCapacitiveReactance : public CEditParam
{
	DECLARE_DYNAMIC(CEditCapacitiveReactance)

public:
	CEditCapacitiveReactance();
	virtual ~CEditCapacitiveReactance();
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


