#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include "file_save.h"

class Entity;

class EntityFactory {

private:
	std::unordered_map<std::string, std::function<Entity*()>> map;

public:
	static EntityFactory* inst;
	void registerEnt(std::string name, std::function<Entity*()> construction_func);
	Entity* constructEnt(std::string name);
};

#define ENT_REGISTER(name) EntityFactory::inst->registerEnt(#name, []() { return new name(); })
#define ENT_CONSTRUCT_BLANK(name) (static_cast<name*>(EntityFactory::inst->constructEnt(#name)))
#define ENT_CONSTRUCT_SAVED(name, sfr) (static_cast<name*>(ENT_CONSTRUCT_BLANK(name)->load(sfr)))