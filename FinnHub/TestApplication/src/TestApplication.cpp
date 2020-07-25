#include<FinnHub.h>

#include<iostream>
int main()
{
	FinnHubAPI dataExchange("bse5d8frh5rea8raakb0");

	std::string candleJSON = dataExchange.GetQuote("AAPL");

	FinnHub::Candle myCandle;
	myCandle.Deserialise(candleJSON);

	std::cout << "AAPL: " << dataExchange.GetQuote("AAPL") << std::endl;
}