#include "disk.h"
using namespace std;

void memSlots(){
	//std::string ramSlotInformation =  
	
}


void disk(json &j)
{	
    unsigned long  hdd_size;
	unsigned long  hdd_free;
	vector<json> drive;
	struct sysinfo info;
	sysinfo( &info );   
	
	struct statvfs fsinfo;
	statvfs("/", &fsinfo);
	
	unsigned num_cpu = std::thread::hardware_concurrency();
	
	hdd_size = fsinfo.f_frsize * fsinfo.f_blocks;
	hdd_free = fsinfo.f_bsize * fsinfo.f_bfree;  
	json drv;
	for(int i=0; i < num_cpu; i++){
		drv["totalSpace"] = std::to_string(hdd_size/(1024*1024*1024)) + " GB";
		drv["freeSpace"] = std::to_string(hdd_free/(1024*1024*1024)) + " GB";
		drv["driveName"] =  "sda"+std::to_string(i+1) ;//Yet to find
		drive.push_back(drv);
		drv.clear();
	}
	j["driveInformation"] =  drive;
}
/*
int main(){
	json j;
	disk(j);
	std::cout << j << std::endl;
	return 0;
}*/
