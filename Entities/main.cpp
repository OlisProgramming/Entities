#include <iostream>

#include "entity.h"
#include "entity_factory.h"

/*struct Data {
	unsigned int a;
	unsigned long b;
}; STRUCTS WORK */

class EntityComponentPos3 : public EntityComponent {

public:
	EntityComponentPos3() {}

	ENT_REGISTER_FIELDS_3(
		float, x,
		float, y,
		float, z
	);

	//ENT_REGISTER(EntTest1)
};

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();
//	EntityFactory::inst->registerEnt("EntTest1", []() { return new EntTest1(); });


	ENT_REGISTER(EntityComponentPos3);

	EntityComponentPos3* ent = ENT_CONSTRUCT_BLANK(EntityComponentPos3);
	ent->x = 1;
	ent->y = 2;
	ent->z = -0.5;

	SaveFileWriter sfw("save.bin");
	ent->save(sfw);
	sfw.close();

	delete ent;

	SaveFileReader sfr("save.bin");
	EntityComponentPos3* ent1 = ENT_CONSTRUCT_SAVED(EntityComponentPos3, sfr);
	sfr.close();

	std::cout << ent1->x << " " << ent1->y << " " << ent1->z << std::endl;

	delete ent1;
	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
