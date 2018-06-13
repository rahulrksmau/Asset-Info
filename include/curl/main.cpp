#include "curl.h"
#include <bits/stdc++.h>
using namespace std;

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
            }  	
			cout << res << endl;
            curl_easy_cleanup(pCurl);  
        }  
        curl_global_cleanup();  
    }  
    catch (std::exception &ex) 
    {  
      
    } 
}

int main(){
	string website = "https://www.httpbin.org/post";
	string data = "posting data";
		post_data(website,data);
}

