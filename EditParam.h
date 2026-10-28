#pragma once

class CEditParam : public CEdit
{
	DECLARE_DYNAMIC(CEditParam)
	char* m_pName;
	CValue* m_pcvValue;
	CValue::ValueUnits m_ValueUnits;
public:
	CEditParam();
	virtual ~CEditParam();
	virtual CValue* GetValuePtr() { return m_pcvValue; }
	virtual void SetValuePtr(CValue* pcvValue) { m_pcvValue = pcvValue; }
	virtual void SetValueUnits(CValue::ValueUnits Units) { m_ValueUnits = Units; }
	virtual CValue::ValueUnits GetValueUnits() { return m_ValueUnits; }
	virtual void SetName(const char* pName);
	virtual char* GetName() { return m_pName; }
	//-----------------------------------
	// Not so Pure Virtual Functions
	//-----------------------------------
	virtual void SetValue(CValue* pcvValue, CValue::ValueUnits Units);
	virtual void ConvertUnits(CValue::ValueUnits Units) = 0;
	virtual void UpdateText();
	virtual void UpdateValue();
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChange();
	afx_msg void OnEnKillfocus();
	afx_msg void OnEnSetfocus();
};

