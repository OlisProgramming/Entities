#pragma once

#include "file_save.h"

class EntityFactory;

class EntityComponent {

public:
	EntityComponent();
	virtual EntityComponent* load(SaveFileReader& sfr);
	virtual void save(SaveFileWriter& sfw);
	virtual std::string toString();
};

class Entity {

private:
	std::vector<EntityComponent*> components;

public:
	Entity();
	~Entity();
	inline void addComponent(EntityComponent* comp) { components.push_back(comp); }
	virtual Entity* load(SaveFileReader& sfr);
	virtual void save(SaveFileWriter& sfw);
	std::string toString();
};

#include "entity_fields.h"