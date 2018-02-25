// Information.cpp : implementation file
//

#include "stdafx.h"
#include "DS_English.h"
#include "Information.h"
#include "DS_EnglishDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInformation

IMPLEMENT_DYNCREATE(CInformation, CFormView)

CInformation::CInformation()
	: CFormView(CInformation::IDD)
{
	//{{AFX_DATA_INIT(CInformation)
	m_rightnum = 0;
	m_falsenum = 0;
	m_wordID = 0;
	//}}AFX_DATA_INIT
}

CInformation::~CInformation()
{
}

void CInformation::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInformation)
	DDX_Text(pDX, IDC_RightNum, m_rightnum);
	DDX_Text(pDX, IDC_FalseNum, m_falsenum);
	DDX_Text(pDX, IDC_WordID, m_wordID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInformation, CFormView)
	//{{AFX_MSG_MAP(CInformation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInformation diagnostics

#ifdef _DEBUG
void CInformation::AssertValid() const
{
	CFormView::AssertValid();
}

void CInformation::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInformation message handlers

//DEL void CInformation::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	
//DEL 	CFormView::OnDrawItem(nIDCtl, lpDrawItemStruct);
//DEL }

void CInformation::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	CDS_EnglishDoc *pDoc=(CDS_EnglishDoc *)GetDocument();
	int index;
	index=pDoc->Lexicon.now_word_id;
	
	m_wordID=index;
	m_falsenum=pDoc->Lexicon.GetWord(index-1)->false_num;
	m_rightnum=pDoc->Lexicon.GetWord(index-1)->right_num;
	UpdateData(false);
	
}
