#pragma once

class CValue;

class CEditParam : public CEdit
{
	char* m_pName;
	CValue* m_pcvValue;
	UINT m_WM_MSG;
public:
	CEditParam();
	virtual ~CEditParam();
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CValue* GetValue() { return m_pcvValue; }
	void SetValue(CValue* pcvValue) { m_pcvValue = pcvValue; }
	void SetWMMessage(UINT WM_Msg) { m_WM_MSG = WM_Msg; }
	void SetName(const char* pName);
	char* GetName() { return m_pName; }
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnEnSetfocus();
	afx_msg void OnEnKillfocus();
public:
//	virtual HRESULT get_accFocus(VARIANT* pvarChild);
};

