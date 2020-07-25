#include"gepch.h"
#include"FinnHub.h"
#include"Core/URLData.h"

FinnHub::FinnHub()
{
	m_Key = "&token=bse5d8frh5rea8raakb0";
	m_Base = "https://finnhub.io/api/v1";
}

FinnHub* FinnHub::S_Instance = nullptr;

FinnHub* FinnHub::Get()
{
	if (S_Instance == nullptr)
		S_Instance = new FinnHub;

	return S_Instance;
}

std::string FinnHub::GetQuote(const char* symbol)
{
	std::string action = "/quote?symbol\=";

	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}