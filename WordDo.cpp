// WordDo.cpp : implementation file
//

#include "stdafx.h"
#include "DS_English.h"
#include "WordDo.h"
#include "Word.h"

#include "DS_EnglishDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordDo dialog

/*CWordDo                     
 *构造函数                      
 *系统自己生成                                
 */ 
CWordDo::CWordDo(CWnd* pParent /*=NULL*/)
	: CDialog(CWordDo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordDo)
	m_c_mean = _T("");
	m_e_mean = _T("");
	m_FlaseNum = 0;
	m_RightNum = 0;
	m_word_id = 0;
	m_LexName = _T("");
	//}}AFX_DATA_INIT
}


void CWordDo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordDo)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_CHIMEAN, m_c_mean);
	DDX_Text(pDX, IDC_ENGMEAN, m_e_mean);
	DDX_Text(pDX, IDC_FALSE_NUM, m_FlaseNum);
	DDX_Text(pDX, IDC_RIGHT_NUM, m_RightNum);
	DDX_Text(pDX, IDC_WordID, m_word_id);
	DDX_Text(pDX, IDC_LexName, m_LexName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWordDo, CDialog)
	//{{AFX_MSG_MAP(CWordDo)
	ON_BN_CLICKED(IDC_ADD_WORD, OnAddWord)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_DELETE_WORD, OnDeleteWord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordDo message handlers


/*OnAddWord                     
 *“添加”按钮的实现                      
 * 将右侧框内填入的信息存入词库                     
 * 参照的是VC++书上列表框的例子                     
 */ 
void CWordDo::OnAddWord() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int n;
	m_e_mean.TrimLeft();   //去除左右空格
	m_e_mean.TrimRight();
	m_c_mean.TrimLeft();
	m_c_mean.TrimRight();
	
	if( (m_list.FindStringExact(-1,m_e_mean))!=LB_ERR)
	{
		MessageBox("词库中已有此项，不能再添加！");
		return ;
	}

	int nIndex=m_list.AddString(m_e_mean);		//列表框中添加此项
	n=m_lex.GetNumWord();						//获取词库单词总数，以便获取ID值								
	CWord w(n+1,m_e_mean,m_c_mean);				//建立新单词
	m_lex.AddWord(w);
	m_list.SetItemDataPtr(nIndex,new CWord(w));//关联

	m_word_id=w.word_id;
	UpdateData(false);

	
	
}



/*CDS_EnglishDoc* CWordDo::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDS_EnglishDoc)));
	return (CDS_EnglishDoc*)m_pDocument;
}*/

//DEL BOOL CWordDo::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CDialog::Create(IDD, pParentWnd);
//DEL }


/*OnInitDialog                     
 *列表框的初始化函数                      
 *将词库显示一一在列表框中                      
 */ 
BOOL CWordDo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int n,nIndex;
	n=m_lex.GetNumWord();
	m_LexName=m_lex.LexName;
	UpdateData(false);
	CWord w;
	CWord *w2;
	for(int i=0;i<n;i++)
	{
		w2=m_lex.GetWord(i);
		w.ChangeWord(i+1,w2->EngMean,w2->ChiMean,w2->right_num,w2->false_num);
		nIndex=m_list.AddString(w.EngMean);
		m_list.SetItemDataPtr(nIndex,new CWord(w));
	}



	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


/*OnSelchangeList1                     
 *列表框选择函数                     
 *当选中列表框中一个单词时，显示其详细信息                      
 */ 
void CWordDo::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_list.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		CWord *w=(CWord *)m_list.GetItemDataPtr(nIndex);
		m_c_mean=w->ChiMean;
		m_e_mean=w->EngMean;
		m_FlaseNum=w->false_num;
		m_RightNum=w->right_num;
		m_word_id=w->word_id;
		UpdateData(false);
	}
}


/*OnDestroy                   
 *列表框的关闭消息函数                      
 *清空列表框                      
 *释放内存            
 */ 
void CWordDo::OnDestroy() 
{
	CDialog::OnDestroy();
	for(int nIndex=m_list.GetCount()-1;nIndex>=0;nIndex--)
		delete(CWord *)m_list.GetItemDataPtr(nIndex);
	// TODO: Add your message handler code here
	
}

/*OnDeleteWord                   
 *删除按钮函数          
 *删除此单词，释放内存，同时清空右侧信息框的内容                                            
 */ 
void CWordDo::OnDeleteWord() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_list.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		CWord *w=(CWord *)m_list.GetItemDataPtr(nIndex);
		m_lex.DeleteWord(w->EngMean);
		delete(CWord *)m_list.GetItemDataPtr(nIndex);
		m_list.DeleteString(nIndex);
		m_c_mean=m_e_mean=" ";
		m_FlaseNum=m_RightNum=0;
		m_word_id=0;
		UpdateData(false);
		
	}
	
}
