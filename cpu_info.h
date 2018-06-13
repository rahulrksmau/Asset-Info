#ifndef _CPU_INFO_H_
#define _CPU_INFO_H_


#include <cstring>
#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

static std::string cpuinfo_value(const char* );
static std::string systemManufacturer();
void cpu_info(json &j);

enum {
	MODE_32BIT	= (1 << 1),
	MODE_64BIT	= (1 << 2)
};

#endif
