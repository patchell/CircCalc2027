#pragma once

class CSuperHetTuning : public CCalculation
{
	CPaddedCapacitance m_LocalOscillatorCapacitance;
	CPaddedCapacitance m_RFInputCapacitance;
	double m_LocalOscillatorInductance;
	double m_RFInputInductance;
	double m_IfFrequency;
	double m_LowFrequency;
	double m_HighFrequency;
	double m_TuningCapacitanceLow;
	double m_TuningCapacitanceHigh;
	double m_TuningTolerance;	// Tolerance in percentage of IF frequency
	double m_TuningTestPoints[5];
	double m_MaxError;
	double m_MinError;
public:
	CSuperHetTuning();
	virtual ~CSuperHetTuning();
	double CalculateResonantFrequency(double TuningCapacitance, double Inductance, double frequency, CPaddedCapacitance& PadCapacitors);
	bool OptimizeTuningCapacitance(int MaxIterations);
	double SweepTuning(int Iterations);
	CPaddedCapacitance* GetLocalOscillatorCapacitance() { return &m_LocalOscillatorCapacitance; }
	CPaddedCapacitance* GetRFInputCapacitance() { return &m_RFInputCapacitance; }
};

