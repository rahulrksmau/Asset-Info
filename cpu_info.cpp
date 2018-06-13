#include "cpu_info.h"
#include <iostream>
using namespace std;

int arch()
{
	int m = 0;
	#if defined(__x86_64__) || defined(__x64__) || defined(__amd64__)
		m |= MODE_64BIT;	/* 64bit platforms only */
	#endif
		/* platforms with 64bit flag in /proc/cpuinfo, define
		 * 32bit default here */
	#if defined(__x86__) || defined(__i686__) || defined(__i386__) 
		m |= MODE_32BIT;
	#endif
	return m;
}

static std::string cpuinfo_value(const char* key) {
	std::ifstream cpuinfo("/proc/cpuinfo");

	if(!cpuinfo.is_open() || !cpuinfo){
		cpuinfo.close();
		return {};
	}

	for(std::string line; std::getline(cpuinfo, line);)
		if(line.find(key) == 0) {
			const auto colon_id    = line.find_first_of(':');
			const auto nonspace_id = line.find_first_not_of(" \t", colon_id) + 1;
			return line.c_str() + nonspace_id;
		}
	cpuinfo.close();
	return {};
}

static std::string systemManufacturer(){
	std::ifstream vendor("/sys/devices/virtual/dmi/id/sys_vendor");
	if (!vendor.is_open() | !vendor){
		vendor.close();
		return {};
	}
	std::string sys_vendor = " ";
	for(std::string line; std::getline(vendor, line);){
		sys_vendor += line;
	}
	vendor.close();
	return sys_vendor;
}

void cpu_info(json &j){
	std::string cpuSpeed = to_string(atof(cpuinfo_value("cpu MHz").c_str())/(1000));
	std::size_t pos = cpuSpeed.find(".");
	j["cpuSpeed"] = cpuSpeed.substr(0,pos+2) ;
	std::string processorInformation  =  cpuinfo_value("model name") + " , " + cpuinfo_value("vendor_id") + " Family"+cpuinfo_value("cpu family") + " Model" + cpuinfo_value("model") ;
	j["processorInformation"] = processorInformation;
	j["systemManufacturer"] = systemManufacturer();
	if (arch() == MODE_32BIT)
		j["architecture"] = "32";
	else
		j["architecture"] = "64";

}


/*
int main(){
	json j;
	cpu_info(j);
	std::cout << j << std::endl;
	
	return 0;
}*/
