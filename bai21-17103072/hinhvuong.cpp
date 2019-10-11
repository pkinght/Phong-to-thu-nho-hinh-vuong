#include "StdAfx.h"
#include "hinhvuong.h"
#include <math.h>

hinhvuong::hinhvuong(void)
{
}
hinhvuong::hinhvuong(CPoint px1,CPoint px2)
{
	x1=px1.x;
	x2=px2.x;
	if(px1.y<px2.y)
	{
		y1=px1.y;
		y2=(sqrt((float)(x2-x1)*(x2-x1))-(px2.y-y1))+px2.y;
	}
	else
	{
		y1=px2.y;
		y2=(sqrt((float)(x2-x1)*(x2-x1))-(px2.y-y1))+px2.y;
	}

}
void hinhvuong::thietlap(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;
	x2=mx2;y2=my2;
}
void hinhvuong::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1,y1,x2,y2);
}
int hinhvuong::tronghinh(CPoint p)
{
	int kq=0;
	if(x1<=p.x&&y1<=p.y&&p.x<=x2&&p.y<=y2)
		kq=1;
	return kq;
}
void hinhvuong::phongto()
{
	x1-=1;y1-=1;
	x2+=1;y2+=1;
}
void hinhvuong::thunho()
{
	x1+=1;y1+=1;
	x2-=1;y2-=1;
}
void hinhvuong::butbandau(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}
void hinhvuong::xoahinh(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}
hinhvuong::~hinhvuong(void)
{
}
