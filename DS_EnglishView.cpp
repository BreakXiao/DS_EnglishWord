// DS_EnglishView.cpp : implementation of the CDS_EnglishView class
//

#include "stdafx.h"
#include "DS_English.h"
#include "LexSet.h"
#include "DS_EnglishDoc.h"
#include "DS_EnglishView.h"
#include "Word.h"
#include "WordDo.h"
#include "WordAdd.h"
#include "MODELSET.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishView

IMPLEMENT_DYNCREATE(CDS_EnglishView, CView)

BEGIN_MESSAGE_MAP(CDS_EnglishView, CView)
	//{{AFX_MSG_MAP(CDS_EnglishView)
	ON_COMMAND(ID_ADD_WORD, OnAddWord)
	ON_COMMAND(ID_ADDMANY, OnAddmany)
	ON_COMMAND(ID_Change, OnChange)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_UPDATE_COMMAND_UI(ID_ADDMANY, OnUpdateAddmany)
	ON_UPDATE_COMMAND_UI(ID_ADD_WORD, OnUpdateAddWord)
	ON_UPDATE_COMMAND_UI(ID_FILE_OPEN, OnUpdateFileOpen)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishView construction/destruction

/*CDS_EnglishView
 *��ͼ��Ĺ��캯��
 *��ʼ����ͼ�ϵ�ptime��rt�Ȳ���
 */
CDS_EnglishView::CDS_EnglishView()
{
	// TODO: add construction code here
	status=0;
	m_last_pstring="5";
	m_rt=0;
	m_ptime=3;

	for(int i=0;i<20000;i++)
	{
		SortId[i]=i+1;
	}
	

}

CDS_EnglishView::~CDS_EnglishView()
{
}

BOOL CDS_EnglishView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishView drawing


/*OnDraw
 *����Ļ��ƺ���
 *�������ݲμ��ڲ�ע��
 */
