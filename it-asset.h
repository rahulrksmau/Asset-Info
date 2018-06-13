#ifndef _IT_ASSET_H_
#define _IT_ASSET_H_

#include <algorithm>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/sysctl.h>
#include <sys/unistd.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


void asset(json &j);

#endif
