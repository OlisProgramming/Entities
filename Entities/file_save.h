#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

/**
\brief Writes Entity data to a binary save file.

Format:
- EntityComponent map (::entcompmap) to map class names onto unsigned integers, giving EntityComponent subclasses 'aliases' so that they can be referenced with a simple unsigned int.
- A 0x01 character to signal the end of the block.
- Each Entity is written to the file as follows:
	- An unsigned int detailing how many EntityComponents it contains.
	- Each component in turn.
- (Unimplemented as currently only one entity can be saved and loaded back properly) A 0x01 character to signal the end of the block.
*/
class SaveFileWriter {

private:
	/** Output file stream. */
	std::ofstream ofs;
	/** A map version of the std::vector created by EntityFactory::getEntComps(). This maps each std::string in the EntityComponent std::vector to its index in the std::vector. */
	std::unordered_map<std::string, unsigned int> entcompmap;

public:
	/** Opens binary file \p fname for writing. */
	SaveFileWriter(std::string fname);
	/** Closes file. */
	void close();

	/** Gets the alias of an EntityComponent subclass' name. This alias is used in the save file to prefix the EntityComponent so that we know what class it is when loading the file. */
	unsigned int getEntCompIndex(std::string entcomp);
	/** Writes the map of EntityComponent subclasses into the file. This is followed by a 0x01 character to signal the end of the block. */
	void writeEntCompMap(std::vector<std::string>* entcomps);

	/** Writes a variable to the file. */
	template<class T> inline void write(T t) {
		ofs.write(reinterpret_cast<char*>(&t), sizeof(T));
	}

	/** Writes an array to the file. Generally the size of the array should be written to the file first, as a size_t type. */
	template<class T> inline void write_array(T* t, size_t bytes) {
		ofs.write(reinterpret_cast<char*>(t), bytes);
	}
};

/**
\brief Reads binary files generated by SaveFileWriter.

For file format details, see the class definition of SaveFileWriter.
*/
class SaveFileReader {

private:
	/** Input file stream. */
	std::ifstream ifs;
	/** A map read from the file converting class aliases into their names. */
	std::unordered_map<unsigned int, std::string> entcompmap;

public:
	/** Opens binary file \p fname for reading. */
	SaveFileReader(std::string fname);
	void close();

	/** Gets the class name with the supplied alias in the file. */
	std::string getEntCompName(unsigned int ind) { return entcompmap[ind]; }
	/** Reads the EntityComponent map from the top of the file. */
	void readEntCompMap();

	/** Reads a variable of type T from the file. */
	template<class T> inline T read() {
		T t;
		ifs.read(reinterpret_cast<char*>(&t), sizeof(T));
		return t;
	}

	/** Reads an array with a size of \p bytes bytes. The size of the array is generally written before the array as a size_t. */
	inline std::vector<char>* read_array(size_t bytes) {
		std::vector<char>* vec = new std::vector<char>(bytes);
		//std::cout << bytes << std::endl;
		ifs.read((char*)(&(*vec)[0]), bytes);
		//std::cout << "Array: " << &(*vec)[0] << std::endl;
		return vec;
	}
};