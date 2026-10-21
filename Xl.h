#pragma once

class CXl :public CValue
{
public:
	CXl();
	virtual ~CXl();
	//-----------------------------------
	// Pure Virtual Functions from CValue
	//-----------------------------------
	virtual void SetValue(double value, ValueUnits vuUnits) override;
	virtual bool HasValidUnits(ValueUnits vuUnits) override;
	virtual double GetValue(ValueUnits vuUnits) override;
	virtual char* GetString(CString& cS, ValueUnits vuUnits) override;
};

