#include<FinnHub.h>
#include<iostream>
#include "MACD/MACD.h"

/// !!!! READ ME FINNHUB REP!!!!!///
// please run in Release mode to test speed, the for loop for populating std::vector<FinnHub::Symbol> symbols; ~ line 17 is inherantly very slow in debug mode because of the number of debug symbols. 
// if you want to run in debug, please set testGetSymbols to false. bslrd7vrh5rdb4ar76a0


//Testing profile
bool testGetSymbols			= false; //Slow in debug mode
bool testGetQuote			= false;
bool testGetCompanyProfile2 = false;
bool testGetNews			= false;
bool testGetCompanyNews		= false;
bool testGetNewsSentiment	= false;
bool testGetPeers			= false;
bool testGetBasicFinancials	= false;
bool testIPOCalendar		= false;
bool testGetReccomendations	= false;
bool testGetPriceTarget		= false;
bool testHistoricData		= true;


int main()
{
	//Initialise FinnHub Exchange object
	/////////////////////////////////////
	FinnHubAPI dataExchange("bslrd7vrh5rdb4ar76a0");

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
		JSON::Print(candleJSON);
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


	//Get Peers
	std::string peersJSON;
	FinnHub::Peers peers;
	if (::testGetPeers) {
		peersJSON = dataExchange.GetPeers("AAPL");
		peers.Deserialise(peersJSON);
	}


	//Basic Financials
	std::string basicFinancialsJSON;
	FinnHub::BasicFinancials basicFinancials;
	if (::testGetBasicFinancials) {
		basicFinancialsJSON = dataExchange.GetBasicFinancials("AAPL", FinnHubAPI::metric::price);
		basicFinancials.Deserialise(basicFinancialsJSON);
	}
	

	//IPO Calendar
	std::string ipoJSON;
	std::vector<FinnHub::IPO> IPOs;
	if (::testIPOCalendar) {
		ipoJSON = dataExchange.GetIPOCalendar();
		for (int i = 0; i < JSON::NumObjects(ipoJSON); i++) {
			FinnHub::IPO tmp;
			tmp.Deserialise(JSON::GetObjDataN(ipoJSON, i));
			IPOs.push_back(tmp);
		}
	}


	//Recommendation Trends
	std::string recommendationJSON;
	std::vector<FinnHub::Recommendations> recommendations;
	if (::testGetReccomendations) {
		recommendationJSON = dataExchange.GetRecommendationTrends("AAPL");
		for (int i = 0; i < JSON::NumObjects(recommendationJSON); i++) {
			FinnHub::Recommendations tmp;
			tmp.Deserialise(JSON::GetObjDataN(recommendationJSON, i));
			recommendations.push_back(tmp);
		}
	}


	//Price Target
	std::string priceTargetJSON;
	FinnHub::PriceTarget priceTarget;
	if (::testGetPriceTarget) {
		priceTargetJSON = dataExchange.GetPriceTarget("AAPL");
		priceTarget.Deserialise(priceTargetJSON);
	}


	//historic data
	//todo, need to deserialise into candle array
	std::string historicJSON;

	auto _end = std::chrono::system_clock::now();
	std::time_t end = std::chrono::system_clock::to_time_t(_end);
	const long long Year = 31556952;
	std::time_t start = end - (Year);

	FinnHub::CandleArray historicCandles;

	if (::testHistoricData) {
		historicJSON = dataExchange.GetHistoricCandles("AAPL", FinnHubAPI::Period::min30, end - 3600*24*7*13, end );
		historicCandles.Deserialise(historicJSON);
	}
	
	auto data = historicCandles.GetData();

	MACD HIST(data);
	
	std::vector<double> TEST = HIST.MACDHist();

	for (auto element : TEST) {
		std::cout << element;
		std::cout << std::endl;
	}



	std::cout << "finished" << std::endl; //debug break here to see output.
}