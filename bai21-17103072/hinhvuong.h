#pragma once
class hinhvuong
{
private:int x1,y1,x2,y2;
public:
	hinhvuong(void);
	hinhvuong(CPoint px1,CPoint px2);
	void thietlap(int mx1,int my1,int mx2,int my2);
	void ve(CClientDC *pDC);
	int tronghinh(CPoint p);
	void phongto();
	void thunho();
	void butbandau(CClientDC *pDC);
	void xoahinh(CClientDC *pDC);
	~hinhvuong(void);
};

