#include"gepch.h"
#include"FinnHub.h"
#include"Core/URLData.h"

FinnHubAPI::FinnHubAPI(std::string key)
{
	m_Key = "&token=" + key;
	m_Base = "https://finnhub.io/api/v1";
}

FinnHubAPI::FinnHubAPI()
{
	m_Key = "&token=null";
	m_Base = "https://finnhub.io/api/v1";
}

void FinnHubAPI::SetKey(std::string key)
{
	std::string keyData = "&token=" + key;
}

void FinnHubAPI::SetBase(std::string base)
{
	m_Base = base;
}


std::string FinnHubAPI::GetQuote(const char* symbol)
{
	std::string action = "/quote?symbol\=";

	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetSymbols(const char* exchange)
{
	std::string action = "/stock/symbol?exchange=";

	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string req = m_Base + action + exchange + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetCompanyProfile2(const char* symbol)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/stock/profile2?symbol=";
	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetNews(const char* category, uint32_t minID)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/news?category=" + std::string(category) + "&minId=" + std::to_string(minID);
	std::string req = m_Base + action + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetCompanyNews(const char* symbol, const char* startDate, const char* endDate)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string action = "/company-news?symbol=" + std::string(symbol) + "&from=" + startDate + "&to=" + endDate;

	std::string req = m_Base + action + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetNewsSentiment(const char* symbol)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string action = "/news-sentiment?symbol=";

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetPeers(const char* symbol)
{
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string action = "/stock/peers?symbol=";

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}