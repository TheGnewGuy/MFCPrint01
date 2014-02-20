
// MFCPrinter01.h : main header file for the MFCPrinter01 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCPrinter01App:
// See MFCPrinter01.cpp for the implementation of this class
//

class CMFCPrinter01App : public CWinAppEx
{
public:
	CMFCPrinter01App();


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

extern CMFCPrinter01App theApp;
