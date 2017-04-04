#pragma once

#include "file_save.h"

/** \file
Contains the classes Entity and EntityComponent, as well as many macros aiding the use of these classes.
*/

class EntityFactory;

/**
\brief Base class for all EntityComponents (named \p C...)

Override this class, but if overriding subclasses of this class, DO NOT reuse the macros mentioned below, i.e. do not have any more saveable data.
Instances of these classes are members of Entity objects.

Inside derived class definitions, place the macro \p ENT_REGISTER_FIELDS_n (declared in file entity_fields.h), where \p n is the amount of fields in the class you would like to be saved into a save file.
Even if you do not wish to save any data in save files, you MUST still declare one of these macros (in this case, \p ENT_REGISTER_FIELDS_0).

Do not override ::load(), ::save() or ::toString(), since these are handled by the macros mentioned above (\p ENT_REGISTER_FIELDS_0 through 10).
*/
class EntityComponent {

public:
	EntityComponent();
	/** Loads all saved component data from the save file. Overriden by \p ENT_REGISTER_FIELDS_n. */
	virtual EntityComponent* load(SaveFileReader& sfr);
	/** Writes all saveable component data to the save file. Overriden by \p ENT_REGISTER_FIELDS_n. */
	virtual void save(SaveFileWriter& sfw);
	/** Stringifies all saveable component data for debug messages. Overriden by \p ENT_REGISTER_FIELDS_n. */
	virtual std::string toString();
	/** Gets the name of the class. */
	virtual std::string getClassName();
};

/**
\brief The basic object. Contains a std::vector of EntityComponent objects that control it. Do not override this class
*/
class Entity {

private:
	std::vector<EntityComponent*> components;

public:
	Entity();
	/** Deletes all EntityComponents in the private std::vector \p components. */
	~Entity();
	/** Adds an EntityComponent to the private std::vector \p components. This component should be generated with the macros \p ENT_COMP_CONSTRUCT_*. */
	inline void addComponent(EntityComponent* comp) { components.push_back(comp); }
	/** DO NOT use this function directly, use the macro #ENT_GET_COMPONENT()! Gets the first EntityComponent in this Entity with the class name of \p className. If none were found, return nullptr. */
	EntityComponent* getComponent(std::string className);
	/** DO NOT use this function directly, use the macro #ENT_GET_COMPONENTS()! Gets a list of all EntityComponent objects in this Entity with the class name of \p className. */
	template<class T> std::vector<T*> getComponents(std::string className);
	/** Fills this instance with EntityComponents from the save file \p sfr. */
	Entity* load(SaveFileReader& sfr);
	/** Saves this instance's data to the save file \p sfw. */
	void save(SaveFileWriter& sfw);
	/** Stringifies this Entity (for debug printing messages). */
	std::string toString();
};

template<class T> inline std::vector<T*> Entity::getComponents(std::string className) {
	std::vector<T*> vec;
	for (EntityComponent* comp : components) {
		if (comp->getClassName() == className) {
			vec.push_back((T*)comp);
		}
	}
	return vec;
}

#define ENT_GET_COMPONENT(ent, _class) ((_class*)(ent.getComponent(#_class)))
#define ENT_GET_COMPONENTS(ent, _class) (ent.getComponents<_class>(#_class))

#include "entity_fields.h"
