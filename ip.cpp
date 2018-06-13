#include "ip.h"
using namespace std;
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d  %X", &tstruct);

    return buf;
}


int ipaddress(json &j){
    std::string interface[3] = {"ens33", "eth0", "wlan0"};
    
    struct ifreq ifr;
    int sock, i, k;
    char *p, addr[32], mask[32], mac[32];
    sock=socket(PF_INET, SOCK_STREAM, 0);
    if (-1==sock) {
	perror("socket() ");
	return 1;
    }
	for(int i=0; i<3; i++){
		strncpy(ifr.ifr_name,interface[i].c_str(),sizeof(ifr.ifr_name)-1);
		ifr.ifr_name[sizeof(ifr.ifr_name)-1]='\0';
		if (-1!=ioctl(sock, SIOCGIFADDR, &ifr)) 
			break;
	}
    p=inet_ntoa(((struct sockaddr_in *)(&ifr.ifr_addr))->sin_addr);
    strncpy(addr,p,sizeof(addr)-1);
    addr[sizeof(addr)-1]='\0';

    if (-1==ioctl(sock, SIOCGIFNETMASK, &ifr)) {
		//perror("ioctl(SIOCGIFNETMASK) ");
		return 1;
    }

    if (-1==ioctl(sock, SIOCGIFHWADDR, &ifr)) {
		//perror("ioctl(SIOCGIFHWADDR) ");
		return 1;
    }
    for (i=0, k=0; i<6; i++) {
	k+=snprintf(mac+k, sizeof(mac)-k-1, i ? ":%02X" : "%02X",
	    (int)(unsigned int)(unsigned char)ifr.ifr_hwaddr.sa_data[i]);
    }
    mac[sizeof(mac)-1]='\0';

    j["IPAddress"] = addr;
    j["macAddress"]= mac;
    close(sock);
    
    j["InventoryDateTime"] = currentDateTime();
    return 0;
}
/*
int main(){
	json j;
	ipaddress(j);
	cout << j << endl;
	return 0;
}*/
