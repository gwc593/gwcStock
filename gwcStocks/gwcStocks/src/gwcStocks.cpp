#include "gepch.h"
#include <curl/curl.h>
const char* Finnhub_APIKey = "bs2omovrh5r9f6apl86g";


int main()
{	
	auto curl = curl_easy_init();

	if (curl)
		std::cout << curl << std::endl;
	return 0;
}