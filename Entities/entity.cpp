#include "entity.h"

#include <iostream>
#include "entity_factory.h"

EntityComponent::EntityComponent() {
}

EntityComponent* EntityComponent::load(SaveFileReader& sfr) {
	return this;
}

void EntityComponent::save(SaveFileWriter& sfw) {
}

std::string EntityComponent::toString() {
	return "(INVALID COMPONENT)";
}

std::string EntityComponent::getClassName() {
	return "EntityComponent";
}

Entity::Entity() {
}

Entity::~Entity() {
	for (EntityComponent* comp : components) delete comp;
}

EntityComponent* Entity::getComponent(std::string className) {
	for (EntityComponent* component : components) {
		if (component->getClassName() == className) {
			return component;
		}
	}
	return nullptr;
}



Entity* Entity::load(SaveFileReader& sfr) {
	size_t size = sfr.read<size_t>();
	std::cout << "Instantiating entity with " << size << " components\n";
	for (unsigned i = 0; i < size; ++i) {
		unsigned int ind = sfr.read<unsigned int>();
		std::string name = sfr.getEntCompName(ind);
		std::cout << "Registering component " << name << " (indexed " << ind << ")" << std::endl;
		addComponent(ENT_COMP_CONSTRUCT_SAVED(name, sfr));
	}
	return this;
}

void Entity::save(SaveFileWriter& sfw) {
	sfw.write<size_t>(components.size());
	for (EntityComponent* comp : components) comp->save(sfw);
}

std::string Entity::toString() {
	std::string s = "{ ";
	for (EntityComponent* comp : components) {
		s += comp->toString() + " ";
	}
	return s + "}";
}
