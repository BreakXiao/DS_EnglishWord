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
	CWord(const CWord &w);//�������캯��
	virtual ~CWord();
public:
	int word_id;  //���ʱ��
	CString EngMean;  //Ӣ����˼
	CString ChiMean;  //������˼
	int false_num;   //�������
	int right_num;   //��ȷ����

public:
	void ChangeWord(int id,CString EM,CString CM,int r,int f);  //���ĵ�����Ϣ
	CString show_EngMean();   //����Ӣ����˼
	CString show_ChiMean();   //����������˼
	int false_add();               //�����������
	int right_add();               //��ȷ��������
	void Serialize(CArchive &ar);	//��CWord�����л�����
	DECLARE_SERIAL(CWord)			//�������л���CWord
};





#endif // !defined(AFX_WORD_H__911759A2_70DD_48CB_BFBD_A044EF1F0FE3__INCLUDED_)
