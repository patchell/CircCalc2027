#pragma once

#define USE_LOW_BASE_CAPACITANCE 1
#define USE_HIGH_BASE_CAPACITANCE 2
#define USE_PARALLEL_PAD_CAPACITANCE 4
#define USE_SERIES_PAD_CAPACITANCE 8
#define USE_OVERALL_PARALLEL_CAPACITANCE 16

class CPaddedCapacitance : public CCalculation
{
	CCapacitor m_LowBaseCapacitance;
	CCapacitor m_HighBaseCapacitance;
	CCapacitor m_ParallelPadCapacitance;
	CCapacitor m_SeriesPadCapacitance;
	CCapacitor m_OverallParallelCapacitance;
	unsigned m_UseCapacitor;
	inline static unsigned m_State[5] = { 
		USE_LOW_BASE_CAPACITANCE, 
		USE_HIGH_BASE_CAPACITANCE, 
		USE_PARALLEL_PAD_CAPACITANCE, 
		USE_SERIES_PAD_CAPACITANCE, 
		USE_OVERALL_PARALLEL_CAPACITANCE 
	};
public:
	CPaddedCapacitance();
	virtual ~CPaddedCapacitance();
	bool Create(
		double LowBaseCapacitance, 
		double HighBaseCapacitance, 
		double ParallelPadCapacitance, 
		double SeriesPadCapacitance, 
		double OverallParallelCapacitance,
		unsigned UseCapacitor
	);
	virtual double CalculateCapacitance();
	double CalculateParallelCapacitance(double C1, double C2);
	double CalculateSeriesCapacitance(double C1, double C2);

	void SetLowBaseCapacitance(double C, CValue::ValueUnits VU) { m_LowBaseCapacitance.SetValue(C, VU); }
	void SetHighBaseCapacitance(double C, CValue::ValueUnits VU) { m_HighBaseCapacitance.SetValue(C, VU); }
	void SetParallelPadCapacitance(double C, CValue::ValueUnits VU) { m_ParallelPadCapacitance.SetValue(C, VU); }
	void SetSeriesPadCapacitance(double C, CValue::ValueUnits VU) { m_SeriesPadCapacitance.SetValue(C, VU); }
	void SetOverallParallelCapacitance(double C, CValue::ValueUnits VU) { m_OverallParallelCapacitance.SetValue(C, VU); }

	double GetLowBaseCapacitance(CValue::ValueUnits VU)  { return m_LowBaseCapacitance.GetValue(VU); }
	double GetHighBaseCapacitance(CValue::ValueUnits VU)  { return m_HighBaseCapacitance.GetValue(VU); }
	double GetParallelPadCapacitance(CValue::ValueUnits VU)  { return m_ParallelPadCapacitance.GetValue(VU); }
	double GetSeriesPadCapacitance(CValue::ValueUnits VU)  { return m_SeriesPadCapacitance.GetValue(VU); }
	double GetOverallParallelCapacitance(CValue::ValueUnits VU)  { return m_OverallParallelCapacitance.GetValue(VU); }
};

