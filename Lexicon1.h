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
	CLexicon(const CLexicon &c);//拷贝构造函数
	virtual ~CLexicon();
public:
	CTypedPtrArray<CObArray,CWord*>m_WordArray;	//单词数组，就是这个数组里放了很多的单词，这是参照书上的某个数组做的
	int word_num;		//单词数量
	int now_word_id;	//当前所背单词，用ID表示

//词库的可修改属性
public:
	CString LexName;//词库名


public:
	CWord *GetWord(int nIndex);		//从词库中获取指定编号的单词
	void AddWord(CWord add_w);		//向动态数组中添加新的单词对象的指针
	int GetNumWord();				//获取单词的数量
	void add_word(CWord add_w);		//增加单词
	void hide_word(int hide_num);	//隐藏单词
	void get_right();				//单词理解正确
	void get_false();				//单词理解错误
	void SetLex(const CLexicon &c); //词库赋值，相当于词库的复制构造函数
	void DeleteLex();				//清空词库
	void DeleteWord(CString e);		//按英文删除单词
};

#endif // !defined(AFX_LEXICON1_H__9AA2E573_3EBB_4DF5_9684_2F3087A693AD__INCLUDED_)
