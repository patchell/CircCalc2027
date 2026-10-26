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
	virtual CValue* GetValue() { return m_pcvValue; }
	virtual void SetValueUnits(CValue::ValueUnits Units) { m_ValueUnits = Units; }
	virtual void SetName(const char* pName);
	virtual char* GetName() { return m_pName; }
	//-----------------------------------
	// Pure Virtual Functions
	//-----------------------------------
	virtual void SetValue(CValue* pcvValue, CValue::ValueUnits Units) = 0;
	virtual void ConvertUnits(CValue::ValueUnits Units) = 0;
	virtual void UpdateText() = 0;
	virtual void UpdateValue() = 0;
protected:
	DECLARE_MESSAGE_MAP()
};

