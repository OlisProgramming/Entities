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

void Entity::addChild(Entity* ent) {
	children.push_back(ent);
}

std::vector<Entity*>& Entity::getChildren() {
	return children;
}



Entity* Entity::load(SaveFileReader& sfr) {
	size_t component_size = sfr.read<size_t>();
	std::cout << "Instantiating entity with " << component_size << " components\n";
	for (unsigned i = 0; i < component_size; ++i) {
		unsigned int ind = sfr.read<unsigned int>();
		std::string name = sfr.getEntCompName(ind);
		std::cout << "Registering component " << name << " (indexed " << ind << ")" << std::endl;
		addComponent(ENT_COMP_CONSTRUCT_SAVED(name, sfr));
	}

	size_t children_size = sfr.read<size_t>();
	std::cout << "Entity has " << children_size << " children\n";
	for (unsigned i = 0; i < children_size; ++i) {
		children.push_back((new Entity)->load(sfr));
	}

	return this;
}

void Entity::save(SaveFileWriter& sfw) {
	sfw.write<size_t>(components.size());
	for (EntityComponent* comp : components) comp->save(sfw);
	sfw.write<size_t>(children.size());
	for (Entity* child : children) child->save(sfw);
}

std::string Entity::toString() {
	std::string s = "[Components = { ";
	for (EntityComponent* comp : components) {
		s += comp->toString() + " ";
	}
	s += "} Children = { ";
	for (Entity* ent : children) {
		s += ent->toString() + " ";
	}
	return s + "}]";
}
