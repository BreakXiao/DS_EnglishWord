// Word.cpp: implementation of the CWord class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DS_English.h"
#include "Word.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CWord,CObject,1);
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWord::CWord(int id,CString EM,CString CM)
{

	word_id=id;
	EngMean=EM;
	ChiMean=CM;
	false_num=right_num=0;
	
}

CWord::CWord(const CWord &w)
{
	word_id=w.word_id;
	EngMean=w.EngMean;
	ChiMean=w.ChiMean;
	false_num=w.false_num;
	right_num=w.right_num;
}

CWord::~CWord()
{

}

CString CWord::show_EngMean()
{
	return EngMean;
}

CString CWord::show_ChiMean()
{
	return ChiMean;
}

int CWord::false_add()
{
	false_num++;
	return false_num;
}

int CWord::right_add()
{
	right_num++;
	return right_num;
}

void CWord::ChangeWord(int id,CString EM,CString CM,int r,int f)
{
	word_id=id;
	EngMean=EM;
	ChiMean=CM;
	false_num=f;
	right_num=r;
}

CWord::CWord()
{
	word_id=0;
	EngMean=" ";
	ChiMean=" ";
	false_num=0;
	right_num=0;
}

void CWord::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
	{
		ar<<word_id;
		ar<<EngMean;
		ar<<ChiMean;
		ar<<false_num;
		ar<<right_num;
	}
	else
	{
		ar>>word_id;
		ar>>EngMean;
		ar>>ChiMean;
		ar>>false_num;
		ar>>right_num;
	}
}