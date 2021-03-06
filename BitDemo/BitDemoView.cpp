
// BitDemoView.cpp : implementation of the CBitDemoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BitDemo.h"
#endif

#include "BitDemoDoc.h"
#include "BitDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBitDemoView

IMPLEMENT_DYNCREATE(CBitDemoView, CView)

BEGIN_MESSAGE_MAP(CBitDemoView, CView)
END_MESSAGE_MAP()

// CBitDemoView construction/destruction

CBitDemoView::CBitDemoView() noexcept
{
	// TODO: add construction code here
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetObject(sizeof(BM), &BM);
	m_BitmapWidth = BM.bmWidth;
	m_BitmapHeight = BM.bmHeight;

}

CBitDemoView::~CBitDemoView()
{
}

BOOL CBitDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBitDemoView drawing

void CBitDemoView::OnDraw(CDC* pDC)
{
	CBitDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CDC MemDC;
	RECT ClientRect;
	// �������� ������ ������ �� � ������� ������ ����������� 
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(&m_Bitmap);
	// ������� ������� ���� ������������� 
	GetClientRect(&ClientRect);
	// ��������� ������� � ����������� ��� ������� 
	pDC->StretchBlt
	(0, 0,              // ������� ����� ���� ���������
		ClientRect.right,  // ������ �������������� ���������
		ClientRect.bottom, // ������ �������������� ���������
		&MemDC,            // ������ �� ���������
		0, 0,              // ������� ����� ���� ���������
		m_BitmapWidth,     // ������ �������������� ���������
		m_BitmapHeight,    // ������ �������������� ���������
		SRCCOPY);          // ��� ��������� ��������

}


// CBitDemoView diagnostics

#ifdef _DEBUG
void CBitDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBitDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitDemoDoc* CBitDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitDemoDoc)));
	return (CBitDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CBitDemoView message handlers
