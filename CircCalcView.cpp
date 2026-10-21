
// CircCalcView.cpp : implementation of the CCircCalcView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CircCalc2027.h"
#endif

#include "CircCalcDoc.h"
#include "CircCalcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCircCalcView

IMPLEMENT_DYNCREATE(CCircCalcView, CView)

BEGIN_MESSAGE_MAP(CCircCalcView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCircCalcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CALCULATE_CAPACITIVEREACTANCE, &CCircCalcView::OnCalculateCapacitivereactance)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_CAPACITIVEREACTANCE, &CCircCalcView::OnUpdateCalculateCapacitivereactance)
	ON_COMMAND(ID_CALCULATE_COILDESIGNER, &CCircCalcView::OnCalculateCoildesigner)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_COILDESIGNER, &CCircCalcView::OnUpdateCalculateCoildesigner)
	ON_COMMAND(ID_CALCULATE_INDUCTIVEREACTANCE, &CCircCalcView::OnCalculateInductivereactance)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_INDUCTIVEREACTANCE, &CCircCalcView::OnUpdateCalculateInductivereactance)
	ON_COMMAND(ID_CALCULATE_LRCRESONANCE, &CCircCalcView::OnCalculateLrcresonance)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_LRCRESONANCE, &CCircCalcView::OnUpdateCalculateLrcresonance)
	ON_COMMAND(ID_CALCULATE_SUPERHETERODYNEMIXER, &CCircCalcView::OnCalculateSuperheterodynemixer)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_SUPERHETERODYNEMIXER, &CCircCalcView::OnUpdateCalculateSuperheterodynemixer)
	ON_COMMAND(ID_CALCULATE_TRANSFORMERDESIGN, &CCircCalcView::OnCalculateTransformerdesign)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_TRANSFORMERDESIGN, &CCircCalcView::OnUpdateCalculateTransformerdesign)
	ON_COMMAND(ID_CALCULATE_TRANSISTORBIAS, &CCircCalcView::OnCalculateTransistorbias)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_TRANSISTORBIAS, &CCircCalcView::OnUpdateCalculateTransistorbias)
	ON_COMMAND(ID_CALCULATE_VOLTAGEDIVIDER, &CCircCalcView::OnCalculateVoltagedivider)
	ON_UPDATE_COMMAND_UI(ID_CALCULATE_VOLTAGEDIVIDER, &CCircCalcView::OnUpdateCalculateVoltagedivider)
END_MESSAGE_MAP()

// CCircCalcView construction/destruction

CCircCalcView::CCircCalcView() noexcept
{
	// TODO: add construction code here

}

CCircCalcView::~CCircCalcView()
{
}

BOOL CCircCalcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCircCalcView drawing

void CCircCalcView::OnDraw(CDC* /*pDC*/)
{
	CCircCalcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCircCalcView printing


void CCircCalcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCircCalcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCircCalcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCircCalcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCircCalcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCircCalcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCircCalcView diagnostics

#ifdef _DEBUG
void CCircCalcView::AssertValid() const
{
	CView::AssertValid();
}

void CCircCalcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCircCalcDoc* CCircCalcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCircCalcDoc)));
	return (CCircCalcDoc*)m_pDocument;
}
#endif //_DEBUG


// CCircCalcView message handlers

void CCircCalcView::OnCalculateCapacitivereactance()
{
	UINT nID = IDCANCEL;

	CDlgCapacitiveReactance dlg;
	nID = dlg.DoModal();
}

void CCircCalcView::OnUpdateCalculateCapacitivereactance(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateCoildesigner()
{
	CDlgCoilDesignCalculator dlg;
	dlg.DoModal();
}

void CCircCalcView::OnUpdateCalculateCoildesigner(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateInductivereactance()
{
	CDlgInductiveReactance dlg;
	UINT nID = dlg.DoModal();
}

void CCircCalcView::OnUpdateCalculateInductivereactance(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateLrcresonance()
{
	// TODO: Add your command handler code here
}

void CCircCalcView::OnUpdateCalculateLrcresonance(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateSuperheterodynemixer()
{
	// TODO: Add your command handler code here
}

void CCircCalcView::OnUpdateCalculateSuperheterodynemixer(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateTransformerdesign()
{
	// TODO: Add your command handler code here
}

void CCircCalcView::OnUpdateCalculateTransformerdesign(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateTransistorbias()
{
	// TODO: Add your command handler code here
}

void CCircCalcView::OnUpdateCalculateTransistorbias(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CCircCalcView::OnCalculateVoltagedivider()
{
	// TODO: Add your command handler code here
}

void CCircCalcView::OnUpdateCalculateVoltagedivider(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}
