#include "file_save.h"

SaveFileWriter::SaveFileWriter(std::string fname) {
	ofs.open(fname.c_str(), std::ios::out | std::ios::binary);
	ofs.seekp(0);
}

SaveFileWriter::~SaveFileWriter() {
	close();
}

void SaveFileWriter::close() {
	ofs.close();
	delete entcomps;
}

unsigned int SaveFileWriter::getEntCompIndex(std::string entcomp) {
	return entcompmap[entcomp];
}

void SaveFileWriter::writeEntCompMap(std::vector<std::string>* entcomps) {
	this->entcomps = entcomps;
	unsigned int i = 0;
	for (std::string s : *entcomps) {
		entcompmap.emplace(s, i++);
		for (char chr : s) {
			write(chr);
		}
		write('\0');
	}
	write('\1');
}

///

SaveFileReader::SaveFileReader(std::string fname) {
	ifs.open(fname.c_str(), std::ios::out | std::ios::binary);
	ifs.seekg(0);
}

SaveFileReader::~SaveFileReader() {
	close();
}

void SaveFileReader::close() {
	ifs.close();
}

void SaveFileReader::readEntCompMap() {
	std::string s;
	char c;
	unsigned int i = 0;
	do {
		do {
			c = read<char>();
			//std::cout << c;
			s += c;
		} while (c != '\0' && c != '\1');
		entcompmap.emplace(i++, s);
	} while (c != '\1');

	for (auto item : entcompmap) {
		std::cout << item.first << " " << item.second << "\n";
	}
}
