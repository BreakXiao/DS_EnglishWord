#if !defined(AFX_INFORMATION_H__94A70F41_F321_4AA1_9922_81B0F9185586__INCLUDED_)
#define AFX_INFORMATION_H__94A70F41_F321_4AA1_9922_81B0F9185586__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Information.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInformation form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CInformation : public CFormView
{
protected:
	CInformation();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CInformation)

// Form Data
public:
	//{{AFX_DATA(CInformation)
	enum { IDD = IDD_FORMVIEW };
	int		m_rightnum;
	int		m_falsenum;
	int		m_wordID;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInformation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CInformation();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CInformation)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORMATION_H__94A70F41_F321_4AA1_9922_81B0F9185586__INCLUDED_)
