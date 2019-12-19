#include "StdAfx.h"
#include "F_ATTR.h"


F_ATTR::F_ATTR(void)
{
}


F_ATTR::~F_ATTR(void)
{
	for (auto itor = m_arr.begin(); itor != m_arr.end(); itor++)
		delete *itor;
}

void F_ATTR::ReadField(BYTE *&buf)
{
	//while (*buf != 0x1E)
	//{
	//	ATTR *attr = new ATTR();
	//	attr->m_natc = buf2uint(buf, 2);
	//	attr->m_atix = buf2uint(buf, 2);
	//	attr->m_paix = buf2uint(buf, 2);
	//	attr->m_atin = *(buf++);
	//	buf2charArr(attr->m_atvl, buf);

	//	//		m_arr.AddTail(attr);
	//	m_arr.push_back(attr);
	//}
}

void F_ATTR::ReadField(BYTE *&buf, int loopCnt)
{
	//for (int i = 0; i < loopCnt; i++)
	//{
	//	ATTR *attr = new ATTR();
	//	attr->m_natc = buf2uint(buf, 2);
	//	attr->m_atix = buf2uint(buf, 2);
	//	attr->m_paix = buf2uint(buf, 2);
	//	attr->m_atin = *(buf++);
	//	buf2charArr(attr->m_atvl, buf);

	//	//m_arr.AddTail(attr);
	//	m_arr.push_back(attr);
	//}
}
BOOL F_ATTR::Save(CFile *file)
{
	//POSITION pos = m_arr.GetHeadPosition();

	//for (auto itor = m_arr.begin(); itor != m_arr.end(); itor++)
	//	//while(pos != NULL)
	//{
	//	//ATTR *attr = m_arr.GetNext(pos);
	//	ATTR *attr = *itor;

	//	file->Write(&attr->m_natc, 2);
	//	file->Write(&attr->m_atix, 2);
	//	file->Write(&attr->m_paix, 2);
	//	file->Write(&attr->m_atin, 1);
	//	CT2CA outputString(attr->m_atvl, CP_UTF8);
	//	file->Write(outputString, ::strlen(outputString));
	//	file->Write(&NonPrintableCharacter::unitTerminator, 1);
	//}
	//file->Write(&NonPrintableCharacter::fieldTerminator, 1);

	//return TRUE;
}


unsigned F_ATTR::GetFieldLength()
{
	unsigned len = 0;

	//POSITION pos = m_arr.GetHeadPosition();

	for (auto itor = m_arr.begin(); itor != m_arr.end(); itor++)
		//while(pos != NULL)
	{
		//ATTR *attr = m_arr.GetNext(pos);
		ATTR *attr = *itor;
		len += ATTR::size;
		CT2CA outputString(attr->m_atvl, CP_UTF8);
		len += ::strlen(outputString) + 1;
	}
	return ++len;
}