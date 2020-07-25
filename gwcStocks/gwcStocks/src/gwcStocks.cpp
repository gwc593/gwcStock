#include "gepch.h"
#include "Core/URLData.h"


std::string getStockDataJson(const char* dataRef, const char* symbol)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string dataToken = dataRef;
	std::string header = "https://uk.finance.yahoo.com/quote/";
	std::string footer = "?p=RR.L&.tsrc=fin-srch";
	std::string _symbol = symbol;

	std::string result = url->CurlURL(header + _symbol + footer);

	auto price = result.substr(result.find(dataToken));
	price.erase(price.find('}') + 1, price.size());

	return price;
}

int main()
{	
	std::cout << getStockDataJson("currentPrice","RR.L") << std::endl;
	return 0;
}