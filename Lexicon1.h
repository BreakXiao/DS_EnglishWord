// Lexicon1.h: interface for the CLexicon class.
//
//////////////////////////////////////////////////////////////////////
#include "Word.h"
#include <afxtempl.h>
#define MAX 1000
#if !defined(AFX_LEXICON1_H__9AA2E573_3EBB_4DF5_9684_2F3087A693AD__INCLUDED_)
#define AFX_LEXICON1_H__9AA2E573_3EBB_4DF5_9684_2F3087A693AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLexicon  
{
public:
	CLexicon();
	CLexicon(const CLexicon &c);//�������캯��
	virtual ~CLexicon();
public:
	CTypedPtrArray<CObArray,CWord*>m_WordArray;	//�������飬���������������˺ܶ�ĵ��ʣ����ǲ������ϵ�ĳ����������
	int word_num;		//��������
	int now_word_id;	//��ǰ�������ʣ���ID��ʾ

//�ʿ�Ŀ��޸�����
public:
	CString LexName;//�ʿ���


public:
	CWord *GetWord(int nIndex);		//�Ӵʿ��л�ȡָ����ŵĵ���
	void AddWord(CWord add_w);		//��̬����������µĵ��ʶ����ָ��
	int GetNumWord();				//��ȡ���ʵ�����
	void add_word(CWord add_w);		//���ӵ���
	void hide_word(int hide_num);	//���ص���
	void get_right();				//���������ȷ
	void get_false();				//����������
	void SetLex(const CLexicon &c); //�ʿ⸳ֵ���൱�ڴʿ�ĸ��ƹ��캯��
	void DeleteLex();				//��մʿ�
	void DeleteWord(CString e);		//��Ӣ��ɾ������
};

#endif // !defined(AFX_LEXICON1_H__9AA2E573_3EBB_4DF5_9684_2F3087A693AD__INCLUDED_)
