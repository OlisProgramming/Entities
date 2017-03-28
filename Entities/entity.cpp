#include "entity.h"

Entity::Entity() {
}

Entity* Entity::load(SaveFileReader& sfr) {
	return this;
}

void Entity::save(SaveFileWriter& sfw) {
}
