#pragma once

class CResistor : public CValue
{
public:
	CResistor();
	virtual ~CResistor();
	//-----------------------------------
	// Pure Virtual Functions from CValue
	//-----------------------------------
	virtual void SetValue(double value, ValueUnits vuUnits) override;
	virtual bool HasValidUnits(ValueUnits vuUnits) override;
	virtual double GetValue(ValueUnits vuUnits) override;
	virtual bool GetString(CString& cS, ValueUnits vuUnits) override;
	//-----------------------------------
	void Print();
};

