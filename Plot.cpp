// Plot.cpp : implementation file
//

#include "pch.h"
#include "Plot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlot

CPlot::CPlot()
{
	BlackPen.CreatePen(PS_SOLID,1,COLORREF(0x00ff0000));
	Data = 0;
}

CPlot::~CPlot()
{
	if( Data) delete[] Data;
}


BEGIN_MESSAGE_MAP(CPlot, CStatic)
	//{{AFX_MSG_MAP(CPlot)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlot message handlers

void CPlot::AddPoint(int x, short y)
{
	if(nData < bsize)
	{
		Data[head] = y;
		++head;
		++nData;
		if(head == bsize)head = 0;
	}
	else
	{
		++tail;
		if(tail == bsize) tail = 0;
		Data[head++] = y;
		if(head == bsize) head = 0;
	}
	Invalidate();
}

void CPlot::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	RECT clientrect;
	int x,y;

	GetClientRect(&clientrect);
	x = clientrect.right;
	y = clientrect.bottom;
	CBitmap BitmapPlot;		//this is where we will draw the histogram
	BitmapPlot.CreateCompatibleBitmap (&dc, x, y);

	CDC dcMem;
	dcMem.CreateCompatibleDC (&dc);

	
	CBrush brush (RGB (0, 255, 255));
	CBitmap* pOldBitmap = dcMem.SelectObject (&BitmapPlot);
	dcMem.FillRect (CRect (0, 0, x, y), &brush);
	DrawXAxis(&dcMem);
	CPen *OldPen = dcMem.SelectObject(&BlackPen);
	if(nData > 2)
	{
		int i=0;
		dcMem.MoveTo(i,ScaleY(Data[i]));
		for(i=1;i<nData;++i)
		{
			dcMem.LineTo(i,ScaleY(Data[i]));
		}
	}
	dc.BitBlt(0,0,x,y,&dcMem,0,0,SRCCOPY);
	dcMem.SelectObject(OldPen);
	dcMem.SelectObject (pOldBitmap);
	
	// Do not call CStatic::OnPaint() for painting messages
}

void CPlot::InitPlot(int nSize)
{
	RECT clientrect;
	GetClientRect(&clientrect);

	if(nSize > 0)
	{
		if(Data) delete [] Data;
		Data = new short[nSize];
		bsize = nSize;
	}
	else
	{
		if(!Data) Data = new short[clientrect.right];
		bsize = clientrect.right;
	}
	head = 0;
	tail = 0;
	nData = 0;
	MaxY = clientrect.bottom;
	MaxX = clientrect.right;
}

int CPlot::ScaleY(int nPy)
{
	return -(int)((m_Scale_Gain * (double)nPy) - m_Scale_Offset);
}

void CPlot::SetScale(int MaxY, int MinY)
{
	RECT clientrect;
	GetClientRect(&clientrect);

	double X1,X2,Y1,Y2;

	X1 = (double)MaxY;
	X2 = (double)MinY;
	Y1 = (double)clientrect.bottom;
	Y2 = (double)clientrect.top;
	m_Scale_Gain = (Y1-Y2)/(X1-X2);	//slope
	m_Scale_Offset = (m_Scale_Gain * X1)/* - Y1*/;
}


void CPlot::Erase()
{
	head = 0;
	tail = 0;
	nData = 0;
	Invalidate();
}

void CPlot::DrawXAxis(CDC *dc)
{
	CPen pen,*old;

	pen.CreatePen(PS_SOLID,1,COLORREF(0));
	old = dc->SelectObject(&pen);
	dc->MoveTo(0,ScaleY(0));
	dc->LineTo(this->MaxX,ScaleY(0));
	dc->SelectObject(old);
}
