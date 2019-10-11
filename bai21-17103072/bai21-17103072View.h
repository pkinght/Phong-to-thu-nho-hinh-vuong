
// bai21-17103072View.h : interface of the Cbai2117103072View class
//

#pragma once
#include "hinhvuong.h"

class Cbai2117103072View : public CView
{
protected: // create from serialization only
	Cbai2117103072View();
	DECLARE_DYNCREATE(Cbai2117103072View)

// Attributes
public:
	Cbai2117103072Doc* GetDocument() const;

// Operations
public:
	CPoint px1,px2;
	hinhvuong b1,b2,b3;
	hinhvuong *hv[20];
	int control;
	CClientDC *pDC;
	int n;
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
	virtual ~Cbai2117103072View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in bai21-17103072View.cpp
inline Cbai2117103072Doc* Cbai2117103072View::GetDocument() const
   { return reinterpret_cast<Cbai2117103072Doc*>(m_pDocument); }
#endif

