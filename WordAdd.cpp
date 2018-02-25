// WordAdd.cpp : implementation file
//

#include "stdafx.h"
#include "DS_English.h"
#include "WordAdd.h"
#include "Word.h"
#include "Lexicon1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordAdd dialog


CWordAdd::CWordAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CWordAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordAdd)
	m_AddWord = _T("");
	//}}AFX_DATA_INIT

}


void CWordAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordAdd)
	DDX_Text(pDX, IDC_EDIT2, m_AddWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWordAdd, CDialog)
	//{{AFX_MSG_MAP(CWordAdd)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordAdd message handlers

void CWordAdd::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString em,cm,s,ss,sss;
	CWord w;
	int len=m_AddWord.GetLength(),len2,n,i;
	n=m_lex.GetNumWord();

	
	
	int flag;//转换指令
	s=m_AddWord;
	int en=0,cn=0;

	for(flag=1,i=0;i<len;i++)
	{
		if(flag==1)   //1为正在英文前的空格期
		{

			if(s[i+1]!=' ')  //如果下一个不为空格，进入英文扫描期
			{
				flag=2;
				if(s[i]!=' ')  //若本身没有前缀空格，i需要减一
				{
					i=i-1;
				}
			}
			
		}

		else if(flag==2)    //2为英文的扫描期
		{
			em+=s[i];
			en++;
			if(s[i+1]==' ')   //如果下一个为空格，再次进入空格期
			{
				flag=3;
			}
		}
		else if(flag==3)
		{
			if(s[i+1]!=' ')  //如果下一个不为空格，进入中文扫描期
			flag=4;
		}
		else if(flag==4)
		{

			if(i==len-1||s[i+1]=='\n')
			{
				flag=1;
				
				if(i==len-1)
				{
					cm+=s[i];
					cn++;
				}
			
				w.ChangeWord(n++,em,cm,0,0);  //将扫描的单词放入词库
				m_lex.AddWord(w);
	
				em.Delete(0,en);
				cm.Delete(0,cn);
				en=cn=0;
				continue;
			}
			cm+=s[i];
			cn++;
		}

	}


	MessageBox("添加成功！");
	CDialog::OnCancel();
}
