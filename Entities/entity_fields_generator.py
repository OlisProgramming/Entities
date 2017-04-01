FIELD_MAX = 10

'''

#define ENT_REGISTER_FIELDS(type0,var0) \
public:	\
	type0 var0; \
	virtual inline void save(SaveFileWriter& sfw) override { \
		if (#type0 == "std::string" || #type0 == "string") { \
			sfw.write<size_t>(var0.length()); \
			sfw.write_array<char>(const_cast<char*>(var0.c_str()), var0.length()); \
		} \
		else \
			sfw.write<type0>(var0); \
	} \
	virtual inline Entity* load(SaveFileReader& sfr) override { \
		if (#type0 == "std::string" || #type0 == "string") {\
\
			size_t size = sfr.read<size_t>(); \
			auto vec = sfr.read_array(size); \
			var0 = std::string(&(*vec)[0], &(*vec)[0] + size); \
			delete vec; \
		} \
		else \
			var0 = sfr.read<std::string>(); \
		return this; \
	}
'''

with open("entity_fields.h", 'w') as f:

    f.write("#pragma once\n\n")

    f.write("inline size_t __ent_str_len(void* ptr) { return ((std::string*)ptr)->length(); }\n")
    f.write("inline void __ent_str_set(void* ptr, std::string& str) { *((std::string*)ptr) = str; }\n")
    f.write("inline const char* __ent_str_cstr(void* ptr) { return ((std::string*)ptr)->c_str(); }\n\n")
    
    for i in range(1, FIELD_MAX+1):
        f.write("#define ENT_REGISTER_FIELDS_" + str(i) + "(")
        for j in range(0, i-1):
            f.write("type" + str(j) + ",var" + str(j) + ",")
        f.write("type" + str(i-1) + ",var" + str(i-1) + ") \\\npublic: \\\n")
        for j in range(0, i):
            f.write("\ttype" + str(j) + " var" + str(j) + "; \\\n")


        f.write("\tvirtual inline void save(SaveFileWriter& sfw) override { \\\n")

        for j in range(0, i):
            f.write('\t\tif (#{type0} == "std::string" || #{type0} == "string") {{ \\\n'
			'\t\t\tsfw.write<size_t>(__ent_str_len(&{var0})); \\\n'
			'\t\t\tsfw.write_array<char>(const_cast<char*>(__ent_str_cstr(&{var0})), __ent_str_len(&{var0})); \\\n'
		'\t\t}} \\\n'
		'\t\telse \\\n'
			'\t\t\tsfw.write<{type0}>({var0}); \\\n'.format(type0="type"+str(j), var0="var"+str(j)))

        f.write("\t} \\\n\tvirtual inline EntityComponent* load(SaveFileReader& sfr) override { \\\n")

        for j in range(0, i):
            f.write('\t\tif (#{type0} == "std::string" || #{type0} == "string") {{ \\\n'
			'\t\t\tsize_t size = sfr.read<size_t>(); \\\n'
			'\t\t\tauto vec = sfr.read_array(size); \\\n'
			'\t\t\t__ent_str_set(&{var0}, std::string(&(*vec)[0], &(*vec)[0] + size)); \\\n'
			'\t\t\tdelete vec; \\\n'
		'\t\t}} \\\n'
		'\t\telse \\\n'
			'\t\t\t{var0} = sfr.read<{type0}>(); \\\n'.format(type0="type"+str(j), var0="var"+str(j)))

        f.write("\t\treturn this; \\\n\t}")
        
        f.write("\n\n")

print("Complete.")
