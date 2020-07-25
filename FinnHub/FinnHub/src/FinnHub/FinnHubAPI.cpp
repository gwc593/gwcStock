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