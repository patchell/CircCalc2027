#pragma once


// CEditCapacitor

class CEditCapacitor : public CEditParam
{
	DECLARE_DYNAMIC(CEditCapacitor)
	//-----------------------------------
	// Pure Virtual Functions
	//-----------------------------------
	virtual void SetValue(CValue* pcvValue, CValue::ValueUnits Units);
	virtual void ConvertUnits(CValue::ValueUnits Units);
	virtual void UpdateText();
	virtual void UpdateValue();
public:
	CEditCapacitor();
	virtual ~CEditCapacitor();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChange();
	afx_msg void OnEnKillfocus();
	afx_msg void OnEnSetfocus();
};


