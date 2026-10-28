#pragma once

class CInches : public CValue
{
public:
	CInches();
	virtual ~CInches();
	//-----------------------------------
	// Pure Virtual Functions from CValue
	//-----------------------------------
	virtual void SetValue(double value, ValueUnits vuUnits) override;
	virtual bool HasValidUnits(ValueUnits vuUnits) override;
	virtual double GetValue(ValueUnits vuUnits) override;
	virtual bool GetString(CString& cS, ValueUnits vuUnits) override;
};

