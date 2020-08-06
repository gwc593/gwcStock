#include"gepch.h"
#include"FinnHub.h"
#include"Core/URLData.h"

FinnHubAPI* FinnHubAPI::s_Instance = nullptr;

void FinnHubAPI::Init(std::string key)
{
	if (key == "") {
		std::cout << "Finnhub API key not initialised... exiting" << std::endl;
		exit(1);
	}

	if (s_Instance == nullptr)
		s_Instance = new FinnHubAPI(key);
}

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
	std::lock_guard<std::mutex> lock(m_threadLock);
	std::string action = "/quote?symbol\=";

	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}


std::string FinnHubAPI::GetHistoricCandles(const char* symbol, Period period, std::time_t start, std::time_t end)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	std::string action = "/stock/candle?symbol=";
	///stock/candle?symbol=AAPL&resolution=1&from=1572651390&to=1572910590
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string prd;

	switch (period) {
	case Period::min1:	prd = "1";	break;
	case Period::min5:	prd = "5";	break;
	case Period::min15: prd = "15"; break;
	case Period::min30: prd = "30"; break;
	case Period::min60: prd = "60"; break;
	case Period::day:	prd = "D";	break;
	case Period::week:	prd = "W";	break;
	case Period::month: prd = "M";	break;
	}

	std::string req = m_Base + action + symbol + std::string("&resolution=") + prd + "&from=" + std::to_string(start) + "&to=" + std::to_string(end) +  m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetSymbols(const char* exchange)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	std::string action = "/stock/symbol?exchange=";

	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string req = m_Base + action + exchange + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetCompanyProfile2(const char* symbol)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/stock/profile2?symbol=";
	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetNews(const char* category, uint32_t minID)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/news?category=" + std::string(category) + "&minId=" + std::to_string(minID);
	std::string req = m_Base + action + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetCompanyNews(const char* symbol, const char* startDate, const char* endDate)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string action = "/company-news?symbol=" + std::string(symbol) + "&from=" + startDate + "&to=" + endDate;

	std::string req = m_Base + action + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetNewsSentiment(const char* symbol)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string action = "/news-sentiment?symbol=";

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}

std::string FinnHubAPI::GetPeers(const char* symbol)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();

	std::string action = "/stock/peers?symbol=";

	std::string req = m_Base + action + symbol + m_Key;

	std::string result = url->CurlURL(req);

	return result;
}



std::string FinnHubAPI::GetBasicFinancials(const char* symbol, metric type)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	std::string metricType;
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/stock/metric?symbol=" + std::string(symbol);

	switch (type) {
	case FinnHubAPI::metric::all:
		metricType = "all";
		break;
	case FinnHubAPI::metric::price:
		metricType = "price";
		break;
	case FinnHubAPI::metric::valuation:
		metricType = "valuation";
		break;
	case FinnHubAPI::metric::margin:
		metricType = "margin";
		break;
	default:
		metricType = "all";
		break;
	}

	action += "&metric=" + metricType;

	std::string req = m_Base + action + m_Key;

	std::string result = url->CurlURL(req);
	return result;
}


std::string FinnHubAPI::GetIPOCalendar(const char* startDate , const char* endDate)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/calendar/ipo?from=" + std::string(startDate) +"&to=" + endDate;
	return url->CurlURL(m_Base + action + m_Key);
}


std::string FinnHubAPI::GetRecommendationTrends(const char* symbol)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/stock/recommendation?symbol=" + std::string(symbol);
	return url->CurlURL(m_Base + action + m_Key);
}

std::string FinnHubAPI::GetPriceTarget(const char* symbol)
{
	std::lock_guard<std::mutex> lock(m_threadLock);
	gwcStock::URLData* url = gwcStock::URLData::GetInstance();
	std::string action = "/stock/price-target?symbol=" + std::string(symbol);
	return url->CurlURL(m_Base + action + m_Key);
}