#include "pch.h"

CSuperHetTuning::CSuperHetTuning()
{
	m_LocalOscillatorInductance = 0.0;
	m_RFInputInductance = 0.0;
	m_HighFrequency = 0.0;
	m_LowFrequency = 0.0;
	m_TuningTolerance = 0.0;
	m_IfFrequency = 0.0;
	m_TuningCapacitanceLow = 0.0;
	m_TuningCapacitanceHigh = 0.0;
	m_MaxError = 0.0;
	m_MinError = 0.0;
}

CSuperHetTuning::~CSuperHetTuning()
{
}

double CSuperHetTuning::CalculateResonantFrequency(
	double TuningCapacitance, 
	double Inductance, 
	double frequency, 
	CPaddedCapacitance& PadCapacitors
)
{
    return 0.0;
}

bool CSuperHetTuning::OptimizeTuningCapacitance(int MaxIterations)
{
	bool success = false;

	return success;
}

double CSuperHetTuning::SweepTuning(int Iterations)
{
	return 0.0;
}
