#pragma once

#define USE_LOW_BASE_CAPACITANCE 1
#define USE_HIGH_BASE_CAPACITANCE 2
#define USE_PARALLEL_PAD_CAPACITANCE 4
#define USE_SERIES_PAD_CAPACITANCE 8
#define USE_OVERALL_PARALLEL_CAPACITANCE 16

class CPaddedCapacitance
{
	double m_LowBaseCapacitance;
	double m_HighBaseCapacitance;
	double m_ParallelPadCapacitance;
	double m_SeriesPadCapacitance;
	double m_OverallParallelCapacitance;
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

	void SetLowBaseCapacitance(double C) { m_LowBaseCapacitance = C; }
	void SetHighBaseCapacitance(double C) { m_HighBaseCapacitance = C; }
	void SetParallelPadCapacitance(double C) { m_ParallelPadCapacitance = C; }
	void SetSeriesPadCapacitance(double C) { m_SeriesPadCapacitance = C; }
	void SetOverallParallelCapacitance(double C) { m_OverallParallelCapacitance = C; }

	double GetLowBaseCapacitance() const { return m_LowBaseCapacitance; }
	double GetHighBaseCapacitance() const { return m_HighBaseCapacitance; }
	double GetParallelPadCapacitance() const { return m_ParallelPadCapacitance; }
	double GetSeriesPadCapacitance() const { return m_SeriesPadCapacitance; }
	double GetOverallParallelCapacitance() const { return m_OverallParallelCapacitance; }
};