void CDS_EnglishView::OnDraw(CDC* pDC)
{
	CDS_EnglishDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect EngRect;  //Ӣ�Ŀ����
	EngRect.SetRect(CPoint(50,180),CPoint(650,280));
	CRect ChiRect; //���Ŀ����
	ChiRect.SetRect(CPoint(50,300),CPoint(650,400));
	
	pDC->Rectangle(&EngRect);   //����Ӣ�Ŀ�
	pDC->Rectangle(&ChiRect);   //�������Ŀ�
	
	/*****************������ʾ����************************/
	CFont *OldFont,NewFont;
	LOGFONT MyFont1=
	{
		26,				//	�߶�
		10,				//	���
 		0,				//	�ı�����Ե׶���б��
		0,				//	�ַ�������Ե׶���б��
		0,				//	�����ϸ
		0,				//	��ʱΪб��
		0,				//	��ʱΪ�»���
		0,				//	��ʱΪ��ɾ����
		ANSI_CHARSET,	//�ַ���
		OUT_DEFAULT_PRECIS,//�ַ��������
		CLIP_DEFAULT_PRECIS,//�ü�����
		PROOF_QUALITY,//�������
		DEFAULT_PITCH,	//�ֿ���
		"����"			//������
	};
	NewFont.CreateFontIndirect(&MyFont1);
	OldFont=pDC->SelectObject(&NewFont);
	CString lex_name="��ǰ�ʿ�:";
	lex_name+=pDoc->Lexicon.LexName;
	pDC->TextOut(50,50,lex_name);
	
	CString model_name="��ǰģʽ:";   //ģʽѡ��
	CString mname="�ͷ�ģʽ";
	model_name+=mname;
	pDC->TextOut(50,80,model_name);

	CString p_s="�ͷ�ֵ::";   //�ͷ�ֵѡ��
	p_s+=this->m_punish_string;
	pDC->TextOut(50,110,p_s);
	
	CString p_ts="�ͷ�ʱ��:",st;   //�ͷ�ʱ��ѡ��
	st.Format("%d",m_ptime);
	if(status==1) p_ts+=st;
	pDC->TextOut(50,140,p_ts);

	pDC->SelectObject(OldFont);
	NewFont.DeleteObject();
	/*****************������ʾ����************************/


	/*****************��ť��ʾ����************************/
	//pDC->Rectangle(299,7,395,96);
	CBitmap Bitmap;
	if(status==0)
		Bitmap.LoadBitmap(IDB_BITGO);
	else Bitmap.LoadBitmap(IDB_BITSTOP);
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap *OldBitmap=MemDC.SelectObject(&Bitmap);
	BITMAP bm;
	Bitmap.GetBitmap(&bm);
	pDC->BitBlt(300,10,bm.bmWidth,bm.bmHeight,&MemDC,0,0,SRCCOPY);
	pDC->SelectObject(OldBitmap);
	



	/*****************��ť��ʾ����************************/

	/*****************ʱ�����************************/
	LOGFONT MyFont3=
	{
		27,				//	�߶�
		9,				//	���
 		0,				//	�ı�����Ե׶���б��
		0,				//	�ַ�������Ե׶���б��
		1,				//	�����ϸ
		0,				//	��ʱΪб��
		0,				//	��ʱΪ�»���
		0,				//	��ʱΪ��ɾ����
		ANSI_CHARSET,	//�ַ���
		OUT_DEFAULT_PRECIS,//�ַ��������
		CLIP_DEFAULT_PRECIS,//�ü�����
		PROOF_QUALITY,//�������
		DEFAULT_PITCH,	//�ֿ���
		"����"			//������
	};
	NewFont.CreateFontIndirect(&MyFont3);
	OldFont=pDC->SelectObject(&NewFont);
	if(status==1)
	{
		CString stime="ʱ�䣺 ";
		CString st;
		int second,hour,minute;
		second=m_time%60;
		minute=m_time/60;
		st.Format("%d : %d ",minute,second);
		stime+=st;
		pDC->TextOut(400,40,stime);
	}
	pDC->SelectObject(OldFont);
	NewFont.DeleteObject();
	/*****************ʱ�����************************/
	




	/*****************������ʾ����************************/
	CWord w(0,"Destroy Dawn","����Ӣ�����");
	LOGFONT MyFont2=
	{
		78,				//	�߶�
		26,				//	���
 		0,				//	�ı�����Ե׶���б��
		0,				//	�ַ�������Ե׶���б��
		0,				//	�����ϸ
		0,				//	��ʱΪб��
		0,				//	��ʱΪ�»���
		0,				//	��ʱΪ��ɾ����
		ANSI_CHARSET,	//�ַ���
		OUT_DEFAULT_PRECIS,//�ַ��������
		CLIP_DEFAULT_PRECIS,//�ü�����
		PROOF_QUALITY,//�������
		DEFAULT_PITCH,	//�ֿ���
		"����"			//������
	};

	NewFont.CreateFontIndirect(&MyFont2);
	OldFont=pDC->SelectObject(&NewFont);
	


	if(status==0)
	{
		pDC->TextOut(60,185,w.EngMean);
		pDC->TextOut(60,310,w.ChiMean);
	}
	else
	{
		int n=pDoc->Lexicon.GetNumWord();
		int nIndex=pDoc->Lexicon.now_word_id;
		if(nIndex==0)
		{
			CWord wno(0,"NO Word","�ʿ���û�е���");
			pDC->TextOut(60,185,wno.EngMean);
			pDC->TextOut(60,310,wno.ChiMean);
			
		}
		else
		{
			CString c_w=pDoc->Lexicon.GetWord(SortId[nIndex-1]-1)->show_ChiMean();
			CString e_w=pDoc->Lexicon.GetWord(SortId[nIndex-1]-1)->show_EngMean();
			pDC->TextOut(60,185,e_w);
			pDC->TextOut(60,310,c_w);
		}
	}


	pDC->SelectObject(OldFont);
	NewFont.DeleteObject();
	/*****************������ʾ����************************/



	/*****************�ڱη�����ʾ����************************/
	switch(m_BlackFlag)
	{
	case 0: m_Black[0]=m_Black[1]=m_Black[2]=m_Black[3]=m_Black[4]=1;break;
	case 1: m_Black[0]=0;m_Black[1]=m_Black[2]=m_Black[3]=m_Black[4]=1;break;
	case 2: m_Black[0]=m_Black[1]=0;m_Black[2]=m_Black[3]=m_Black[4]=1;break;
	case 3: m_Black[0]=m_Black[1]=m_Black[2]=0;m_Black[3]=m_Black[4]=1;break;
	case 4: m_Black[0]=m_Black[1]=m_Black[2]=m_Black[3]=0;m_Black[4]=1;break;
	case 5: m_Black[0]=m_Black[1]=m_Black[2]=m_Black[3]=m_Black[4]=0;break;
	case 6: m_Black[0]=1;m_Black[1]=m_Black[2]=m_Black[3]=m_Black[4]=0;break;
	case 7: m_Black[0]=m_Black[1]=1;m_Black[2]=m_Black[3]=m_Black[4]=0;break;
	case 8: m_Black[0]=m_Black[1]=m_Black[2]=1;m_Black[3]=m_Black[4]=0;break;
	case 9: m_Black[0]=m_Black[1]=m_Black[2]=m_Black[3]=1;m_Black[4]=0;break;
	}

	CBrush *oldB,newB;
	newB.CreateSolidBrush(RGB(0,0,0));
	oldB=pDC->SelectObject(&newB);
	for(int i=0;i<5;i++)
	{
		if(m_Black[i]==1)
			pDC->Rectangle(50,300+i*20,650,320+i*20);
	}
	pDC->SelectObject(oldB);
	newB.DeleteObject();
	
	/*****************�ڱη�����ʾ����************************/

	/*****************�������ʾ********************/
	LOGFONT MyFont4=
	{
		42,				//	�߶�
		13,				//	���
 		0,				//	�ı�����Ե׶���б��
		0,				//	�ַ�������Ե׶���б��
		2,				//	�����ϸ
		1,				//	��ʱΪб��
		0,				//	��ʱΪ�»���
		0,				//	��ʱΪ��ɾ����
		ANSI_CHARSET,	//�ַ���
		OUT_DEFAULT_PRECIS,//�ַ��������
		CLIP_DEFAULT_PRECIS,//�ü�����
		PROOF_QUALITY,//�������
		DEFAULT_PITCH,	//�ֿ���
		"����"			//������
	};
	NewFont.CreateFontIndirect(&MyFont4);
	OldFont=pDC->SelectObject(&NewFont);
	if(m_rt==1)
	{
		pDC->SetTextColor(RGB(128,0,0));
		pDC->TextOut(400,130,"�����!");
	}
	else if(m_rt==2)
	{
		pDC->SetTextColor(RGB(0,255,255));
		pDC->TextOut(400,130,"�����~");
	}
	pDC->SelectObject(OldFont);
	NewFont.DeleteObject();
	/*****************�������ʾ********************/		


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishView printing

BOOL CDS_EnglishView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDS_EnglishView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDS_EnglishView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishView diagnostics

#ifdef _DEBUG
void CDS_EnglishView::AssertValid() const
{
	CView::AssertValid();
}

void CDS_EnglishView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDS_EnglishDoc* CDS_EnglishView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDS_EnglishDoc)));
	return (CDS_EnglishDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDS_EnglishView message handlers


/*OnAddWord
 *��ɾ�����ʡ���ť��Ϣ����Ӧ
 *ģ̬�Ի���Ĵ�����ʽ
 *�˳�ʱ��Ϣ����
 */
void CDS_EnglishView::OnAddWord() 
{
	// TODO: Add your command handler code here
	CWordDo dlg;
	CDS_EnglishDoc *pDoc=GetDocument();		//��ȡָ��
	dlg.m_lex.SetLex(pDoc->Lexicon);		//���ĵ�����Ĵʿ⸴�Ƶ��Ի�����Ĵʿ���		
	
	
	if(dlg.DoModal()==IDCANCEL)
	{
		pDoc->Lexicon.SetLex(dlg.m_lex);   //�˳��Ի��򣬶��ĵ���Ĵʿ���и���
		if(now_index>dlg.m_lex.GetNumWord())
			now_index=pDoc->Lexicon.now_word_id=1;
		Invalidate();
		pDoc->UpdateAllViews(this);
	}
	pDoc->SetModifiedFlag();

}




void CDS_EnglishView::OnAddmany() 
{
	// TODO: Add your command handler code here
	CWordAdd dlg;
	CDS_EnglishDoc *pDoc=GetDocument();		//��ȡָ��
	dlg.m_lex.SetLex(pDoc->Lexicon);		//���ĵ�����Ĵʿ⸴�Ƶ��Ի�����Ĵʿ���		
	
	
	if(dlg.DoModal()==IDCANCEL)
	{
		pDoc->Lexicon.SetLex(dlg.m_lex);   //�˳��Ի��򣬶��ĵ���Ĵʿ���и���
	}
	pDoc->SetModifiedFlag();

}
/*OnChange
 *�ʿ����ý������Ӧ����
 *���޸Ĵʿ����ƺ͵���˳��
 */
void CDS_EnglishView::OnChange() 
{
	// TODO: Add your command handler code here
	CLexSet dlg;
	CDS_EnglishDoc *pDoc=GetDocument();		//��ȡָ��
	dlg.m_lex.SetLex(pDoc->Lexicon);		//���ĵ�����Ĵʿ⸴�Ƶ��Ի�����Ĵʿ���		
	dlg.m_LexName=pDoc->Lexicon.LexName;
	
	if(dlg.DoModal()==IDOK)
	{
		//pDoc->Lexicon.SetLex(dlg.m_lex);   //�˳��Ի��򣬶��ĵ���Ĵʿ���и���
		int n=pDoc->Lexicon.GetNumWord();
		for(int i=0;i<n;i++)
		{
			SortId[i]=dlg.sort_id[i];
		}
		pDoc->Lexicon.LexName=dlg.m_LexName;
		Invalidate();
	}
}

//DEL BOOL CDS_EnglishView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//DEL }

int CDS_EnglishView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{


	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_BlackFlag=5;
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL);
	return 0;
}

