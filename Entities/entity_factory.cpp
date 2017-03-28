#include "entity_factory.h"

EntityFactory* EntityFactory::inst;

void EntityFactory::registerEnt(std::string name, std::function<Entity*()> construction_func) {
	map.emplace(name, construction_func);
}

Entity* EntityFactory::constructEnt(std::string name) {
	if (map.count(name) == 0) {
		throw std::runtime_error("Unable to instantiate entity of type '" + name + "'");
	}
	else {
		return map[name]();
	}
}
