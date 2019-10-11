
// bai21-17103072View.cpp : implementation of the Cbai2117103072View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "bai21-17103072.h"
#endif

#include "bai21-17103072Doc.h"
#include "bai21-17103072View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbai2117103072View

IMPLEMENT_DYNCREATE(Cbai2117103072View, CView)

BEGIN_MESSAGE_MAP(Cbai2117103072View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cbai2117103072View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cbai2117103072View construction/destruction

Cbai2117103072View::Cbai2117103072View()
{
	// TODO: add construction code here
	control=0;
	n=0;
}

Cbai2117103072View::~Cbai2117103072View()
{
}

BOOL Cbai2117103072View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cbai2117103072View drawing

void Cbai2117103072View::OnDraw(CDC* /*pDC*/)
{
	Cbai2117103072Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC=new CClientDC (this);
	b1.thietlap(100,30,150,60);
	b1.ve(pDC);
	pDC->TextOutW(115,35,CString("Ve"));
	b2.thietlap(155,30,220,60);
	b2.ve(pDC);
	pDC->TextOutW(160,35,CString("Phong to"));
	b3.thietlap(225,30,290,60);
	b3.ve(pDC);
	pDC->TextOutW(230,35,CString("Thu nho"));
	// TODO: add draw code for native data here
}


// Cbai2117103072View printing


void Cbai2117103072View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cbai2117103072View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cbai2117103072View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cbai2117103072View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cbai2117103072View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cbai2117103072View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cbai2117103072View diagnostics

#ifdef _DEBUG
void Cbai2117103072View::AssertValid() const
{
	CView::AssertValid();
}

void Cbai2117103072View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cbai2117103072Doc* Cbai2117103072View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbai2117103072Doc)));
	return (Cbai2117103072Doc*)m_pDocument;
}
#endif //_DEBUG


// Cbai2117103072View message handlers


void Cbai2117103072View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	px1.x=point.x;
	px1.y=point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void Cbai2117103072View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	px2.x=point.x;
	px2.y=point.y;
	if (b1.tronghinh(point) == 1)
	{
		control = 1;
	}
	else
	if(b2.tronghinh(point) == 1)
	{
		control = 2;
	}
	else
		if (b3.tronghinh(point) == 1)
		{
			control = 3;
		}
	else
		if(control==1)
		{
			hv[n]=new hinhvuong(px1,px2);
			hv[n]->ve(pDC);
			n++;
		}
		else
			if(control==2)
			{
				for(int i=0;i<n;i++)
					if(hv[i]->tronghinh(point)==1)
					{
						{
							hv[i]->phongto();
							hv[i]->xoahinh(pDC);
							hv[i]->butbandau(pDC);
						}
					}
			}
			else
				if (control == 3)
				{
					for (int i = 0; i < n; i++)
						if (hv[i]->tronghinh(point) == 1)
						{
							{
								
								hv[i]->xoahinh(pDC);
								hv[i]->thunho();
								hv[i]->butbandau(pDC);
							}
						}
				}
				
	CView::OnLButtonUp(nFlags, point);
}
