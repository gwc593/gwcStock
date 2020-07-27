#include<FinnHub.h>
#include<iostream>

/// !!!! READ ME FINNHUB REP!!!!!///
// please run in Release mode to test speed, the for loop for populating std::vector<FinnHub::Symbol> symbols; ~ line 17 is inherantly very slow in debug mode because of the number of debug symbols. 
// if you want to run in debug, please comment the afformentioned section out.

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


	//GetNews
	//////////
	std::string newsJSON = dataExchange.GetNews("general", 0);
	std::vector<FinnHub::News> articles;
	auto numberOfArticles = JSON::NumObjects(newsJSON);
	for (int i = 0; i < numberOfArticles; i++) {
		FinnHub::News tmp;
		tmp.Deserialise(JSON::GetObjDataN(newsJSON, i));
		articles.push_back(tmp);
	}

	//GetCompanyNews
	std::string companyNewsJSON = dataExchange.GetCompanyNews("AAPL");
	std::vector<FinnHub::News> companyArticles;
	auto numberOfCompanyArticles = JSON::NumObjects(companyNewsJSON);
	for (int i = 0; i < numberOfCompanyArticles; i++) {
		FinnHub::News tmp;
		tmp.Deserialise(JSON::GetObjDataN(companyNewsJSON, i));
		companyArticles.push_back(tmp);
	}

	

	//Get News Sentiment
	std::string newsSentimentJSON = dataExchange.GetNewsSentiment("AAPL");
	FinnHub::NewsSentiment newsSentiment;
	newsSentiment.Deserialise(newsSentimentJSON);
}