/*OnTimer
 *ʵʱ������
 *����ʱʱ��ֹͣ
 *û����ʱ��ʱ��һֱ��������
 */

void CDS_EnglishView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(status==1&&m_rt==0)
	{
		m_time++;
		Invalidate();
	}
	if(m_rt!=0)
	{	
		CDS_EnglishDoc *pDoc=GetDocument();
		ptime++;
		if(ptime==m_ptime)
		{
			m_rt=0;
			m_BlackFlag=0;
			
			(pDoc->Lexicon.GetWord(SortId[now_index-1]-1)->false_num)++;
			if(pDoc->Lexicon.GetNumWord()>0)
			{
				now_index-=m_punish_value;
				if(now_index<=0)
				{
					//MessageBox("������!\n����ӵ���!����ǰ��!");
						now_index=1; //��ѭ��
				}
			}
			pDoc->Lexicon.now_word_id=now_index;
			Invalidate(); //����
			pDoc->UpdateAllViews(this);
		}
	}
	CView::OnTimer(nIDEvent);
}


/*OnLButtonDown
 *��갴����Ϣ��Ӧ����
 *������갴�µ�����ȷ��GO��STOP��ť
 *����������ģʽ
 */
void CDS_EnglishView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//299,7,395,96
	// TODO: Add your message handler code here and/or call default
	CDS_EnglishDoc *pDoc=GetDocument();
	if(point.x>299&&point.x<395&&point.y>7&&point.y<96)
	{
		if(status==0)     //go��ť���������ʼ����
		{
			if(pDoc->Lexicon.GetNumWord()==0)
			{
				MessageBox("�ʿ���û�е��ʣ�����ӣ�");
				return ;
			}
			status=1;
			m_time=0;
			m_BlackFlag=0;
			Invalidate();
			//MessageBox("��ʼ���䵥�ʣ�");
			CMODELSET dlg; //����ģʽ���öԻ���
			CString st;
			dlg.m_pValue=this->m_last_pstring;
			st.Format("%d",m_ptime);
			dlg.m_pTime=st;
			if(dlg.DoModal()==IDOK)  //�Ի���ȷ��ʱ������Ϣ
			{
				this->m_punish_string=dlg.m_pValue;
				this->m_punish_value=atoi(dlg.m_pValue);//atoi���ɽ��ַ����������
				this->m_ptime=atoi(dlg.m_pTime);
				m_last_pstring=dlg.m_pValue;
				Invalidate();
			}
		}
		else
		{
			status=0;
			m_BlackFlag=5;
			Invalidate();
			MessageBox("���䵥�ʽ�����");
		}



	}
	CView::OnLButtonDown(nFlags, point);
}


