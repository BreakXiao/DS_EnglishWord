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
 *�˺����Ǵʿ���Ĺ��캯��                      
 *�����˴ʿ����ƺ͵�ǰ���ʱ��                      
 */ 
CLexicon::CLexicon()
{
	LexName="��ʱ�ʿ�";
	now_word_id=0;
}


/*CLexicon                   
 *�ʿ���ĸ��ƹ��캯��                      
 *������ĵ����������������ȫ��������һ��                      
 *��������C++�ĸ��ƹ��췽��                      
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
 *ɾ�����ʺ���
 *����Ϊ���ʵ�Ӣ��                      
 *����Ϊ����һ�飬�ҵ���ͬ�ľ�ɾ��                                        
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
 *ɾ���ʿ�                      
 *��ռ���                                    
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
 *Ϊ�ʿ������ʺ���                      
 *����Ϊһ�����������Եĵ���                                            
 */ 
void CLexicon::AddWord(CWord add_w)
{
	CWord *pWord=new CWord(add_w);	//�½�һ�����ʶ���
	m_WordArray.Add(pWord);			//���õ��ʶ�����ӵ���̬����
	if(now_word_id==0)
		this->now_word_id=1;
	
}


/*GetWord                     
 *���ձ�Ż�ȡ���ʺ���                      
 *����Ϊ���                      
 *ֱ������Array���ܵ�GetAt��������ȡ                      
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
 *��ȡ�ʿ��е�����������                      
 *����Ϊ����Array��Getsize����                      
 */ 
int CLexicon::GetNumWord()
{
	return m_WordArray.GetSize();
}


/* SetLex                    
 * �ʿ����ú���                     
 * ��ͬ�ڸ��ƹ��캯��                        
 */ 
void CLexicon::SetLex(const CLexicon &c)   //�ʿ�����
{
	DeleteLex();//�����֮ǰ���еĵ���
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

