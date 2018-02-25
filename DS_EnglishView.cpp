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
 *视图类的构造函数
 *初始化视图上的ptime，rt等参数
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
 *界面的绘制函数
 *具体内容参加内部注释
 */
void CDS_EnglishView::OnDraw(CDC* pDC)
{
	CDS_EnglishDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect EngRect;  //英文框矩形
	EngRect.SetRect(CPoint(50,180),CPoint(650,280));
	CRect ChiRect; //中文框矩形
	ChiRect.SetRect(CPoint(50,300),CPoint(650,400));
	
	pDC->Rectangle(&EngRect);   //绘制英文框
	pDC->Rectangle(&ChiRect);   //绘制中文框
	
	/*****************标题显示操作************************/
	CFont *OldFont,NewFont;
	LOGFONT MyFont1=
	{
		26,				//	高度
		10,				//	宽度
 		0,				//	文本行相对底端倾斜度
		0,				//	字符基线相对底端倾斜度
		0,				//	字体粗细
		0,				//	真时为斜体
		0,				//	真时为下划线
		0,				//	真时为带删除线
		ANSI_CHARSET,	//字符集
		OUT_DEFAULT_PRECIS,//字符输出精度
		CLIP_DEFAULT_PRECIS,//裁剪精度
		PROOF_QUALITY,//输出质量
		DEFAULT_PITCH,	//字库族
		"楷体"			//字体名
	};
	NewFont.CreateFontIndirect(&MyFont1);
	OldFont=pDC->SelectObject(&NewFont);
	CString lex_name="当前词库:";
	lex_name+=pDoc->Lexicon.LexName;
	pDC->TextOut(50,50,lex_name);
	
	CString model_name="当前模式:";   //模式选择
	CString mname="惩罚模式";
	model_name+=mname;
	pDC->TextOut(50,80,model_name);

	CString p_s="惩罚值::";   //惩罚值选择
	p_s+=this->m_punish_string;
	pDC->TextOut(50,110,p_s);
	
	CString p_ts="惩罚时间:",st;   //惩罚时间选择
	st.Format("%d",m_ptime);
	if(status==1) p_ts+=st;
	pDC->TextOut(50,140,p_ts);

	pDC->SelectObject(OldFont);
	NewFont.DeleteObject();
	/*****************标题显示操作************************/


	/*****************按钮显示操作************************/
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
	



	/*****************按钮显示操作************************/

	/*****************时间操作************************/
	LOGFONT MyFont3=
	{
		27,				//	高度
		9,				//	宽度
 		0,				//	文本行相对底端倾斜度
		0,				//	字符基线相对底端倾斜度
		1,				//	字体粗细
		0,				//	真时为斜体
		0,				//	真时为下划线
		0,				//	真时为带删除线
		ANSI_CHARSET,	//字符集
		OUT_DEFAULT_PRECIS,//字符输出精度
		CLIP_DEFAULT_PRECIS,//裁剪精度
		PROOF_QUALITY,//输出质量
		DEFAULT_PITCH,	//字库族
		"黑体"			//字体名
	};
	NewFont.CreateFontIndirect(&MyFont3);
	OldFont=pDC->SelectObject(&NewFont);
	if(status==1)
	{
		CString stime="时间： ";
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
	/*****************时间操作************************/
	




	/*****************单词显示操作************************/
	CWord w(0,"Destroy Dawn","破晓英文软件");
	LOGFONT MyFont2=
	{
		78,				//	高度
		26,				//	宽度
 		0,				//	文本行相对底端倾斜度
		0,				//	字符基线相对底端倾斜度
		0,				//	字体粗细
		0,				//	真时为斜体
		0,				//	真时为下划线
		0,				//	真时为带删除线
		ANSI_CHARSET,	//字符集
		OUT_DEFAULT_PRECIS,//字符输出精度
		CLIP_DEFAULT_PRECIS,//裁剪精度
		PROOF_QUALITY,//输出质量
		DEFAULT_PITCH,	//字库族
		"黑体"			//字体名
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
			CWord wno(0,"NO Word","词库内没有单词");
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
	/*****************单词显示操作************************/



	/*****************遮蔽方块显示操作************************/
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
	
	/*****************遮蔽方块显示操作************************/

	/*****************答错答对提示********************/
	LOGFONT MyFont4=
	{
		42,				//	高度
		13,				//	宽度
 		0,				//	文本行相对底端倾斜度
		0,				//	字符基线相对底端倾斜度
		2,				//	字体粗细
		1,				//	真时为斜体
		0,				//	真时为下划线
		0,				//	真时为带删除线
		ANSI_CHARSET,	//字符集
		OUT_DEFAULT_PRECIS,//字符输出精度
		CLIP_DEFAULT_PRECIS,//裁剪精度
		PROOF_QUALITY,//输出质量
		DEFAULT_PITCH,	//字库族
		"黑体"			//字体名
	};
	NewFont.CreateFontIndirect(&MyFont4);
	OldFont=pDC->SelectObject(&NewFont);
	if(m_rt==1)
	{
		pDC->SetTextColor(RGB(128,0,0));
		pDC->TextOut(400,130,"答错了!");
	}
	else if(m_rt==2)
	{
		pDC->SetTextColor(RGB(0,255,255));
		pDC->TextOut(400,130,"答对啦~");
	}
	pDC->SelectObject(OldFont);
	NewFont.DeleteObject();
	/*****************答错答对提示********************/		


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
 *“删减单词”按钮消息的响应
 *模态对话框的创建方式
 *退出时信息更新
 */
void CDS_EnglishView::OnAddWord() 
{
	// TODO: Add your command handler code here
	CWordDo dlg;
	CDS_EnglishDoc *pDoc=GetDocument();		//获取指针
	dlg.m_lex.SetLex(pDoc->Lexicon);		//将文档类里的词库复制到对话框里的词库中		
	
	
	if(dlg.DoModal()==IDCANCEL)
	{
		pDoc->Lexicon.SetLex(dlg.m_lex);   //退出对话框，对文档类的词库进行更新
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
	CDS_EnglishDoc *pDoc=GetDocument();		//获取指针
	dlg.m_lex.SetLex(pDoc->Lexicon);		//将文档类里的词库复制到对话框里的词库中		
	
	
	if(dlg.DoModal()==IDCANCEL)
	{
		pDoc->Lexicon.SetLex(dlg.m_lex);   //退出对话框，对文档类的词库进行更新
	}
	pDoc->SetModifiedFlag();

}
/*OnChange
 *词库设置界面的响应函数
 *可修改词库名称和单词顺序
 */
void CDS_EnglishView::OnChange() 
{
	// TODO: Add your command handler code here
	CLexSet dlg;
	CDS_EnglishDoc *pDoc=GetDocument();		//获取指针
	dlg.m_lex.SetLex(pDoc->Lexicon);		//将文档类里的词库复制到对话框里的词库中		
	dlg.m_LexName=pDoc->Lexicon.LexName;
	
	if(dlg.DoModal()==IDOK)
	{
		//pDoc->Lexicon.SetLex(dlg.m_lex);   //退出对话框，对文档类的词库进行更新
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
 *实时处理函数
 *错误时时间停止
 *没错误时。时间一直有序增加
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
					//MessageBox("到底了!\n请添加单词!或者前进!");
						now_index=1; //可循环
				}
			}
			pDoc->Lexicon.now_word_id=now_index;
			Invalidate(); //更新
			pDoc->UpdateAllViews(this);
		}
	}
	CView::OnTimer(nIDEvent);
}


/*OnLButtonDown
 *鼠标按下消息响应函数
 *按照鼠标按下的坐标确定GO和STOP按钮
 *开启背单词模式
 */
void CDS_EnglishView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//299,7,395,96
	// TODO: Add your message handler code here and/or call default
	CDS_EnglishDoc *pDoc=GetDocument();
	if(point.x>299&&point.x<395&&point.y>7&&point.y<96)
	{
		if(status==0)     //go按钮被点击，开始运行
		{
			if(pDoc->Lexicon.GetNumWord()==0)
			{
				MessageBox("词库内没有单词！请添加！");
				return ;
			}
			status=1;
			m_time=0;
			m_BlackFlag=0;
			Invalidate();
			//MessageBox("开始记忆单词！");
			CMODELSET dlg; //创建模式设置对话框
			CString st;
			dlg.m_pValue=this->m_last_pstring;
			st.Format("%d",m_ptime);
			dlg.m_pTime=st;
			if(dlg.DoModal()==IDOK)  //对话框确定时更新信息
			{
				this->m_punish_string=dlg.m_pValue;
				this->m_punish_value=atoi(dlg.m_pValue);//atoi，可将字符串变成数字
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
			MessageBox("记忆单词结束！");
		}



	}
	CView::OnLButtonDown(nFlags, point);
}


/*OnKeyDown
 *按键消息函数
 *主要用来判断左和右，上和下这四个按键
 *左就是不认识，右就是认识，上和下控制单词显示
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
			MessageBox("到底了!\n请添加单词!或者前进!");
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
			MessageBox("词库内没有单词！\n请添加单词！");
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
