#include "entity_factory.h"

EntityFactory* EntityFactory::inst;

void EntityFactory::registerEntComp(std::string name, std::function<EntityComponent*()> construction_func) {
	map.emplace(name, construction_func);
}

EntityComponent* EntityFactory::constructEntComp(std::string name) {
	if (map.count(name) == 0) {
		throw std::runtime_error("Unable to instantiate entity component of type '" + name + "'");
	}
	else {
		return map[name]();
	}
}
