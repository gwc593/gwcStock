#pragma once
#include<string>
#include<ctime>


/// <summary>
/// An Object to execute the available API calls provided by FinnHub
/// </summary>
class FinnHubAPI
{
public:
	/// <summary>
	/// Default Constructor.  APIT key must be set with SetKey(std::string key) method
	/// </summary>
	/// <returns></returns>
	FinnHubAPI();

	/// <summary>
	/// Constructor Overloaded to take API key, linked to your FinnHub account
	/// </summary>
	/// <returns></returns>
	FinnHubAPI(std::string key);
	~FinnHubAPI() = default;

	/// <summary>
	/// Method to set API key, linked to your FinnHub account
	/// </summary>
	/// <param name="key"> your API key </param>
	/// <returns>void</returns>
	void SetKey(std::string key);

	/// <summary>
	/// Method to set the base URL - defaulted to https://finnhub.io/api/v1
	/// </summary>
	/// <param name="base"> base URL of API calls </param>
	/// <returns>void</returns>
	void SetBase(std::string base);

	/// <summary>
	/// Method to retrieve all available stock symbols tracked by FinnHub within the specified exchange.
	/// return JSON fomatted string, can be deserialied by a FinnHub::Symbol object.
	/// Documentation at https://finnhub.io/docs/api#stock-symbols
	/// </summary>
	/// <param name="exchange"> stock exchange symbol eg 'US' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetSymbols(const char* exchange);

	/// <summary>
	/// Method to get a real-time quote for a symbol provided.
	/// return JSON fomatted string, can be deserialied by a FinnHub::Candle object.
	/// Documentation at https://finnhub.io/docs/api#quote
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetQuote(const char* symbol);


	/// <summary>
	/// Method to get a years worth of historic data between start and end datas
	/// return JSON fomatted string, can be deserialied by a FinnHub::CandleArray object.
	/// Documentation at https://finnhub.io/docs/api#quote
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <param name="start"> std::time_t start date </param>
	/// <param name="end"> std::time_t end date </param>
	/// <param name="period"> use FinnHubAPI::Period enum class </param>
	/// <returns>JSON formatted std::string</returns>
	enum class Period{min1=0, min5,min15,min30,min60,day,week,month};
	std::string GetHistoricCandles(const char* symbol, std::time_t start, std::time_t end, Period period);


	/// <summary>
	/// Method to get company profile data from the free CompanyProfile2 API call
	/// return JSON fomatted string, can be deserialied by a FinnHub::CompanyProfile object.
	/// Documentation at https://finnhub.io/docs/api#company-profile2
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetCompanyProfile2(const char* symbol);

	/// <summary>
	/// Method to get real-time news data
	/// return JSON fomatted string, can be deserialied by a FinnHub::News object.
	/// Documentation at https://finnhub.io/docs/api#general-news
	/// </summary>
	/// <param name="category"> This parameter can be 1 of the following values general, forex, crypto, merger. default to general </param>
	/// <param name="minID"> Use this field to get only news after this ID. Default to 0 </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetNews(const char* category = "general", uint32_t minID = 0);

	/// <summary>
	/// Method to get real-time news data about a specific company
	/// return JSON fomatted string, can be deserialied by a FinnHub::News object.
	/// Documentation at https://finnhub.io/docs/api#company-news
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <param name="startDate"> From this data "YYYY-MM-DD" </param>
	/// <param name="endDate"> To this data "YYYY-MM-DD" </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetCompanyNews(const char* symbol, const char* startDate = "1970-01-01", const char* endDate = "3000-01-01");

	/// <summary>
	/// Method to get real-time news sentiment data about a company/stock
	/// return JSON fomatted string, can be deserialied by a FinnHub::NewsSentiment object.
	/// Documentation at https://finnhub.io/docs/api#news-sentiment
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetNewsSentiment(const char* symbol);


	/// <summary>
	/// Method to peers/similar companies compared to the provided symbol
	/// return JSON fomatted string, can be deserialied by a FinnHub::Peers object.
	/// Documentation at https://finnhub.io/docs/api#news-sentiment
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetPeers(const char* symbol);


	enum class metric
	{
		all = 0,
		price,
		valuation,
		margin
	};
	/// <summary>
	/// Method to peers/similar companies compared to the provided symbol
	/// return JSON fomatted string, can be deserialied by a FinnHub::Peers object.
	/// Documentation at https://finnhub.io/docs/api#company-basic-financials
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <param name="type"> Metric type, please use metric enum, default all </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetBasicFinancials(const char* symbol, metric type = metric::all);

	/// <summary>
	/// Method to get Initial Public Offerings schedule
	/// return JSON fomatted string, can be deserialied by a FinnHub::Peers object.
	/// Documentation at https://finnhub.io/docs/api#ipo-calendar
	/// </summary>
	/// <param name="startDate"> From this data "YYYY-MM-DD" </param>
	/// <param name="endDate"> To this data "YYYY-MM-DD" </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetIPOCalendar(const char* startDate = "1970-01-01", const char* endDate = "3000-01-01");

	/// <summary>
	/// Method to get Recommendation Trends
	/// return JSON fomatted string, can be deserialied by a FinnHub::Peers object.
	/// Documentation at https://finnhub.io/docs/api#recommendation-trends
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetRecommendationTrends(const char* symbol);

	/// <summary>
	/// Method to get Price Target
	/// return JSON fomatted string, can be deserialied by a FinnHub::Peers object.
	/// Documentation at https://finnhub.io/docs/api#price-target
	/// </summary>
	/// <param name="symbol"> stock  symbol eg 'AAPL' </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetPriceTarget(const char* symbol);

private:


	std::string m_Key;
	std::string m_Base;
};