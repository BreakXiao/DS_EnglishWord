// MODELSET.cpp : implementation file
//

#include "stdafx.h"
#include "DS_English.h"
#include "MODELSET.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMODELSET dialog


CMODELSET::CMODELSET(CWnd* pParent /*=NULL*/)
	: CDialog(CMODELSET::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMODELSET)
	m_pValue = _T("");
	m_pTime = _T("");
	//}}AFX_DATA_INIT
}


void CMODELSET::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMODELSET)
	DDX_CBString(pDX, IDC_COMBO1, m_pValue);
	DDX_CBString(pDX, IDC_COMBO2, m_pTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMODELSET, CDialog)
	//{{AFX_MSG_MAP(CMODELSET)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMODELSET message handlers

BOOL CMODELSET::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
