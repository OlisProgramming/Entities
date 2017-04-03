#include "file_save.h"

SaveFileWriter::SaveFileWriter(std::string fname) {
	std::cout << "Writing save file to " << fname << "..." << std::endl;
	ofs.open(fname.c_str(), std::ios::out | std::ios::binary);
	ofs.seekp(0);
}

void SaveFileWriter::close() {
	ofs.close();
	//std::cout << "finished." << std::endl;
}

unsigned int SaveFileWriter::getEntCompIndex(std::string entcomp) {
	return entcompmap[entcomp];
}

void SaveFileWriter::writeEntCompMap(std::vector<std::string>* entcomps) {
	unsigned int i = 0;
	for (std::string s : *entcomps) {
		entcompmap.emplace(s, i++);
		for (char chr : s) {
			write(chr);
		}
		write('\0');
	}
	write('\1');
	delete entcomps;
}

///

SaveFileReader::SaveFileReader(std::string fname) {
	std::cout << "Reading save file from " << fname << "..." << std::endl;
	ifs.open(fname.c_str(), std::ios::out | std::ios::binary);
	ifs.seekg(0);
}

void SaveFileReader::close() {
	ifs.close();
	//std::cout << "finished." << std::endl;
}

void SaveFileReader::readEntCompMap() {
	std::string s;
	char c;
	unsigned int i = 0;
	do {
		do {
			c = read<char>();
			//std::cout << c;
			if (c != '\0' && c != '\1')
				s += c;
		} while (c != '\0' && c != '\1');
		if (c != '\1')
			entcompmap.emplace(i++, s);
		s = "";
	} while (c != '\1');

	std::cout << std::endl << "Entity Component Map:" << std::endl;
	for (auto item : entcompmap) {
		std::cout << item.first << " " << item.second << std::endl;
	}
	std::cout << std::endl;
}
