// DS_EnglishDoc.h : interface of the CDS_EnglishDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DS_ENGLISHDOC_H__BEDBA6C3_3F98_4504_88D7_C83ABC7D280F__INCLUDED_)
#define AFX_DS_ENGLISHDOC_H__BEDBA6C3_3F98_4504_88D7_C83ABC7D280F__INCLUDED_

#include "Word.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Lexicon1.h"
#define MAX 1000

class CDS_EnglishDoc : public CDocument
{
protected: // create from serialization only
	CDS_EnglishDoc();
	DECLARE_DYNCREATE(CDS_EnglishDoc)

// Attributes
public:
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDS_EnglishDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:      
	CLexicon Lexicon;    //´Ê¿â

	virtual ~CDS_EnglishDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDS_EnglishDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DS_ENGLISHDOC_H__BEDBA6C3_3F98_4504_88D7_C83ABC7D280F__INCLUDED_)
