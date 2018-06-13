#include "it-asset.h"

#include <iostream>

using namespace std;
// Total Ram 
int meminfo(void)
{
  struct sysinfo myinfo;
  unsigned long total_bytes;

  sysinfo(&myinfo);

  total_bytes = myinfo.mem_unit * myinfo.totalram;


  printf("total usable main memory is %lu B, %lu MB, %0.2f GB\n",
         total_bytes, total_bytes/1024/1024, (double)total_bytes/(1024*1024*1024));

  return 0;

}


static std::string getosinfo(const char* key) {
	std::ifstream osinfo("/etc/os-release");
	if (!osinfo || !osinfo.is_open() ) {
		osinfo.close();
		return NULL;
	}
	for (std::string line;  std::getline(osinfo,line);){
	
		if (line.find(key) == 0) {
			const auto colon_index = line.find_first_of("=");
			const auto value_index = line.find_first_not_of(" \t", colon_index) + 1;
			char ch = '\"';
			if (std::count (line.begin(), line.end(), ch) >= 2)
				line.erase(line.find(ch),1);line.erase(line.find_last_of(ch),1);
			return  (line.c_str() + value_index);
		}
	}
	osinfo.close();
	return {};
}

void asset(json &j){
	struct utsname sysinfo;
	uname(&sysinfo);
	j["computerName"] = sysinfo.nodename;
    	std::string osInformation = getosinfo("PRETTY_NAME") + ", " +sysinfo.sysname +" , " + sysinfo.machine;
	j["osInformation"] = osInformation;
    
}


/*
int main(){
	json j;
	asset(j);
	cout << j << endl;
	return 0;
}*/
