#pragma once

#include "file_save.h"

class EntityFactory;

/**
Base class for all EntityComponents.
Override this class.
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
};

/**
Contains a std::vector of EntityComponent objects. Do not override this class.
Entities are controlled by their EntityComponents.
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
	/** Fills this instance with EntityComponents from the save file \p sfr. */
	Entity* load(SaveFileReader& sfr);
	/** Saves this instance's data to the save file \p sfw. */
	void save(SaveFileWriter& sfw);
	/** Stringifies this Entity (for debug printing messages). */
	std::string toString();
};

#include "entity_fields.h"