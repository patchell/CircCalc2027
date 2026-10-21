#pragma once

class CTurns : public CValue
{
public:
	CTurns();
	~CTurns();
	//-----------------------------------
	// Pure Virtual Functions from CValue
	//-----------------------------------
	void SetValue(double value, ValueUnits vuUnits) override;
	bool HasValidUnits(ValueUnits vuUnits) override;
	double GetValue(ValueUnits vuUnits) override;
	char* GetString(CString& cS, ValueUnits vuUnits) override;
};

