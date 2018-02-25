// LexSet.cpp : implementation file
//

#include "stdafx.h"
#include "DS_English.h"
#include "LexSet.h"
#include <stdlib.h>
#include<time.h> 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLexSet dialog


CLexSet::CLexSet(CWnd* pParent /*=NULL*/)
	: CDialog(CLexSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLexSet)
	m_LexName = _T("");
	//}}AFX_DATA_INIT
}


void CLexSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLexSet)
	DDX_Text(pDX, IDC_LexName, m_LexName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLexSet, CDialog)
	//{{AFX_MSG_MAP(CLexSet)
	ON_BN_CLICKED(IDC_UPSET_ID, OnUpsetId)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLexSet message handlers

BOOL CLexSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



/*OnUpsetId                     
 *使单词编号乱序的函数                      
 *方法是利用随机函数产生一个1-n但顺序混乱的数组                     
 *使数组重新编排
 */ 
void CLexSet::OnUpsetId() 
{
	// TODO: Add your control notification handler code here
	srand((int)time(NULL));   //随机种子
	int n=m_lex.GetNumWord();
	int *id_room=(int *)malloc((n) * sizeof(int)),k,m;
	for(int i=0;i<n;i++)
	{
		id_room[i]=-1;
	}
	int id=1;
	while(id!=n+1)
	{
		k=rand()%n;  //k是在1-n之间随机的一个数字
		m=rand()%2;  //当k位置已经被利用过时，随机一个0或1，
		             //是0的话往k前方搜寻空位，是1的话往后搜寻空位
		while(1)
		{
			if(id_room[k]==-1)
			{
				id_room[k]=id;
				id++;
				break;
			}
			else
			{
				if(m==0)
					k=k-1;
				else k=k+1;
				if(k==-1) k=n-1;
				if(k==n)  k=0;
			}
		}
	}
	for(i=0;i<n;i++)  //将重新编排的序号放进sort_id中
	{
		sort_id[i]=id_room[i];
	}
	MessageBox("乱序成功！");	
}
