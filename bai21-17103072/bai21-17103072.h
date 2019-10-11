
// bai21-17103072.h : main header file for the bai21-17103072 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cbai2117103072App:
// See bai21-17103072.cpp for the implementation of this class
//

class Cbai2117103072App : public CWinAppEx
{
public:
	Cbai2117103072App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cbai2117103072App theApp;
