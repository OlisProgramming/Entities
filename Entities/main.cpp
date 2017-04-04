#include <iostream>

#include "entity_components.h"

int main(int argc, char** argv) {

	EntityFactory::inst = new EntityFactory();

	entRegisterBaseComponents();

	Entity ent;

	CPos3* entPos = ENT_COMP_CONSTRUCT_BLANK(CPos3);
	entPos->x = 1;
	entPos->y = 2;
	entPos->z = -0.5;
	ent.addComponent(entPos);
	
	CTag* entTag = ENT_COMP_CONSTRUCT_BLANK(CTag);
	entTag->tag = "Tagged object";
	ent.addComponent(entTag);


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
	
	std::cout << "Ent1 was tagged as: '" << ENT_GET_COMPONENT(ent1, CTag)->tag << "'." << std::endl;
	
	for (auto comp : ENT_GET_COMPONENTS(ent, CPos3)) {
		std::cout << "Pos: " << comp->x << ", " << comp->y << ", " << comp->z << "." << std::endl;
	}

	delete EntityFactory::inst;

	system("PAUSE");

	return 0;
}
