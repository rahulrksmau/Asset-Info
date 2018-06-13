#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

const std::string pkg_data( const std::string);
int installed_apps(vector< map<string, string> >&apps_list); 
void installed_app(json &j);

#endif
