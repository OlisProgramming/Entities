#include <iostream>

#include "entity.h"
#include "entity_factory.h"

class EntityComponentPos3 : public EntityComponent {

public:
	EntityComponentPos3() {}

	ENT_REGISTER_FIELDS_4(
		EntityComponentPos3,
		float, x,
		float, y,
		float, z,
		std::string, q
	)
};

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();
//	EntityFactory::inst->registerEnt("EntTest1", []() { return new EntTest1(); });


	ENT_REGISTER(EntityComponentPos3);

	EntityComponentPos3* ent = ENT_CONSTRUCT_BLANK(EntityComponentPos3);
	ent->x = 1;
	ent->y = 2;
	ent->z = -0.5;
	ent->q = "Hello, World!";

	std::cout << ent->toString() << std::endl;

	SaveFileWriter sfw("save.bin");
	sfw.writeEntCompMap(EntityFactory::inst->getEntComps());
	ent->save(sfw);
	sfw.close();

	delete ent;

	SaveFileReader sfr("save.bin");
	sfr.readEntCompMap();
	EntityComponentPos3* ent1 = ENT_CONSTRUCT_SAVED(EntityComponentPos3, sfr);
	sfr.close();

	std::cout << ent1->x << " " << ent1->y << " " << ent1->z << std::endl;

	delete ent1;
	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
