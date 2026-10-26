#pragma once


// CEditBW

class CEditBW : public CEditParam
{
	DECLARE_DYNAMIC(CEditBW)

public:
	CEditBW();
	virtual ~CEditBW();
	//-----------------------------------
	// Pure Virtual Functions
	//-----------------------------------
	virtual void SetValue(CValue* pcvValue, CValue::ValueUnits Units);
	virtual void ConvertUnits(CValue::ValueUnits Units);
	virtual void UpdateText();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChange();
	afx_msg void OnEnKillfocus();
	afx_msg void OnEnSetfocus();
};


