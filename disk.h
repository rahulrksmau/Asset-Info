#ifndef _DISK_H_
#define _DISK_H_

#include <sys/statvfs.h>
#include <sys/sysinfo.h>
#include <stdio.h>
#include <iostream>
#include <cstring> 
#include <fstream>
#include <thread>

#include <nlohmann/json.hpp>
using json = nlohmann::json;
void disk(json &j);

#endif
