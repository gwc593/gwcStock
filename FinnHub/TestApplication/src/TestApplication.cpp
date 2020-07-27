#include<FinnHub.h>

#include<iostream>
int main()
{
	//Initialise FinnHub Exchange object
	/////////////////////////////////////
	FinnHubAPI dataExchange("bse5d8frh5rea8raakb0");

	//get all available symbols from US stock exchange
	//////////////////////////////////////////////////
	std::string symbolDataJSON = dataExchange.GetSymbols("US");

	auto numberOfSymbols = JSON::NumObjects(symbolDataJSON);
	std::vector<FinnHub::Symbol> symbols;
	for (int i = 0; i < numberOfSymbols; i++) {
		FinnHub::Symbol tmp;
		tmp.Deserialise(JSON::GetObjDataN(symbolDataJSON, i));
		symbols.push_back(tmp);
	}
	
	//Get quote for AAPL and store it in a FinnHub Candle Object
	/////////////////////////////////////////////////////////////
	std::string candleJSON = dataExchange.GetQuote("AAPL");
	FinnHub::Candle myCandle;
	myCandle.Deserialise(candleJSON);

	//Get Company Profile2 for AAPL
	///////////////////////////////
	std::string companyProfile2JSON = dataExchange.GetCompanyProfile2("AAPL");
	FinnHub::CompanyProfile companyProfleObj;
	companyProfleObj.Deserialise(companyProfile2JSON);

}