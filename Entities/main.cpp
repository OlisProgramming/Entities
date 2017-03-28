#include <iostream>

#include "entity.h"
#include "entity_factory.h"

class EntTest1 : public Entity {

public:
	EntTest1() {}

	ENT_REGISTER_FIELDS(
		unsigned long long, a
	);

	//ENT_REGISTER(EntTest1)
};

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();
//	EntityFactory::inst->registerEnt("EntTest1", []() { return new EntTest1(); });


	ENT_REGISTER(EntTest1);

	EntTest1* ent = ENT_CONSTRUCT_BLANK(EntTest1);
	ent->a = -1;

	std::cout << (unsigned long long)-1 << std::endl;

	SaveFileWriter sfw("save.bin");
	ent->save(sfw);
	sfw.close();

	delete ent;

	SaveFileReader sfr("save.bin");
	EntTest1* ent1 = ENT_CONSTRUCT_SAVED(EntTest1, sfr);
	sfr.close();

	std::cout << ent1->a << std::endl;

	delete ent1;
	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
