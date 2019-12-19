#pragma once
#include<vector>
class MultiData
{
public:
	/*

	Type 001
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - ENC_Vector* 
		arg 2 - SG2D*
		arg 3 - ENC_Vector*

	Type 011
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - ATTF*

	Type 012
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - NATF*

	Type 100
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - R_VectorRecord*
		arg 2 - IC2D*
		arg 3 - F_C2IL*
		arg 4 - int (index)

	Type 101
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - R_VectorRecord*
		arg 2 - F_C2IT*

	Type 102
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - R_VectorRecord*
		arg 2 - IC3D*
		arg 3 - F_C3IL*
		arg 4 - int (index)

	Type 111
		arg 0 - CMFCPropertyGridProperty *
		arg 1 - R_FeatureRecord*
		arg 2 - ATTR*
	*/

	int type;

	std::vector<DWORD_PTR> data;
};