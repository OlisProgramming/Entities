#include "entity.h"

EntityComponent::EntityComponent() {
}

EntityComponent* EntityComponent::load(SaveFileReader& sfr) {
	return this;
}

void EntityComponent::save(SaveFileWriter& sfw) {
}
