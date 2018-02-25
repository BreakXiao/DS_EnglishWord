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
	int m_ptime;//�ͷ�ʱ��
	int ptime;  //�ͷ�ʱ������ʱ�Ĳ���
	int m_rt;  //������ʶ����ʱ���������벻��ʶ���ܵ�״̬�б�
	int m_time;//��ʼ������ʱ��ʱ��ֵ������Ϊ��λ
	CString m_last_pstring;  //�ͷ��ַ���
	CString m_punish_string;//�ͷ��ַ���
	int m_punish_value;//�ͷ�ֵ��������ʱ���˵ĸ���
	int m_BlackFlag;  //��ɫ����״ֵ̬��FlagΪ5ʱȫ�ף�Ϊ0ʱȫ��
	int m_Black[5]; //�����ȷ��6�������Ƿ���ʾ
	int now_index;//��ǰ�������ʱ��
	int status;//���״̬�������ʿ�ʼʱΪ1������ʱΪ0
	int SortId[20000]; //���ʱ������
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
