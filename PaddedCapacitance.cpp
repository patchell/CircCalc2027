#include "pch.h"

CPaddedCapacitance::CPaddedCapacitance()
{
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
	m_LowBaseCapacitance.SetValue(LowBaseCapacitance, CValue::ValueUnits::FARADS);
	m_HighBaseCapacitance.SetValue(HighBaseCapacitance, CValue::ValueUnits::FARADS);
	m_ParallelPadCapacitance.SetValue(ParallelPadCapacitance, CValue::ValueUnits::FARADS);
	m_SeriesPadCapacitance.SetValue(SeriesPadCapacitance, CValue::ValueUnits::FARADS);
	m_OverallParallelCapacitance.SetValue(OverallParallelCapacitancee, CValue::ValueUnits::FARADS)	;
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
			C = m_LowBaseCapacitance.GetValue(CValue::ValueUnits::FARADS);
			break;
		case USE_HIGH_BASE_CAPACITANCE:
			C = m_HighBaseCapacitance.GetValue(CValue::ValueUnits::FARADS);
			break;
		case USE_PARALLEL_PAD_CAPACITANCE:
			C = CalculateParallelCapacitance(C, m_ParallelPadCapacitance.GetValue(CValue::ValueUnits::FARADS));
			break;
		case USE_SERIES_PAD_CAPACITANCE:
			C = CalculateSeriesCapacitance(C, m_SeriesPadCapacitance.GetValue(CValue::ValueUnits::FARADS));
			break;
		case USE_OVERALL_PARALLEL_CAPACITANCE:
			C = CalculateParallelCapacitance(C, m_OverallParallelCapacitance.GetValue(CValue::ValueUnits::FARADS));
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
