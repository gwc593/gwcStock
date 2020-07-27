#pragma once
#include<string>

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
	/// <param name="minID"> Use this field to get only news after this ID. Default to 0 </param>
	/// <returns>JSON formatted std::string</returns>
	std::string GetCompanyNews(const char* symbol, const char* startDate = "1970-01-01", const char* endDate = "3000-01-01");


private:


	std::string m_Key;
	std::string m_Base;
};