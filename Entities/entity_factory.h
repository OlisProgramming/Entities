#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
#include "file_save.h"

class EntityComponent;

class EntityFactory {

private:
	std::unordered_map<std::string, std::function<EntityComponent*()>> map;

public:
	static EntityFactory* inst;
	void registerEntComp(std::string name, std::function<EntityComponent*()> construction_func);
	EntityComponent* constructEntComp(std::string name);
	std::vector<std::string>* getEntComps();
};

#define ENT_COMP_REGISTER(name) EntityFactory::inst->registerEntComp(#name, []() { return new name(); })
#define ENT_COMP_CONSTRUCT_BLANK_STRING_NAMED(name) (EntityFactory::inst->constructEntComp(name))
#define ENT_COMP_CONSTRUCT_BLANK(name) ((name*)(ENT_COMP_CONSTRUCT_BLANK_STRING_NAMED(#name)))
#define ENT_COMP_CONSTRUCT_SAVED(name, sfr) (ENT_COMP_CONSTRUCT_BLANK_STRING_NAMED(name)->load(sfr))