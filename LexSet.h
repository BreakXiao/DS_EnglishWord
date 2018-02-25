#if !defined(AFX_LEXSET_H__C78F43E4_926C_447C_9CAD_C4A7911D6163__INCLUDED_)
#define AFX_LEXSET_H__C78F43E4_926C_447C_9CAD_C4A7911D6163__INCLUDED_

#include "Lexicon1.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LexSet.h : header file
//
#include "Lexicon1.h"
/////////////////////////////////////////////////////////////////////////////
// CLexSet dialog

class CLexSet : public CDialog
{
// Construction
public:
	CLexicon m_lex;
	CLexSet(CWnd* pParent = NULL);   // standard constructor
	int sort_id[20000];
// Dialog Data
	//{{AFX_DATA(CLexSet)
	enum { IDD = IDD_LexSet };
	CString	m_LexName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLexSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLexSet)
	virtual BOOL OnInitDialog();
	afx_msg void OnUpsetId();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEXSET_H__C78F43E4_926C_447C_9CAD_C4A7911D6163__INCLUDED_)
