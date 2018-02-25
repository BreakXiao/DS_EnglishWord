// Word.h: interface for the CWord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORD_H__911759A2_70DD_48CB_BFBD_A044EF1F0FE3__INCLUDED_)
#define AFX_WORD_H__911759A2_70DD_48CB_BFBD_A044EF1F0FE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWord:public CObject
{
public:
	CWord(int id,CString EM,CString CM);
	CWord();
	CWord(const CWord &w);//拷贝构造函数
	virtual ~CWord();
public:
	int word_id;  //单词编号
	CString EngMean;  //英文意思
	CString ChiMean;  //中文意思
	int false_num;   //错误次数
	int right_num;   //正确次数

public:
	void ChangeWord(int id,CString EM,CString CM,int r,int f);  //更改单词信息
	CString show_EngMean();   //返回英文意思
	CString show_ChiMean();   //返回中文意思
	int false_add();               //错误次数增加
	int right_add();               //正确次数增加
	void Serialize(CArchive &ar);	//类CWord的序列化函数
	DECLARE_SERIAL(CWord)			//声明序列化类CWord
};





#endif // !defined(AFX_WORD_H__911759A2_70DD_48CB_BFBD_A044EF1F0FE3__INCLUDED_)
