#pragma once
#include "Common.h"

class GCCTypeInfo;

class GCCVtable
{

public:
	ea_t ea;
	signed long ptrDiff;
	unsigned int methodsCount;
	GCCTypeInfo *typeInfo;

};

class GCCVtableInfo
{
public:
	GCCVtableInfo();
	~GCCVtableInfo();

	ea_t ea_start;
	ea_t vtbl_start;
	qstring typeName;
	GCCTypeInfo *typeInfo;
	unsigned int vtablesCount;
	GCCVtable *vtables;
	ea_t ea_end;

	static GCCVtableInfo *parseVtableInfo(ea_t ea);
	static bool parseVtableInnerInfo(ea_t ea, GCCVtable *vtbl);
};

