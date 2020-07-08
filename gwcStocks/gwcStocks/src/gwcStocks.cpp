#include "gepch.h"
#include "Core/URLData.h"
const char* Finnhub_APIKey = "bs2omovrh5r9f6apl86g";



int main()
{	
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string result = url->CurlURL("https://finnhub.io/api/v1/stock/symbol?exchange=L&token=bs2omovrh5r9f6apl86g");

	std::cout << result << std::endl;
	return 0;
}