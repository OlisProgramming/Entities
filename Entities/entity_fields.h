#pragma once

#include <string>
inline size_t __ent_str_len(void* ptr) { return ((std::string*)ptr)->length(); }
inline void __ent_str_set(void* ptr, std::string& str) { *((std::string*)ptr) = str; }
inline const char* __ent_str_cstr(void* ptr) { return ((std::string*)ptr)->c_str(); }

#define ENT_REGISTER_FIELDS_1(name,type0,var0) \
public: \
	type0 var0; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_2(name,type0,var0,type1,var1) \
public: \
	type0 var0; \
	type1 var1; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_3(name,type0,var0,type1,var1,type2,var2) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_4(name,type0,var0,type1,var1,type2,var2,type3,var3) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_5(name,type0,var0,type1,var1,type2,var2,type3,var3,type4,var4) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	type4 var4; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " + std::to_string(var4) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
		if (#type4 == "std::string" || #type4 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var4)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var4)), __ent_str_len(&var4)); \
		} \
		else \
			sfw.write<type4>(var4); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		if (#type4 == "std::string" || #type4 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var4, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var4 = sfr.read<type4>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_6(name,type0,var0,type1,var1,type2,var2,type3,var3,type4,var4,type5,var5) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	type4 var4; \
	type5 var5; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " + std::to_string(var4) + " " + std::to_string(var5) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
		if (#type4 == "std::string" || #type4 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var4)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var4)), __ent_str_len(&var4)); \
		} \
		else \
			sfw.write<type4>(var4); \
		if (#type5 == "std::string" || #type5 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var5)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var5)), __ent_str_len(&var5)); \
		} \
		else \
			sfw.write<type5>(var5); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		if (#type4 == "std::string" || #type4 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var4, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var4 = sfr.read<type4>(); \
		if (#type5 == "std::string" || #type5 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var5, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var5 = sfr.read<type5>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_7(name,type0,var0,type1,var1,type2,var2,type3,var3,type4,var4,type5,var5,type6,var6) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	type4 var4; \
	type5 var5; \
	type6 var6; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " + std::to_string(var4) + " " + std::to_string(var5) + " " + std::to_string(var6) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
		if (#type4 == "std::string" || #type4 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var4)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var4)), __ent_str_len(&var4)); \
		} \
		else \
			sfw.write<type4>(var4); \
		if (#type5 == "std::string" || #type5 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var5)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var5)), __ent_str_len(&var5)); \
		} \
		else \
			sfw.write<type5>(var5); \
		if (#type6 == "std::string" || #type6 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var6)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var6)), __ent_str_len(&var6)); \
		} \
		else \
			sfw.write<type6>(var6); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		if (#type4 == "std::string" || #type4 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var4, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var4 = sfr.read<type4>(); \
		if (#type5 == "std::string" || #type5 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var5, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var5 = sfr.read<type5>(); \
		if (#type6 == "std::string" || #type6 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var6, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var6 = sfr.read<type6>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_8(name,type0,var0,type1,var1,type2,var2,type3,var3,type4,var4,type5,var5,type6,var6,type7,var7) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	type4 var4; \
	type5 var5; \
	type6 var6; \
	type7 var7; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " + std::to_string(var4) + " " + std::to_string(var5) + " " + std::to_string(var6) + " " + std::to_string(var7) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
		if (#type4 == "std::string" || #type4 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var4)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var4)), __ent_str_len(&var4)); \
		} \
		else \
			sfw.write<type4>(var4); \
		if (#type5 == "std::string" || #type5 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var5)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var5)), __ent_str_len(&var5)); \
		} \
		else \
			sfw.write<type5>(var5); \
		if (#type6 == "std::string" || #type6 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var6)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var6)), __ent_str_len(&var6)); \
		} \
		else \
			sfw.write<type6>(var6); \
		if (#type7 == "std::string" || #type7 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var7)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var7)), __ent_str_len(&var7)); \
		} \
		else \
			sfw.write<type7>(var7); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		if (#type4 == "std::string" || #type4 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var4, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var4 = sfr.read<type4>(); \
		if (#type5 == "std::string" || #type5 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var5, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var5 = sfr.read<type5>(); \
		if (#type6 == "std::string" || #type6 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var6, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var6 = sfr.read<type6>(); \
		if (#type7 == "std::string" || #type7 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var7, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var7 = sfr.read<type7>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_9(name,type0,var0,type1,var1,type2,var2,type3,var3,type4,var4,type5,var5,type6,var6,type7,var7,type8,var8) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	type4 var4; \
	type5 var5; \
	type6 var6; \
	type7 var7; \
	type8 var8; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " + std::to_string(var4) + " " + std::to_string(var5) + " " + std::to_string(var6) + " " + std::to_string(var7) + " " + std::to_string(var8) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
		if (#type4 == "std::string" || #type4 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var4)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var4)), __ent_str_len(&var4)); \
		} \
		else \
			sfw.write<type4>(var4); \
		if (#type5 == "std::string" || #type5 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var5)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var5)), __ent_str_len(&var5)); \
		} \
		else \
			sfw.write<type5>(var5); \
		if (#type6 == "std::string" || #type6 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var6)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var6)), __ent_str_len(&var6)); \
		} \
		else \
			sfw.write<type6>(var6); \
		if (#type7 == "std::string" || #type7 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var7)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var7)), __ent_str_len(&var7)); \
		} \
		else \
			sfw.write<type7>(var7); \
		if (#type8 == "std::string" || #type8 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var8)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var8)), __ent_str_len(&var8)); \
		} \
		else \
			sfw.write<type8>(var8); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		if (#type4 == "std::string" || #type4 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var4, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var4 = sfr.read<type4>(); \
		if (#type5 == "std::string" || #type5 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var5, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var5 = sfr.read<type5>(); \
		if (#type6 == "std::string" || #type6 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var6, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var6 = sfr.read<type6>(); \
		if (#type7 == "std::string" || #type7 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var7, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var7 = sfr.read<type7>(); \
		if (#type8 == "std::string" || #type8 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var8, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var8 = sfr.read<type8>(); \
		return this; \
	}

#define ENT_REGISTER_FIELDS_10(name,type0,var0,type1,var1,type2,var2,type3,var3,type4,var4,type5,var5,type6,var6,type7,var7,type8,var8,type9,var9) \
public: \
	type0 var0; \
	type1 var1; \
	type2 var2; \
	type3 var3; \
	type4 var4; \
	type5 var5; \
	type6 var6; \
	type7 var7; \
	type8 var8; \
	type9 var9; \
	virtual inline std::string toString() override { \
		return #name ## " ( " + std::to_string(var0) + " " + std::to_string(var1) + " " + std::to_string(var2) + " " + std::to_string(var3) + " " + std::to_string(var4) + " " + std::to_string(var5) + " " + std::to_string(var6) + " " + std::to_string(var7) + " " + std::to_string(var8) + " " + std::to_string(var9) + " " ")";\
	}\
	virtual inline void save(SaveFileWriter& sfw) override { \
		sfw.write<unsigned int>(sfw.getEntCompIndex(#name));\
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var0)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var0)), __ent_str_len(&var0)); \
		} \
		else \
			sfw.write<type0>(var0); \
		if (#type1 == "std::string" || #type1 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var1)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var1)), __ent_str_len(&var1)); \
		} \
		else \
			sfw.write<type1>(var1); \
		if (#type2 == "std::string" || #type2 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var2)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var2)), __ent_str_len(&var2)); \
		} \
		else \
			sfw.write<type2>(var2); \
		if (#type3 == "std::string" || #type3 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var3)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var3)), __ent_str_len(&var3)); \
		} \
		else \
			sfw.write<type3>(var3); \
		if (#type4 == "std::string" || #type4 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var4)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var4)), __ent_str_len(&var4)); \
		} \
		else \
			sfw.write<type4>(var4); \
		if (#type5 == "std::string" || #type5 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var5)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var5)), __ent_str_len(&var5)); \
		} \
		else \
			sfw.write<type5>(var5); \
		if (#type6 == "std::string" || #type6 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var6)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var6)), __ent_str_len(&var6)); \
		} \
		else \
			sfw.write<type6>(var6); \
		if (#type7 == "std::string" || #type7 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var7)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var7)), __ent_str_len(&var7)); \
		} \
		else \
			sfw.write<type7>(var7); \
		if (#type8 == "std::string" || #type8 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var8)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var8)), __ent_str_len(&var8)); \
		} \
		else \
			sfw.write<type8>(var8); \
		if (#type9 == "std::string" || #type9 == "string") { \
			sfw.write<size_t>(__ent_str_len(&var9)); \
			sfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&var9)), __ent_str_len(&var9)); \
		} \
		else \
			sfw.write<type9>(var9); \
	} \
	virtual inline EntityComponent* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var0, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<type0>(); \
		if (#type1 == "std::string" || #type1 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var1, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var1 = sfr.read<type1>(); \
		if (#type2 == "std::string" || #type2 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var2, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var2 = sfr.read<type2>(); \
		if (#type3 == "std::string" || #type3 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var3, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var3 = sfr.read<type3>(); \
		if (#type4 == "std::string" || #type4 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var4, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var4 = sfr.read<type4>(); \
		if (#type5 == "std::string" || #type5 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var5, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var5 = sfr.read<type5>(); \
		if (#type6 == "std::string" || #type6 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var6, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var6 = sfr.read<type6>(); \
		if (#type7 == "std::string" || #type7 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var7, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var7 = sfr.read<type7>(); \
		if (#type8 == "std::string" || #type8 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var8, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var8 = sfr.read<type8>(); \
		if (#type9 == "std::string" || #type9 == "string") { \
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			__ent_str_set(&var9, std::string(&(*vec)[0], &(*vec)[0] + size)); \
			delete vec; \
		} \
		else \
			var9 = sfr.read<type9>(); \
		return this; \
	}

