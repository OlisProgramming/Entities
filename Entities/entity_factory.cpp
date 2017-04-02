#include "entity_factory.h"

EntityFactory* EntityFactory::inst;

void EntityFactory::registerEntComp(std::string name, std::function<EntityComponent*()> construction_func) {
	map.emplace(name, construction_func);
}

EntityComponent* EntityFactory::constructEntComp(std::string name) {
	if (map.count(name) == 0) {
		std::cerr << "Unable to instantiate entity component of type '" << name << "'." << std::endl;
		for (unsigned int i = 0; i < name.size(); ++i)
			std::cerr << i << ": " << name[i] << std::endl;
		system("PAUSE");
		std::exit(-1);
	}
	else {
		return map[name]();
	}
}

std::vector<std::string>* EntityFactory::getEntComps() {
	std::vector<std::string>* vec = new std::vector<std::string>();
	for (auto pair : map) {
		vec->push_back(pair.first);
	}
	return vec;
}
