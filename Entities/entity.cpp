#include "entity.h"

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

Entity::Entity() {
}

std::string Entity::toString() {
	std::string s = "{ ";
	for (EntityComponent& comp : components) {
		s += comp.toString() + " ";
	}
	return s + "}";
}
