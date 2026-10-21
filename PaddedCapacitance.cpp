#include "pch.h"

CPaddedCapacitance::CPaddedCapacitance()
{
	m_HighBaseCapacitance = 0.0;
	m_LowBaseCapacitance = 0.0;
	m_ParallelPadCapacitance = 0.0;
	m_SeriesPadCapacitance = 0.0;
	m_OverallParallelCapacitance = 0.0;
}

CPaddedCapacitance::~CPaddedCapacitance()
{
}

bool CPaddedCapacitance::Create(
	double LowBaseCapacitance, 
	double HighBaseCapacitance, 
	double ParallelPadCapacitance, 
	double SeriesPadCapacitance, 
	double OverallParallelCapacitancee,
	unsigned UseCapacitor
)
{
	m_LowBaseCapacitance = LowBaseCapacitance;
	m_HighBaseCapacitance = HighBaseCapacitance;
	m_ParallelPadCapacitance = ParallelPadCapacitance;
	m_SeriesPadCapacitance = SeriesPadCapacitance;
	m_OverallParallelCapacitance = OverallParallelCapacitancee;
	m_UseCapacitor = UseCapacitor;
	return false;
}

double CPaddedCapacitance::CalculateCapacitance()
{
	//----------------------
	// Calculate the parallel
	// series parallel
	// capacitance of
	// ((C || m_ParallelPadCapacitance) Series(m_SeriesPadCapacitance)) || m_OverallParallelCapacitance
	//----------------------
	double C = 0.0;
	unsigned Mask = 0;

	for (int i = 0; i < 5; i++)
	{
		Mask = m_State[i];
		switch (m_UseCapacitor & Mask)
		{
		case USE_LOW_BASE_CAPACITANCE:
			C = m_LowBaseCapacitance;
			break;
		case USE_HIGH_BASE_CAPACITANCE:
			C = m_HighBaseCapacitance;
			break;
		case USE_PARALLEL_PAD_CAPACITANCE:
			C = CalculateParallelCapacitance(C, m_ParallelPadCapacitance);
			break;
		case USE_SERIES_PAD_CAPACITANCE:
			C = CalculateSeriesCapacitance(C, m_SeriesPadCapacitance);
			break;
		case USE_OVERALL_PARALLEL_CAPACITANCE:
			C = CalculateParallelCapacitance(C, m_OverallParallelCapacitance);
			break;
		default:
			break;
		}
	}
	return C;
}

double CPaddedCapacitance::CalculateParallelCapacitance(double C1, double C2)
{
	double capacitance = C1 + C2;
	return capacitance;
}

double CPaddedCapacitance::CalculateSeriesCapacitance(double C1, double C2)
{
	double capacitance = (C1 * C2) / (C1 + C2);
	return capacitance;
}
