#include <iostream>

#include "entity.h"
#include "entity_factory.h"

/*struct Data {
	unsigned int a;
	unsigned long b;
}; STRUCTS WORK */

class EntTest1 : public Entity {

public:
	EntTest1() {}

	ENT_REGISTER_FIELDS_4(
		std::string, s,
		unsigned long long, a,
		char, q,
		std::string, s2
	);

	//ENT_REGISTER(EntTest1)
};

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();
//	EntityFactory::inst->registerEnt("EntTest1", []() { return new EntTest1(); });


	ENT_REGISTER(EntTest1);

	EntTest1* ent = ENT_CONSTRUCT_BLANK(EntTest1);
	ent->s = "Hello, World!";
	ent->a = 1024;
	ent->q = 'A';
	ent->s2 = "uagsodiuad";

	SaveFileWriter sfw("save.bin");
	ent->save(sfw);
	sfw.close();

	delete ent;

	SaveFileReader sfr("save.bin");
	EntTest1* ent1 = ENT_CONSTRUCT_SAVED(EntTest1, sfr);
	sfr.close();

	std::cout << ent1->s << " " << ent1->a << " " << ent->q << " " << ent->s2 << std::endl;

	delete ent1;
	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
