// DS_EnglishView.h : interface of the CDS_EnglishView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DS_ENGLISHVIEW_H__89171EA8_6E3A_442C_9E02_19F2DB331EF6__INCLUDED_)
#define AFX_DS_ENGLISHVIEW_H__89171EA8_6E3A_442C_9E02_19F2DB331EF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDS_EnglishDoc;
class CDS_EnglishView : public CView
{
protected: // create from serialization only
	CDS_EnglishView();
	DECLARE_DYNCREATE(CDS_EnglishView)

// Attributes
public:
	CDS_EnglishDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDS_EnglishView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_ptime;//惩罚时间
	int ptime;  //惩罚时用来计时的参数
	int m_rt;  //当不认识单词时，用来进入不认识功能的状态判别
	int m_time;//开始背单词时的时间值，以秒为单位
	CString m_last_pstring;  //惩罚字符串
	CString m_punish_string;//惩罚字符串
	int m_punish_value;//惩罚值，即错误时后退的个数
	int m_BlackFlag;  //黑色方框状态值，Flag为5时全白，为0时全黑
	int m_Black[5]; //用这个确定6个长条是否显示
	int now_index;//当前所背单词编号
	int status;//软件状态，背单词开始时为1，不背时为0
	int SortId[20000]; //单词编号数组
	virtual ~CDS_EnglishView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDS_EnglishView)
	afx_msg void OnAddWord();
	afx_msg void OnAddmany();
	afx_msg void OnChange();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUpdateAddmany(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddWord(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileOpen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DS_EnglishView.cpp
inline CDS_EnglishDoc* CDS_EnglishView::GetDocument()
   { return (CDS_EnglishDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DS_ENGLISHVIEW_H__89171EA8_6E3A_442C_9E02_19F2DB331EF6__INCLUDED_)
