#include "applications.h"

using namespace std;

const std::string pkg_data( const std::string line){
	const auto colon_index = line.find_first_of(":");
	const auto last_index  = line.find_first_not_of(" \t",colon_index)+2;
	return line.c_str() + last_index ;
} 

int installed_apps( vector< map<string, string> >& apps_list) {
	std::ifstream cpuinfo("/var/lib/dpkg/status");

	if(!cpuinfo.is_open() || !cpuinfo){
		cpuinfo.close();
		return 0;
	}
	map <string,string> tmp; string section;
	for(std::string line; std::getline(cpuinfo, line);){
		
			if (line.find("Package")==0)
				tmp["DisplayName"] = pkg_data(line);
			else if (line.find("Maintainer")==0)
				tmp["Publisher"] = pkg_data(line);
			else if (line.find("Version")==0)
				tmp["DisplayVersion"] = pkg_data(line);
			else if (line.find("Installed-Size")==0)
				tmp["InstalledDate"] = "";// pkg_data(line);
			else if (line.find("Section")==0)
				section = pkg_data(line);
			else if (!line.size()){
				std::string filter = "Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>";
				if (tmp["Publisher"]==filter || section=="doc" || section=="libs" || section=="utils")	
					tmp.clear();
				else			
					apps_list.push_back(tmp);
			}
	}	
		
	cpuinfo.close();
	return 1;
}

void installed_app(json &j){
	vector < map<string, string> > apps_list;
	installed_apps(apps_list);
	j["InstalledSoftwares"] = apps_list;
	//cout << apps_list.size();
}
/*
int main(){
	json j;
	installed_app(j);
	std::cout << j << std::endl;
	
	return 0;
}*/
