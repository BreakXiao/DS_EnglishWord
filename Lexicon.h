// Lexicon.h: interface for the CLexicon class.
//
//////////////////////////////////////////////////////////////////////
/*
#if !defined(AFX_LEXICON_H__7AED53A8_3AAF_41A3_A5F8_46C8C4CE80C3__INCLUDED_)
#define AFX_LEXICON_H__7AED53A8_3AAF_41A3_A5F8_46C8C4CE80C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define MAX 1000

class CWord;
class CLexicon  //词库类
{
public:
	CLexicon();
	virtual ~CLexicon();
private:
	CWord *m_word;	//单词数组
	int word_num;		//单词数量
	int now_word_id;	//当前所背单词，用ID表示
public:
	void add_word(CWord add_w);		//增加单词
	void hide_word(CWord hide_w);	//隐藏单词
	void get_right();				//单词理解正确
	void get_false();				//单词理解错误


};
*/
#endif // !defined(AFX_LEXICON_H__7AED53A8_3AAF_41A3_A5F8_46C8C4CE80C3__INCLUDED_)
