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

	template<class T> inline void write(T t) {
		ofs.write(reinterpret_cast<char*>(&t), sizeof(T));
	}
};

class SaveFileReader {

private:
	std::ifstream ifs;

public:
	SaveFileReader(std::string fname);
	~SaveFileReader();
	void close();

	template<class T> inline T read() {
		T t;
		ifs.read(reinterpret_cast<char*>(&t), sizeof(T));
		return t;
	}
};