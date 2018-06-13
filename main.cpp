#include <curl/curl.h>  
#include <exception> 
#include <nlohmann/json.hpp>
#include "main.h"
#define boundry "-----------------------------------------------------------------------"
using namespace std;
using json = nlohmann::json;

void post_data(string website, string data){
	try   
    {  
        CURL *pCurl = NULL;  
        CURLcode res;  
        // get a curl handle  
        pCurl = curl_easy_init();  
        if (NULL != pCurl)   
        {  
            
            //curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, 1);  
            curl_easy_setopt(pCurl, CURLOPT_URL, website.c_str());  
     
            curl_slist *plist = curl_slist_append(NULL,"Content-Type:application/json");  
            curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, plist);  
            
            curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, data.c_str());  
  
            res = curl_easy_perform(pCurl);  
            if (res != CURLE_OK)   
            {  
                printf("curl_easy_perform() failed:%s\n", curl_easy_strerror(res));  
		cout << res << endl;
            }  	
			
            curl_easy_cleanup(pCurl);  
        }  
        curl_global_cleanup();  
    }  
    catch (std::exception &ex) 
    {  
      
    } 
}

int main(int argc, char** argv ){
	json sys_asset,ResponseData;	

		asset(ResponseData);
		cpu_info(ResponseData);
		disk(ResponseData);
		ipaddress(ResponseData);
		installed_app(ResponseData) ;
		sys_asset["ResponseData"] = ResponseData;

		/* other */
		sys_asset["loginID"] = {};
		sys_asset["Status"]  = "1";
	  	sys_asset["ErrorMessage"] =  {};
	  	sys_asset["Version"]= "1.0.0.0";
	  	sys_asset["ErrorCode"] = {};
		//cout << sys_asset << endl;
	
		string website = "https://www.httpbin.org/post";
	if (argc > 1){	website  = argv[1];
		cout << "Posting data to  " << website << endl;
	}	
		string data = sys_asset.dump();	
		post_data(website,data);
	
	return 0;
}
