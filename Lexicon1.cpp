// Lexicon1.cpp: implementation of the CLexicon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DS_English.h"
#include "Lexicon1.h"
#include "Word.h"
#include <afxtempl.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/*CLexicon       
 *此函数是词库类的构造函数                      
 *构造了词库名称和当前单词编号                      
 */ 
CLexicon::CLexicon()
{
	LexName="临时词库";
	now_word_id=0;
}


/*CLexicon                   
 *词库类的复制构造函数                      
 *将里面的单词数组和其他参数全都复制了一遍                      
 *方法参照C++的复制构造方法                      
 */ 
CLexicon::CLexicon(const CLexicon &c)
{
	int n=c.m_WordArray.GetSize();
	CWord w1;CWord *w2;
	for(int i=0;i<n;i++)
	{
		w2=m_WordArray.GetAt(i);
		w1.ChangeWord(w2->word_id,w2->EngMean,w2->ChiMean,w2->right_num,w2->false_num);
		AddWord(w1);
	}
}

CLexicon::~CLexicon()
{
	int nIndex=GetNumWord();
	while(nIndex--)
	{
		delete m_WordArray.GetAt(nIndex);
	}
	m_WordArray.RemoveAll();
}

/*DeleteWord                   
 *删除单词函数
 *参数为单词的英文                      
 *方法为检索一遍，找到相同的就删掉                                        
 */ 
void CLexicon::DeleteWord(CString e)
{
	int nIndex=GetNumWord();
	while(nIndex--)
	{
		if(m_WordArray.GetAt(nIndex)->EngMean==e)
		{
			delete m_WordArray.GetAt(nIndex);
			m_WordArray.RemoveAt(nIndex);
			return ;
		}
	}
}


/*DeleteLex                     
 *删除词库                      
 *清空即可                                    
 */ 
void CLexicon::DeleteLex()
{
	int nIndex=GetNumWord();
	while(nIndex--)
	{
		delete m_WordArray.GetAt(nIndex);
	}
	m_WordArray.RemoveAll();
}


/*AddWord                     
 *为词库增添单词函数                      
 *参数为一个有完整属性的单词                                            
 */ 
void CLexicon::AddWord(CWord add_w)
{
	CWord *pWord=new CWord(add_w);	//新建一个单词对象
	m_WordArray.Add(pWord);			//将该单词对象添加到动态数组
	if(now_word_id==0)
		this->now_word_id=1;
	
}


/*GetWord                     
 *按照编号获取单词函数                      
 *参数为编号                      
 *直接利用Array功能的GetAt函数来获取                      
 */ 
CWord * CLexicon::GetWord(int nIndex)
{
	if(nIndex<0||nIndex>m_WordArray.GetUpperBound())
	{
		return NULL;
	}
	return m_WordArray.GetAt(nIndex);
}


/*GetNumWord                   
 *获取词库中单词数量函数                      
 *方法为利用Array的Getsize函数                      
 */ 
int CLexicon::GetNumWord()
{
	return m_WordArray.GetSize();
}


/* SetLex                    
 * 词库设置函数                     
 * 等同于复制构造函数                        
 */ 
void CLexicon::SetLex(const CLexicon &c)   //词库设置
{
	DeleteLex();//先清空之前所有的单词
	int n=c.m_WordArray.GetSize();
	this->LexName=c.LexName;
	this->now_word_id=c.now_word_id;

	CWord w1;CWord *w2;
	for(int i=0;i<n;i++)
	{
		w2=c.m_WordArray.GetAt(i);
		w1.ChangeWord(w2->word_id,w2->EngMean,w2->ChiMean,w2->right_num,w2->false_num);
		AddWord(w1);
	}
	
}

