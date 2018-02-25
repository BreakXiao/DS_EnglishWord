// DS_EnglishDoc.cpp : implementation of the CDS_EnglishDoc class
//

#include "stdafx.h"
#include "DS_English.h"

#include "DS_EnglishDoc.h"
#include "Word.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishDoc

IMPLEMENT_DYNCREATE(CDS_EnglishDoc, CDocument)

BEGIN_MESSAGE_MAP(CDS_EnglishDoc, CDocument)
	//{{AFX_MSG_MAP(CDS_EnglishDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishDoc construction/destruction

CDS_EnglishDoc::CDS_EnglishDoc()
{
	// TODO: add one-time construction code here

	
}

CDS_EnglishDoc::~CDS_EnglishDoc()
{
}

BOOL CDS_EnglishDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishDoc serialization

void CDS_EnglishDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<Lexicon.LexName;
		ar<<Lexicon.now_word_id;
		Lexicon.m_WordArray.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		ar>>Lexicon.LexName;
		ar>>Lexicon.now_word_id;
		Lexicon.m_WordArray.Serialize(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishDoc diagnostics

#ifdef _DEBUG
void CDS_EnglishDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDS_EnglishDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishDoc commands

void CDS_EnglishDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	int nIndex=Lexicon.GetNumWord();
	while(nIndex--)
	{
		delete Lexicon.m_WordArray.GetAt(nIndex);
	}
	Lexicon.m_WordArray.RemoveAll();
	CDocument::DeleteContents();
}
