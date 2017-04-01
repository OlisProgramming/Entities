#pragma once

#include "file_save.h"

class EntityFactory;

class EntityComponent {

public:
	EntityComponent();
	virtual EntityComponent* load(SaveFileReader& sfr);
	virtual void save(SaveFileWriter& sfw);
};

#include "entity_fields.h"
/*
#define ENT_REGISTER_FIELDS(type0,var0) \
public:	\
	type0 var0; \
	virtual inline void save(SaveFileWriter& sfw) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(var0.length()); \
			sfw.write_array<char>(const_cast<char*>(var0.c_str()), var0.length()); \
		} \
		else \
			sfw.write<type0>(var0); \
	} \
	virtual inline Entity* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") {\
\
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			var0 = std::string(&(*vec)[0], &(*vec)[0] + size); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<std::string>(); \
		return this; \
	}*/

//size_t s = ; \