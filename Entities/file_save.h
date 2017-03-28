#pragma once

#include <string>
#include <fstream>

class SaveFileWriter {

private:
	std::ofstream ofs;

public:
	SaveFileWriter(std::string fname);
	~SaveFileWriter();
	void close();

	void write(char c);
};

class SaveFileReader {

private:
	std::ifstream ifs;

public:
	SaveFileReader(std::string fname);
	~SaveFileReader();
	void close();

	char read_char();
};