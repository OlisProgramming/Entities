#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
#include "file_save.h"

/** @file

Defines a set of macros for use with the EntityFactory.
Do not interface with the EntityFactory directly, use the macros!

#ENT_COMP_REGISTER\n
#ENT_COMP_CONSTRUCT_BLANK\n
#ENT_COMP_CONSTRUCT_SAVED

*/

class EntityComponent;

/**
\brief Indirectly interfaced when using \p ENT_* macros. Do not handle this class directly!
*/
class EntityFactory {

private:
	/** A map of EntityComponent class names onto their (zero-argument) constructors. */
	std::unordered_map<std::string, std::function<EntityComponent*()>> map;

public:
	/** The singleton instance of this class. */
	static EntityFactory* inst;
	/** Registers an EntityComponent with the factory. NEVER call this function directly, always use #ENT_COMP_REGISTER! */
	void registerEntComp(std::string name, std::function<EntityComponent*()> construction_func);
	/** Constructs an EntityComponent with the given class name. NEVER call this function directly, always use #ENT_COMP_CONSTRUCT_BLANK or #ENT_COMP_CONSTRUCT_SAVED! */
	EntityComponent* constructEntComp(std::string name);
	/** Used by SaveFileWriter to get a list of all registered EntityComponent subclasses. */
	std::vector<std::string>* getEntComps();
};

/**
Registers a class with the EntityFactory.
\param name The class name (not as a string) of the class to be registered.
*/
#define ENT_COMP_REGISTER(name) EntityFactory::inst->registerEntComp(#name, []() { return new name(); })

/**
NEVER use this macro, always use #ENT_COMP_CONSTRUCT_BLANK and/or #ENT_COMP_CONSTRUCT_SAVED!
Creates an EntityComponent subclass that has been previously registered using #ENT_COMP_REGISTER.
\param name The (stringified) name of the class to be created.
*/
#define ENT_COMP_CONSTRUCT_BLANK_STRING_NAMED(name) (EntityFactory::inst->constructEntComp(name))

/**
Creates an EntityComponent subclass that has been previously registered using #ENT_COMP_REGISTER, then casts it to the required type.
\param name The (non-stringified) name of the class to be created.
*/
#define ENT_COMP_CONSTRUCT_BLANK(name) ((name*)(ENT_COMP_CONSTRUCT_BLANK_STRING_NAMED(#name)))

/**
Creates an EntityComponent subclass that has been previously registered using #ENT_COMP_REGISTER, loads it from a save file, then casts it to the required type.
\param name The (non-stringified) name of the class to be created.
\param sfr The save file (SaveFileReader&) to read data from.
*/
#define ENT_COMP_CONSTRUCT_SAVED(name, sfr) (ENT_COMP_CONSTRUCT_BLANK_STRING_NAMED(name)->load(sfr))
