#include <iostream>

#include "entity_components.h"

void demo_populate(Entity* ent) {
	Entity* tagged = new Entity;
	CTag* ctag = ENT_COMP_CONSTRUCT_BLANK(CTag);
	ctag->tag = "tagged";
	tagged->addComponent(ctag);
	ent->addChild(tagged);

	Entity* positioned = new Entity;
	CPos3* cpos3 = ENT_COMP_CONSTRUCT_BLANK(CPos3);
	cpos3->x = 0.f;
	cpos3->y = 1.f;
	cpos3->z = 2.f;
	positioned->addComponent(cpos3);
	ent->addChild(positioned);

	Entity* group = new Entity;
	Entity* neither = new Entity;
	group->addChild(neither);
	ent->addChild(group);
}

void demo_save() {
	Entity* ent = new Entity;
	demo_populate(ent);

	SaveFileWriter sfw("save.bin");
	sfw.writeEntCompMap(EntityFactory::inst->getEntComps());
	ent->save(sfw);
	sfw.close();

	delete ent;
}

Entity* demo_load() {
	Entity* ent = new Entity;

	SaveFileReader sfr("save.bin");
	sfr.readEntCompMap();
	ent->load(sfr);
	sfr.close();

	return ent;
}

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();

	entRegisterBaseComponents();

	demo_save();
	Entity* ent = demo_load();
	std::cout << "Loaded: " << ent->toString();
	delete ent;

	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
