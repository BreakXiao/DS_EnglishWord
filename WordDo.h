#if !defined(AFX_WORDDO_H__078B0C1D_D2FD_4C7B_B6C7_5224AB935309__INCLUDED_)
#define AFX_WORDDO_H__078B0C1D_D2FD_4C7B_B6C7_5224AB935309__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordDo.h : header file
//
#include "Word.h"
#include "DS_English.h"
#include "DS_EnglishDoc.h"
#include "Lexicon1.h"
/////////////////////////////////////////////////////////////////////////////
// CWordDo dialog

class CWordDo : public CDialog
{
// Construction
public:
	CWordDo(CWnd* pParent = NULL);   // standard constructor
	//CDS_EnglishDoc* GetDocument();
// Dialog Data
	//{{AFX_DATA(CWordDo)
	enum { IDD = IDD_DIALWordDo };
	CListBox	m_list; //ÁÐ±í¿òÀà
	CString	m_c_mean;
	CString	m_e_mean;
	int		m_FlaseNum;
	int		m_RightNum;
	int		m_word_id;
	CLexicon m_lex;
	CString	m_LexName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordDo)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWordDo)
	afx_msg void OnAddWord();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	afx_msg void OnDestroy();
	afx_msg void OnDeleteWord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DS_EnglishView.cpp
inline CDS_EnglishDoc* CDS_EnglishView::GetDocument()
   { return (CDS_EnglishDoc*)m_pDocument; }
#endif
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDDO_H__078B0C1D_D2FD_4C7B_B6C7_5224AB935309__INCLUDED_)
