#pragma once

#include "entity.h"
#include "entity_factory.h"

/**
\brief An EntityComponent that stores a 3-Dimensional position vector.
*/
class CPos3 : public EntityComponent {

public:
	CPos3() {}

	ENT_REGISTER_FIELDS_3(
		CPos3,
		float, x,
		float, y,
		float, z
	)
};

/**
\brief An EntityComponent that stores a std::string tagging the Entity.
*/
class CTag : public EntityComponent {

public:
	CTag() {}

	ENT_REGISTER_FIELDS_1(
		CTag,
		std::string, tag
	)
};

void entRegisterBaseComponents() {
	ENT_COMP_REGISTER(CPos3);
	ENT_COMP_REGISTER(CTag);
}