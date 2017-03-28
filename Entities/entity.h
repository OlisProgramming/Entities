#pragma once

#include "file_save.h"

class EntityFactory;

class Entity {

public:
	Entity();
	virtual Entity* load(SaveFileReader& sfr);
	virtual void save(SaveFileWriter& sfw);
};

#define ENT_REGISTER_FIELDS(type0,var0) \
public:	\
	type0 var0; \
	virtual void save(SaveFileWriter& sfw) override { \
		sfw.write<type0>(var0); \
	} \
	virtual Entity* load(SaveFileReader& sfr) override { \
		var0 = sfr.read<type0>(); \
		return this; \
	}