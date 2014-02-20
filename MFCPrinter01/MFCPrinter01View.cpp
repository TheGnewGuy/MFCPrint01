
// MFCPrinter01View.cpp : implementation of the CMFCPrinter01View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCPrinter01.h"
#endif

#include "MFCPrinter01Doc.h"
#include "MFCPrinter01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPrinter01View

IMPLEMENT_DYNCREATE(CMFCPrinter01View, CView)

BEGIN_MESSAGE_MAP(CMFCPrinter01View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCPrinter01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCPrinter01View construction/destruction

CMFCPrinter01View::CMFCPrinter01View()
{
	// TODO: add construction code here

}

CMFCPrinter01View::~CMFCPrinter01View()
{
}

BOOL CMFCPrinter01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCPrinter01View drawing

void CMFCPrinter01View::OnDraw(CDC* pDC)
{
	CMFCPrinter01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
	CBrush brush(RGB(255, 255, 0));

	CPen *pOldPen = pDC->SelectObject(&pen);
	CBrush *pOldBrush = pDC->SelectObject(&brush);

	pDC->SetMapMode(MM_LOMETRIC);
	pDC->Ellipse(100, -100, 1100, -1100);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

}


// CMFCPrinter01View printing


void CMFCPrinter01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCPrinter01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	pInfo->SetMaxPage(1);
	return DoPreparePrinting(pInfo);
}

void CMFCPrinter01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCPrinter01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCPrinter01View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCPrinter01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCPrinter01View diagnostics

#ifdef _DEBUG
void CMFCPrinter01View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPrinter01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPrinter01Doc* CMFCPrinter01View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPrinter01Doc)));
	return (CMFCPrinter01Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPrinter01View message handlers
