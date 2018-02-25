#if !defined(AFX_WORDADD_H__8793CA3C_9464_4197_B78A_A34A82A64A85__INCLUDED_)
#define AFX_WORDADD_H__8793CA3C_9464_4197_B78A_A34A82A64A85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordAdd.h : header file
//
#include "Lexicon1.h"
/////////////////////////////////////////////////////////////////////////////
// CWordAdd dialog

class CWordAdd : public CDialog
{
// Construction
public:
	CWordAdd(CWnd* pParent = NULL);   // standard constructor
	CString	m_c_mean;
	CString	m_e_mean;
	CLexicon m_lex;
// Dialog Data
	//{{AFX_DATA(CWordAdd)
	enum { IDD = IDD_DIALWordAdd };
	CString	m_AddWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWordAdd)
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDADD_H__8793CA3C_9464_4197_B78A_A34A82A64A85__INCLUDED_)
