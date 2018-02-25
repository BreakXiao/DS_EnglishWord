#if !defined(AFX_MODELSET_H__EACED142_FB2B_4899_A64E_17864D9DB2FC__INCLUDED_)
#define AFX_MODELSET_H__EACED142_FB2B_4899_A64E_17864D9DB2FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MODELSET.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMODELSET dialog

class CMODELSET : public CDialog
{
// Construction
public:
	CMODELSET(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMODELSET)
	enum { IDD = IDD_DIALOG1 };
	CString	m_pValue;
	CString	m_pTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMODELSET)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMODELSET)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELSET_H__EACED142_FB2B_4899_A64E_17864D9DB2FC__INCLUDED_)
