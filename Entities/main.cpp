#include <iostream>

#include "entity.h"
#include "entity_factory.h"

class EntityComponentPos3 : public EntityComponent {

public:
	EntityComponentPos3() {}

	ENT_REGISTER_FIELDS_3(
		EntityComponentPos3,
		float, x,
		float, y,
		float, z
	)
};

class EntityComponentTag : public EntityComponent {

public:
	EntityComponentTag() {}

	ENT_REGISTER_FIELDS_1(
		EntityComponentTag,
		std::string, tag
	)
};

class EntityComponentEmpty : public EntityComponent {

public:
	EntityComponentEmpty() {}

	ENT_REGISTER_FIELDS_0(EntityComponentEmpty)
};

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();
//	EntityFactory::inst->registerEnt("EntTest1", []() { return new EntTest1(); });


	ENT_COMP_REGISTER(EntityComponentTag);
	ENT_COMP_REGISTER(EntityComponentPos3);
	ENT_COMP_REGISTER(EntityComponentEmpty);

	Entity ent;
	
	EntityComponentPos3* entPos = ENT_COMP_CONSTRUCT_BLANK(EntityComponentPos3);
	entPos->x = 1;
	entPos->y = 2;
	entPos->z = -0.5;
	ent.addComponent(entPos);
	
	EntityComponentTag* entTag = ENT_COMP_CONSTRUCT_BLANK(EntityComponentTag);
	entTag->tag = "Tagged object";
	ent.addComponent(entTag);

	ent.addComponent(ENT_COMP_CONSTRUCT_BLANK(EntityComponentEmpty));


	std::cout << ent.toString() << std::endl;

	SaveFileWriter sfw("save.bin");
	sfw.writeEntCompMap(EntityFactory::inst->getEntComps());
	ent.save(sfw);
	sfw.close();

	SaveFileReader sfr("save.bin");
	sfr.readEntCompMap();
	Entity ent1;
	ent1.load(sfr);
	sfr.close();
	std::cout << ent1.toString() << std::endl;
	//EntityComponentPos3* ent1 = ENT_COMP_CONSTRUCT_SAVED(EntityComponentPos3, sfr);
	//sfr.close();

	//std::cout << ent1->x << " " << ent1->y << " " << ent1->z << std::endl;

	//delete ent1;
	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
