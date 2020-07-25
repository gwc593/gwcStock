#include "gepch.h"
#include "DataExchanges/Finnhub/FinnHub.h"


//note large volume historic price data at https://uk.finance.yahoo.com/quote/AAPL/history?period1=0&period2=1595635200&interval=1d&filter=history&frequency=1m
//need to make API for this...
//starts at: '[{"date":'
//ends at '}]'



/*
std::string getHistoricDataJson(const char* symbol)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string header = "https://uk.finance.yahoo.com/quote/";
	std::string footer = "/history?period1=0&period2=1595635200000&interval=1d&filter=history&frequency=1m";
	std::string _symbol = symbol;

	std::string _start = "[{\"date\":";
	std::string _end = "}]";

	std::string result = url->CurlURL(header + _symbol + footer);

	if (result.find(_start) != 0)
		return std::string("{}");

	std::string _data = result.substr(result.find(_start));


	auto data = result.substr(result.find(_start));
	data.erase(data.find(_end) + 2, data.size());

	return data;
}
*/
int main()
{	
	std::cout << FinnHub::Get()->GetQuote("AAPL");
	return 0;
}