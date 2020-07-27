#include<FinnHub.h>
#include<iostream>

/// !!!! READ ME FINNHUB REP!!!!!///
// please run in Release mode to test speed, the for loop for populating std::vector<FinnHub::Symbol> symbols; ~ line 17 is inherantly very slow in debug mode because of the number of debug symbols. 
// if you want to run in debug, please set testGetSymbols to false.


//Testing profile
bool testGetSymbols			= false; //Slow in debug mode
bool testGetQuote			= true;
bool testGetCompanyProfile2 = true;
bool testGetNews			= true;
bool testGetCompanyNews		= true;
bool testGetNewsSentiment	= true;


int main()
{
	//Initialise FinnHub Exchange object
	/////////////////////////////////////
	FinnHubAPI dataExchange("bse5d8frh5rea8raakb0");

	//get all available symbols from US stock exchange
	//////////////////////////////////////////////////
	std::string symbolsJSON;
	int32_t numberOfSymbols;
	std::vector<FinnHub::Symbol> symbols;

	if (::testGetSymbols) {
		symbolsJSON = dataExchange.GetSymbols("US");
		numberOfSymbols = JSON::NumObjects(symbolsJSON);
		for (int i = 0; i < numberOfSymbols; i++) {
			FinnHub::Symbol tmp;
			tmp.Deserialise(JSON::GetObjDataN(symbolsJSON, i));
			symbols.push_back(tmp);
		}
	}


	//Get quote for AAPL and store it in a FinnHub Candle Object
	/////////////////////////////////////////////////////////////
	std::string candleJSON;
	FinnHub::Candle myCandle;

	if (::testGetQuote) {
		candleJSON = dataExchange.GetQuote("AAPL");
		myCandle.Deserialise(candleJSON);
	}


	//Get Company Profile2 for AAPL
	///////////////////////////////
	std::string companyProfile2JSON;
	FinnHub::CompanyProfile companyProfleObj;

	if (::testGetCompanyProfile2) {
		companyProfile2JSON = dataExchange.GetCompanyProfile2("AAPL");
		companyProfleObj.Deserialise(companyProfile2JSON);
	}

	//GetNews
	//////////
	std::string newsJSON;
	std::vector<FinnHub::News> articles;
	int32_t numberOfArticles;

	if (::testGetNews) {
		newsJSON = dataExchange.GetNews("general", 0);
		numberOfArticles = JSON::NumObjects(newsJSON);
		for (int i = 0; i < numberOfArticles; i++) {
			FinnHub::News tmp;
			tmp.Deserialise(JSON::GetObjDataN(newsJSON, i));
			articles.push_back(tmp);
		}
	}


	//GetCompanyNews
	std::string companyNewsJSON;
	std::vector<FinnHub::News> companyArticles;
	int32_t numberOfCompanyArticles;

	if (::testGetCompanyNews) {
		companyNewsJSON = dataExchange.GetCompanyNews("AAPL");
		numberOfCompanyArticles = JSON::NumObjects(companyNewsJSON);
		for (int i = 0; i < numberOfCompanyArticles; i++) {
			FinnHub::News tmp;
			tmp.Deserialise(JSON::GetObjDataN(companyNewsJSON, i));
			companyArticles.push_back(tmp);
		}
	}

	
	//Get News Sentiment
	std::string newsSentimentJSON;
	FinnHub::NewsSentiment newsSentiment;

	if (::testGetNewsSentiment) {
		newsSentimentJSON = dataExchange.GetNewsSentiment("AAPL");
		newsSentiment.Deserialise(newsSentimentJSON);
	}

	std::cout << "finished" << std::endl;
}