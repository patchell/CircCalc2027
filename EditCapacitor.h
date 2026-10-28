#pragma once


// CEditCapacitor

class CEditCapacitor : public CEditParam
{
	DECLARE_DYNAMIC(CEditCapacitor)
public:
	CEditCapacitor();
	virtual ~CEditCapacitor();
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


