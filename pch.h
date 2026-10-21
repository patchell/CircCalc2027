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
#include "EditParam.h"

#include "CircCalc2027.h"

//-----------------------------------------
// Values
//-----------------------------------------
#include "Value.h"

#include "Inches.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "Resistor.h"
#include "Xc.h"
#include "Xl.h"
#include "Frequency.h"
#include "TimeConstant.h"
#include "RiseTime.h"
#include "Bw.h"
#include "Q.h"
#include "ResFreq.h"

#include "CoilCalculator.h"

//------------------------------------------
// Calculator Classes
//------------------------------------------
#include "PaddedCapacitance.h"

#include "Calculation.h"
#include "CapacitiveReactance.h"
#include "InductiveReactance.h"
#include "Resonant.h"
#include "SuperHetTuning.h"

#include "Plot.h"

//------------------------------------------
// Dialog Box Headers
//------------------------------------------

#include "DlgCapacitiveReactance.h"
#include "DlgCoilDesignCalculator.h"
#include "DlgInductiveReactance.h"
#include "DlgResonantLRC.h"
#include "DlgSuperHeterodynMixer.h"
#include "DlgTransformerDesignCalculator.h"
#include "DlgTransistorBiasCalculator.h"
#include "DlgVoltageDivider.h"


#endif //PCH_H
