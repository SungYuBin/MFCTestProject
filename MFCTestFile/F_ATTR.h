#pragma once
#include<vector>

struct ATTR {

	/*
	* Numeric attribute code
	* Format		: b12
	* Description	: A valid attribute code as defined in the ATCS field of the Dataset General Information Record
	*/
	unsigned m_natc;
	/*
	* Attribute index
	* Format		: b12
	* Description	: Index (position) of the attribute in the sequence of attributes with the same code and the same parent (starting with 1).
	*/
	unsigned m_atix;
	/*
	* Parent index
	* Format		: b12
	* Description	: Index (position) of the parent complex attribute within this ATTR field (starting with 1).
	  If the attribute has no parent (top level attribute) the value is 0.
	*/
	unsigned m_paix;
	/*
	* Attribute instruction
	* Format		: b11
	* {1} - Insert
	* {2} - Delete
	* {3} - Modify
	*/
	unsigned m_atin;
	/*
	* Attribute value
	* Format		: A()
	* A string containing a valid value for the domain of the attribute specified by the subfields above.
	*/
	CString m_atvl;

	/*
	* Attribute name
	* Format		: A()
	* A string containing a valid value for the domain of the attribute specified by the subfields above.
	*/
	CString m_atname;

	static const int size = 7;



};

class F_ATTR
{
public:
	F_ATTR(void);
	~F_ATTR(void);
	/*
	* Attribute Array
	*/
	std::vector<ATTR*> m_arr;

public:
	void ReadField(BYTE *&buf);
	void ReadField(BYTE *&buf, int loopCnt);
	BOOL Save(CFile *file);
	unsigned GetFieldLength();
};

