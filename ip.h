#ifndef _IP_H_
#define _IP_H_

#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <time.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;
const std::string currentDateTime();
void names(std::vector<char*>& names);
int ipaddress(json &j);

#endif
