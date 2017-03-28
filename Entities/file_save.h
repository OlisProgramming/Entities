#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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

	template<class T> inline void write_array(T* t, size_t bytes) {
		ofs.write(reinterpret_cast<char*>(t), bytes);
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

	inline std::vector<char>* read_array(size_t bytes) {
		std::vector<char>* vec = new std::vector<char>(bytes);
		//std::cout << bytes << std::endl;
		ifs.read((char*)(&(*vec)[0]), bytes);
		//std::cout << "Array: " << &(*vec)[0] << std::endl;
		return vec;
	}
};