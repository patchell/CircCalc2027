#pragma once

class CValue
{
public:
	enum class ValueState
	{
		NOTSET,
		SET,
		UPDATE
	};
	enum class ValueUnits
	{
		NONE,
		FARADS,
		PICO_FARADS,
		INCHES,
		HENRYS,
		MICROHENRYS,
		OHMS,
		TURNS,
		TURNS_PER_INCH,
		HERTZ,
		SECONDS
	};
private:
	ValueState m_ValueState;
	double m_Value;
public:
	CValue();
	virtual ~CValue();
	double GetValue() const { return m_Value; }
	void SetValue(double value) { m_Value = value; }
	//-----------------------------------
	// Pure Virtual Functions
	//-----------------------------------
	virtual void SetValue(double value, ValueUnits vuUnits) = 0;
	virtual bool HasValidUnits(ValueUnits vuUnits) = 0;
	virtual double GetValue(ValueUnits vuUnits) = 0;
	virtual char* GetString(CString& cS, ValueUnits vuUnits) = 0;
	//-----------------------------------
	virtual void SetState(ValueState state) { m_ValueState = state; }
	virtual ValueState GetState() const { return m_ValueState; };
	virtual bool IsSet() const { return m_ValueState == ValueState::SET; };
	virtual bool IsNotSet() const { return m_ValueState == ValueState::NOTSET; };
	virtual bool IsUpdate() const { return m_ValueState == ValueState::UPDATE; };
	virtual void Clr() { m_Value = 0.0; m_ValueState = ValueState::NOTSET; }
};

