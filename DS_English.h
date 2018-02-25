// DS_English.h : main header file for the DS_ENGLISH application
//

#if !defined(AFX_DS_ENGLISH_H__09584054_3DCC_4866_8E85_B40AA30B0804__INCLUDED_)
#define AFX_DS_ENGLISH_H__09584054_3DCC_4866_8E85_B40AA30B0804__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishApp:
// See DS_English.cpp for the implementation of this class
//

class CDS_EnglishApp : public CWinApp
{
public:
	CDS_EnglishApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDS_EnglishApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDS_EnglishApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DS_ENGLISH_H__09584054_3DCC_4866_8E85_B40AA30B0804__INCLUDED_)
