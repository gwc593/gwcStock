#include<FinnHub.h>

#include<iostream>
int main()
{
	//Initialise FinnHub Exchange object
	FinnHubAPI dataExchange("bse5d8frh5rea8raakb0");

	//get all available symbols from US stock exchange
	std::string symbolData = dataExchange.GetSymbols("US");

	auto numberOfSymbols = JSON::NumObjects(symbolData);
	std::vector<FinnHub::Symbol> symbols;
	for (int i = 0; i < numberOfSymbols; i++) {
		FinnHub::Symbol tmp;
		tmp.Deserialise(JSON::GetObjDataN(symbolData, i));
		symbols.push_back(tmp);
	}
	

	//Get quote for APPL and store it in a FinnHub Candle Object
	std::string candleJSON = dataExchange.GetQuote("AAPL");
	FinnHub::Candle myCandle;
	myCandle.Deserialise(candleJSON);



	std::cout << "AAPL: " << dataExchange.GetQuote("AAPL") << std::endl;
}