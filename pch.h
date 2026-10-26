// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

//----------------------
// Windows Messages
// used by the various
// things that are
// calculated in this
// program.
//----------------------

#define WM_XC (WM_USER + 1)
#define WM_XL (WM_USER + 2)
#define WM_RESONANT (WM_USER + 3)
#define WM_COIL_CALC (WM_USER + 4)
#define WM_SUPERHET_TUNING (WM_USER + 5)

// add headers that you want to pre-compile here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <atlconv.h> // CT2A

#include "framework.h"

#include "resource.h"       // main symbols
#include "afxdialogex.h"

#include "CircCalc2027.h"

//-----------------------------------------
// Values
//-----------------------------------------
#include "Value.h"			// Base Value object

#include "Inches.h"			// Inches Value object
#include "Capacitor.h"		// Capacitor Value object
#include "Inductor.h"		// Inductor Value object
#include "Resistor.h"		// Resistor Value object
#include "Xc.h"				// Capacitive Reactance Value object
#include "Xl.h"				// Inductive Reactance Value object
#include "Frequency.h"		// Frequency Value object
#include "TimeConstant.h"	// Time Constant Value object
#include "RiseTime.h"		// Rise Time Value object
#include "Bw.h"				// Bandwidth Value object
#include "Q.h"				// Quality Factor Value object
#include "TurnsPerInch.h"	// Turns Per Inch Value object
#include "Turns.h"			// Turns Value object

//------------------------------------------
// Calculator Classes
//------------------------------------------

#include "Calculation.h"			// Base Calculation object
#include "CapacitiveReactance.h"	// Capacitive Reactance Calculation object
#include "InductiveReactance.h"		// Inductive Reactance Calculation object
#include "Resonant.h"				// Resonant Calculation object
#include "CoilCalculator.h"			// Coil Calculator object
#include "PaddedCapacitance.h"		// Padded Capacitance object for Super Heterodyne Tuning
#include "SuperHetTuning.h"			// Super Heterodyne Tuning Calculation object

#include "Plot.h"

//------------------------------------------
// Dialog Box Headers
//------------------------------------------

#include "EditParam.h"
#include "EditBW.h"
#include "EditCapacitiveReactance.h"
#include "EditCapacitor.h"
#include "EditFrequency.h"
#include "EditInductiveReactance.h"
#include "EditInductor.h"
#include "EditResistor.h"
#include "EditSeconds.h"
#include "EditTurns.h"
#include "EditTurnsPerInch.h"
#include "EditInches.h"
#include "EditQFactor.h"
#include "EditDouble.h"

#include "DlgCapacitiveReactance.h"				// Capacitive Reactance dialog box
#include "DlgCoilDesignCalculator.h"			// Coil Design Calculator dialog box
#include "DlgInductiveReactance.h"				// Inductive Reactance dialog box
#include "DlgResonantLRC.h"						// Resonant LRC dialog box
#include "DlgSuperHeterodynMixer.h"				// Super Heterodyne Mixer dialog box
#include "DlgTransformerDesignCalculator.h"		// Transformer Design Calculator dialog box
#include "DlgTransistorBiasCalculator.h"		// Transistor Bias Calculator dialog box
#include "DlgVoltageDivider.h"					// Voltage Divider dialog box

#include "CircCalcDoc.h"
#include "CircCalcView.h"


#endif //PCH_H
