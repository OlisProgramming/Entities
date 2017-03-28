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
}

void SaveFileWriter::write(char c) {
	ofs.write(&c, 1);
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

char SaveFileReader::read_char() {
	char c;
	ifs.read(&c, 1);
	return c;
}