/*OnKeyDown
 *������Ϣ����
 *��Ҫ�����ж�����ң��Ϻ������ĸ�����
 *����ǲ���ʶ���Ҿ�����ʶ���Ϻ��¿��Ƶ�����ʾ
 */

void CDS_EnglishView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

	// TODO: Add your message handler code here and/or call default


	int max;
	CDS_EnglishDoc *pDoc=GetDocument();
	now_index=pDoc->Lexicon.now_word_id;
	max=pDoc->Lexicon.GetNumWord();
	if(status==1&&nChar==VK_UP)
	{
		if(m_BlackFlag==0)
			m_BlackFlag=9;
		else
			m_BlackFlag=m_BlackFlag-1;
		Invalidate();
		
	}
	else if(status==1&&nChar==VK_DOWN)
	{
		if(m_BlackFlag==9)
			m_BlackFlag=0;
		else
			m_BlackFlag=m_BlackFlag+1;
		Invalidate();
		
	}
	else if(status==1&&nChar==VK_LEFT&&m_rt==0)
	{
		//if(now_index==1)
		//{
		//	(pDoc->Lexicon.GetWord(now_index-1)->false_num)++;
		//	now_index=max;
		//}
		//else 
		if(now_index<=0)
		{
			MessageBox("������!\n����ӵ���!����ǰ��!");
		}
		else 
		{
		
			
		}
	
		ptime=0;
		m_rt=1;
		m_BlackFlag=5;
		Invalidate();
		pDoc->UpdateAllViews(this);

	
	}
	else if(status==1&&(nChar==VK_RIGHT))
	{

		if(now_index==0)
		{
			MessageBox("�ʿ���û�е��ʣ�\n����ӵ��ʣ�");
		}
		else if(now_index==max)
		{
			pDoc->Lexicon.GetWord(SortId[now_index-1]-1)->right_num++;
			now_index=1;
		}
		else 
		{
			pDoc->Lexicon.GetWord(SortId[now_index-1]-1)->right_num++;
			now_index++;

		}

		pDoc->Lexicon.now_word_id=now_index;
		m_BlackFlag=0;
		Invalidate();
		pDoc->UpdateAllViews(this);
	}
	
	pDoc->SetModifiedFlag();



	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDS_EnglishView::OnUpdateAddmany(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL checkl;
	if(status==1)
		checkl=false;
	else checkl=true;
	pCmdUI->Enable(checkl);
}

void CDS_EnglishView::OnUpdateAddWord(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL checkl;
	if(status==1)
		checkl=false;
	else checkl=true;
	pCmdUI->Enable(checkl);
}

void CDS_EnglishView::OnUpdateFileOpen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL checkl;
	if(status==1)
		checkl=false;
	else checkl=true;
	pCmdUI->Enable(checkl);	
}

void CDS_EnglishView::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL checkl;
	if(status==1)
		checkl=false;
	else checkl=true;
	pCmdUI->Enable(checkl);	
}
