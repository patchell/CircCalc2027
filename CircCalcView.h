
// CircCalcView.h : interface of the CCircCalcView class
//

#pragma once


class CCircCalcView : public CView
{
protected: // create from serialization only
	CCircCalcView() noexcept;
	DECLARE_DYNCREATE(CCircCalcView)

// Attributes
public:
	CCircCalcDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCircCalcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCalculateCapacitivereactance();
	afx_msg void OnUpdateCalculateCapacitivereactance(CCmdUI* pCmdUI);
	afx_msg void OnCalculateCoildesigner();
	afx_msg void OnUpdateCalculateCoildesigner(CCmdUI* pCmdUI);
	afx_msg void OnCalculateInductivereactance();
	afx_msg void OnUpdateCalculateInductivereactance(CCmdUI* pCmdUI);
	afx_msg void OnCalculateLrcresonance();
	afx_msg void OnUpdateCalculateLrcresonance(CCmdUI* pCmdUI);
	afx_msg void OnCalculateSuperheterodynemixer();
	afx_msg void OnUpdateCalculateSuperheterodynemixer(CCmdUI* pCmdUI);
	afx_msg void OnCalculateTransformerdesign();
	afx_msg void OnUpdateCalculateTransformerdesign(CCmdUI* pCmdUI);
	afx_msg void OnCalculateTransistorbias();
	afx_msg void OnUpdateCalculateTransistorbias(CCmdUI* pCmdUI);
	afx_msg void OnCalculateVoltagedivider();
	afx_msg void OnUpdateCalculateVoltagedivider(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // debug version in CircCalcView.cpp
inline CCircCalcDoc* CCircCalcView::GetDocument() const
   { return reinterpret_cast<CCircCalcDoc*>(m_pDocument); }
#endif

